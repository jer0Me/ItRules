#include "TypeFunction.h"
#include <boost/algorithm/string.hpp>

bool TypeFunction::match(Trigger* trigger, std::string parameter)
{
	boost::to_lower(parameter);
	return trigger->get_frame()->is(parameter);
}
