#pragma once
#include "AbstractFrame.h"
#include "ItRules.h"

class PrimitiveFrame : public AbstractFrame
{
	ItRules::type value;

public:

	PrimitiveFrame(ItRules::type value);

	void set_value(ItRules::type value);

	ItRules::type get_value();

	bool is_primitive() override;	

	std::list<AbstractFrame*> get_frames(std::string slot) override;

};
