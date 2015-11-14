#pragma once
#include "Token.h"
#include <list>

class Expression : public Token
{
	std::list<Token*> tokens;
	Expression* other;

public:
	Expression(std::list<Token*> tokens);
	void setOtherExpression(Expression& other);
};
