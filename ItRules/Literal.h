﻿#pragma once
#include <string>
#include "Token.h"

class Literal : public Token
{
	std::string text;

public:
	Literal(std::string text);
	std::string getText();
};
