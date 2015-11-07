#include "Token.h"

Token::~Token(){}

void Token::setPrevious(Token* previous)
{
	this->previous = previous;
}
