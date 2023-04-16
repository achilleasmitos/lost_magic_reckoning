#include "utils.h"
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <cwchar>
#include <windows.h>

int utils::g_sleep_for_ms = 100;
int utils::g_text_size = 16;
utils::FontWeightValues utils::g_text_weight = utils::FontWeightValues::Normal;

void utils::get_sanitized_string(std::string& string)
{
	if (std::cin.peek() == '\n')
	{
		std::cout << "Found new line character at the end, skipping it..." << std::endl;
		std::cin.ignore();
	}
	std::getline(std::cin, string);
}

void utils::Print(std::initializer_list<std::string> list, int sleep_for_ms)
{
	for (auto string : list)
	{
		for (auto character : string)
		{
			std::cout << character;
			std::this_thread::sleep_for(std::chrono::milliseconds(sleep_for_ms));
		}
	}
	std::cout << std::endl;
}

void utils::CustomizeText(int font_size, utils::FontWeightValues font_weight, const wchar_t* face_name)
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0; // The index of the font in the system's console font table.
	cfi.dwFontSize.X = 0; // A COORD structure that contains the width and height of each character in the font.
	cfi.dwFontSize.Y = font_size; //   The X member contains the width, while the Y member contains the height.
	cfi.FontFamily = FF_DONTCARE; // The font pitch and family. See also TEXTMETRICA.
	cfi.FontWeight = font_weight; // The font weight. The weight can range from 100 to 1000, in multiples of 100.
	std::wcscpy(cfi.FaceName, face_name); // Copies the desired typeface over to FaceName.
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
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