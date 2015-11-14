#pragma once
#include "Trigger.h"
#include "Function.h"

class SlotFunction : public Function
{
public:

	bool match(Trigger* trigger, std::string parameter) override;
	
};
