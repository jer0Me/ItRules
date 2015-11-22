#include "Formatter.h"
#include <boost/variant/get.hpp>

ItRules::type Formatter::format(ItRules::type value)
{
	return "";
}

Formatter::~Formatter(){}

bool Formatter::is_string(ItRules::type value)
{
	try
	{
		boost::get<std::string>(value);
		return true;
	}
	catch (std::exception exception)
	{
		return false;
	}
}

bool Formatter::is_date(ItRules::type value)
{
	try
	{
		boost::get<boost::gregorian::date>(value);
		return true;
	}
	catch (std::exception exception)
	{
		return false;
	}
}

bool Formatter::is_number(ItRules::type value)
{
	return  is_double(value) || is_int(value) ;
}


bool Formatter::is_int(ItRules::type value)
{
	try
	{
		boost::get<int>(value);
		return true;
	}
	catch(std::exception exception)
	{
		return false;
	}
}


bool Formatter::is_double(ItRules::type value)
{
	try
	{
		boost::get<double>(value);
		return true;
	}
	catch (std::exception exception)
	{
		return false;
	}
}

