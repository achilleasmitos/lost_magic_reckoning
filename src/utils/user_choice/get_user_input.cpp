#include "get_user_input.h"
#include <iostream>

/**
 * @brief Helper function for GetUserInput. It removes all whitespace characters
 * from the start and end of the passed-in string.
 *
 * @param input The user input (pass-by-reference)
 */
static void TrimWhitespaceFromStartEnd(std::string& input)
{
	const std::string WHITESPACE = " \n\r\t\f\v";

	size_t start = input.find_first_not_of(WHITESPACE);
	if (start == std::string::npos)
	{
		// String consists of just whitespace
		input = "";
		return;
	}

	size_t end = input.find_last_not_of(WHITESPACE);
	if (end == std::string::npos)
	{
		// No trailing whitespace found
		input = input.substr(start);
		return;
	}

	input = input.substr(start, end + 1);
}

/**
 * @brief Helper function for GetUserInput. It checks that the passed-in string
 * is not empty, and that no character in it is undesired (i.e. not a number,
 * letter, space ' ', or dash '-').
 *
 * @param input The user input (pass-by-reference)
 * @return True, only if all checks passed
 */
static bool CheckInputValidity(std::string& input)
{
	// Check that the string is not empty
	if (input.length() == 0)
	{
		std::cout << "\nYour input cannot be empty. Please try again: ";
		return false;
	}

	// Check that only desired characters are present
	for (const auto character : input)
	{
		if (!(std::isalnum(character) || character == ' ' || character == '-'))
		{
			std::cout << "\nYour input was invalid. Please try again: ";
			return false;
		}
	}

	// All checks passed
	return true;
}

void utils::GetUserInput(std::string& user_input)
{
	// Sanitize the cin buffer
	if (std::cin.peek() == '\n')
	{
		std::cin.ignore();
	}

	bool is_input_valid{false};

	while (!is_input_valid)
	{
		// Get the input from the user
		std::getline(std::cin, user_input);

		// Discard whitespace characters from the start and end of string
		TrimWhitespaceFromStartEnd(user_input);

		// Check validity of input, ask for input again if it is invalid
		is_input_valid = CheckInputValidity(user_input);
	}
}

void utils::GetUserInput(int& user_input)
{
	bool can_get_digit{false};

	while (!can_get_digit)
	{
		// Get and process the input as string
		std::string str_user_input;
		utils::GetUserInput(str_user_input);

		try
		{
			// Convert it to integer
			can_get_digit = true;
			user_input = std::stoi(str_user_input);
		}
		catch (const std::exception& e)
		{
			can_get_digit = false;
			std::cerr << e.what() << '\n';
			std::cout << "\nCould not extract a number from your answer. "
						 "Please try again: ";
		}
	}
}
