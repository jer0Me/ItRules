#include "Rule.h"

void Rule::setRule(std::list<Condition> conditions, std::list<Token*> tokens)
{
	this->conditions = conditions;
	this->tokens = tokens;
}

std::list<Condition>::iterator Rule::get_conditions_iterator()
{
	return conditions.begin();
}

std::list<Token*>::iterator Rule::get_token_iterator()
{
	return tokens.begin();
}