#pragma once
#include <string>
#include "Token.h"

struct Literal : public Token
{
	std::string text;
};
