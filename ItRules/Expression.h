#pragma once
#include "Token.h"
#include <list>

class Expression : public Token
{
	std::list<Token*> tokens;
	Expression* other;

public:
	Expression(std::list<Token*> tokens);
	Expression(std::initializer_list<Token*> tokens);
	void set_other_expression(Expression* other);
	std::list<Token*> get_tokens();
	Expression* get_other();
};
