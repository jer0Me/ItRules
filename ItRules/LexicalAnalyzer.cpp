#include "LexicalAnalyzer.h"
#include "LexicalTokenizer.h"
#include <boost/spirit/include/qi.hpp>

LexicalAnalyzer::LexicalAnalyzer() {}


RuleList LexicalAnalyzer::analyze(std::string input) const
{
	namespace qi = boost::spirit::qi;
	LexicalTokenizer lexicalTokenizer;
	RuleList ruleList;
	std::vector<Rule> rules;
	std::string::const_iterator iter = input.begin();
	std::string::const_iterator end = input.end();

	qi::phrase_parse(iter, end, lexicalTokenizer, qi::ascii::blank, ruleList);

	return ruleList;
}