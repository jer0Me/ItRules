#include "SlotMap.h"
#include <boost/algorithm/string.hpp>


SlotMap::~SlotMap()
{
	for_each(this->slots.begin(), this->slots.end(), [this](std::pair<std::string,std::list<AbstractFrame*>> slot)
	{
		delete_abstract_frame_list(slot.second);
	});
}

void SlotMap::delete_abstract_frame_list(std::list<AbstractFrame*> list)
{
	for_each(list.begin(), list.end(), [](AbstractFrame* abstract_frame)
	{
		delete abstract_frame;
	});
}

std::list<AbstractFrame*>& SlotMap::at(std::string key)
{
	boost::to_lower(key);
	try {
		return this->slots.at(key);     
	}
	catch (const std::out_of_range oor) {
		std::list<AbstractFrame*> abstract_frames;
		slots.insert(std::pair<std::string, std::list<AbstractFrame*>>(key, abstract_frames));
		return this->slots.at(key);
	}
}

void SlotMap::insert(std::string key, std::list<AbstractFrame*> frames)
{
	boost::to_lower(key);
	this->slots.insert(std::pair<std::string, std::list<AbstractFrame*>>(key, frames));
}


bool SlotMap::contain(std::string key) const
{
	boost::to_lower(key);
	return this->slots.count(key) > 0;
}

