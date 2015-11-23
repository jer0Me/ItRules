#include "ValueFunction.h"
#include <boost/algorithm/string.hpp>

bool ValueFunction::match(Trigger* trigger, std::string parameter)
{
	if(trigger->get_frame()->is_primitive())
	{
		boost::to_lower(parameter);
		return parameter.compare(boost::to_lower_copy(trigger->get_frame()->to_string())) == 0;
	}
	return false;
}
