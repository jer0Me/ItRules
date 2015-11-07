#pragma once
#include <boost/spirit/include/qi.hpp>
#include "RuleList.h"

namespace qi = boost::spirit::qi;
using Iterator = std::string::const_iterator;
using Skipper = qi::ascii::blank_type;
using boost::spirit::qi::symbols;

struct LexicalTokenizer : qi::grammar<Iterator, std::list<Rule>(), Skipper>
{
public:
	LexicalTokenizer();

private:
	void setConditionDefinition();
	void setTokensDefinition();
	void setRulesDefinition();
	void setMarkTokenDefinition();
	void setLiteralTokenDefinition();
	void setExpressionTokenDefinition();

	qi::rule<Iterator, std::string(), Skipper> conditionType;
	qi::rule<Iterator, std::string(), Skipper> conditionParameter;
	qi::rule<Iterator, std::list<Condition>(), Skipper> conditions;
	qi::rule<Iterator, std::string(), Skipper> escaped_character;
	qi::rule<Iterator, std::string(), Skipper> expressionLiteralText;
	qi::rule<Iterator, std::string(), Skipper> expressionCharAdmitted;
	qi::rule<Iterator, Token*(), Skipper> expression;
	qi::rule<Iterator, std::string(), Skipper> markWithDots;
	qi::rule<Iterator, Token*(), Skipper> markList;
	qi::rule<Iterator, std::string(), Skipper> markText;
	qi::rule<Iterator, std::string(), Skipper> separator;
	qi::rule<Iterator, Token*(), Skipper> mark;
	qi::rule<Iterator, std::string(), Skipper> name;
	qi::rule<Iterator, std::string(), Skipper> text;
	qi::rule<Iterator, std::list<std::string>(), Skipper> options;
	qi::rule<Iterator, Token*(), Skipper> literal;
	qi::rule<Iterator, Token*(), Skipper> expressionLiteral;
	qi::rule<Iterator, std::string(), Skipper> newLine;
	qi::rule<Iterator, std::string(), Skipper> tab;
	qi::rule<Iterator, std::list<Token*>(), Skipper> tokens;
	qi::rule<Iterator, std::list<Token*>(), Skipper> expressionTokens;
	qi::rule<Iterator, std::list<Rule>(), Skipper> ruleList;
	qi::rule<Iterator, Rule(), Skipper> rule;
	qi::rule<Iterator, std::list<Rule>(), Skipper> start;
	qi::rule<Iterator, std::string(), Skipper> charAdmitted;
	qi::rule<Iterator, Condition(), Skipper> condition;
};


