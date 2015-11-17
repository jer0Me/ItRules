#include "FormatterStore.h"
#include "StringFormatter.h"
#include "DateFormatter.h"
#include <boost/algorithm/string.hpp>
#include <boost/variant/get.hpp>

FormatterStore::FormatterStore()
{
	this->string_formatter = new StringFormatter();
	this->date_formatter = new DateFormatter();
	this->map.insert(string_formatter->get().begin(), string_formatter->get().end());
	this->map.insert(date_formatter->get().begin(), date_formatter->get().end());
}

FormatterStore::~FormatterStore()
{
	delete string_formatter;
	delete date_formatter;
}


Formatter* FormatterStore::get(std::string name)
{
	return name.empty() == 0 ? formatter(name) : null_formatter();
}

Formatter* FormatterStore::formatter(std::string name)
{
	return exists(name) ? create_formatter(name) : unknown_formatter();
}

Formatter* FormatterStore::create_formatter(std::string name)
{
	boost::to_lower(name);
	auto* formatter = this->map.at(name);
	return formatter;
}

bool FormatterStore::exists(std::string name)
{
	boost::to_lower(name);
	return map.find(name) != map.end();
}

Formatter* FormatterStore::unknown_formatter()
{
	class unknown_formatter: public Formatter
	{
		ItRules::type format(ItRules::type value) override {
			return value;
		}
	};
	return new unknown_formatter();
}

Formatter* FormatterStore::null_formatter()
{
	class null_formatter: public Formatter
	{
		ItRules::type format(ItRules::type value) override {
			return value;
		}
	};
	return new null_formatter();
}
