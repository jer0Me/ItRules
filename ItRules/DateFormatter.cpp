#include "DateFormatter.h"
#include <boost/variant/get.hpp>
#include <sstream>
#include <boost/foreach.hpp>


DateFormatter::DateFormatter()
{
	map.insert(std::pair<std::string, Formatter*>("year", year()));
}

DateFormatter::~DateFormatter()
{
	for_each(this->map.begin(), this->map.end(), [](std::pair<std::string, Formatter*> formatter)
	{
		delete formatter.second;
	});
}

Formatter* DateFormatter::year()
{
	class year: public Formatter
	{
		ItRules::type format(ItRules::type value) override {
			auto date = boost::get<boost::gregorian::date>(value);
			return std::to_string(date.year_month_day().year);
		}
	};
	return new year();
}

std::map<std::string, Formatter*>& DateFormatter::get()
{
	return this->map;
}
