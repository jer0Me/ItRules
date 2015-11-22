#pragma once
#include "Formatter.h"

class NumberFormatter
{
	std::map<std::string, Formatter*> map;
	Formatter* separators();
	Formatter* two_decimals();

public:
	
	NumberFormatter();
	~NumberFormatter();
	std::map<std::string, Formatter*>& get();
};
