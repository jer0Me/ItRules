#include "TypeFunction.h"
#include <boost/algorithm/string.hpp>
#include <boost/foreach.hpp>

bool TypeFunction::match(Trigger* trigger, std::string parameter)
{
	boost::to_lower(parameter);
	boost::erase_all(parameter, " ");
	boost::char_separator<char> separators("|&");
	tokenizer tokens(parameter, separators);
	return parameter.find("|") != std::string::npos ?
		match_any(tokens, trigger->get_frame()) : 
		match_all(tokens, trigger->get_frame());
}

bool TypeFunction::match_any(tokenizer& types, AbstractFrame* frame)
{
	boost::sregex_token_iterator end;
	BOOST_FOREACH(std::string type, types)
	{
		if (frame->is(type)) return true;
	}
	return false;
}

bool TypeFunction::match_all(tokenizer& types, AbstractFrame* frame)
{
	BOOST_FOREACH(std::string type, types)
	{
		if (!frame->is(type)) return false;
	}
	return true;
}
