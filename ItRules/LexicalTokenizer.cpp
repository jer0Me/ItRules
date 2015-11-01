#define BOOST_SPIRIT_DEBUG
#include "LexicalTokenizer.h"
#include <boost/spirit/include/phoenix.hpp>
#include <boost/spirit/home/qi/operator/list.hpp>
#include <boost/spirit/include/qi_list.hpp>

using Iterator = std::string::const_iterator;


BOOST_FUSION_ADAPT_STRUCT(Function, (std::string, type), (std::string, value))
BOOST_FUSION_ADAPT_STRUCT(Condition, (std::vector<Function>, functionList))
BOOST_FUSION_ADAPT_STRUCT(Action, (std::string, body))
BOOST_FUSION_ADAPT_STRUCT(Rule, (Condition, condition), (Action, action))
BOOST_FUSION_ADAPT_STRUCT(RuleList, (std::vector<Rule>, rules))

LexicalTokenizer::LexicalTokenizer() : LexicalTokenizer::base_type(start)
{
	setConditionDefinition();
	setActionDefinition();
	setRulesDefinition();
	qi::on_error<qi::fail>
		(ruleList, std::cout
			<< boost::phoenix::val("Error! Expecting ")
			<< qi::_4
			<< boost::phoenix::val(":")
			<< std::endl
			<< boost::phoenix::construct<std::string>(qi::_3, qi::_2)
			<< std::endl);
	BOOST_SPIRIT_DEBUG_NODES((keyword)(function)(functionList)(condition)(actionBody)(action)(rule)(ruleList))
}

void LexicalTokenizer::setConditionDefinition()
{
	functionList %= +(qi::lexeme[+qi::alnum > '(' > *qi::alnum > ')']);
	condition %= functionList;
}

void LexicalTokenizer::setActionDefinition()
{
	actionBody %= +(!(qi::eol >> qi::lit("end")) >> qi::no_skip[qi::char_]);
	action %= actionBody;
}

void LexicalTokenizer::setRulesDefinition()
{
	rule %= qi::lit("def") >> condition >> qi::eol >> action >> qi::eol >> qi::lit("end");
	ruleList %= rule % +qi::eol;
	start %= ruleList;
}
