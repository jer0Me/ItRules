#include "NumberFormatter.h"
#include "NumberSpellingFormatter.h"
#include <sstream>
#include <iomanip>
#include <boost/variant/get.hpp>
#include <boost/locale.hpp>


NumberFormatter::NumberFormatter()
{
	map.insert(std::pair<std::string, Formatter*>("words", new NumberSpellingFormatter()));
	map.insert(std::pair<std::string, Formatter*>("separators", separators()));
	map.insert(std::pair<std::string, Formatter*>("twodecimals", two_decimals()));
}

NumberFormatter::~NumberFormatter()
{
	for_each(this->map.begin(), this->map.end(), [](std::pair<std::string, Formatter*> formatter)
	{
		delete formatter.second;
	});
}

Formatter* NumberFormatter::separators()
{
	class separators : public Formatter
	{
		NumberFormatter* number_formatter;
	public:
		separators(NumberFormatter* number_formatter) : number_formatter(number_formatter){}

		ItRules::type format(ItRules::type value) override {
			if (!is_number(value)) return value;
			std::stringstream ss;
			ss.imbue(std::locale("en-US"));
			if (is_int(value))
			{
				auto result = boost::get<int>(value);
				ss << std::fixed << result;
			}
			else
			{
				auto result = boost::get<double>(value);
				ss << std::fixed << std::setprecision(1) << result;
			}
			return ss.str();
		}
	};
	return new separators(this);
}

std::map<std::string, Formatter*>& NumberFormatter::get()
{
	return map;
}

Formatter* NumberFormatter::two_decimals()
{
	class two_decimals : public Formatter
	{
	public:
		ItRules::type format(ItRules::type value) override {
			if (!is_double(value)) return value;
			std::stringstream ss;
			ss << std::fixed << std::setprecision(2) << boost::get<double>(value);
			return ss.str();
		}
	};
	return new two_decimals();
}