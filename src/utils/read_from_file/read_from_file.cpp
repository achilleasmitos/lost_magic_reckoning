#include "read_from_file.h"
#include "handle_custom_speed_text_cmd.h"
#include "handle_sleep_for_cmd.h"
#include "handle_text_cmd.h"
#include "../print/print.h"
#include <iostream>
#include <fstream>

void utils::ReadFromFile(std::string file_path)
{
	// Open the source file.
	std::ifstream source_file(file_path);

	// A variable that stores the lines of the txt (one line per loop, see `std::getline`).
	std::string text;
	// A lambda function that checks the current line for a command beginning/end.
	auto cmd_begins_ends = [&text]() -> bool
	{ return (text.substr(0, 3) == "@@@"); };

	while (std::getline(source_file, text))
	{
		if (cmd_begins_ends())
		{
			// Remove the leading '@@@' from the new command's line
			text = text.substr(3);

			// Check the stored command against a list of known commands,
			// and call the appropriate function to handle it.
			if (text == "TEXT")
			{
				utils::HandleTextCmd(source_file, text, cmd_begins_ends);
			}
			else if (text == "CUSTOM_SPEED_TEXT")
			{
				utils::HandleCustomSpeedTextCmd(source_file, text, cmd_begins_ends);
			}
			else if (text == "SLEEP_FOR")
			{
				utils::HandleSleepForCmd(source_file, text);
			}
			else
			{
				std::cout << "I do not know this comand yet..." << std::endl;
				std::cout << "The command you tried to use is: " << text << std::endl;
			}
		}
	}

	source_file.close();
}
