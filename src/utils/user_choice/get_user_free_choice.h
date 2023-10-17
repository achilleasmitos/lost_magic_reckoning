#pragma once

#include <string>
#include <vector>

namespace utils
{
/**
 * @brief Ask the user for a string input.
 * Optionally, provide a list of expected answers. Return one of them
 * if the input matches it, otherwise return the user input unmodifed.
 *
 * Internally it uses GetUserInput, and should be preferred over it.
 *
 * @param user_choice The variable that will get modified as the return of the function
 * @param expected_answers (optional) A list of answers to try and match the input against
 */
void GetUserFreeChoice(std::string& user_choice,
	std::vector<std::string> const& expected_answers = {});

/**
 * @brief Ask the user for an integer input.
 * Optionally, provide a list of expected answers. Return one of them
 * if the input matches it, otherwise return the user input unmodifed.
 *
 * Internally it uses GetUserInput, and should be preferred over it.
 *
 * @param user_choice The variable that will get modified as the return of the function
 * @param expected_answers (optional) A list of answers to try and match the input against
 */
void GetUserFreeChoice(int& user_choice, std::vector<int> const& expected_answers = {});
} // namespace utils
