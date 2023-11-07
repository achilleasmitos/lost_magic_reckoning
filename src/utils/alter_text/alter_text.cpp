#include "alter_text.h"

#include <iostream>

std::string utils::UppercasedFirstChar(std::string input_string)
{
	input_string[0] = toupper(input_string[0]);
	return input_string;
}

std::string utils::ReplaceUnderscoreWIthSpace(std::string input_string)
{
	for (size_t i = 0; i < input_string.length(); i++)
	{
		if (input_string[i] == '_')
		{
			input_string[i] = ' ';
		}
	}
	return input_string;
}
