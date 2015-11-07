#include "gtest/gtest.h"
#include "LexicalAnalyzer.h"
#include "Mark.h"

TEST(LexicalAnalyzer, testSimpleRule)
{
	std::string const input = "def type(name)\nbody\nend";
	LexicalAnalyzer analyzer;
	std::list<Rule> rules = analyzer.analyze(input);
	Rule rule = *rules.begin();
	Condition condition = *rule.get_conditions_iterator();
	ASSERT_EQ("type", condition.getName());
	ASSERT_EQ("name", condition.getParameter());
}

TEST(LexicalAnalyzer, testRuleWithMarksAndOptions)
{
	std::string const input = "def type(person)\n$Name was born in $Country+Capitalize in $Birthday+Year\nend";
	LexicalAnalyzer analyzer;
	std::list<Rule> rules = analyzer.analyze(input);
	Rule rule = *rules.begin();
	Condition condition = *rule.get_conditions_iterator();
	ASSERT_EQ("type", condition.getName());
	ASSERT_EQ("person", condition.getParameter());
	auto tokenIterator = rule.get_token_iterator();
	Token* token = *tokenIterator;
	Mark* mark = dynamic_cast<Mark *>(token);
	ASSERT_EQ("Name", mark->getName());

	}
/*
 TEST(LexicalAnalyzer, testRuleWithEscapedCharacter)
{
	std::string const rule = "def type(Person)\n\tName: $Name+Uppercase\n\tBirthYear:"
		" $Birthday+Year\n\n\tHeight: $Height ($Height+Letters) "
		"cm\n\tSalary: $$$Salary+Separators\nend";
	LexicalAnalyzer analyzer;
	RuleList ruleList = analyzer.analyze(rule);
	ASSERT_EQ("type", ruleList.rules[0].conditions[0].name);
	ASSERT_EQ("Person", ruleList.rules[0].conditions[0].parameter);
	ASSERT_EQ("Name: ", boost::get<Literal>(ruleList.rules[0].tokens[0]).text);
	ASSERT_EQ("Name", boost::get<Mark>(ruleList.rules[0].tokens[1]).name);
	ASSERT_EQ("Uppercase", boost::get<Mark>(ruleList.rules[0].tokens[1]).options[0]);
	ASSERT_EQ("\nBirthYear: ", boost::get<Literal>(ruleList.rules[0].tokens[2]).text);
	ASSERT_EQ("Birthday", boost::get<Mark>(ruleList.rules[0].tokens[3]).name);
	ASSERT_EQ("Year", boost::get<Mark>(ruleList.rules[0].tokens[3]).options[0]);
	ASSERT_EQ("\n\nHeight: ", boost::get<Literal>(ruleList.rules[0].tokens[4]).text);
	ASSERT_EQ("Height", boost::get<Mark>(ruleList.rules[0].tokens[5]).name);
	ASSERT_EQ(" (", boost::get<Literal>(ruleList.rules[0].tokens[6]).text);
	ASSERT_EQ("Height", boost::get<Mark>(ruleList.rules[0].tokens[7]).name);
	ASSERT_EQ("Letters", boost::get<Mark>(ruleList.rules[0].tokens[7]).options[0]);
	ASSERT_EQ(") cm\nSalary: $", boost::get<Literal>(ruleList.rules[0].tokens[8]).text);
	ASSERT_EQ("Salary", boost::get<Mark>(ruleList.rules[0].tokens[9]).name);
	ASSERT_EQ("Separators", boost::get<Mark>(ruleList.rules[0].tokens[9]).options[0]);
}
 
TEST(LexicalAnalyzer, testRuleWithMarkSeparator)
{
	std::string const rule = "def type(Person)\n\t$Name has $PetsCount+Letters pets:\n\t"
		"  * $Pets...[$NL]\nend";
	LexicalAnalyzer analyzer;
	RuleList ruleList = analyzer.analyze(rule);
	ASSERT_EQ("type", ruleList.rules[0].conditions[0].name);
	ASSERT_EQ("Person", ruleList.rules[0].conditions[0].parameter);
	ASSERT_EQ("Name", boost::get<Mark>(ruleList.rules[0].tokens[0]).name);
	ASSERT_EQ(" has ", boost::get<Literal>(ruleList.rules[0].tokens[1]).text);
	ASSERT_EQ("PetsCount", boost::get<Mark>(ruleList.rules[0].tokens[2]).name);
	ASSERT_EQ("Letters", boost::get<Mark>(ruleList.rules[0].tokens[2]).options[0]);
	ASSERT_EQ(" pets:\n  * ", boost::get<Literal>(ruleList.rules[0].tokens[3]).text);
	ASSERT_EQ("Pets...", boost::get<Mark>(ruleList.rules[0].tokens[4]).name);
	ASSERT_EQ("\n", boost::get<Mark>(ruleList.rules[0].tokens[4]).separator);
}

TEST(LexicalAnalyzer, testRuleWithExpression)
{
	std::string const rule = "def type(Module)\n\t<module name=\"$name\">[\n\t$modules...[$NL]\n\t]</module>\nend";
	LexicalAnalyzer analyzer;
	RuleList ruleList = analyzer.analyze(rule);
	ASSERT_EQ("type", ruleList.rules[0].conditions[0].name);
	ASSERT_EQ("Module", ruleList.rules[0].conditions[0].parameter);
	ASSERT_EQ("<module name=\"", boost::get<Literal>(ruleList.rules[0].tokens[0]).text);
	ASSERT_EQ("name", boost::get<Mark>(ruleList.rules[0].tokens[1]).name);
	ASSERT_EQ("\">", boost::get<Literal>(ruleList.rules[0].tokens[2]).text);
	ASSERT_EQ("\n", boost::get<Literal>(boost::get<Expression>(ruleList.rules[0].tokens[3]).tokens[0]).text);	
	ASSERT_EQ("\t", boost::get<Literal>(boost::get<Expression>(ruleList.rules[0].tokens[3]).tokens[1]).text);

}

TEST(LexicalAnalyzer, testConditionNegated)
{
	std::string const rules = "def type(!name)\nbody\nend";
	LexicalAnalyzer analyzer;
	RuleList ruleList = analyzer.analyze(rules);
	ASSERT_EQ("type", ruleList.rules[0].conditions[0].name);
	ASSERT_EQ("name", ruleList.rules[0].conditions[0].parameter);
	ASSERT_TRUE(ruleList.rules[0].conditions[0].negated);
}
*/