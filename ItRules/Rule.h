#pragma once
#include "Condition.h"
#include "Mark.h"
#include "Literal.h"
#include <boost/variant/variant.hpp>
#include "Expression.h"

struct Rule
{
	typedef boost::variant<Mark, Literal> tokenVariant;

	std::vector<Condition> conditions;	
	std::vector<tokenVariant> tokens;
	
};
