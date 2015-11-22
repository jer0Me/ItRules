#pragma once
#include <map>
#include "Formatter.h"
#include "StringFormatter.h"
#include "DateFormatter.h"
#include "NumberFormatter.h"

class FormatterStore
{
	std::map<std::string, Formatter*> map;
	StringFormatter* string_formatter;
	DateFormatter* date_formatter;
	NumberFormatter* number_formatter;

	Formatter* null_formatter();
	Formatter* unknown_formatter();
	Formatter* formatter(std::string name);
	Formatter* create_formatter(std::string name);

public:

	FormatterStore();
	~FormatterStore();
	Formatter* get(std::string name);
	bool exists(std::string name);

};
