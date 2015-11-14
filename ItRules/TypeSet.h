#pragma once
#include <set>

class TypeSet
{
	std::set<std::string> types;

public:
	void insert(std::string);
	bool contain(std::string) const;
};
