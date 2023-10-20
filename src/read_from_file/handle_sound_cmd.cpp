#include "handle_sound_cmd.h"
#include "../utils/utils.h"

#include <iostream>

std::string const PATH_TO_RESOURCES_MUSIC = "..\\src\\resources\\music\\";

static void OnPlay(std::ifstream& source_file, std::string& text)
{
	// Read the filename
	std::getline(source_file, text);

	std::string file_path{PATH_TO_RESOURCES_MUSIC + text};
	utils::HandleSound(utils::SoundOperations::Open, file_path, text);
	utils::HandleSound(utils::SoundOperations::Play, text + " repeat");

	std::getline(source_file, text); // Read (and discard) the next line of "@@@"
}
static void OnPause(std::ifstream& source_file, std::string& text)
{
	// Read the filename
	std::getline(source_file, text);

	utils::HandleSound(utils::SoundOperations::Pause, text);

	std::getline(source_file, text); // Read (and discard) the next line of "@@@"
}
static void OnClose(std::ifstream& source_file, std::string& text)
{
	// Read the filename
	std::getline(source_file, text);

	utils::HandleSound(utils::SoundOperations::Close, text);

	std::getline(source_file, text); // Read (and discard) the next line of "@@@"
}

void HandleSoundCmd(std::ifstream& source_file, std::string& text)
{
	std::getline(source_file, text);

	if (text == "PLAY")
	{
		OnPlay(source_file, text);
	}
	else if (text == "PAUSE")
	{
		OnPause(source_file, text);
	}
	else if (text == "CLOSE")
	{
		OnClose(source_file, text);
	}
	else
	{
		std::cerr
			<< "Invalid arguments provided for SOUND command.\nArgument was "
			<< text << ".\n";
	}
}
