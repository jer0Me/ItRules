#include <algorithm>
#include <boost/algorithm/string.hpp>
#include "Mark.h"
#include "Literal.h"

Mark::Mark(std::string name) : name(name){}

Mark::Mark(std::string name, std::vector<std::string> options, std::string separator) : name(name), options(options), separator(separator){}

Mark::Mark(std::string name, std::vector<std::string> options) : name(name), options(options){}

std::string Mark::get_name()
{
	return this->name;
}

std::string Mark::full_name()
{
	return this->name + options_text();
}

std::string Mark::options_text()
{
	std::string result = "";

	std::for_each(options.begin(), options.end(), [&result](std::string& option){
		result += option;
	});

	return result;
}

std::string Mark::get_separator()
{
	return this->separator;
}

bool Mark::is_multiple()
{
	return this->separator != "";
}

std::vector<std::string> Mark::get_options()
{

	return this->options;
}

std::string Mark::get_indentation()
{
	return indent_of(this->previous);
}

std::string Mark::indent_of(Token* token)
{
	return (token == nullptr) ? "" : text_of(token).empty() ? indent_of(token->get_previous()) : text_of(token);
}

std::string Mark::text_of(Token* token)
{
	return is_literal(token) ? dynamic_cast<Literal*> (token)->get_text() : "";
}

bool Mark::is_literal(Token* token)
{
	auto* literal = dynamic_cast<Literal*> (token);
	return literal != nullptr;
}

std::string Mark::to_string()
{
	return this->name;
}