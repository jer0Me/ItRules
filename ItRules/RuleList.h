#pragma once
#include "Rule.h"
#include <list>

class RuleList
{
	std::list<Rule> rules;

private:
	RuleList(std::list<Rule> rules);
	std::list<Rule>::iterator getRules();
};
