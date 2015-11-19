#pragma once
#include "Condition.h"
#include "Token.h"
#include <list>

class Rule : public Token
{
	std::list<Condition*> conditions;	
	std::list<Token*> tokens;
	bool initiated = false;

	void delete_conditions();
	void delete_tokens();

public:

	Rule(std::list<Condition*> conditions, std::list<Token*> tokens);

	~Rule();

	void set_rule(std::list<Condition*> conditions, std::list<Token*> tokens);

	bool operator<(const Rule &rule) const;

	std::list<Condition*> get_conditions();

	bool is_initiated() const;

	std::list<Token*> get_tokens();

};
