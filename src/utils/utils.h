#pragma once
#include <string>

namespace utils
{
// Number of milliseconds that the 'Print' function waits for in-between character prints.
extern int g_sleep_for_ms;
extern int g_text_size;

/**
 * @brief Function to print a list of strings to the console, pausing in-between characters.
 *
 * @param list A comma separated list of std::strings to std::cout
 * @param sleep_for_ms (optional) The amount of milliseconds to sleep between characters.
 */
void Print(std::initializer_list<std::string> list, int sleep_for_ms = g_sleep_for_ms);

enum FontWeightValues
{
	Light = 100,
	SemiLight = 200,
	Normal = 400,
	SemiBold = 600,
	Bold = 800
};

extern FontWeightValues g_text_weight;

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
void CustomizeText(int font_size = g_text_size,
	FontWeightValues font_weight = g_text_weight,
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
void HandleSound(SoundOperations operation);

/**
 * @brief An overload of the function with just two arguments, used in any operation other than 'Open'.
 * Read the description and implementation of the main function for more information.
 *
 * @param operation The operation to execute, one of: Play, Pause, Close.
 * @param alias An alias for this audio file. If you want to play on repeat, put: alias + ' repeat'.
 */
void HandleSound(SoundOperations operation, std::string alias);

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
void HandleSound(SoundOperations operation, std::string file_path, std::string alias);
} // namespace utils