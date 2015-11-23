#include "LexicalAnalyzerFixtures.h"
#include <LexicalAnalyzer.h>
#include <boost/foreach.hpp>
#include <Literal.h>
#include <Mark.h>


std::list<Rule*> LexicalAnalyzerFixtures::simple_rule() const
{
	std::string const input = "def type(person)\nbody\nend";
	LexicalAnalyzer analyzer;
	return analyzer.analyze(input);
}

std::list<Rule*> LexicalAnalyzerFixtures::simple_rule_with_tabs() const
{
	std::string const input = "def type(person)\n        body\nend";
	LexicalAnalyzer analyzer;
	return analyzer.analyze(input);
}

std::list<Rule*> LexicalAnalyzerFixtures::rule_with_mark_options() const
{
	std::string const input = "def type(person)\n$Name was born in $Country+Capitalize in $Birthday+Year\nend";
	LexicalAnalyzer analyzer;
	return analyzer.analyze(input);
}

bool LexicalAnalyzerFixtures::is_condition_name(std::string name, Condition* condition) const
{
	return condition->get_name().compare(name) == 0;
}

bool LexicalAnalyzerFixtures::is_condition_parameter(std::string parameter, Condition* condition) const
{
	return condition->getParameter().compare(parameter) == 0;
}

bool LexicalAnalyzerFixtures::is_literal(Token* token)
{
	return dynamic_cast<Literal*>(token) != nullptr;
}

bool LexicalAnalyzerFixtures::is_mark(Token* token)
{
	return dynamic_cast<Mark*>(token) != nullptr;
}

bool LexicalAnalyzerFixtures::is_mark_name(std::string name, Token* token)
{
	return dynamic_cast<Mark*>(token)->get_name().compare(name) == 0;
}

bool LexicalAnalyzerFixtures::is_mark_options(std::vector<std::string> options, Token* token)
{
	return options == dynamic_cast<Mark*>(token)->get_options();
}

bool LexicalAnalyzerFixtures::check_literal_value(Token* token, std::string text) const
{
	return dynamic_cast<Literal*>(token)->to_string().compare(text) == 0;
}

bool LexicalAnalyzerFixtures::check_condition(::std::string name, ::std::string parameter, Rule* rule) const
{
	BOOST_FOREACH(Condition* condition, rule->get_conditions())
	{
		if (is_condition_name(name, condition) && 
			is_condition_parameter(parameter, condition) ) return true;
	}
	return false;
}

bool LexicalAnalyzerFixtures::check_token_literal(std::string text, Rule* rule)
{
	BOOST_FOREACH(Token* token, rule->get_tokens())
	{
		if (is_literal(token) && check_literal_value(token, text))
		{
			return true;
		}
	}
	return false;
}

bool LexicalAnalyzerFixtures::check_token_mark(std::string name, std::initializer_list<std::string> options, Rule* rule)
{
	BOOST_FOREACH(Token* token, rule->get_tokens())
	{
		if (is_mark(token) && is_mark_name(name, token) && is_mark_options(options, token))
		{
			return true;
		}
	}
	return false;
}