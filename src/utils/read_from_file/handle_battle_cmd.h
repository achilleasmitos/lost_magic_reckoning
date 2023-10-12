#pragma once

#include "../../creature/main_character/main_character.h"

#include <fstream>
#include <functional>
#include <string>

namespace utils
{
/**
 * @brief This function handles the "BATTLE" command from `ReadFromFile()`.
 * It reads the lines after the command, tries to extract the inputs to the
 * `Battle()` function, then invokes it with the supplied parameters.
 *
 * @param source_file The currently open txt source file
 * @param text The variable that stores the lines of the txt
 * @param cmd_begins_ends A callback for when a new command begins or ends
 * @param main_character The main character variable
 */
void HandleBattleCmd(std::ifstream& source_file,
	std::string& text,
	const std::function<bool()>& cmd_begins_ends,
	MainCharacter& main_character);
} // namespace utils
