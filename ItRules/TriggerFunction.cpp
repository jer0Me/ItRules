#include "TriggerFunction.h"
#include <boost/algorithm/string.hpp>
#include <boost/foreach.hpp>

bool TriggerFunction::match(Trigger* trigger, std::string parameter)
{
	return matchMark(trigger->get_mark()->get_name(), parameter) ||
		matchOptions(trigger->get_mark()->get_options(), parameter);
}

bool TriggerFunction::matchMark(std::string mark, std::string parameter)
{
	return boost::to_lower_copy(mark).compare(boost::to_lower_copy(parameter)) == 0;
}

bool TriggerFunction::matchOptions(std::vector<std::string> options, std::string parameter)
{
	BOOST_FOREACH(std::string option, options)
	{
		if (matchOption(option, parameter)) return true;
	}
	return false;
}

bool TriggerFunction::matchOption(std::string option, std::string parameter)
{
	return boost::to_lower_copy(option).compare(boost::to_lower_copy(parameter)) == 0;
}



