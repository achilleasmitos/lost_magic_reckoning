#pragma once

#include <fstream>
#include <functional>
#include <string>

/**
 * @brief This function handles the case for the "CUSTOM_SPEED_TEXT" command from
 * `ReadFromFile()`. It reads the next line after the command, extracts the text speed from it,
 * then continues reading the source file and prints it line-by-line using the text speed
 * until the EOF is reached or the beginning/end of a command is found.
 *
 * @param source_file The currently open txt source file
 * @param text The variable that stores the lines of the txt
 * @param cmd_begins_ends A callback for when a new command begins or ends
 */
void HandleCustomSpeedTextCmd(std::ifstream& source_file,
	std::string& text,
	const std::function<bool()>& cmd_begins_ends);
