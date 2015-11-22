#pragma once
#include <string>
#include "RuleList.h"

class LexicalAnalyzer
{
	void setRuleTokenPrevious(std::list<Rule*>& rules);
	void setTokenPrevious(std::list<Token*>& tokens);
	bool LexicalAnalyzer::is_expression(Token* token);

public:
	LexicalAnalyzer();
	std::list<Rule*>analyze(std::string rules);
	
};
