﻿#include "LexicalAnalyzer.h"
#include "LexicalTokenizer.h"
#include <boost/spirit/include/qi.hpp>
#include "Mark.h"
#include "Expression.h"

LexicalAnalyzer::LexicalAnalyzer() {}


std::list<Rule*>LexicalAnalyzer::analyze(std::string input)
{
	namespace qi = boost::spirit::qi;
	LexicalTokenizer lexicalTokenizer;
	std::list<Rule*> rules;
	std::string::const_iterator iter = input.begin();
	std::string::const_iterator end = input.end();

	qi::phrase_parse(iter, end, lexicalTokenizer, qi::ascii::blank, rules);
	setRuleTokenPrevious(rules);
	addSlotRule(rules);

	return rules;
}

void LexicalAnalyzer::setRuleTokenPrevious(std::list<Rule*>& rules)
{
	BOOST_FOREACH(Rule* rule, rules)
	{
		setTokenPrevious(rule->get_tokens());
	}
}

void LexicalAnalyzer::setTokenPrevious(std::list<Token*>& tokens)
{
	auto iterator = tokens.begin();
	Token* previous = nullptr;
	Token* current = nullptr;
	auto index = 0;
	while (index++ != tokens.size())
	{
		current = *iterator;
		current->set_previous(previous);
		previous = current;
		if (is_expression(current)) {
			auto expression = dynamic_cast<Expression*>(current);
			setTokenPrevious(expression->get_tokens());
		}
		++iterator;
	}
}

void LexicalAnalyzer::addSlotRule(std::list<Rule*>& rules)
{
	std::list<Condition*> conditions;
	conditions.push_back(new Condition("slot","value", false));
	std::list<Token*> tokens;
	tokens.push_back(new Mark("value"));
	rules.push_back(new Rule(conditions, tokens));
}


bool LexicalAnalyzer::is_expression(Token* token)
{
	try
	{
		auto expression = dynamic_cast<Expression*>(token);
		return expression != nullptr;
	}
	catch (std::exception exception)
	{
		return false;
	}
}