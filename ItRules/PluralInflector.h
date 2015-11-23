#pragma once
#include <string>
#include <map>
#include <vector>
#include "ReplacesMap.h"

class PluralInflector
{
	std::map<std::string, std::string> irregulars;
	ReplacesMap replaces;

	std::string replace_last(std::string word, std::string ending);
	std::string remove_ending(std::string word, std::string ending);
public:
	PluralInflector();
	virtual ~PluralInflector();
	virtual std::string plural(std::string word);
protected:
	void add_replace(std::string from, std::string to);
	
	void add_irregular(std::string from, std::string to);
	
	std::vector<char> consonants();
	
	bool is_irregular_plural(std::string word);
	
	std::string irregular_plural(std::string word);
	
	std::string do_replaces(std::string word);
	
	virtual void set_irregulars();
	
	virtual void set_replaces();
};
