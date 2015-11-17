#pragma once
#include "ItRules.h"

class Buffer
{
	bool replaced = false;
	std::string content = "";
	std::string indentation;

	std::string indent(std::string text);

	bool is_string(ItRules::type text);
	bool is_date(ItRules::type text);
	bool is_int(ItRules::type text);
	std::string date_to_string(ItRules::type text);

public:

	Buffer(std::string indentation);
	void write(ItRules::type text);
	void write(Buffer* buffer);
	std::string get_content();
	void used();
	bool is_used();
};
