#pragma once
#include "WordSpelling.h"

class EnglishSpelling : public WordSpelling
{
	std::string words(int n, std::string ending);
	std::string _and(int number);
public:
	std::string spell(int number) override;

};
