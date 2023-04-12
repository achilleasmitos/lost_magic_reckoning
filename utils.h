#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <cwchar>
#include <windows.h>

namespace utils
{
    // Number of milliseconds that the 'print' function waits for in-between character prints.
    int sleep_for_ms = 100;
    int text_size=16;
    
    /**
     * @brief Receives a string to modify with std::getline after any remaining new line characters have ben dropped out.
     *
     * @param string The string to modify via std::getline and std::cin.
     */
    void get_sanitized_string(std::string &string)
    {
        if (std::cin.peek() == '\n')
        {
            std::cout << "Found new line character at the end, skipping it..." << std::endl;
            std::cin.ignore();
        }
        std::getline(std::cin, string);
    }

    /**
     * @brief Function to print a list of strings to the console, pausing in-between characters.
     *
     * @param list A list of std::strings to std::cout
     * @param sleep_for_ms (optional) The amount of milliseconds to sleep between characters.
     */
    void print(std::initializer_list<std::string> list, int sleep_for_ms = sleep_for_ms)
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

    enum FontWeightValues
    {
        Light = 100,
        SemiLight = 200,
        Normal = 400,
        SemiBold = 600,
        Bold = 800
    };
    enum FontWeightValues Font_value=Normal;
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
    void customize_text(int font_size = text_size, FontWeightValues font_weight = Font_value, const wchar_t *face_name = L"Courier")
    {
        CONSOLE_FONT_INFOEX cfi;
        cfi.cbSize = sizeof(cfi);
        cfi.nFont = 0;                        // The index of the font in the system's console font table.
        cfi.dwFontSize.X = 0;                 // A COORD structure that contains the width and height of each character in the font.
        cfi.dwFontSize.Y = font_size;         //   The X member contains the width, while the Y member contains the height.
        cfi.FontFamily = FF_DONTCARE;         // The font pitch and family. See also TEXTMETRICA.
        cfi.FontWeight = font_weight;         // The font weight. The weight can range from 100 to 1000, in multiples of 100.
        std::wcscpy(cfi.FaceName, face_name); // Copies the desired typeface over to FaceName.
        SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    }

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
    void handle_sound(SoundOperations operation)
    {
        switch (operation)
        {
        case Close:
        {
            std::string command = "close all";
            LPCTSTR close_all_command = LPCTSTR(command.c_str());
            mciSendString(close_all_command, NULL, 0, NULL);
            break;
        }
        default:
        {
            std::cerr << "'handle_sound' with one argument can only accept 'Close'..." << std::endl;
        }
        }
    }

    /**
     * @brief An overload of the function with just two arguments, used in any operation other than 'Open'.
     * Read the description and implementation of the main function for more information.
     *
     * @param operation The operation to execute, one of: Play, Pause, Close.
     * @param alias An alias for this audio file. If you want to play on repeat, put: alias + ' repeat'.
     */
    void handle_sound(SoundOperations operation, std::string alias)
    {
        switch (operation)
        {
        case Play:
        {
            std::string command = "play " + alias;
            LPCTSTR play_command = LPCTSTR(command.c_str());
            mciSendString(play_command, NULL, 0, NULL);
            break;
        }
        case Pause:
        {
            std::string command = "pause " + alias;
            LPCTSTR pause_command = LPCTSTR(command.c_str());
            mciSendString(pause_command, NULL, 0, NULL);
            break;
        }
        case Close:
        {
            std::string command = "close " + alias;
            LPCTSTR close_command = LPCTSTR(command.c_str());
            mciSendString(close_command, NULL, 0, NULL);
            break;
        }
        default:
        {
            std::cerr << "'handle_sound' with two arguments cannot accept 'Open'..." << std::endl;
        }
        }
    }

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
    void handle_sound(SoundOperations operation, std::string file_path, std::string alias)
    {
        switch (operation)
        {
        case Open: // Only the 'Open' case needs the file path
        {
            // Construct a string for the desired command.
            std::string command = "open \"" + file_path + "\" type mpegvideo alias " + alias;
            // Make that string into a 'const char *' (=LPCTSTR).
            LPCTSTR open_command = LPCTSTR(command.c_str());
            // Use the LPCTSTR command in the mciSendString function.
            mciSendString(open_command, NULL, 0, NULL);
            break;
        }
        case Play:
        case Pause:
        case Close:
        {
            handle_sound(operation, alias); // Call the overload of this function for the rest operations.
            break;
        }
        default:
        {
            std::cerr << "Sorry, no such sound operation exists..." << std::endl;
        }
        }
    }
}