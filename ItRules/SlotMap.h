#pragma once
#include <map>
#include "AbstractFrame.h"

class SlotMap
{
	std::map<std::string, std::list<AbstractFrame* >> slots;

public:

	std::list<AbstractFrame*>& at(std::string key);
	bool contain(std::string key) const;
	void insert(std::string key, std::list<AbstractFrame*> frames);
};
