#pragma once
#include <string>
#include "RuleList.h"

class LexicalAnalyzer
{
public:
	LexicalAnalyzer();
	std::list<Rule*>analyze(std::string rules) const;
};
