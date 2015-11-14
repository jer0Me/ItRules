#include "Trigger.h"

Trigger::Trigger(AbstractFrame* frame, AbstractMark* mark)
{
	this->frame = frame;
	this->mark = mark;
}


AbstractFrame* Trigger::get_frame() const
{
	return this->frame;
}

AbstractMark* Trigger::get_mark() const
{
	return this->mark;
}

