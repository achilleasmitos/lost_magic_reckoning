#include "start_menu.h"
#include "./main_settings/main_settings.h"
#include "../utils/utils.h"
#include <iostream>

int start_menu::StartMenu()
{
		int choice = -1;

	while (choice != 1)
	{
		std::cout << "Please select an option:" << std::endl;
		std::cout << "1. Start Game" << std::endl;
		std::cout << "2. Settings" << std::endl;
		std::cout << "3. Quit" << std::endl;

		utils::GetUserInput(choice);

		switch (choice)
		{
			case 1:
				{
					// code for starting the game
					std::cout << "Starting the game..." << std::endl;
					return 0;
				}
			case 2:
				{
					MainSettings(); // When called, it displays a list of available settings options and prompts the user to select one
					break;
				}
			case 3:
				{
					// code for quitting
					std::cout << "Quitting the game..." << std::endl;
					return 1;
					break;
				}
			default:
				{
					std::cout << "Invalid choice! Please choose again." << std::endl;
					break;
				}
		}
	}
	return -1;
}
