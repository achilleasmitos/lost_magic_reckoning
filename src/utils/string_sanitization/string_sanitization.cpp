#include "string_sanitization.h"

#include <iostream>

bool utils::CheckForAlphaOrWhitespace(std::string const string)
{
	bool has_invalid_char{false};

	for (const auto& character : string)
	{
		if (!(std::isalpha(character) || character == ' '))
		{
			has_invalid_char = true;
		}
	}

	return !has_invalid_char;
}
