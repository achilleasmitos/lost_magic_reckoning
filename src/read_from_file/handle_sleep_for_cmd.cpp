#include "handle_sleep_for_cmd.h"

#include <chrono>
#include <iostream>
#include <thread>

void HandleSleepForCmd(std::ifstream& source_file, std::string& text)
{
	std::getline(source_file, text);

	int sleep_for_ms;

	try
	{
		sleep_for_ms = std::stoi(text);
		std::this_thread::sleep_for(std::chrono::milliseconds(sleep_for_ms));

		std::getline(source_file, text); // Read (and discard) the next line of "@@@"
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout
			<< "\nCould not extract a number of milliseconds to sleep for."
			<< std::endl;
	}
}
