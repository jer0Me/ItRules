#include "Token.h"

Token::~Token(){}

void Token::set_previous(Token* previous)
{
	this->previous = previous;
}

Token* Token::get_previous()
{
	return this->previous;
}

std::string Token::to_string()
{
	return "";
}
