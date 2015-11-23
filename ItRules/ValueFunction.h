#pragma once
#include "Function.h"

class ValueFunction : public Function
{
public:
	bool match(Trigger* trigger, std::string parameter) override;
};
