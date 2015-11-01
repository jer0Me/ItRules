#include "gtest/gtest.h"
#include "LexicalAnalyzer.h"
#include <string>

TEST(LexicalAnalyzer, testSimpleRule)
{
	std::string const rules = "def type(name)\nbody\nend";
	LexicalAnalyzer analyzer;
	RuleList ruleList = analyzer.analyze(rules);
	ASSERT_EQ("type", ruleList.rules[0].condition.functionList[0].type);
	ASSERT_EQ("name", ruleList.rules[0].condition.functionList[0].value);
}
TEST(LexicalAnalyzer, testRuleWithTwoFunctions)
{
	std::string const rules = "def type(name) trigger(mark)\nbody\nend";
	LexicalAnalyzer analyzer;
	RuleList ruleList = analyzer.analyze(rules);
	ASSERT_EQ("type", ruleList.rules[0].condition.functionList[0].type);
	ASSERT_EQ("name", ruleList.rules[0].condition.functionList[0].value);
	ASSERT_EQ("trigger", ruleList.rules[0].condition.functionList[1].type);
	ASSERT_EQ("mark", ruleList.rules[0].condition.functionList[1].value);
}

TEST(LexicalAnalyzer, testRuleWithFunctionWithoutArgument)
{
	std::string const rules = "def one()trigger(object)\nbody\nend";
	LexicalAnalyzer analyzer;
	RuleList ruleList = analyzer.analyze(rules);
	ASSERT_EQ("one", ruleList.rules[0].condition.functionList[0].type);
	ASSERT_EQ("", ruleList.rules[0].condition.functionList[0].value);
	ASSERT_EQ("trigger", ruleList.rules[0].condition.functionList[1].type);
	ASSERT_EQ("object", ruleList.rules[0].condition.functionList[1].value);
}

TEST(LexicalAnalyzer, testRuleWithThreeFunctionAndOneOfThemWithoutArgument)
{
	std::string const rules = "def type(Person) one() trigger(object)\nbody\nend";
	LexicalAnalyzer analyzer;
	RuleList ruleList = analyzer.analyze(rules);
	ASSERT_EQ(3, ruleList.rules[0].condition.functionList.size());
}

TEST(LexicalAnalyzer, testRuleWithThreeFunctionOneOfThemWithoutArgumentAndWithoutSpaceBetweenThem)
{
	std::string const rules = "def type(Person)one()trigger(object)\nbody\nend";
	LexicalAnalyzer analyzer;
	RuleList ruleList = analyzer.analyze(rules);
	ASSERT_EQ(3, ruleList.rules[0].condition.functionList.size());
}

TEST(LexicalAnalyzer, testRuleWithSimpleBody)
{
	std::string const rules = "def type(Person)\nbody\nend";
	LexicalAnalyzer analyzer;
	RuleList ruleList = analyzer.analyze(rules);
	ASSERT_EQ("body", ruleList.rules[0].action.body);
}

TEST(LexicalAnalyzer, testRuleWithBodyWithSpacesBetweenCharacter)
{
	std::string const rules = "def type(Person)\nbody with spaces\nend";
	LexicalAnalyzer analyzer;
	RuleList ruleList = analyzer.analyze(rules);
	ASSERT_EQ("body with spaces", ruleList.rules[0].action.body);
}

TEST(LexicalAnalyzer, testRuleWithNewLinesInBodyCondition)
{
	std::string const rules = "def type(Person)\nbody with\n spaces\n end";
	LexicalAnalyzer analyzer;
	RuleList ruleList = analyzer.analyze(rules);
	ASSERT_EQ("body with\n spaces", ruleList.rules[0].action.body);
}
TEST(LexicalAnalyzer, testRuleWithMultipleNewLinesInBodyCondition)
{
	std::string const rules = "def type(Person)\n\nbody with\n \n spaces\nend";
	LexicalAnalyzer analyzer;
	RuleList ruleList = analyzer.analyze(rules);
	ASSERT_EQ("\nbody with\n \n spaces", ruleList.rules[0].action.body);
}

TEST(LexicalAnalyzer, testRuleWithDefKeywordBadSpelled)
{
	std::string const rules = "defs type(Person)one()trigger(object)\nbody\nend";
	LexicalAnalyzer analyzer;
	RuleList ruleList = analyzer.analyze(rules);
	ASSERT_EQ(0, ruleList.size());
}

TEST(LexicalAnalyzer, testRuleBadDefined)
{
	std::string const rules = "def t y p e(Person) one()trigger(object)\nbody\nend";
	LexicalAnalyzer analyzer;
	RuleList ruleList = analyzer.analyze(rules);
	ASSERT_EQ(0, ruleList.size());
}

TEST(LexicalAnalyzer, testRuleWithFunctionBadDefined)
{
	std::string const rules = "deftype(\nPerson)one()trigger(object)\nbody\nend";
	LexicalAnalyzer analyzer;
	RuleList ruleList = analyzer.analyze(rules);
	ASSERT_EQ(0, ruleList.size());
}

TEST(LexicalAnalyzer, testMultipleRules)
{
	std::string const rules = "def type(Person)\n\n(body) with\n \n spaces\nend\n\n\ndef type(Person)\n\nbody with\n \n spaces\nend";
	LexicalAnalyzer analyzer;
	RuleList ruleList = analyzer.analyze(rules);
	ASSERT_EQ(2, ruleList.size());
}

TEST(LexicalAnalyzer, testMultipleRulesWithOneOfThemBadDefined)
{
	std::string const rules = "def type(Person)\n\n(body) with\n \n spaces\nend\ndef ty pe(Person)\n\nbody with\n \n spaces\nend";
	LexicalAnalyzer analyzer;
	RuleList ruleList = analyzer.analyze(rules);
	ASSERT_EQ(0, ruleList.size());
}

TEST(LexicalAnalyzer, testMarkWithFormat)
{
	std::string const rules = "def type(Attribute) trigger(attribute+Const) type(Const)\n"
								"\tpublic static final $name+UPPERCASE;\nend";
}


