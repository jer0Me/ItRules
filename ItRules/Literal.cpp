#include "Literal.h"

Literal::Literal(std::string text) : text(text) {}

std::string Literal::get_text()
{
	return this->text;
}

std::string Literal::to_string()
{
	return this->text;
}


