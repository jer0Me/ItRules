#include "FunctionStore.h"
#include "TypeFunction.h"
#include <boost/algorithm/string.hpp>
#include "SlotFunction.h"
#include <boost/foreach.hpp>


FunctionStore::FunctionStore()
{
	map.insert(std::pair<std::string, Function*>("type", new TypeFunction()));
	map.insert(std::pair<std::string, Function*>("slot", new SlotFunction()));
}

FunctionStore::~FunctionStore()
{
	typedef std::map<std::string, Function*> function_map;
	BOOST_FOREACH(function_map::value_type &value, this->map)
	{
		delete value.second;
	}
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
	auto* function = map.at(condition->get_name());
	return condition->isNegated() ? negatedFunction(function) : function;

}

Function* FunctionStore::unknown_function(Condition* condition) const
{
	throw std::runtime_error("Function " + condition->get_name() + " does not exist");
}

Function* FunctionStore::negatedFunction(Function* function)
{
	return new Function();
}



