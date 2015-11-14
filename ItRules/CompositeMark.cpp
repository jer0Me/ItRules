#include "CompositeMark.h"
#include <boost/algorithm/string/join.hpp>

CompositeMark::CompositeMark(AbstractMark* mark, std::vector<std::string> options) : DelegateMark(mark), options(options) {}

std::vector<std::string> CompositeMark::get_options()
{
	std::vector<std::string> result (this->options.size() + this->mark->get_options().size());
	std::copy(this->options.begin(), this->options.end(), result.begin());
	std::copy(this->mark->get_options().begin(), this->mark->get_options().end(), result.end() + 1);
	return result;
}

