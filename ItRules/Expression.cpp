#include "Expression.h"

Expression::Expression(std::list<Token*> tokens) : tokens(tokens){}

void Expression::setOtherExpression(Expression& other)
{
	this->other = &other;
}
