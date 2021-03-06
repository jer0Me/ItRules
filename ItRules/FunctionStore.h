﻿#pragma once
#include <map>
#include "Function.h"
#include "Condition.h"

class FunctionStore
{
	std::map<std::string, Function*> map;

	bool exists(std::string function);
	Function* create_function(Condition* condition);
	Function* unknown_function(Condition* condition) const;
	Function* negated_function(Function* function);

public:
	FunctionStore();
	~FunctionStore();
	Function* get(Condition* condition);
	void add(std::string name, Function* function);
};
