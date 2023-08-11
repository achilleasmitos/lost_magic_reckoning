#pragma once

#include "../../creature/main_character/main_character.h"
#include "../../creature/main_character/main_character_prototypes.h"

#include <string>

namespace utils
{
/**
 * @brief This function reads from a supplied text file line-by-line and prints
 * to the console. It checks for certain types of reserved characters to
 * invoke different actions and exhibit the appropriate behavior for each one.
 *
 * @param file_path The path to the source file, relative to the main executable
 * @param main_character The main character variable
 */
void ReadFromFile(std::string file_path, MainCharacterSharedPtr main_character);
} // namespace utils
