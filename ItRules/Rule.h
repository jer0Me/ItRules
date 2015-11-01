#pragma once
#include "Condition.h"
#include "Action.h"

struct Rule
{
	Condition condition;
	Action action;
};
