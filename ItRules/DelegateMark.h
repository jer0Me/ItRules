#pragma once
#include "AbstractMark.h"

class DelegateMark : public AbstractMark
{
protected:
	AbstractMark* mark;

public:
	
	DelegateMark(AbstractMark* mark);

	std::string full_name() override;

	std::string get_name() override;

	std::string get_separator() override;

	bool is_multiple() override;

	std::vector<std::string> get_options() override;

	std::string get_indentation() override;

};
