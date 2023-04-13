#pragma once
#include <string>

namespace utils
{
// Number of milliseconds that the 'print' function waits for in-between character prints.
extern int sleep_for_ms;
extern int text_size;

/**
 * @brief Receives a string to modify with std::getline after any remaining new line characters have ben dropped out.
 *
 * @param string The string to modify via std::getline and std::cin.
 */
void get_sanitized_string(std::string& string);

/**
 * @brief Function to print a list of strings to the console, pausing in-between characters.
 *
 * @param list A list of std::strings to std::cout
 * @param sleep_for (optional) The amount of milliseconds to sleep between characters.
 */
void print(std::initializer_list<std::string> list, int sleep_for_ms = sleep_for_ms);

enum FontWeightValues
{
	Light = 100,
	SemiLight = 200,
	Normal = 400,
	SemiBold = 600,
	Bold = 800
};

extern FontWeightValues Font_value;

/**
 * @brief A function that changes the basic aesthetics of the text. This is only in a real cmd,
 * and should probably be changed when an (inevitable) switch to virtual terminal happens.
 * For now, it works as a proof of concept, and a starting point for further development.
 * Read more: https://learn.microsoft.com/en-us/windows/console/console-font-infoex?redirectedfrom=MSDN
 *
 * @param font_size An integer indicating how large the font will be.
 * @param font_weight The weight of the font, one of: Light, SemiLight, Normal, SemiBold, Bold.
 * @param face_name A wchar_t string for the font typeface used.
 */
void customize_text(int font_size = text_size,
	FontWeightValues font_weight = Font_value,
	const wchar_t* face_name = L"Courier");

enum SoundOperations
{
	Open = 0,
	Play = 1,
	Pause = 2,
	Close = 3
};

/**
 * @brief An overload of the function with just one argument, used to close all audio files.
 *
 * @param operation Only the 'Close' option can be specified for this overload.
 */
void handle_sound(SoundOperations operation);

/**
 * @brief An overload of the function with just two arguments, used in any operation other than 'Open'.
 * Read the description and implementation of the main function for more information.
 *
 * @param operation The operation to execute, one of: Play, Pause, Close.
 * @param alias An alias for this audio file. If you want to play on repeat, put: alias + ' repeat'.
 */
void handle_sound(SoundOperations operation, std::string alias);

/**
 * @brief A general function for handling the background music. It can open a sound file,
 * play it in repeat in the background, pause it, and close it.
 * This function can concurrently play many different audio files. By giving an alias to each one,
 * we can do operations on any of them any time we want.
 *
 * @param operation The operation to execute, one of: Open, Play, Pause, Close.
 * @param file_path A string of type '..\\resources\\music\\file.mp3' that is the path to the audio file.
 * @param alias An alias for this particular audio file. See the description.
 */
void handle_sound(SoundOperations operation, std::string file_path, std::string alias);
} // namespace utils