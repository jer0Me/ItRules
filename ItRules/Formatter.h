#pragma once
#include <boost/variant/variant.hpp>
#include "ItRules.h"

class Formatter
{
public:
	virtual ItRules::type format(ItRules::type value);
	virtual ~Formatter();

};
