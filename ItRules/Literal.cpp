#include "Literal.h"
#include <boost/algorithm/string.hpp>

Literal::Literal(std::string text) : text(text) {}

std::string Literal::get_text()
{
	return this->text;
}

std::string Literal::to_string()
{
	return this->text;
}

bool Literal::is_type(std::string type)
{
	boost::to_lower(type);
	return type.compare("literal") == 0;
}

