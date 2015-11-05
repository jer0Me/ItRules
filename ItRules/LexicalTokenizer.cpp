#define BOOST_SPIRIT_DEBUG
#include "LexicalTokenizer.h"
#include <boost/spirit/include/phoenix.hpp>

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


BOOST_FUSION_ADAPT_STRUCT(Condition, (std::string, name), (std::string, parameter), (bool, negated))
BOOST_FUSION_ADAPT_STRUCT(RuleList, (std::vector<Rule>, rules))
BOOST_FUSION_ADAPT_STRUCT(Mark, (std::string, name), (std::vector<std::string>, options),(std::string, separator))
BOOST_FUSION_ADAPT_STRUCT(Literal, (std::string, text))
BOOST_FUSION_ADAPT_STRUCT(Expression, (std::vector<Expression::tokenVariant>, tokens))
BOOST_FUSION_ADAPT_STRUCT(Rule, (std::vector<Condition>, conditions), (std::vector<Rule::tokenVariant>, tokens))

LexicalTokenizer::LexicalTokenizer() : base_type(start)
{
	setConditionDefinition();
	setTokensDefinition();
	setRulesDefinition();
	BOOST_SPIRIT_DEBUG_NODES(
		(conditions)
		(expressionLiteralText)
		(expressionLiteral)
		(expressionTokens)
		(mark)
		(markWithDots)
		(markList)
		(tokens)
		(charAdmitted)
		(tab)
		(text)
		(literal)
		(expression)
		(newLine)
		(options)
		(rule)
		(ruleList)
		(start)
	)
}


void LexicalTokenizer::setConditionDefinition()
{	
	condition = lexeme[+(alnum)[at_c<0>(_val) += _1] >> '(' >> (lit('!')[at_c<2>(_val) = true] | -lit('!')[at_c<2>(_val) = false]) >> *(alnum)[at_c<1>(_val) += _1] >> ')'];
	conditions %= +(condition);
}

void LexicalTokenizer::setMarkTokenDefinition()
{
	options %= no_skip[lit("+") >> +alnum];
	markWithDots %= lexeme[lit("$") >> +alnum >> string("...")];
	markList = markWithDots[at_c<0>(_val) = _1] >> lexeme[lit("[") >> string("$NL")[at_c<2>(_val) = "\n"] >> lit("]")] >> *(options)[at_c<1>(_val) = _1];
	mark %= markList | (lexeme[lit("$") >> +alnum] >> *options);
}

void LexicalTokenizer::setLiteralTokenDefinition()
{
	charAdmitted %= no_skip[char_ - lit("$")];
	tab = ((!eol >> charAdmitted) >> no_skip[string("\t")] >> charAdmitted)[_val += _1 + _2 + _3] | no_skip[lit("\t")];
	escaped_character %= no_skip[lit("$") >> string("$") | string("[") | string("]")];
	text %= +(!((eol >> lit("end") | lit("["))) >> (tab | escaped_character | charAdmitted));
	literal %= text;
}

void LexicalTokenizer::setExpressionTokenDefinition()
{	
	expressionLiteralText %= no_skip[string("\n")] | no_skip[string("\t")] | +(!(lit("]") | lit("[")) >> charAdmitted);
	expressionLiteral %= expressionLiteralText;
	expressionTokens %= lit("[") >> +(expressionLiteral | mark) >> lit("]");
	expression %= expressionTokens;
	
}

void LexicalTokenizer::setTokensDefinition()
{
	setMarkTokenDefinition();
	setLiteralTokenDefinition();
	setExpressionTokenDefinition();
	tokens %= +(mark | literal | expression);
}



void LexicalTokenizer::setRulesDefinition()
{
	rule %= lit("def") >> conditions >> eol >> tokens >> eol >> lit("end");
	ruleList %= (rule % +eol);
	start %= ruleList;
}
