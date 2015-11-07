#include "Condition.h"

void Condition::setCondition(std::string name, std::string parameter)
{
	this->name = name;
	this->parameter = parameter;
}


std::string Condition::getName()
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


