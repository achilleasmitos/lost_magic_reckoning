#include "handle_sound.h"
#include <iostream>
#include <algorithm>
#include <windows.h>

int utils::g_sound_volume = 500;
std::vector<std::string> utils::g_audio_list;

/**
 * @brief Helper function to be used in this file. It constructs and sends
 * the correct command to the supplied audio track in order to change its volume.
 *
 * @param audio_track The alias of the audio track to change the volume of,
 * as declared during the opening of the file.
 */
static void HandleTrackVolume(std::string audio_track)
{
	std::string command = "setaudio " + audio_track + " volume to " +
		std::to_string(utils::g_sound_volume);
	LPCTSTR change_volume_command = LPCTSTR(command.c_str());
	mciSendString(change_volume_command, NULL, 0, NULL);
}

void utils::HandleSoundVolume()
{
	if (!utils::g_audio_list.empty())
	{
		for (auto audio_track : utils::g_audio_list)
		{
			HandleTrackVolume(audio_track);
		}
	}
}

void utils::HandleSound(utils::SoundOperations operation)
{
	switch (operation)
	{
		case utils::SoundOperations::Close:
			{
				std::string command = "close all";
				LPCTSTR close_all_command = LPCTSTR(command.c_str());
				mciSendString(close_all_command, NULL, 0, NULL);

				utils::g_audio_list.clear();
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

				// Find and remove from the list of open tracks the one with this `alias`
				auto place =
					std::find(utils::g_audio_list.begin(), utils::g_audio_list.end(), alias);
				if (place == utils::g_audio_list.end())
				{
					std::cerr << "Couldn't find " << alias
							  << " in the list of open audio files..." << std::endl;
				}
				else
				{
					utils::g_audio_list.erase(place);
				}

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
				auto index =
					std::find(utils::g_audio_list.begin(), utils::g_audio_list.end(), alias);
				if (index != utils::g_audio_list.end())
				{
					break; // The file is already open, skip re-opening it.
				}

				// Construct a string for the desired command.
				std::string command =
					"open \"" + file_path + "\" type mpegvideo alias " + alias;
				// Make that string into a 'const char *' (=LPCTSTR).
				LPCTSTR open_command = LPCTSTR(command.c_str());
				// Use the LPCTSTR command in the mciSendString function.
				mciSendString(open_command, NULL, 0, NULL);

				// Add the new track to the list of open audio tracks, then adjust its volume.
				utils::g_audio_list.push_back(alias);
				HandleTrackVolume(alias);
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
