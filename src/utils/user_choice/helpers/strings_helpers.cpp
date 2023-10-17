#include "strings_helpers.h"

#include <iostream>

std::string user_choice_helpers::ToLowerCase(std::string const& input)
{
	std::string output{""};

	for (const auto& character : input)
	{
		try
		{
			output += static_cast<unsigned char>(
				std::tolower(static_cast<unsigned char>(character)));
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			output += character;
		}
	}

	return output;
}