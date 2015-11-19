#define BOOST_SPIRIT_DEBUG
#include "LexicalTokenizer.h"
#include <boost/spirit/include/phoenix.hpp>
#include <boost/spirit/include/qi.hpp>
#include "Literal.h"
#include "Mark.h"
#include "Expression.h"

namespace qi = boost::spirit::qi;

using Iterator = std::string::const_iterator;
using boost::phoenix::at_c;
using qi::lit;
using qi::string;
using qi::char_;
using qi::alnum;
using qi::no_skip;
using qi::lexeme;
using qi::eol;
using qi::_val;
using qi::_1;
using qi::_2;
using qi::_3;
using qi::_4;
using boost::phoenix::new_;
using boost::phoenix::push_back;

LexicalTokenizer::LexicalTokenizer() : base_type(start)
{
	setConditionDefinition();
	setTokensDefinition();
	setRulesDefinition();
	BOOST_SPIRIT_DEBUG_NODES(
		(conditionType)
		(conditionParameter)
		(conditions)
		(escaped_character)
		(expressionLiteralText)
		(expression)
		(markWithDots)
		(markList)
		(markText)
		(separator)
		(mark)
		(text)
		(options)
		(literal)
		(expressionLiteral)
		(tab)
		(tokens)
		(expressionTokens)
		(rule)
		(start)
		(charAdmitted)
		(condition)
		(separatorChar)
		)
}


void LexicalTokenizer::setConditionDefinition()
{	
	conditionType %= +alnum;
	conditionParameter %= lexeme['(' >> *alnum >> ')'];
	condition = (conditionType >> conditionParameter)[_val = new_<Condition>(_1, _2, false)];
	conditions = +(condition)[push_back(_val, _1)];
}

void LexicalTokenizer::setMarkTokenDefinition()
{
	escaped_character %= no_skip[lit("$") >> (string("$") | string("[") | string("]") | lit("NL")[_val = "\n"])];
	options %= no_skip[*(lit("+") >> +alnum)];
	markText %= lexeme[lit("$") >> +alnum];
	markWithDots %= lexeme[lit("$") >> +alnum >> lit("...")];
	separatorChar %= no_skip[+(char_ - "]")];
	separator %= lit("[") >> (escaped_character | separatorChar) >> lit("]");
	markList = (markWithDots >> separator >> options)[_val = new_<Mark>(_1, _3, _2)];
	mark = markList[_val = _1] | (markText >> options)[_val = new_<Mark>(_1, _2)];
}

void LexicalTokenizer::setLiteralTokenDefinition()
{
	charAdmitted %= no_skip[char_ - lit("$")];
	tab %= no_skip[lit("\t") >> *string("\t")];
	text %= +(!((eol >> lit("end") | lit("["))) >> (tab | escaped_character | charAdmitted));
	literal = text[_val = new_<Literal>(_1)];
}

void LexicalTokenizer::setExpressionTokenDefinition()
{	
	expressionLiteralText %= no_skip[string("\n")] | no_skip[lit("\t") >> string("\t")] | +(!(lit("]") | lit("[")) >> charAdmitted);
	expressionLiteral = expressionLiteralText[_val = new_<Literal>(_1)];
	expressionTokens = lit("[") >> +(expressionLiteral | mark)[push_back(_val, _1)] >> lit("]");
	expression = expressionTokens[_val = new_<Expression>(_1)];
	
}

void LexicalTokenizer::setTokensDefinition()
{
	setMarkTokenDefinition();
	setLiteralTokenDefinition();
	setExpressionTokenDefinition();
	tokens = +(mark | literal | expression)[push_back(_val, _1)];
}



void LexicalTokenizer::setRulesDefinition()
{
	rule = (lit("def") >> conditions >> eol >> tokens >> eol >> lit("end"))[_val = new_<Rule>(_1, _2)];
	start = *(rule[push_back(_val, _1)] % +eol);
}
