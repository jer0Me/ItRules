#include "Frame.h"

bool Frame::is(std::string type)
{
	return this->types.contain(type);
}

bool Frame::is_primitive()
{
	return false;
}

std::list<AbstractFrame*> Frame::get_frames(std::string slot)
{
	std::list<AbstractFrame*> emptyList; 
	return slots.contain(slot) ? slots.at(slot) : emptyList;
}

void Frame::set_types(TypeSet& types)
{
	this->types = types;
}


void Frame::set_slots(SlotMap& slots)
{
	this->slots = slots;
}

