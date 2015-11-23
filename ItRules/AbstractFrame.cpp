#include "AbstractFrame.h"

AbstractFrame::~AbstractFrame()
{
	
}


bool AbstractFrame::is(std::string type)
{
	return false;
}

bool AbstractFrame::is_primitive()
{
	return false;
}

std::list<AbstractFrame*> AbstractFrame::get_frames(std::string slot)
{
	std::list<AbstractFrame*> emptyList;
	return emptyList;
}

std::string AbstractFrame::to_string()
{
	return "";
}
