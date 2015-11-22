#pragma once
#include <map>
#include "Formatter.h"

class DateFormatter
{
	std::map<std::string, Formatter*> map;
	Formatter* year();
	Formatter* short_date();

public:

	DateFormatter();
	~DateFormatter();
	std::map<std::string, Formatter*>& get();
	
};
