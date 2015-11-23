﻿#include "FormatterStore.h"
#include "StringFormatter.h"
#include "DateFormatter.h"
#include <boost/algorithm/string.hpp>
#include <boost/variant/get.hpp>
#include "PluralFormatter.h"

FormatterStore::FormatterStore()
{
	this->string_formatter = new StringFormatter();
	this->date_formatter = new DateFormatter();
	this->number_formatter = new NumberFormatter();
	this->map.insert(string_formatter->get().begin(), string_formatter->get().end());
	this->map.insert(date_formatter->get().begin(), date_formatter->get().end());
	this->map.insert(number_formatter->get().begin(), number_formatter->get().end());
	this->map.insert(std::pair<std::string, Formatter*>("plural", new PluralFormatter()));
}

FormatterStore::~FormatterStore()
{
	delete string_formatter;
	delete date_formatter;
	delete number_formatter;
	delete map.at("plural");
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

void FormatterStore::add(std::string name, Formatter* formatter)
{
	boost::to_lower(name);
	map.insert(std::pair<std::string, Formatter*>(name, formatter));
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
