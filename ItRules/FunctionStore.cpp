#include "FunctionStore.h"
#include "TypeFunction.h"
#include <boost/algorithm/string.hpp>
#include "SlotFunction.h"
#include <algorithm>
#include "TriggerFunction.h"
#include "ValueFunction.h"


FunctionStore::FunctionStore()
{
	map.insert(std::pair<std::string, Function*>("type", new TypeFunction()));
	map.insert(std::pair<std::string, Function*>("slot", new SlotFunction()));
	map.insert(std::pair<std::string, Function*>("trigger", new TriggerFunction()));
	map.insert(std::pair<std::string, Function*>("value", new ValueFunction()));
}

FunctionStore::~FunctionStore()
{
	for_each(this->map.begin(), this->map.end(), [](std::pair<std::string, Function*> function_pair)
	{
		delete function_pair.second;
	});
}


Function* FunctionStore::get(Condition* condition)
{
	return exists(condition->get_name()) ? create_function(condition) : unknown_function(condition);
}

bool FunctionStore::exists(std::string function)
{
	boost::to_lower(function);
	return map.count(function) != 0;
}

Function* FunctionStore::create_function(Condition* condition)
{

	auto* function = map.at(boost::to_lower_copy(condition->get_name()));
	return condition->isNegated() ? negatedFunction(function) : function;

}

Function* FunctionStore::unknown_function(Condition* condition) const
{
	throw std::runtime_error("Function " + condition->get_name() + " does not exist");
}

Function* FunctionStore::negatedFunction(Function* function)
{
	class negated : public Function
	{
		Function* function;
	public:
		negated(Function* function) : function(function){}
		bool match(Trigger* trigger, std::string parameter) override {
			return !function->match(trigger, parameter);
		}
	};
	return new negated(function);
}

void FunctionStore::add(std::string name, Function* function)
{
	map.insert(std::pair<std::string, Function*>(name, function));
}


