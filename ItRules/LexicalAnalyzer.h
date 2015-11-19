#pragma once
#include <string>
#include "RuleList.h"

class LexicalAnalyzer
{
	void setRuleTokenPrevious(std::list<Rule*>& rules);
	void setTokenPrevious(std::list<Token*>& tokens);
	void addSlotRule(std::list<Rule*>& rules);
	bool LexicalAnalyzer::is_expression(Token* token);

public:
	LexicalAnalyzer();
	std::list<Rule*>analyze(std::string rules);
	
};
