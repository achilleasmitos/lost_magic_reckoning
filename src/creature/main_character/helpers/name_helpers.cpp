#include "name_helpers.h"

#include <iostream>

bool main_character_helpers::CheckForAlphaOrWhitespace(std::string string)
{
	bool has_digit = false;

	for (const auto character : string)
	{
		if (!(std::isalpha(character) || character == ' '))
		{
			has_digit = true;
		}
	}

	if (has_digit)
	{
		std::cout
			<< "Sorry, your name can only contain letters and spaces...\n";
		return false;
	}
	else
	{
		return true;
	}
}
