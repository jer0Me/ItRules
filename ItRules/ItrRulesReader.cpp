#include "ItrRulesReader.h"
#include <sstream>
#include <fstream>

std::list<Rule*> ItrRulesReader::read(std::string path)
{
	std::fstream file;
	file.open(path, std::ios::in);
	if (file)
	{
		std::stringstream buffer;
		buffer << std::noskipws << file.rdbuf();
		file.close();
		return lexical_analyzer.analyze(buffer.str());
	}
	else
	{
		throw std::runtime_error(path + "file does not exist");
	}
}