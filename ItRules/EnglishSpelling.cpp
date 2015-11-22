#include "EnglishSpelling.h"
#include <boost/algorithm/string.hpp>
#include <vector>

std::string EnglishSpelling::spell(int number)
{
	int n = number;

	return boost::trim_copy(words(n / 1000000, " million " + _and (n % 1000000)) +
		words((n % 1000000) / 1000, " thousand " + _and (n % 1000)) + words(n % 1000, ""));
}

std::string EnglishSpelling::words(int n, std::string ending)
{
	std::vector<std::string> first = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
		"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
	std::vector<std::string> ten_set = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
	return (n == 0) ? "" : ((n >= 100) ? first[n / 100] + " hundred" + _and (n % 100) : "") +
		(((n % 100) >= 20) ? ten_set[(n % 100) / 10] + " " + first[n % 10] : first[n % 20]) + ending;
}

std::string EnglishSpelling::_and(int number)
{
	return ((number > 0) && (number < 100)) ? " and " : "";
}
