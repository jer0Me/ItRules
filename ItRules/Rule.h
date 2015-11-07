#pragma once
#include "Condition.h"
#include "Token.h"
#include <list>

class Rule
{
	std::list<Condition> conditions;	
	std::list<Token*> tokens;

public:
	void setRule(std::list<Condition> conditions, std::list<Token*> tokens);

	std::list<Condition>::iterator get_conditions_iterator();

	std::list<Token*>::iterator get_token_iterator();
};
