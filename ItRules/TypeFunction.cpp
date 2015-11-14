#include "TypeFunction.h"

bool TypeFunction::match(Trigger* trigger, std::string parameter)
{
	return trigger->get_frame()->is(parameter);
}
