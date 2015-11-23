#include "LexicalAnalyzer.h"
#include "ItRulesGrammar.h"
#include <boost/spirit/include/qi.hpp>
#include "Expression.h"

LexicalAnalyzer::LexicalAnalyzer() {}


std::list<Rule*>LexicalAnalyzer::analyze(std::string input)
{
	namespace qi = boost::spirit::qi;
	ItRulesGrammar grammar;
	std::list<Rule*> rules;
	std::string::const_iterator iter = input.begin();
	std::string::const_iterator end = input.end();

	phrase_parse(iter, end, grammar, qi::ascii::blank, rules);
	set_rule_token_previous(rules);
	return rules;
}

void LexicalAnalyzer::set_rule_token_previous(std::list<Rule*>& rules)
{
	BOOST_FOREACH(Rule* rule, rules)
	{
		set_token_previous(rule->get_tokens());
	}
}

void LexicalAnalyzer::set_token_previous(std::list<Token*>& tokens)
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
			set_token_previous(expression->get_tokens());
		}
		++iterator;
	}
}

bool LexicalAnalyzer::is_expression(Token* token) const
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