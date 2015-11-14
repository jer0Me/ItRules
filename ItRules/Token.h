#pragma once
#include <string>

class Token
{
protected:
	Token* previous;

public:
	virtual ~Token();
	void set_previous(Token* previous);
	Token* get_previous();
	virtual std::string to_string();
};
