#pragma once
#include <string>
#include "RuleList.h"

class LexicalAnalyzer
{
public:
	LexicalAnalyzer();
	RuleList analyze(std::string rules) const;
};
