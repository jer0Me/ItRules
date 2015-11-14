#pragma once
#include <string>
#include <vector>
#include "Token.h"

class AbstractMark : public Token
{
public:

	virtual ~AbstractMark();

	virtual std::string full_name();

	virtual std::string get_name();

	virtual std::string get_separator();

	virtual bool is_multiple();

	virtual std::vector<std::string> get_options();

	virtual std::string get_indentation();

	virtual std::string to_string();


};
