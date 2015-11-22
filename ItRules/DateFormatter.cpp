#include "DateFormatter.h"
#include <boost/variant/get.hpp>
#include <sstream>
#include <boost/date_time/gregorian/gregorian.hpp>


DateFormatter::DateFormatter()
{
	map.insert(std::pair<std::string, Formatter*>("year", year()));
	map.insert(std::pair<std::string, Formatter*>("shortdate", short_date()));
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
			return date.year_month_day().year;
		}
	};
	return new year();
}

Formatter* DateFormatter::short_date()
{
	class short_date : public Formatter
	{
		ItRules::type format(ItRules::type value) override {
			std::string result = "";
			if (is_date(value))
			{
				boost::gregorian::date_facet* facet(new boost::gregorian::date_facet("%d/%m/%Y"));
				std::stringstream stream;
				stream.imbue(std::locale(std::cout.getloc(), facet));
				stream << boost::get<boost::gregorian::date>(value);
				result = stream.str();
			}
			return result;
			
		}
	};
	return new short_date();
}



std::map<std::string, Formatter*>& DateFormatter::get()
{
	return this->map;
}
