#pragma once
#include <map>
#include "ReplaceString.h"

class ReplacesMap
{
	int num_replaces = 0;
	std::map<ReplaceString, std::string> map;
public:
	std::map<ReplaceString, std::string>& get_replaces();
	void add_replace(std::string from, std::string to);
	std::string at(std::string key);
};
