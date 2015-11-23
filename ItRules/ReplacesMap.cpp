#include "ReplacesMap.h"
#include <boost/foreach.hpp>

std::map<ReplaceString, std::string>& ReplacesMap::get_replaces()
{
	return map;
}

void ReplacesMap::add_replace(std::string from, std::string to)
{
	map.insert(std::pair<ReplaceString, std::string>(ReplaceString(num_replaces++, from),to));
}

std::string ReplacesMap::at(std::string key)
{
	typedef std::pair<ReplaceString, std::string> pair_replace;
	BOOST_FOREACH(pair_replace replace, map)
	{
		if (replace.first.get_replace().compare(key) == 0) 
			return replace.second;
	}
	return "";
}