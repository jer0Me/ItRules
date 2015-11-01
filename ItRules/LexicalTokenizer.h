#pragma once

#include <boost/spirit/include/qi.hpp>
#include "RuleList.h"

namespace qi = boost::spirit::qi;
using Iterator = std::string::const_iterator;
using Skipper = qi::ascii::blank_type;

struct LexicalTokenizer : qi::grammar<Iterator, RuleList(), Skipper>
{
public:
	LexicalTokenizer();
	void setConditionDefinition();
	void setActionDefinition();
	void setRulesDefinition();
	qi::rule<Iterator, std::string(), Skipper> actionBody;
	qi::rule<Iterator, std::string(), Skipper> stringWithNewLine;
	qi::rule<Iterator, std::string(), Skipper> keyword;
	qi::rule<Iterator, Condition(), Skipper> condition;
	qi::rule<Iterator, Function(), Skipper> function;
	qi::rule<Iterator, std::vector<Function>(), Skipper> functionList;
	qi::rule<Iterator, Action(), Skipper> action;
	qi::rule<Iterator, RuleList(), Skipper> start;
	qi::rule<Iterator, std::vector<Rule>(), Skipper> ruleList;
	qi::rule<Iterator, Rule(), Skipper> rule;

};


