#pragma once
#include <iostream>
#include <string>

void get_sanitized_string(std::string &string)
{
    if (std::cin.peek() == '\n')
    {
        std::cout << "Found new line character at the end, skipping it..." << std::endl;
        std::cin.ignore();
    }
    std::getline(std::cin, string);
}