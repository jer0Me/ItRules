#include "gtest/gtest.h"
#include "LexicalAnalyzer.h"
#include "Mark.h"
#include <Literal.h>
#include "LexicalAnalyzerFixtures.h"

TEST(LexicalAnalyzer, simple_rule)
{
	auto fixtures = new LexicalAnalyzerFixtures();
	auto rules = fixtures->simple_rule();
	auto rule = *rules.begin();
	ASSERT_TRUE(fixtures->check_condition("type", "person", rule));
	ASSERT_TRUE(fixtures->check_token_literal("body", rule));
	delete fixtures;
}

TEST(LexicalAnalyzer, simple_rule_with_tabs)
{
	auto fixtures = new LexicalAnalyzerFixtures();
	auto rules = fixtures->simple_rule_with_tabs();
	auto rule = *rules.begin();
	ASSERT_TRUE(fixtures->check_condition("type", "person", rule));
	ASSERT_TRUE(fixtures->check_token_literal("\tbody", rule));
	delete fixtures;
}

TEST(LexicalAnalyzer, rule_with_mark_options)
{//"def type(person)\n$Name was born in $Country+Capitalize in $Birthday+Year\nend";
	auto fixtures = new LexicalAnalyzerFixtures();
	auto rules = fixtures->rule_with_mark_options();
	auto rule = *rules.begin();
	ASSERT_TRUE(fixtures->check_condition("type", "person", rule));
	ASSERT_TRUE(fixtures->check_token_mark("Name", {}, rule));
	ASSERT_TRUE(fixtures->check_token_literal(" was born in ", rule));
	ASSERT_TRUE(fixtures->check_token_mark("Country", {"Capitalize"}, rule));
	ASSERT_TRUE(fixtures->check_token_literal(" in ", rule));
	ASSERT_TRUE(fixtures->check_token_mark("Birthday", {"Year"}, rule));
}

TEST(LexicalAnalyzer, )
{
	
}
