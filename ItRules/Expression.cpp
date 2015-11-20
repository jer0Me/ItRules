#include "Expression.h"
#include <boost/foreach.hpp>

Expression::Expression(std::list<Token*> tokens) : tokens(tokens){}

Expression::Expression(std::initializer_list<Token*> tokens)
{
	BOOST_FOREACH(Token* token, tokens)
	{
		this->tokens.push_back(token);
	}
}


void Expression::set_other_expression(Expression* other)
{
	this->other = other;
}

std::list<Token*> Expression::get_tokens()
{
	return this->tokens;
}

Expression* Expression::get_other()
{
	return this->other;
}
