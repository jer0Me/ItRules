#pragma once
#include <string>
#include "RuleList.h"

class LexicalAnalyzer
{
	void set_rule_token_previous(std::list<Rule*>& rules);
	void set_token_previous(std::list<Token*>& tokens);
	bool LexicalAnalyzer::is_expression(Token* token) const;

public:
	LexicalAnalyzer();
	std::list<Rule*>analyze(std::string rules);
	
};
