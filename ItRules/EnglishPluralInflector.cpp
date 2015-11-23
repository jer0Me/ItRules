#include "EnglishPluralInflector.h"
#include <boost/foreach.hpp>


EnglishPluralInflector::EnglishPluralInflector()
{
	EnglishPluralInflector::set_replaces();
	EnglishPluralInflector::set_irregulars();
}

std::string EnglishPluralInflector::plural(std::string word)
{
	if (is_irregular_plural(word)) return irregular_plural(word);
	return do_replaces(word + "s");
}

void EnglishPluralInflector::set_replaces()
{

	add_replace("sss", "sses");
	add_replace("siss", "ses");
	add_replace("ss", "ses");
	add_replace("shs", "shes");
	add_replace("chs", "ches");
	add_replace("xs", "xes");
	add_replace("zzs", "zzes");
	add_replace("zs", "zzes");
	add_replace("fes", "ves");
	add_replace("fs", "ves");
	set_consonant_y_replaces();
}

void EnglishPluralInflector::set_irregulars()
{
	add_irregular("man", "men");
	add_irregular("woman", "women");
	add_irregular("child", "children");
	add_irregular("foot", "feet");
	add_irregular("tooth", "teeth");
	add_irregular("goose", "geese");
	add_irregular("mouse", "mice");
	add_irregular("sheep", "sheep");
	add_irregular("deer", "deer");
	add_irregular("moose", "moose");
	add_irregular("aircraft", "aircraft");
	add_irregular("potato", "potatoes");
	add_irregular("tomato", "tomatoes");
	add_irregular("echo", "echoes");
	add_irregular("hero", "heroes");
	add_irregular("torpedo", "torpedoes");
	add_irregular("buffalo", "buffaloes");
}

void EnglishPluralInflector::set_consonant_y_replaces()
{
	std::string from = "";
	std::string to = "";
	BOOST_FOREACH(char consonant, consonants())
	{
		from.append(1u, consonant);
		from += "ys";
		to.append(1u, consonant);
		to += "ies";
		add_replace(from, to);
		from = "";
		to = "";
	}
}
