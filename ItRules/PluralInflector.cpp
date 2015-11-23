#include "PluralInflector.h"
#include <iterator>
#include <boost/algorithm/string.hpp>
#include <boost/foreach.hpp>


PluralInflector::PluralInflector()
{
	
}

PluralInflector::~PluralInflector(){}

std::string PluralInflector::plural(std::string word)
{
	return "";
}

void PluralInflector::set_irregulars()
{
}

void PluralInflector::set_replaces()
{
}

void PluralInflector::add_replace(std::string from, std::string to)
{
	replaces.add_replace(from, to);
}

void PluralInflector::add_irregular(std::string from, std::string to)
{
	irregulars.insert(std::pair<std::string, std::string>(from, to));
}

std::vector<char> PluralInflector::consonants()
{
	std::string consonants = "bcdfghjklmnpqrstvwxyz";
	std::vector<char> vector_char;
	std::copy(consonants.begin(), consonants.end(), std::back_inserter(vector_char));
	return vector_char;
}

bool PluralInflector::is_irregular_plural(std::string word)
{
	return irregulars.find(word) != irregulars.end();
}

std::string PluralInflector::irregular_plural(std::string word)
{
	return irregulars.at(word);
}

std::string PluralInflector:: do_replaces(std::string word)
{
	typedef std::pair<ReplaceString, std::string> pair_replace;
	BOOST_FOREACH(pair_replace replace, replaces.get_replaces())
	{
		if (boost::ends_with(word, replace.first.get_replace())) return replace_last(word, replace.first.get_replace());
	}
	return word;
}

std::string PluralInflector::replace_last(std::string word, std::string ending)
{
	return remove_ending(word, ending) + replaces.at(ending);
}


std::string PluralInflector::remove_ending(std::string word, std::string ending)
{
	return word.substr(0, word.length() - ending.length());
}
