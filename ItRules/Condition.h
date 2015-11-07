#pragma once
#include <vector>

class Condition
{
	std::string name;
	std::string parameter;
	bool negated;

public:
	void setCondition(std::string name, std::string parameter);

	std::string getName();
	std::string getParameter();
	
	bool isNegated();

};
