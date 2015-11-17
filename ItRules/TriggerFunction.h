#pragma once
#include "Function.h"

class TriggerFunction : public Function
{
	bool matchMark(std::string mark, std::string parameter);
	bool matchOptions(std::vector<std::string> options, std::string parameter);
	bool matchOption(std::string option, std::string parameter);

public:
	bool match(Trigger* trigger, std::string parameter) override;
	
	
};
