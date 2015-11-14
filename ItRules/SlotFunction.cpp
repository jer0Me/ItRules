#include "SlotFunction.h"
#include <boost/algorithm/string.hpp>

bool SlotFunction::match(Trigger* trigger, std::string parameter)
{
	boost::to_lower(parameter);
	if(trigger->get_frame()->is_primitive())
	{
		return parameter.compare("value") == 0;
	}
	return trigger->get_frame()->get_frames(parameter).size() > 0;
}
