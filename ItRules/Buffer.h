#pragma once
#include "ItRules.h"

class Buffer
{
	bool replaced = false;
	std::string content = "";
	std::string indentation;

	std::string indent(std::string text);

	bool is_string(ItRules::type text) const;
	bool is_date(ItRules::type text) const;
	bool is_int(ItRules::type text) const;
	std::string date_to_string(ItRules::type text) const;

public:

	Buffer(std::string indentation);
	void write(ItRules::type text);
	void write(Buffer* buffer);
	std::string get_content();
	void used();
	bool is_used() const;
};
