#include "Condition.h"

Condition::Condition(std::string name, std::string parameter, bool negated) : name(name), parameter(parameter), negated(negated) {}

Condition::Condition(std::string name, std::string parameter) : name(name), parameter(parameter)
{
	this->negated = false;
}

std::string Condition::get_name()
{
	return this->name;
}

std::string Condition::getParameter()
{
	return this->parameter;
}

bool Condition::isNegated()
{
	return this->negated;
}


