#pragma once
#include "AbstractFrame.h"
#include "AbstractMark.h"

class Trigger
{
	AbstractFrame* frame;
	AbstractMark* mark;

public:

	Trigger(AbstractFrame* frame, AbstractMark* mark);

	AbstractFrame* get_frame() const;

	AbstractMark* get_mark() const;
	
};
