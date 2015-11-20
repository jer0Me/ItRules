#include "gtest/gtest.h"
#include <TemplateEngine.h>
#include <Frame.h>

TEST(ItRulesTest, testRuleSimple)
{
	auto template_engine = new TemplateEngine();
	auto frame = new Frame();
	template_engine->use("Person.itr");


	frame->add_types({ "object","person" })
		->add_frame("name", "Pau Gasol")
		->add_frame("birthday", boost::gregorian::date(1980, boost::date_time::Jul, 06))
		->add_frame("country", "spain");
	ASSERT_EQ("body", template_engine->render(frame));
	delete frame;
	delete template_engine;
}