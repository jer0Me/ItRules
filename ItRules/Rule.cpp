#include "Rule.h"

Rule::Rule(std::list<Condition*> conditions, std::list<Token*> tokens) : conditions(conditions), tokens(tokens)
{
	this->initiated = true;
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

std::list<Condition*>& Rule::get_conditions()
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






