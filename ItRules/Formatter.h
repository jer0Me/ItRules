#pragma once
#include <boost/variant/variant.hpp>
#include "ItRules.h"

class Formatter
{
public:
	virtual std::string format(ItRules::type value);
	virtual ~Formatter();

};
