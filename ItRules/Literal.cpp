#include "Literal.h"

Literal::Literal(std::string text) : text(text) {}

std::string Literal::getText()
{
	return text;
}

