#include "NumberSpellingFormatter.h"
#include "EnglishSpelling.h"
#include <boost/variant/get.hpp>

NumberSpellingFormatter::NumberSpellingFormatter()
{
	readers.insert(std::pair<std::string, WordSpelling*>("en", new EnglishSpelling()));
}

ItRules::type NumberSpellingFormatter::format(ItRules::type value)
{
	return is_number(value) ? get_reader()->spell(boost::get<int>(value)) : value;
}

WordSpelling* NumberSpellingFormatter::get_reader()
{
	return get_reader("en");
}

WordSpelling* NumberSpellingFormatter::get_reader(std::string locale)
{
	return readers.at(locale);
}


