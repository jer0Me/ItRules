#include "Rule.h"
#include <algorithm>
#include <boost/foreach.hpp>

Rule::Rule(){}

Rule::Rule(std::list<Condition*> conditions, std::list<Token*> tokens) : conditions(conditions), tokens(tokens){}


Rule::~Rule()
{
	delete_conditions();
	delete_tokens();
}

void Rule::delete_conditions()
{
	for_each(this->conditions.begin(), this->conditions.end(), [](Condition* condition)
	{
		delete condition;
	});
}

void Rule::delete_tokens()
{
	for_each(this->tokens.begin(), this->tokens.end(), [](Token* token)
	{
		delete token;
	});
}

void Rule::set_rule(std::list<Condition*> conditions, std::list<Token*> tokens)
{
	this->conditions = conditions;
	this->tokens = tokens;
}

bool Rule::operator < (const Rule& rule) const
{
	return true;
}

std::list<Condition*> Rule::get_conditions()
{
	return this->conditions;
}

std::list<Token*> Rule::get_tokens()
{
	return tokens;
}

Rule* Rule::add(Condition* condition)
{
	this->conditions.push_back(condition);
	return this;
}

Rule* Rule::add(std::initializer_list<Condition*> conditions)
{
	BOOST_FOREACH(Condition* condition, conditions)
	{
		this->conditions.push_back(condition);
	}
	return this;
}

Rule* Rule::add(Token* token)
{
	this->tokens.push_back(token);
	return this;
}

Rule* Rule::add(std::initializer_list<Token*> tokens)
{
	BOOST_FOREACH(Token* token, tokens)
	{
		this->tokens.push_back(token);
	}
	return this;
}