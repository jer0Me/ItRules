#include "CompositeMark.h"
#include <boost/algorithm/string/join.hpp>

CompositeMark::CompositeMark(AbstractMark* mark, std::vector<std::string> options) : DelegateMark(mark), options(options) {}

std::vector<std::string> CompositeMark::get_options()
{
	std::vector<std::string> result;
	auto markOptions = this->mark->get_options();
	result.reserve(this->options.size() + markOptions.size());
	result.insert(result.end(), this->options.begin(), this->options.end());
	result.insert(result.end(), markOptions.begin(), markOptions.end());
	return result;
}

