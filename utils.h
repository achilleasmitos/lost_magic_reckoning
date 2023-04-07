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

    /**
     * @brief A function that changes the basic aesthetics of the text. This is only in a real cmd,
     * and should probably be changed when an (inevitable) switch to virtual terminal happens.
     * For now, it works as a proof of concept, and a starting point for further development.
     * Read more: https://learn.microsoft.com/en-us/windows/console/console-font-infoex?redirectedfrom=MSDN
     * @param font_size An integer indicating how large the font will be.
     * @param font_weight The weight of the font, one of: Light, SemiLight, Normal, SemiBold, Bold.
     * @param face_name A wchar_t string for the font typeface used.
     */
    void customize_text(int font_size = 16, FontWeightValues font_weight = Normal, const wchar_t *face_name = L"Courier")
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
}