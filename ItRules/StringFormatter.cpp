﻿#include "StringFormatter.h"
#include <boost/variant/get.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/foreach.hpp>


StringFormatter::StringFormatter()
{
	map.insert(std::pair<std::string, Formatter*>("uppercase", upper_case()));
	map.insert(std::pair<std::string, Formatter*>("capitalize", capitalize()));
}

StringFormatter::~StringFormatter()
{
	typedef std::map<std::string, Formatter*> string_formatter_map;
	BOOST_FOREACH(string_formatter_map::value_type &value, this->map)
	{
		delete value.second;
	}
}


Formatter* StringFormatter::upper_case()
{
	class uppercase: public Formatter
	{
		ItRules::type format(ItRules::type value) override {
			auto text = boost::get<std::string>(value);
			boost::to_upper(text);
			return text;
		}
	};
	return new uppercase();
}

Formatter* StringFormatter::capitalize()
{
	class capitalize : public Formatter
	{
		ItRules::type format(ItRules::type value) override {
			auto text = boost::get<std::string>(value);
			transform(text.begin(), text.begin()+1, text.begin(), ::toupper);
			return text;
		}
	};
	return new capitalize();
}

std::map<std::string, Formatter*>& StringFormatter::get()
{
	return this->map;
};
