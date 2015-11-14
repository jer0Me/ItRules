#include "FormatterStore.h"
#include "StringFormatter.h"
#include "DateFormatter.h"
#include <boost/algorithm/string.hpp>
#include <boost/foreach.hpp>
#include <boost/variant/get.hpp>

FormatterStore::FormatterStore()
{
	auto string_formatter = StringFormatter();
	auto date_formatter = DateFormatter();
	this->map.insert(string_formatter.get().begin(), string_formatter.get().end());
	this->map.insert(date_formatter.get().begin(), date_formatter.get().end());
}

FormatterStore::~FormatterStore()
{
	typedef std::map<std::string, Formatter*> formatter_map;
	BOOST_FOREACH(formatter_map::value_type &value, this->map)
	{
		delete value.second;
	}
}


Formatter* FormatterStore::get(std::string name)
{
	return name.empty() ? formatter(name) : null_formatter();
}

Formatter* FormatterStore::formatter(std::string name)
{
	boost::trim(name);
	boost::to_lower(name);
	return exists(name) ? this->map.at(name) : unknown_formatter();
}

bool FormatterStore::exists(std::string name) const
{
	return this->map.count(name) > 0;
}

Formatter* FormatterStore::unknown_formatter() const
{
	class unknown_formatter: public Formatter
	{
		std::string format(ItRules::type value) override {
			return boost::get<std::string>(value);
		}
	};
	return new unknown_formatter();
}

Formatter* FormatterStore::null_formatter() const
{
	class null_formatter: public Formatter
	{
		std::string format(ItRules::type value) override {
			return boost::get<std::string>(value);
		}
	};
	return new null_formatter();
}
