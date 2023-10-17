#include "name_helpers.h"

#include <iostream>

bool main_character_helpers::CheckForAlphaOrWhitespace(std::string string)
{
	bool has_invalid_char{false};

	for (const auto& character : string)
	{
		if (!(std::isalpha(character) || character == ' '))
		{
			has_invalid_char = true;
		}
	}

	if (has_invalid_char)
	{
		std::cout
			<< "Sorry, your name can only contain letters and spaces...\n\n";
	}

	return !has_invalid_char;
}
