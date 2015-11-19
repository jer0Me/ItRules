#include "Rule.h"
#include <algorithm>

Rule::Rule(std::list<Condition*> conditions, std::list<Token*> tokens) : conditions(conditions), tokens(tokens)
{
	this->initiated = true;
}

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
	this->initiated = true;
}

bool Rule::operator < (const Rule& rule) const
{
	return true;
}

std::list<Condition*> Rule::get_conditions()
{
	return this->conditions;
}

bool Rule::is_initiated() const
{
	return initiated;
}

std::list<Token*> Rule::get_tokens()
{
	return tokens;
}






