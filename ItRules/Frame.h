#pragma once
#include "AbstractFrame.h"
#include "SlotMap.h"
#include "TypeSet.h"
#include "FormatterStore.h"

class Frame : public AbstractFrame
{
	TypeSet types;
	SlotMap slots;

public:

	Frame* add_types(std::initializer_list<std::string> types);

	Frame* add_frame(std::string slot, ItRules::type value);

	Frame* add_frame(std::string slot, std::initializer_list<AbstractFrame*> frames);

	Frame* add_frame(std::string slot, std::initializer_list<ItRules::type> values);

	Frame* add_primitive_frame(std::string slot, ItRules::type value);

	Frame* add_type(std::string type);

	void add_slot(std::string slot, std::list<AbstractFrame*> slot_list);

	bool is(std::string type) override;

	bool is_primitive() override;

	std::list<AbstractFrame*> get_frames(std::string slot) override;
	
	void set_types(TypeSet& types);

	void set_slots(SlotMap& slots);
};
