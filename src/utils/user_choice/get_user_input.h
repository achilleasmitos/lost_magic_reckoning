#pragma once

#include <string>

namespace utils
{
/**
 * @brief Function to ask for the user's input, when this is inteded to be a string.
 * It checks the input for validity, and asks for it again if it's invalid.
 *
 * @param user_input The variable to store the user's input in (pass-by-reference)
 */
void GetUserInput(std::string& user_input);

/**
 * @brief Function to ask for the user's input, when this is inteded to be an integer.
 * It calls its overload for strings, then converts the input to integer before storing it
 * in the passed-in variable.
 *
 * @param user_input The variable to store the user's input in (pass-by-reference)
 */
void GetUserInput(int& user_input);
} // namespace utils
