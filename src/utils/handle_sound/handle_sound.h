#pragma once
#include <string>

namespace utils
{
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
