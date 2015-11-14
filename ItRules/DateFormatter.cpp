#include "DateFormatter.h"
#include <boost/variant/get.hpp>
#include <sstream>


DateFormatter::DateFormatter()
{
	map.insert(std::pair<std::string, Formatter*>("year", year()));
}

Formatter* DateFormatter::year()
{
	class year: public Formatter
	{
		std::string format(ItRules::type value) override {
			std::stringstream ss;
			auto date = boost::get<boost::gregorian::date>(value);
			ss << date.year_month_day().year;
			return ss.str();
		}
	};
	return new year();
}

std::map<std::string, Formatter*>& DateFormatter::get()
{
	return this->map;
}
