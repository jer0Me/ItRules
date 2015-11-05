#pragma once
#include "Condition.h"
#include "Mark.h"
#include "Literal.h"
#include "Expression.h"
#include <boost/variant/variant.hpp>

struct Rule
{
	typedef boost::variant<Mark, Literal, Expression> tokenVariant;

	std::vector<Condition> conditions;	
	std::vector<tokenVariant> tokens;
	
};
