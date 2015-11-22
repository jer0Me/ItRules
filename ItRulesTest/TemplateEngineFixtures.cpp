#include <Mark.h>
#include <Literal.h>
#include <Expression.h>
#include <TemplateEngine.h>
#include <Frame.h>
#include "TemplateEngineFixtures.h"


Frame* TemplateEngineFixtures::person()
{

	auto person = new Frame();
	person->add_types({"person","object" })
		->add_frame("name", "Pau Gasol")
		->add_frame("birthday", boost::gregorian::date(1980, boost::date_time::Jul, 6))
		->add_frame("country", "Spain");
	return person;
}



Rule* TemplateEngineFixtures::person_rule() const
{
	auto rule = new Rule();
	rule->add(new Condition("type", "Person"))
		->add({ new Mark("name"), new Literal(" was born in "), new Mark("country"), new Literal(" on "), new Mark("Birthday", {"quoated","ShortDate"}) });
	return rule;
}

Rule* TemplateEngineFixtures::person_rule_with_mark_in_dirty_line() const
{
	auto rule = new Rule();
	rule->add(new Condition("type", "Person"))
		->add({ new Mark("name"), new Literal(" was born in "), new Mark("country"), new Literal("\n\t    \t   "), new Mark("dirty"), new Literal("\n"), new Literal("on "), new Mark("Birthday",{ "quoated","ShortDate"}) });
	return rule;
}

Rule* TemplateEngineFixtures::person_rule_with_expressions() const
{
	auto rule = new Rule();
	rule->add(new Condition("type", "Person"))
		->add({ new Mark("name"), new Literal(" was born"), new Expression({new Literal(" in "), new Mark("country")}), new Expression({new Literal("on "), new Mark("Birthday", {"ShortDate"})}) });
	return rule;
}

Rule* TemplateEngineFixtures::person_rule_with_sex() const
{
	auto rule = new Rule();
	rule->add(new Condition("type", "Person"))
		->add({new Mark("name"), new Literal(" is "), new Mark("Sex")});
	return rule;
}

Rule* TemplateEngineFixtures::person_rule_uppercase() const
{
	auto rule = new Rule();
	rule->add(new Condition("TYPE", "PERSON"))
		->add({ new Mark("NAME"), new Literal("was born in "), new Mark("COUNTRY"), new Literal(" on "), new Mark("Birthday",{"ShortDate"}) });
	return rule;
}

Rule* TemplateEngineFixtures::person_rule_with_date_format_on_string() const
{
	auto rule = new Rule();
	rule->add(new Condition("Type", "Person"))
		->add({ new Mark("Name", { "ShortDate" }), new Literal(" was born in "), new Mark("Country"), new Literal(" on "), new Mark("Birthday",{"ShortDate"}) });
	return rule;
}


Rule* TemplateEngineFixtures::person_rule_with_double_format_on_string() const
{
	auto rule = new Rule();
	rule->add(new Condition("Type", "Person"))
		->add({ new Mark("Name",{"TwoDecimals", "Capitalize"}), new Literal(" was born in "), new Mark("Country",{"Letters", "LowerCase"}), new Literal(" on "), new Mark("Birthday",{"Separators", "ShortDate"})});
	return rule;
}

Rule* TemplateEngineFixtures::person_rule_with_two_formats() const
{
	auto rule = new Rule();
	rule->add(new Condition("Type", "Person"))
		->add({ new Mark("Name",{"CamelCase", "Plural"}), new Literal(" was born in "), new Mark("Country"), new Literal(" on "), new Mark("Birthday",{"ShortDate"}) });
	return rule;
}

Rule* TemplateEngineFixtures::person_rule_with_format_marks() const
{
	auto rule = new Rule();
	rule->add(new Condition("Type", "Person"))
		->add({new Mark("Name",{"Uppercase"}), new Literal(" was born in "), new Mark("Country",{"Lowercase"}), new Literal(" on "), new Mark("Birthday",{"ShortDate"})});
	return rule;
}

Rule* TemplateEngineFixtures::person_rule_with_custom_condition() const
{
	auto rule = new Rule();
	rule->add(new Condition("Custom", "Gasol"))
		->add({ new Mark("Name"), new Literal(" was born in "), new Mark("Country"), new Literal(" on "), new Mark("Birthday", {"ShortDate"})});
	return rule;
}

Rule* TemplateEngineFixtures::person_rule_with_custom_format() const
{
	auto rule = new Rule();
	rule->add(new Condition("Type", "Person"))
		->add({ new Mark("Name"), new Literal(" was born in "), new Mark("Country"), new Literal(" on "), new Mark("Birthday", {"ShortDate"}) });
	return rule;
}

Rule* TemplateEngineFixtures::person_rule_with_or_expressions() const
{
	auto first_expression = new Expression({ new Literal("..."), new Mark("Nothing"), new Literal("...") });
	auto second_expression = new Expression({ new Literal("..."), new Mark("Empty") });
	auto third_expression = new Expression({ new Literal(" was born in "), new Mark("Country") });

	second_expression->set_other_expression(third_expression);
	first_expression->set_other_expression(second_expression);
	auto rule = new Rule();
	rule->add(new Condition("Type", "Person"))
		->add({new Mark("Name"),first_expression});
	return rule;
}
















