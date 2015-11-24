#include "Function.h"
#include <boost/variant/get.hpp>

bool Function::match(Trigger* trigger, std::string parameter)
{
	return false;
}

Function::~Function(){}

bool Function::is_string(ItRules::type value) const
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

bool Function::is_date(ItRules::type value) const
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

bool Function::is_number(ItRules::type value)
{
	return  is_double(value) || is_int(value);
}


bool Function::is_int(ItRules::type value) const
{
	try
	{
		boost::get<int>(value);
		return true;
	}
	catch (std::exception exception)
	{
		return false;
	}
}

bool Function::is_double(ItRules::type value) const
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

std::string Function::get_string(ItRules::type value) const
{
	return boost::get<std::string>(value);
}

boost::gregorian::date Function::get_date(ItRules::type value) const
{
	return boost::get<boost::gregorian::date>(value);
}

int Function::get_int(ItRules::type value) const
{
	return boost::get<int>(value);
}

double Function::get_double(ItRules::type value) const
{
	return boost::get<double>(value);
}