#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <chrono>

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
void print(std::initializer_list<std::string> list, int sleep_for_ms = 100)
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