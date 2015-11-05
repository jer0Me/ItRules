﻿#pragma once
#include <boost/spirit/include/qi.hpp>
#include "Mark.h"
#include "Literal.h"
#include "Expression.h"
#include "RuleList.h"

namespace qi = boost::spirit::qi;
using Iterator = std::string::const_iterator;
using Skipper = qi::ascii::blank_type;
using boost::spirit::qi::symbols;

struct LexicalTokenizer : qi::grammar<Iterator, RuleList(), Skipper>
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

	qi::rule<Iterator, std::vector<Condition>(), Skipper> conditions;
	qi::rule<Iterator, std::string(), Skipper> escaped_character;
	qi::rule<Iterator, std::string(), Skipper> expressionLiteralText;
	qi::rule<Iterator, std::string(), Skipper> expressionCharAdmitted;
	qi::rule<Iterator, Expression(), Skipper> expression;
	qi::rule<Iterator, std::string(), Skipper> markWithDots;
	qi::rule<Iterator, Mark(), Skipper> markList;
	qi::rule<Iterator, std::string(), Skipper> separator;
	qi::rule<Iterator, Mark(), Skipper> mark;
	qi::rule<Iterator, std::string(), Skipper> name;
	qi::rule<Iterator, std::string(), Skipper> text;
	qi::rule<Iterator, std::vector<std::string>(), Skipper> options;
	qi::rule<Iterator, Literal(), Skipper> literal;
	qi::rule<Iterator, Literal(), Skipper> expressionLiteral;
	qi::rule<Iterator, std::string(), Skipper> newLine;
	qi::rule<Iterator, std::string(), Skipper> tab;
	qi::rule<Iterator, std::vector<Rule::tokenVariant>(), Skipper> tokens;
	qi::rule<Iterator, std::vector<Expression::tokenVariant>(), Skipper> expressionTokens;
	qi::rule<Iterator, std::vector<Rule>(), Skipper> ruleList;
	qi::rule<Iterator, Rule(), Skipper> rule;
	qi::rule<Iterator, RuleList(), Skipper> start;
	qi::rule<Iterator, std::string(), Skipper> charAdmitted;
	qi::rule<Iterator, Condition(), Skipper> condition;
};


