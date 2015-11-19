#pragma once
#include <map>
#include "AbstractFrame.h"

class SlotMap
{
	std::map<std::string, std::list<AbstractFrame* >> slots;
	void delete_abstract_frame_list(std::list<AbstractFrame*> list);

public:
	~SlotMap();
	std::list<AbstractFrame*>& at(std::string key);
	bool contain(std::string key) const;
	void insert(std::string key, std::list<AbstractFrame*> frames);
};
