#include "PluralFormatter.h"
#include <boost/variant/get.hpp>
#include "EnglishPluralInflector.h"


PluralFormatter::PluralFormatter()
{
	inflectors.insert(std::pair<std::string, PluralInflector*>("en", new EnglishPluralInflector()));
}

ItRules::type PluralFormatter::format(ItRules::type value)
{
	if (!is_string(value)) return value;
	return get_inflector()->plural(boost::get<std::string>(value));
}

PluralInflector* PluralFormatter::get_inflector()
{
	return get_inflector("en");
}

PluralInflector* PluralFormatter::get_inflector(std::string locale)
{
	return inflectors.at(locale);
}
