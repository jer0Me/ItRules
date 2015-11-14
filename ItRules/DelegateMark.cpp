#include "DelegateMark.h"

DelegateMark::DelegateMark(AbstractMark* mark) : mark(mark) {}

std::string DelegateMark::full_name()
{
	return this->mark->full_name();
}

std::string DelegateMark::get_name()
{
	return this->mark->get_name();
}

std::string DelegateMark::get_separator()
{
	return this->mark->get_separator();
}

bool DelegateMark::is_multiple()
{
	return this->mark->is_multiple();
}

std::vector<std::string> DelegateMark::get_options()
{
	return this->mark->get_options();
}

std::string DelegateMark::get_indentation()
{
	return this->mark->get_indentation();
}



