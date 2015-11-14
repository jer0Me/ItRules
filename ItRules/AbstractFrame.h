#pragma once
#include <string>
#include <list>



class AbstractFrame
{

public:

	virtual ~AbstractFrame();

	virtual bool is(std::string type);

	virtual bool is_primitive();

	virtual std::list<AbstractFrame*> get_frames(std::string slot);
};
