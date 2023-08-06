#pragma once
#include <fstream>
#include <string>
#include <functional>

namespace utils
{
/**
 * @brief This function handles the case for the "TEXT" command from
 * `ReadFromFile()`. It simply reads the source file and prints it line-by-line
 * until the EOF is reached or the beginning/end of a command is found.
 *
 * @param source_file The currently open txt source file
 * @param text The variable that stores the lines of the txt
 * @param cmd_begins_ends A callback for when a new command begins or ends
 */
void HandleTextCmd(std::ifstream& source_file,
	std::string& text,
	const std::function<bool()>& cmd_begins_ends);
} // namespace utils
