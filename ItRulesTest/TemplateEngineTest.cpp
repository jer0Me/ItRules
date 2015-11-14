#include "gtest/gtest.h"
#include <Rule.h>
#include <TemplateEngine.h>
#include <LexicalAnalyzer.h>
#include <Frame.h>
#include <boost/date_time/gregorian/greg_date.hpp>

using boost::gregorian::date;
using boost::date_time::Jul;

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
}