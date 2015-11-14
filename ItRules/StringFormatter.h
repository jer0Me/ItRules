#pragma once
#include <map>
#include "Formatter.h"

class StringFormatter
{
	std::map<std::string, Formatter*> map;

	Formatter* upper_case();
	Formatter* capitalize();

public:

	StringFormatter();
	std::map<std::string, Formatter*>& get();
	
};
