#include "print.h"
#include <iostream>
#include <thread>
#include <chrono>

int utils::g_sleep_for_ms = 50;

void utils::Print(std::vector<std::string> const& list, int sleep_for_ms)
{
	for (const auto string : list)
	{
		for (const auto character : string)
		{
			std::cout << character;
			std::this_thread::sleep_for(std::chrono::milliseconds(sleep_for_ms));
		}
	}
	std::cout << std::endl;
}
