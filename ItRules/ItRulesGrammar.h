#pragma once
#include <boost/spirit/include/qi.hpp>
#include "Rule.h"

namespace qi = boost::spirit::qi;
using Iterator = std::string::const_iterator;
using Skipper = qi::ascii::blank_type;
using boost::spirit::qi::symbols;

struct ItRulesGrammar : qi::grammar<Iterator, std::list<Rule*>(), Skipper>
{
public:
	ItRulesGrammar();

private:
	void set_condition_grammar();
	void set_tokens_grammar();
	void set_rules_grammar();
	void set_mark_token_grammar();
	void set_literal_token_grammar();
	void set_expression_token_grammar();

	qi::rule<Iterator, std::string(), Skipper> condition_name;
	qi::rule<Iterator, std::string(), Skipper> condition_parameter;
	qi::rule<Iterator, std::list<Condition*>(), Skipper> conditions;
	qi::rule<Iterator, std::string(), Skipper> escaped_character;
	qi::rule<Iterator, std::string(), Skipper> expression_literal_text;
	qi::rule<Iterator, Token*(), Skipper> expression;
	qi::rule<Iterator, std::string(), Skipper> mark_with_dots;
	qi::rule<Iterator, Token*(), Skipper> mark_list;
	qi::rule<Iterator, std::string(), Skipper> mark_name;
	qi::rule<Iterator, std::string(), Skipper> separator;
	qi::rule<Iterator, Token*(), Skipper> mark;
	qi::rule<Iterator, std::string(), Skipper> text;
	qi::rule<Iterator, std::vector<std::string>(), Skipper> mark_options;
	qi::rule<Iterator, Token*(), Skipper> literal;
	qi::rule<Iterator, Token*(), Skipper> expression_literal;
	qi::rule<Iterator, std::string(), Skipper> tab;
	qi::rule<Iterator, std::list<Token*>(), Skipper> tokens;
	qi::rule<Iterator, std::list<Token*>(), Skipper> expression_tokens;
	qi::rule<Iterator, Rule*(), Skipper> rule;
	qi::rule<Iterator, std::list<Rule*>(), Skipper> start;
	qi::rule<Iterator, std::string(), Skipper> char_admitted;
	qi::rule<Iterator, Condition*(), Skipper> condition;
	qi::rule<Iterator, std::string(), Skipper> string_separator;
};


