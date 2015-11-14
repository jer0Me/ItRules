#pragma once
#include <string>

class Buffer
{
	bool replaced = false;
	std::string content = "";
	std::string indentation;

	std::string indent(std::string text);

public:

	Buffer(std::string indentation);
	void write(std::string);
	void write(Buffer* buffer);
	std::string get_content();
	void used();
	bool is_used();
};
