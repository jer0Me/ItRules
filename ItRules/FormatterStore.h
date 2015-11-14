#pragma once
#include <map>
#include "Formatter.h"

class FormatterStore
{

	std::map<std::string, Formatter*> map;

public:

	FormatterStore();
	~FormatterStore();
	Formatter* get(std::string name);
	Formatter* formatter(std::string name);
	Formatter* null_formatter() const;
	Formatter* unknown_formatter() const;
	bool exists(std::string name) const;
};
