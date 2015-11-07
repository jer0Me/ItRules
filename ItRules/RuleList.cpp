#include "RuleList.h"

RuleList::RuleList(std::list<Rule> rules) : rules(rules){}

std::list<Rule>::iterator RuleList::getRules()
{
	return rules.begin();
}
