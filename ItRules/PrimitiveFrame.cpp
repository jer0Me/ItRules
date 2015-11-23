#include "PrimitiveFrame.h"
#include <boost/variant/get.hpp>
#include <boost/date_time/gregorian/formatters.hpp>

PrimitiveFrame::PrimitiveFrame(ItRules::type value) : value(value){}


void PrimitiveFrame::set_value(ItRules::type value)
{
	this->value = value;
}

std::string PrimitiveFrame::to_string()
{
	if(is_string(value)) return boost::get<std::string>(value);
	if(is_date(value)) return to_simple_string(boost::get<boost::gregorian::date>(value));
	if (is_int(value)) return std::to_string(boost::get<int>(value));
	if (is_double(value)) return std::to_string(boost::get<double>(value));
	return "";
}

std::list<AbstractFrame*> PrimitiveFrame::get_frames(std::string slot)
{
	std::list<AbstractFrame*> empty_list;
	return empty_list;
}
bool PrimitiveFrame::is_primitive()
{
	return true;
}

ItRules::type PrimitiveFrame::get_value()
{
	return this->value;
}

bool PrimitiveFrame::is_string(ItRules::type value)
{
	try
	{
		boost::get<std::string>(value);
		return true;
	}
	catch(std::exception exception)
	{
		return false;
	}
}

bool PrimitiveFrame::is_date(ItRules::type value)
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

bool PrimitiveFrame::is_int(ItRules::type value)
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

bool PrimitiveFrame::is_double(ItRules::type value)
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