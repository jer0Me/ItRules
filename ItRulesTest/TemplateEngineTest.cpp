#include "gtest/gtest.h"
#include <Rule.h>
#include <TemplateEngine.h>
#include <LexicalAnalyzer.h>
#include <Frame.h>
#include <PrimitiveFrame.h>
#include <boost/date_time/gregorian/greg_date.hpp>


TEST(TemplateEngine, testSimpleRule)
{
	std::string const input = "def type(person)\nbody\nend";
	LexicalAnalyzer analyzer;
	auto rules = analyzer.analyze(input);
	auto template_engine = new TemplateEngine();
	template_engine->add(rules);

	Frame* frame = new Frame();
	auto type_set = TypeSet();
	type_set.insert("person");
	auto slots_map = SlotMap();

	std::list<AbstractFrame*> name;
	auto* primitive_frame = new PrimitiveFrame();
	primitive_frame->set_value("Pau Gasol");
	name.push_back(primitive_frame);
	slots_map.insert("name", name);

	std::list<AbstractFrame*> birthday;
	primitive_frame = new PrimitiveFrame();
	boost::gregorian::date date(1980,boost::date_time::Jul, 06);
	primitive_frame->set_value(date);
	birthday.push_back(primitive_frame);
	slots_map.insert("birthday", birthday);

	std::list<AbstractFrame*> country;
	primitive_frame = new PrimitiveFrame();
	primitive_frame->set_value("spain");
	country.push_back(primitive_frame);
	slots_map.insert("country", country);

	frame->set_types(type_set);
	frame->set_slots(slots_map);

	ASSERT_EQ("body", template_engine->render(frame));
}