#include "alter_text.h"

#include <iostream>

std::string utils::UppercasedFirstChar(std::string inputstring)
{
	inputstring[0] = toupper(inputstring[0]);
	return inputstring;
}

std::string utils::ReplaceUnderscoreWIthSpace(std::string inputstring)
{
	for (size_t i = 0; i < inputstring.length(); i++)
	{
		if (inputstring[i] == '_')
		{
			inputstring[i] = ' ';
		}
	}
	return inputstring;
}
