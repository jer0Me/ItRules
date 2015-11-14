#include "AbstractMark.h"


AbstractMark::~AbstractMark()
{
	
}


std::string AbstractMark::get_name()
{
	return "";
}

std::string AbstractMark::full_name()
{
	return "";
}

std::string AbstractMark::get_indentation()
{
	return "";
}

std::string AbstractMark::get_separator()
{
	return "";
}

bool AbstractMark::is_multiple()
{
	return false;
}

std::vector<std::string> AbstractMark::get_options()
{
	std::vector<std::string> emptyVector;
	return emptyVector;
}

std::string AbstractMark::to_string()
{
	return "";
}


