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
	typedef std::map<std::string, Formatter*> date_formatter_map;
	BOOST_FOREACH(date_formatter_map::value_type &value, this->map)
	{
		delete value.second;
	}
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
