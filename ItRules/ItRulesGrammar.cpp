#define BOOST_SPIRIT_DEBUG
#include "ItRulesGrammar.h"
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

ItRulesGrammar::ItRulesGrammar() : base_type(start)
{
	set_condition_grammar();
	set_tokens_grammar();
	set_rules_grammar();
	BOOST_SPIRIT_DEBUG_NODES(
		(condition_name)
		(condition_parameter)
		(conditions)
		(escaped_character)
		(expression_literal_text)
		(expression)
		(mark_with_dots)
		(mark_list)
		(mark_name)
		(separator)
		(mark)
		(text)
		(mark_options)
		(literal)
		(expression_literal)
		(tab)
		(tokens)
		(expression_tokens)
		(rule)
		(start)
		(char_admitted)
		(condition)
		(string_separator)
		)
}


void ItRulesGrammar::set_condition_grammar()
{	
	condition_name %= +alnum;
	condition_parameter %= lexeme['(' >> *alnum >> ')'];
	condition = (condition_name >> condition_parameter)[_val = new_<Condition>(_1, _2, false)];
	conditions = +(condition)[push_back(_val, _1)];
}

void ItRulesGrammar::set_mark_token_grammar()
{
	escaped_character %= no_skip[lit("$") >> (string("$") | string("[") | string("]") | lit("NL")[_val = "\n"])];
	mark_options %= no_skip[*(lit("+") >> +alnum)];
	mark_name %= lexeme[lit("$") >> +alnum];
	mark_with_dots %= lexeme[lit("$") >> +alnum >> lit("...")];
	string_separator %= no_skip[+(char_ - "]")];
	separator %= lit("[") >> (escaped_character | string_separator) >> lit("]");
	mark_list = (mark_with_dots >> separator >> mark_options)[_val = new_<Mark>(_1, _3, _2)];
	mark = mark_list[_val = _1] | (mark_name >> mark_options)[_val = new_<Mark>(_1, _2)];
}

void ItRulesGrammar::set_literal_token_grammar()
{
	char_admitted %= no_skip[char_ - lit("$")];
	tab %= no_skip[qi::repeat(4)[" "] >> *(qi::repeat(4)[" "][_val += "\t"])];
	text %= +(!((eol >> lit("end") | no_skip[lit("[")])) >> (tab | escaped_character | char_admitted));
	literal = text[_val = new_<Literal>(_1)];
}

void ItRulesGrammar::set_expression_token_grammar()
{	
	expression_literal_text %= no_skip[string("\n")] | no_skip[qi::repeat(4)[" "] >> qi::repeat(4)[" "][_val += "\t"]] | +(!(lit("]") | lit("[")) >> char_admitted);
	expression_literal = expression_literal_text[_val = new_<Literal>(_1)];
	expression_tokens = lit("[") >> +(expression_literal | mark)[push_back(_val, _1)] >> lit("]");
	expression = expression_tokens[_val = new_<Expression>(_1)];
	
}

void ItRulesGrammar::set_tokens_grammar()
{
	set_mark_token_grammar();
	set_literal_token_grammar();
	set_expression_token_grammar();
	tokens = +(mark | literal | expression)[push_back(_val, _1)];
}

void ItRulesGrammar::set_rules_grammar()
{
	rule = (lit("def") >> conditions >> eol >> tokens >> eol >> lit("end"))[_val = new_<Rule>(_1, _2)];
	start = *(rule[push_back(_val, _1)] % +eol);
}
