#pragma once
#include "Condition.h"
#include "Token.h"
#include <list>

class Rule
{
	std::list<Condition*> conditions;	
	std::list<Token*> tokens;
	bool initiated = false;

public:

	Rule(std::list<Condition*> conditions, std::list<Token*> tokens);

	void set_rule(std::list<Condition*> conditions, std::list<Token*> tokens);

	bool operator<(const Rule &rule) const;

	std::list<Condition*>& get_conditions();

	bool is_initiated() const;

	std::list<Token*> get_tokens();

};
