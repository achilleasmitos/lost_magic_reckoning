#include "handle_sound.h"
#include <iostream>
#include <windows.h>

void utils::HandleSound(utils::SoundOperations operation)
{
	switch (operation)
	{
		case utils::SoundOperations::Close:
			{
				std::string command = "close all";
				LPCTSTR close_all_command = LPCTSTR(command.c_str());
				mciSendString(close_all_command, NULL, 0, NULL);
				break;
			}
		default:
			{
				std::cerr << "'HandleSound' with one argument can only accept "
							 "'Close'..."
						  << std::endl;
			}
	}
}

void utils::HandleSound(utils::SoundOperations operation, std::string alias)
{
	switch (operation)
	{
		case utils::SoundOperations::Play:
			{
				std::string command = "play " + alias;
				LPCTSTR play_command = LPCTSTR(command.c_str());
				mciSendString(play_command, NULL, 0, NULL);
				break;
			}
		case utils::SoundOperations::Pause:
			{
				std::string command = "pause " + alias;
				LPCTSTR pause_command = LPCTSTR(command.c_str());
				mciSendString(pause_command, NULL, 0, NULL);
				break;
			}
		case utils::SoundOperations::Close:
			{
				std::string command = "close " + alias;
				LPCTSTR close_command = LPCTSTR(command.c_str());
				mciSendString(close_command, NULL, 0, NULL);
				break;
			}
		default:
			{
				std::cerr << "'HandleSound' with two arguments cannot accept "
							 "'Open'..."
						  << std::endl;
			}
	}
}

void utils::HandleSound(utils::SoundOperations operation, std::string file_path, std::string alias)
{
	switch (operation)
	{
		case utils::SoundOperations::Open: // Only the 'Open' case needs the file path
			{
				// Construct a string for the desired command.
				std::string command =
					"open \"" + file_path + "\" type mpegvideo alias " + alias;
				// Make that string into a 'const char *' (=LPCTSTR).
				LPCTSTR open_command = LPCTSTR(command.c_str());
				// Use the LPCTSTR command in the mciSendString function.
				mciSendString(open_command, NULL, 0, NULL);
				break;
			}
		case utils::SoundOperations::Play:
		case utils::SoundOperations::Pause:
		case utils::SoundOperations::Close:
			{
				utils::HandleSound(operation, alias); // Call the overload of this function for the rest operations.
				break;
			}
		default:
			{
				std::cerr << "Sorry, no such sound operation exists..." << std::endl;
			}
	}
}
