#include "Buffer.h"
#include "boost/date_time/gregorian/gregorian.hpp"
#include <boost/variant/get.hpp>

Buffer::Buffer(std::string indentation)
{
	this->indentation = indentation;
}

void Buffer::write(ItRules::type text)
{
	if (is_string(text)) this->content += indent(boost::get<std::string>(text));
	if (is_date(text)) this->content += indent(date_to_string(text));
	if (is_int(text)) this->content += indent(std::to_string(boost::get<int>(text)));
}

std::string Buffer::indent(std::string text)
{
	text += "~";
	std::string result = "";
	std::string character;
	std::string nextCharacter;
	std::string indentation;
	for (auto it = text.begin(); it != text.end() - 1; ++it)
	{
		character = *it;
		nextCharacter = *it + 1;
		indentation = ((character.compare("\n") == 0) && (nextCharacter.compare("\n") != 0)) ? this->indentation : "";
		result += character + indentation;
	}
	return result;
}

void Buffer::used()
{
	this->replaced = true;
}

bool Buffer::is_used()
{
	return this->replaced;
}

std::string Buffer::get_content()
{
	return this->content;
}

void Buffer::write(Buffer* buffer)
{
	write(buffer->get_content());
}

std::string Buffer::date_to_string(ItRules::type text)
{
	return boost::gregorian::to_simple_string(boost::get<boost::gregorian::date>(text));
}


bool Buffer::is_string(ItRules::type text)
{
	try
	{
		boost::get<std::string>(text);
		return true;
	}
	catch (std::exception exception)
	{
		return false;
	}
}

bool Buffer::is_date(ItRules::type text)
{
	try
	{
		boost::get<boost::gregorian::date>(text);
		return true;
	}
	catch (std::exception exception)
	{
		return false;
	}
}

bool Buffer::is_int(ItRules::type text)
{
	try
	{
		boost::get<int>(text);
		return true;
	}
	catch (std::exception exception)
	{
		return false;
	}
}
