#pragma once
#include "Function.h"

class TypeFunction : public Function
{
public:

	bool match(Trigger* trigger, std::string parameter) override;
	
};
