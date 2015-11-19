#include "Expression.h"

Expression::Expression(std::list<Token*> tokens) : tokens(tokens){}

void Expression::setOtherExpression(Expression& other)
{
	this->other = &other;
}

std::list<Token*> Expression::get_tokens()
{
	return this->tokens;
}

Expression* Expression::get_other()
{
	return this->other;
}
