#include "LexicalAnalyzer.h"
#include "LexicalTokenizer.h"
#include <boost/spirit/include/qi.hpp>

LexicalAnalyzer::LexicalAnalyzer() {}


RuleList LexicalAnalyzer::analyze(std::string rules) const
{
	namespace qi = boost::spirit::qi;

	LexicalTokenizer lexicalTokenizer;

	RuleList ruleList;
	std::string::const_iterator iter = rules.begin();
	std::string::const_iterator end = rules.end();

	qi::phrase_parse(iter, end, lexicalTokenizer, qi::ascii::blank, ruleList);

	return ruleList;
}