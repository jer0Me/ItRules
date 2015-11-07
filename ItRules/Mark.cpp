#include "Mark.h"

Mark::Mark(std::string name, std::list<std::string> options, std::string separator) : name(name), options(options), separator(separator){}

Mark::Mark(std::string name, std::list<std::string> options) : name(name), options(options){}

std::string Mark::getName()
{
	return name;
}

std::list<std::string>::iterator Mark::getOptions()
{
	return options.begin();
}

std::string Mark::getSeparator()
{
	return separator;
}

