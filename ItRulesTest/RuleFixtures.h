#pragma once
#include <Rule.h>

class RuleFixtures
{
	Rule* person_rule() const;
	Rule* person_rule_with_mark_in_dirty_line() const;
	Rule* person_rule_with_expressions() const;
	Rule* person_rule_with_sex() const;
	Rule* person_rule_uppercase() const;
	Rule* person_rule_with_date_format_on_string() const;
	Rule* person_rule_with_double_format_on_string() const;
	Rule* person_rule_with_two_formats() const;
	Rule* person_rule_with_format_marks() const;
	Rule* person_rule_with_custom_condition() const;
	Rule* person_rule_with_custom_format() const;
	Rule* person_rule_with_or_expressions() const;
};
