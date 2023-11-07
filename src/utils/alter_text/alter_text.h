#pragma once

#include <string>

namespace utils
{

/**
 * @brief A function that capitalizes the first letter of a string.
 * This function does NOT alter the original string.
 */
std::string UppercasedFirstChar(std::string inputstring);

/**
 * @brief A function that replaces the every underscore of a sring to spaces.
 * This function does NOT alter the original string.
 */
std::string ReplaceUnderscoreWIthSpace(std::string inputstring);
} // namespace utils
