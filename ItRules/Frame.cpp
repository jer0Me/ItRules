#include "Frame.h"
#include <boost/foreach.hpp>
#include "PrimitiveFrame.h"


Frame::Frame()
{
	this->types = TypeSet();
	this->slots = SlotMap();
}


Frame * Frame::add_types(std::initializer_list<std::string> types)
{
	BOOST_FOREACH(std::string type, types)
	{
		this->add_type(type);
	}
	return this;
}

Frame* Frame::add_frame(std::string slot, ItRules::type value)
{
	add_primitive_frame(slot, value);
	return this;
}

Frame * Frame::add_frame(std::string slot, std::initializer_list<AbstractFrame*> frames)
{
	BOOST_FOREACH(AbstractFrame* abstract_frame, frames)
	{
		this->slots.at(slot).push_back(abstract_frame);
	}
	return this;
}

Frame* Frame::add_frame(std::string slot, std::initializer_list<ItRules::type> values)
{
	BOOST_FOREACH(ItRules::type value, values)
	{
		add_primitive_frame(slot, value);
	}
	return this;
}

Frame* Frame::add_primitive_frame(std::string slot, ItRules::type value)
{
	this->slots.at(slot).push_back(new PrimitiveFrame(value));
	return this;
}

Frame* Frame::add_type(std::string type)
{
	this->types.insert(type);
	return this;
}

void Frame::add_slot(std::string slot, std::list<AbstractFrame*> slot_list)
{
	this->slots.insert(slot, slot_list);
}

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
	return this->slots.contain(slot) ? this->slots.at(slot) : emptyList;
}

void Frame::set_types(TypeSet& types)
{
	this->types = types;
}


void Frame::set_slots(SlotMap& slots)
{
	this->slots = slots;
}

