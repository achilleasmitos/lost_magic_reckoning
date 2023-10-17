#pragma once

#include <fstream>
#include <string>

/**
 * @brief This function handles the "SLEEP_FOR" command from `ReadFromFile()`.
 * It reads the very next line after the command, tries to extract a number from
 * it, then sleeps for a number of milliseconds that this number describes.
 */
void HandleSleepForCmd(std::ifstream& source_file, std::string& text);
