#pragma once
#include <list>
#include <Rule.h>

class LexicalAnalyzerFixtures
{

	bool is_condition_name(std::string name, Condition* condition) const;
	bool is_condition_parameter(std::string parameter, Condition* condition) const;
	bool is_literal(Token* token);
	bool is_mark(Token* token);
	bool is_mark_name(std::string name, Token* token);
	bool is_mark_options(std::vector<std::string> options, Token* token);

	bool check_literal_value(Token* token, std::string text) const;
	
public:
	std::list<Rule*> simple_rule() const;
	std::list<Rule*> simple_rule_with_tabs() const;
	std::list<Rule*> rule_with_mark_options() const;
	bool check_condition(std::string name, std::string parameter, Rule* rule) const;
	bool check_token_literal(std::string text, Rule* rule);
	bool check_token_mark(std::string name, std::initializer_list<std::string> options, Rule* rule);
	
};
