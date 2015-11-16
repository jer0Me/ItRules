#pragma once
#include "DelegateMark.h"
#include "FormatterStore.h"

class NonFormattingMark : public DelegateMark
{
	FormatterStore* formatter_store;

public:
	NonFormattingMark(AbstractMark* mark, FormatterStore* formatter_store);
	std::vector<std::string> get_options() override;
};
