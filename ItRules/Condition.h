#pragma once
#include <vector>

class Condition
{
	std::string name;
	std::string parameter;
	bool negated;

public:
	Condition(std::string name, std::string parameter);
	Condition(std::string name, std::string parameter, bool negated);

	std::string get_name();
	std::string getParameter();
	
	bool is_negated();

};
