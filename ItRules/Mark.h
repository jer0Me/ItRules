#pragma once
#include <string>
#include <vector>
#include "AbstractMark.h"

class Mark : public AbstractMark
{
	std::string name;
	std::vector<std::string> options;
	std::string separator = "";

	std::string options_text();
	std::string indent_of(Token* token);
	std::string text_of(Token* token);
	bool is_literal(Token* token);
	std::string extract_indent(std::string text);

public:
	Mark(std::string name);
	Mark(std::string name, std::vector<std::string> options, std::string separator);
	Mark(std::string name, std::vector<std::string> options);

	std::string full_name() override;

	std::string get_name() override;

	std::string get_separator() override;

	bool is_multiple() override;

	std::vector<std::string> get_options() override;

	std::string get_indentation() override;

	std::string to_string() override;

};
