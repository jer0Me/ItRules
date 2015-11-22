#pragma once
#include <map>
#include "Formatter.h"
#include <boost/regex/v4/regex.hpp>

class StringFormatter
{
	std::map<std::string, Formatter*> map;

	Formatter* upper_case();
	Formatter* lower_case();
	Formatter* capitalize();
	Formatter* first_upper_case();
	Formatter* first_lower_case();
	Formatter* camel_case();
	Formatter* lower_camel_case();
	Formatter* length();

	std::vector<std::string> tokenizing_string(ItRules::type value);

public:

	StringFormatter();
	~StringFormatter();
	std::map<std::string, Formatter*>& get();
	Formatter* get_formatter(std::string name);
	
};
