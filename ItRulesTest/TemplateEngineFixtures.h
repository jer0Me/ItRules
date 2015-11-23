#pragma once
#include <Rule.h>
#include <Frame.h>

class TemplateEngineFixtures
{
	
public:
	Frame* person();
	Frame* person_with_null_attributes();
	Rule* person_rule() const;
	Rule* person_rule_with_mark_in_dirty_line() const;
	Rule* person_rule_with_expressions() const;
	Rule* person_rule_negated_condition() const;
	Rule* person_rule_with_sex() const;
	Rule* person_rule_uppercase() const;
	Rule* person_rule_with_date_format_on_string() const;
	Rule* person_rule_with_double_format_on_string() const;
	Rule* person_rule_with_two_formats() const;
	Rule* person_rule_with_format_marks() const;
	Rule* person_rule_with_custom_condition() const;
	Rule* person_rule_with_custom_format() const;
	Rule* person_rule_with_or_expressions() const;
	Rule* person_value_rule() const;
	Rule* person_trigger_condition_rule() const;
	Rule* person_trigger_format_condition_rule() const;
	Formatter* custom_formatter();
	Function* custom_condition_function();
};
