#pragma once
#include <string>
#include "Trigger.h"
#include "DateFormatter.h"

class Function
{
public:
	
	virtual bool match(Trigger* trigger, std::string parameter);
	virtual ~Function();
	bool is_string(ItRules::type value) const;
	bool is_date(ItRules::type value) const;
	bool is_number(ItRules::type value);
	bool is_int(ItRules::type value) const;
	bool is_double(ItRules::type value) const;
	std::string get_string(ItRules::type value) const;
	boost::gregorian::date get_date(ItRules::type value) const;
	int get_int(ItRules::type value) const;
	double get_double(ItRules::type value) const;

};
