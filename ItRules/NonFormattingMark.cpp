#include "NonFormattingMark.h"
#include <boost/foreach.hpp>

NonFormattingMark::NonFormattingMark(AbstractMark* mark,FormatterStore* formatter_store)
	: DelegateMark(mark), formatter_store(formatter_store) {}

std::vector<std::string> NonFormattingMark::get_options()
{
	std::vector<std::string> result;
	BOOST_FOREACH(std::string option, this->mark->get_options())
	{
		if(!formatter_store->exists(option)) result.push_back(option);
		
	}
	return result;
}




