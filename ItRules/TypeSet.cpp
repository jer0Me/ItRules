#include "TypeSet.h"
#include <boost/algorithm/string.hpp>

void TypeSet::insert(std::string type)
{
	boost::to_lower(type);
	this->types.insert(type);
}

bool TypeSet::contain(std::string type) const
{
	boost::to_lower(type);
	return this->types.count(type) > 0;
}