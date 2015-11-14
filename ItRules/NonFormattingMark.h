#pragma once
#include "DelegateMark.h"

class NonFormattingMark : public DelegateMark
{
	AbstractMark* mark;
public:
	NonFormattingMark(AbstractMark* mark);
	
};
