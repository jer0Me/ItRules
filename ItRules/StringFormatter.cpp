#include "StringFormatter.h"
#include <boost/variant/get.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/foreach.hpp>


StringFormatter::StringFormatter()
{
	map.insert(std::pair<std::string, Formatter*>("uppercase", upper_case()));
	map.insert(std::pair<std::string, Formatter*>("lowercase", lower_case()));
	map.insert(std::pair<std::string, Formatter*>("firstuppercase", first_upper_case()));
	map.insert(std::pair<std::string, Formatter*>("firstlowercase", first_lower_case()));
	map.insert(std::pair<std::string, Formatter*>("camelcase", camel_case()));
	map.insert(std::pair<std::string, Formatter*>("lowercamelcase", lower_camel_case()));
	map.insert(std::pair<std::string, Formatter*>("capitalize", capitalize()));
	map.insert(std::pair<std::string, Formatter*>("length", length()));
}

StringFormatter::~StringFormatter()
{
	for_each(this->map.begin(), this->map.end(), [](std::pair<std::string, Formatter*> formatter)
	{
		delete formatter.second;
	});
}


Formatter* StringFormatter::upper_case()
{
	class uppercase: public Formatter
	{
		ItRules::type format(ItRules::type value) override {
			if (!is_string(value)) return value;
			return boost::to_upper_copy(boost::get<std::string>(value));;
		}
	};
	return new uppercase();
}

Formatter* StringFormatter::lower_case()
{
	class lowercase : public Formatter
	{
		ItRules::type format(ItRules::type value) override {
			if (!is_string(value)) return value;
			return boost::to_lower_copy(boost::get<std::string>(value));;
		}
	};
	return new lowercase();
}

Formatter* StringFormatter::first_upper_case()
{
	class first_upper_case : public Formatter
	{
		ItRules::type format(ItRules::type value) override {
			if (!is_string(value)) return value;
			auto text = boost::get<std::string>(value);
			transform(text.begin(), text.begin() + 1, text.begin(), ::toupper);
			return text;
		}
	};
	return new first_upper_case();
}

Formatter* StringFormatter::first_lower_case()
{
	class first_lower_case : public Formatter
	{
		ItRules::type format(ItRules::type value) override {
			if (!is_string(value)) return value;
			auto text = boost::get<std::string>(value);
			transform(text.begin(), text.begin() + 1, text.begin(), ::tolower);
			return text;
		}
	};
	return new first_lower_case();
}

Formatter* StringFormatter::camel_case()
{
	class camel_case : public Formatter
	{
		StringFormatter* string_formatter;
	public:
		camel_case(StringFormatter* string_formatter) : string_formatter(string_formatter)  {}

		ItRules::type format(ItRules::type value) override {
			if (!is_string(value)) return value;
			std::string result = "";
			BOOST_FOREACH(std::string token, string_formatter->tokenizing_string(value))
			{
				std::string formatted_token = boost::get<std::string>(string_formatter->capitalize()->format(token));
				result += formatted_token;
			}
			return result;
		}
	};
	return new camel_case(this);
}

Formatter* StringFormatter::lower_camel_case()
{
	class lower_camel_case : public Formatter
	{
		StringFormatter* string_formatter;
	public:
		lower_camel_case(StringFormatter* string_formatter) : string_formatter(string_formatter){}

		ItRules::type format(ItRules::type value) override {
			if (!is_string(value)) return value;
			auto result = string_formatter->get_formatter("camelcase")->format(value);
			return string_formatter->get_formatter("firstlowercase")->format(result);
		}
	};
	return new lower_camel_case(this);
}

std::vector<std::string> StringFormatter::tokenizing_string(ItRules::type value)
{
	auto text = boost::get<std::string>(value);
	boost::regex splitter("\\s");
	boost::sregex_token_iterator iterator(text.begin(), text.end(), splitter, -1);
	boost::sregex_token_iterator end;
	std::vector<std::string> result;

	while(iterator != end)
	{
		result.push_back(*iterator++);
	}
	return result;
}

Formatter* StringFormatter::capitalize()
{
	class capitalize : public Formatter
	{
		ItRules::type format(ItRules::type value) override {
			if (!is_string(value)) return value;
			auto text = boost::get<std::string>(value);
			boost::to_lower(text);
			transform(text.begin(), text.begin()+1, text.begin(), ::toupper);
			return text;
		}
	};
	return new capitalize();
}


Formatter* StringFormatter::length()
{
	class length : public Formatter
	{
		ItRules::type format(ItRules::type value) override {
			if (!is_string(value)) return value;
			return std::to_string(boost::get<std::string>(value).length());
		}
	};
	return new length();
}

std::map<std::string, Formatter*>& StringFormatter::get()
{
	return this->map;
};

Formatter* StringFormatter::get_formatter(std::string name)
{
	auto* formatter = this->map.at(name);
	return formatter;
}
