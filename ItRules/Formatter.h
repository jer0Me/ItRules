#pragma once
#include "ItRules.h"

class Formatter
{

public:
	virtual ItRules::type format(ItRules::type value);
	virtual ~Formatter();
	bool is_string(ItRules::type value);
	bool is_date(ItRules::type value);
	bool is_number(ItRules::type value);
	bool is_int(ItRules::type value);
	bool is_double(ItRules::type value);
};
