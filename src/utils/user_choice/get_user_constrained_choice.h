#pragma once

#include <string>
#include <vector>

namespace utils
{
/**
 * @brief Prints a list of available options, and asks the user for a string
 * input. If the input matches one of the options, return the index (+1) of it,
 * otherwise print a guiding message, along with the options, and try again.
 *
 * Internally it uses GetUserInput, and should be preferred over it.
 *
 * @param expected_answers A list of answers to try and match the input against
 * @param use_strict_comparison If the comparison should ignore letter casing
 * @return The index of the matched option
 */
int GetUserConstrainedChoice(std::vector<std::string> const& expected_answers,
	bool use_strict_comparison = false);

/**
 * @brief Prints a list of available options, and asks the user for an integer
 * input. If the input matches one of the options, return the index (+1) of it,
 * otherwise print a guiding message, along with the options, and try again.
 *
 * Internally it uses GetUserInput, and should be preferred over it.
 *
 * @param expected_answers A list of answers to try and match the input against
 * @param use_strict_comparison If the comparison should ignore letter casing
 * @return The index of the matched option
 */
int GetUserConstrainedChoice(std::vector<int> const& expected_answers);
} // namespace utils
