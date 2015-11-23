#pragma once
#include "Formatter.h"
#include "PluralInflector.h"

class PluralFormatter : public Formatter
{
	std::map<std::string, PluralInflector*> inflectors;
	std::locale locale;

	PluralInflector* get_inflector();
	PluralInflector* get_inflector(std::string locale);
public:
	PluralFormatter();
	ItRules::type format(ItRules::type value) override;
};
