#include "gtest/gtest.h"
#include <TemplateEngine.h>
#include <boost/date_time/gregorian/greg_date.hpp>
#include "Fixtures.h"

using boost::gregorian::date;
using boost::date_time::Jul;

TEST(TemplateEngine, should_render_person_defining_a_rule)
{
	auto template_engine = new TemplateEngine();
	Fixtures fixtures;
	template_engine->add({ fixtures.person_rule() });
	ASSERT_EQ("Pau Gasol was born in Spain on 06/07/1980", template_engine->render(fixtures.person()));
}

TEST(TemplateEngine, should_render_person_with_null_attributes_defining_a_rule)
{
	auto template_engine = new TemplateEngine();
	Fixtures fixtures;
	template_engine->add({ fixtures.person_rule_with_expressions() });
	ASSERT_EQ("Pau Gasol was born", template_engine->render(fixtures.person_with_null_attributes()));
}

TEST(TemplateEngine, should_render_person_defining_a_rule_with_negated_condition)
{
	auto template_engine = new TemplateEngine();
	Fixtures fixtures;
	template_engine->add({ fixtures.person_rule(), fixtures.person_rule_negated_condition() });
	ASSERT_EQ("Pau Gasol was born in - on -", template_engine->render(fixtures.person()));
}

TEST(TemplateEngine, should_render_person_defining_a_rule_with_uppercase_tokens)
{
	auto template_engine = new TemplateEngine();
	Fixtures fixtures;
	template_engine->add({ fixtures.person_rule_uppercase() });
	ASSERT_EQ("Pau Gasol was born in Spain on 06/07/1980", template_engine->render(fixtures.person()));
}

TEST(TemplateEngine, should_render_person_defining_a_rule_with_formatted_marks)
{
	auto template_engine = new TemplateEngine();
	Fixtures fixtures;
	template_engine->add({ fixtures.person_rule_with_format_marks() });
	ASSERT_EQ("PAU GASOL was born in spain on 06/07/1980", template_engine->render(fixtures.person()));
}

TEST(TemplateEngine, should_render_person_with_rule_expression)
{
	auto template_engine = new TemplateEngine();
	Fixtures fixtures;
	template_engine->add({ fixtures.person_rule_with_or_expressions() });
	ASSERT_EQ("Pau Gasol was born in Spain", template_engine->render(fixtures.person()));
}

TEST(TemplateEngine, should_render_person_defining_a_rule_with_value_function)
{
	auto template_engine = new TemplateEngine();
	Fixtures fixtures;
	template_engine->add({ fixtures.person_rule(), fixtures.person_value_rule()});
	ASSERT_EQ("*Pau Gasol* was born in Spain on 06/07/1980", template_engine->render(fixtures.person()));
}

TEST(TemplateEngine, should_render_person_defining_rule_with_a_trigger_condition)
{
	auto template_engine = new TemplateEngine();
	Fixtures fixtures;
	template_engine->add({ fixtures.person_rule(), fixtures.person_trigger_condition_rule() });
	ASSERT_EQ("*Pau Gasol* was born in Spain on 06/07/1980", template_engine->render(fixtures.person()));
}

TEST(TemplateEngine, should_render_person_defining_rule_with_a_trigger_format_condition)
{
	auto template_engine = new TemplateEngine();
	Fixtures fixtures;
	template_engine->add({ fixtures.person_rule(), fixtures.person_trigger_format_condition_rule() });
	ASSERT_EQ("Pau Gasol was born in Spain on \"06/07/1980\"", template_engine->render(fixtures.person()));
}

TEST(TemplateEngine, should_render_person_ignoring_date_formats_if_value_is_not_date)
{
	auto template_engine = new TemplateEngine();
	Fixtures fixtures;
	template_engine->add({ fixtures.person_rule_with_date_format_on_string() });
	ASSERT_EQ("Pau Gasol was born in Spain on 06/07/1980", template_engine->render(fixtures.person()));
}

TEST(TemplateEngine, should_render_person_ignoring_number_formats_if_value_is_not_double)
{
	auto template_engine = new TemplateEngine();
	Fixtures fixtures;
	template_engine->add({ fixtures.person_rule_with_double_format_on_string() });
	ASSERT_EQ("Pau gasol was born in spain on 06/07/1980", template_engine->render(fixtures.person()));
}

TEST(TemplateEngine, should_render_person_chaining_two_formats)
{
	auto template_engine = new TemplateEngine();
	Fixtures fixtures;
	template_engine->add({ fixtures.person_rule_with_two_formats() });
	ASSERT_EQ("PauGasols was born in Spain on 06/07/1980", template_engine->render(fixtures.person()));
}

TEST(TemplateEngine, should_render_person_defining_a_rule_with_a_custom_formatter)
{
	auto template_engine = new TemplateEngine();
	Fixtures fixtures;
	template_engine->add({ fixtures.person_rule_with_custom_format() });
	template_engine->add("Custom", fixtures.custom_formatter());
	ASSERT_EQ("9 was born in 5 on 06/07/1980", template_engine->render(fixtures.person()));
}

TEST(TemplateEngine, should_render_person_defining_rule_with_a_custom_condition_function)
{
	auto template_engine = new TemplateEngine();
	Fixtures fixtures;
	template_engine->add({ fixtures.person_rule_with_custom_condition() });
	template_engine->add("Custom", fixtures.custom_condition_function());
	ASSERT_EQ("Pau Gasol was born in Spain on 06/07/1980", template_engine->render(fixtures.person()));
}






