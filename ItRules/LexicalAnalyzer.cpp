#include "LexicalAnalyzer.h"
#include "LexicalTokenizer.h"
#include <boost/spirit/include/qi.hpp>

LexicalAnalyzer::LexicalAnalyzer() {}


std::list<Rule*>LexicalAnalyzer::analyze(std::string input) const
{
	namespace qi = boost::spirit::qi;
	LexicalTokenizer lexicalTokenizer;
	std::list<Rule*> rules;
	std::string::const_iterator iter = input.begin();
	std::string::const_iterator end = input.end();

	qi::phrase_parse(iter, end, lexicalTokenizer, qi::ascii::blank, rules);

	return rules;
}