#pragma once
#include "Rule.h"
#include "LexicalAnalyzer.h"

class ItrRulesReader
{
	LexicalAnalyzer lexical_analyzer;
public:

	std::list<Rule*> read(std::string path);
};
