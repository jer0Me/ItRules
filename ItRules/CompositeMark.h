#pragma once
#include <vector>
#include "DelegateMark.h"

class AbstractMark;

class CompositeMark : public DelegateMark
{
	std::vector<std::string> options;

public:
	CompositeMark(AbstractMark* mark, std::vector<std::string> options);
	
	std::vector<std::string> get_options() override;
};
