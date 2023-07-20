#include "print.h"
#include <iostream>
#include <thread>
#include <chrono>

int utils::g_sleep_for_ms = 50;

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
