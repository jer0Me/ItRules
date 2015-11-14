#include "Buffer.h"
#include <algorithm>
Buffer::Buffer(std::string indentation)
{
	this->indentation = indentation;
}

void Buffer::write(std::string text)
{
	this->content += indent(text);
}

std::string Buffer::indent(std::string text)
{
	text += "~";
	std::string result = "";
	std::string character;
	std::string nextCharacter;
	std::string indentation;
	for (auto it = text.begin(); it != text.end() - 1; ++it)
	{
		character = *it;
		nextCharacter = *it + 1;
		indentation = ((character.compare("\n") == 0) && (nextCharacter.compare("\n") != 0)) ? this->indentation : "";
		result += character + indentation;
	}
	return result;
}

void Buffer::used()
{
	this->replaced = true;
}

bool Buffer::is_used()
{
	return this->replaced;
}

std::string Buffer::get_content()
{
	return this->content;
}

void Buffer::write(Buffer* buffer)
{
	write(buffer->get_content());
}

