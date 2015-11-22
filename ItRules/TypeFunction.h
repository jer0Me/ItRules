#pragma once
#include "Function.h"
#include <boost/regex.hpp>
#include <boost/token_functions.hpp>
#include <boost/tokenizer.hpp>

class Frame;

class TypeFunction : public Function
{
public:
	typedef boost::tokenizer<boost::char_separator<char>>tokenizer;

	bool match(Trigger* trigger, std::string parameter) override;
	bool match_any(tokenizer& types, AbstractFrame* frame);
	bool match_all(tokenizer& types, AbstractFrame* frame);
	
};
