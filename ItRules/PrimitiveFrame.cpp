#include "PrimitiveFrame.h"

PrimitiveFrame::PrimitiveFrame(ItRules::type value) : value(value){}


void PrimitiveFrame::set_value(ItRules::type value)
{
	this->value = value;
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

