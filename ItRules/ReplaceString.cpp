#include "ReplaceString.h"

ReplaceString::ReplaceString(int id, std::string replace) : id(id), replace(replace) {}

std::string ReplaceString::get_replace()
{
	return replace;
}

bool ReplaceString::operator<(const ReplaceString& rs) const
{
	if (this->id < rs.get_id()) return true;
	return false;
}

int ReplaceString::get_id() const
{
	return id;
}