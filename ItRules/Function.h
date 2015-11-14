#pragma once
#include <string>
#include "Trigger.h"

class Function
{
public:
	
	virtual bool match(Trigger* trigger, std::string parameter);
	virtual ~Function();
	
};
