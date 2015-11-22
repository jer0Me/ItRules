#pragma once
#include <string>
#include <map>
#include "WordSpelling.h"
#include "Formatter.h"

class NumberSpellingFormatter : public Formatter
{
	std::map<std::string, WordSpelling*> readers;

	WordSpelling* get_reader();
	WordSpelling* get_reader(std::string locale);
public:
	NumberSpellingFormatter();
	ItRules::type format(ItRules::type value);

	
};
