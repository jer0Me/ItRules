#include "gtest/gtest.h"
#include <TemplateEngine.h>
#include <LexicalAnalyzer.h>
#include <PrimitiveFrame.h>
#include <Frame.h>
#include <boost/date_time/gregorian/greg_date.hpp>
#include <boost/variant/get.hpp>
#include "TemplateEngineFixtures.h"

using boost::gregorian::date;
using boost::date_time::Jul;
/*
TEST(TemplateEngine, testSimpleRule)
{
	std::string const input = "def type(person)\nbody\nend";
	LexicalAnalyzer analyzer;
	auto template_engine = new TemplateEngine();
	template_engine->add(analyzer.analyze(input));

	Frame* frame = new Frame();
	frame->add_types({ "object","person" })
		->add_frame("name", "Pau Gasol")
		->add_frame("birthday", date(1980, Jul, 06))
		->add_frame("country","spain");
	ASSERT_EQ("body", template_engine->render(frame));
	delete frame;
	delete template_engine;
}


TEST(TemplateEngine, testRuleWithMultipleMarksAndOption)
{
	std::string const input = "def type(person)\n$Name was born in $Country+Capitalize in $Birthday+Year\nend";
	LexicalAnalyzer analyzer;
	auto* template_engine = new TemplateEngine();
	template_engine->add(analyzer.analyze(input));

	Frame* frame = new Frame();
	frame->add_types({ "object","person" })
	->add_frame("name", "Pau Gasol")
	->add_frame("birthday", date(1980, Jul, 06))
	->add_frame("country","spain");

	ASSERT_EQ("Pau Gasol was born in Spain in 1980", template_engine->render(frame));
	delete frame;
	delete template_engine;
}
*/
TEST(TemplateEngine, testCustomFormatter)
{
	std::string const input = "def type(Person)\n\t$Name has $PetsCount+Letters pets:\n\t\t* $Pets...[$NL]\nend"
		"\n\ndef type(Dog)\n\t$Name, a $Age dog\nend\n\ndef type(Cat)\n\t$Name, a $Age kitty\nend\n\n"
		"def trigger(Age) one()\n\tone year old\nend\n\ndef trigger(Age)\n\t$value+Letters years old\nend";
	LexicalAnalyzer analyzer;
	auto* template_engine = new TemplateEngine();
	template_engine->add(analyzer.analyze(input));

	class one : public Function
	{
		bool match(Trigger* trigger, std::string parameter) override
		{
			return trigger->get_frame()->is_primitive() && is_value_one(trigger->get_frame());
		}

		bool is_value_one(AbstractFrame* abstract_frame) const
		{
			PrimitiveFrame* primitive_frame = dynamic_cast<PrimitiveFrame*>(abstract_frame);
			try
			{
				int test = boost::get<int>(primitive_frame->get_value());
				return test == 1;
			}
			catch(std::exception exception)
			{
				return false;
			}
		}
	};

	Function* function = new one();
	template_engine->add("one",function);

	Frame* ruffo = new Frame();
	ruffo->add_types({"dog","pet","object"})
		->add_frame("name", "Ruffo")
		->add_frame("age", 5);

	Frame* missy = new Frame();
	missy->add_types({ "cat","pet","object" })
		->add_frame("name", "Missy")
		->add_frame("age", 1);

	Frame* toby = new Frame();
	toby->add_types({ "dog","pet","object" })
		->add_frame("name", "Toby")
		->add_frame("age", 3);

	Frame* frame = new Frame();
	frame->add_types({ "object", "person" })
		->add_frame("name", "Roger Dickens")
		->add_frame("petscount", 3)
		->add_frame("pets", {ruffo,missy,toby});

	ASSERT_EQ("Roger Dickens has 3 pets:\n"
		"\t* Ruffo, a 5 years old dog\n"
		"\tMissy, a one year old kitty\n"
		"\tToby, a 3 years old dog", template_engine->render(frame));
}

TEST(TemplateEngine, testRecursiveRule)
{
	std::string const input = "def type(Module)\n\t<module name=$name [type=$type]>[\n"
		"\t\t$modules...[$NL]\n\t]</module>\nend";

	LexicalAnalyzer analyzer;
	auto* template_engine = new TemplateEngine();
	template_engine->add(analyzer.analyze(input));

	auto first_one_one_level = new Frame();
	first_one_one_level->add_types({ "module","object" })
		->add_frame("name", "1.1.1")
		->add_frame("type", "last level")
		->add_frame("modulescount", 1);

	auto first_one_level = new Frame();
	first_one_level->add_types({ "module","object" })
		->add_frame("name", "1.1")
		->add_frame("modulescount", 1)
		->add_frame("modules",first_one_one_level);



	auto first_two_level = new Frame();
	first_two_level->add_types({ "module","object" })
		->add_frame("name", "1.2")
		->add_frame("modulescount", 1);

	auto first_level = new Frame();
	first_level->add_types({ "module","object" })
		->add_frame("name", 1)
		->add_frame("modulescount", 1)
		->add_frame("modules", {
			first_one_level, first_two_level
		});

	

	auto root= new Frame();
	root->add_types({ "module","object" })
		->add_frame("name", "X")
		->add_frame("modulescount", 5)
		->add_frame("modules", {
				first_level
		});

	std::string result = template_engine->render(root);
	std::cout << result;

}


TEST(TemplateEngine, should_render_person_defining_a_rule)
{
	auto template_engine = new TemplateEngine();
	TemplateEngineFixtures fixtures;
	template_engine->add({ fixtures.person_rule() });
	ASSERT_EQ("Pau Gasol was born in Spain on 06/07/1980", template_engine->render(fixtures.person()));
}
