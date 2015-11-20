#pragma once
#include "Condition.h"
#include "Token.h"
#include <list>

class Rule : public Token
{
	std::list<Condition*> conditions;	
	std::list<Token*> tokens;

	void delete_conditions();
	void delete_tokens();

public:

	Rule();

	Rule(std::list<Condition*> conditions, std::list<Token*> tokens);

	~Rule();

	std::list<Token*> get_tokens();

	std::list<Condition*> get_conditions();

	void set_rule(std::list<Condition*> conditions, std::list<Token*> tokens);

	bool operator<(const Rule &rule) const;

	Rule* add(Condition* condition);

	Rule* add(std::initializer_list<Condition*> conditions);

	Rule* add(std::initializer_list<Token*> tokens);

	Rule* add(Token* token);




};
