#pragma once
#include <string>

class ReplaceString
{
	int id;
	std::string replace;

public:
	ReplaceString(int id, std::string replace);
	std::string get_replace();
	bool operator < (const ReplaceString &rs) const;
	int get_id() const;
};
