#pragma once
#include "Rule.h"
#include <vector>

struct RuleList
{
	std::vector<Rule> rules;
	const int size();
};
