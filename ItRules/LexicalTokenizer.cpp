#define BOOST_SPIRIT_DEBUG
#include "LexicalTokenizer.h"
#include <boost/spirit/include/phoenix.hpp>
#include <boost/spirit/home/qi/operator/list.hpp>
#include <boost/spirit/include/qi_list.hpp>

using Iterator = std::string::const_iterator;
using boost::phoenix::at_c;

BOOST_FUSION_ADAPT_STRUCT(Condition, (std::string, name), (std::string, parameter))
BOOST_FUSION_ADAPT_STRUCT(RuleList, (std::vector<Rule>, rules))
BOOST_FUSION_ADAPT_STRUCT(Mark, (std::string, name), (std::vector<std::string>, options),(std::string, separator))
BOOST_FUSION_ADAPT_STRUCT(Literal, (std::string, text))
BOOST_FUSION_ADAPT_STRUCT(Rule, (std::vector<Condition>, conditions), (std::vector<Rule::tokenVariant>, tokens))

LexicalTokenizer::LexicalTokenizer() : LexicalTokenizer::base_type(start)
{
	setConditionDefinition();
	setTokensDefinition();
	setRulesDefinition();
	BOOST_SPIRIT_DEBUG_NODES((conditions)(mark)(markWithDots)(markList)(tokens)(text)(literal)(options)(rule)(ruleList)(start))
}


void LexicalTokenizer::setConditionDefinition()
{	
	conditions %= +(qi::lexeme[+qi::alnum > '(' > *qi::alnum > ')']);
	
}

void LexicalTokenizer::setTokensDefinition()
{
	
	options %= qi::no_skip[qi::lit("+") >> +qi::alnum];
	markWithDots %= qi::lexeme[qi::lit("$") >> +qi::alnum >> qi::string("...")];
	markList = markWithDots[at_c<0>(qi::_val) = qi::_1] >> 
		qi::lexeme[qi::lit("[") >> qi::string("$NL")[at_c<2>(qi::_val) = "\n"] >> 
		qi::lit("]")] >> *(options)[at_c<1>(qi::_val) = qi::_1];
	mark %= markList | (qi::lexeme[qi::lit("$") >> +qi::alnum] >> *options);
	escaped_character %= qi::no_skip[qi::lit("$") >> qi::string("$") | qi::string("[") | qi::string("]")];
	text %= +(!(qi::eol >> qi::lit("end")) >> (escaped_character | qi::no_skip[*qi::lit("\t") >> qi::char_ - qi::lit("$")]));
	literal %= text;
	tokens %= +(mark | literal);
}

void LexicalTokenizer::setRulesDefinition()
{
	rule %= qi::lit("def") >> conditions >> qi::eol >> tokens >> qi::eol >> qi::lit("end");
	ruleList %= (rule % +qi::eol);
	start %= ruleList;
}
