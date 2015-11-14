#include "SlotMap.h"
#include <boost/algorithm/string.hpp>

std::list<AbstractFrame*> SlotMap::at(std::string key)
{
	return this->slots.at(key);
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

