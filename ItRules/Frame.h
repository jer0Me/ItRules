#pragma once
#include "AbstractFrame.h"
#include "SlotMap.h"
#include "TypeSet.h"

class Frame : public AbstractFrame
{
	TypeSet types;
	SlotMap slots;

public:

	bool is(std::string type) override;

	bool is_primitive() override;

	std::list<AbstractFrame*> get_frames(std::string slot) override;
	
	void set_types(TypeSet& types);

	void set_slots(SlotMap& slots);
};
