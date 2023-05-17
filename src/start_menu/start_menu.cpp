#include "start_menu.h"
#include "./main_settings/main_settings.h"
#include "./start_game/start_game.h"
#include "../utils/utils.h"
#include <iostream>

void StartMenu()
{
	int main_menu_choice = 0;

	do
	{
		utils::ClearScreen();

		std::cout << "Please select an option:" << std::endl;
		std::cout << "1. Start Game" << std::endl;
		std::cout << "2. Settings" << std::endl;
		std::cout << "3. Quit" << std::endl;

		utils::GetUserInput(main_menu_choice);

		while (main_menu_choice < 1 || main_menu_choice > 3)
		{
			std::cout << "Invalid choice! Please choose again: " << std::endl;
			utils::GetUserInput(main_menu_choice);
		}

		switch (main_menu_choice)
		{
			case 1:
				{
					StartGame();
					break;
				}
			case 2:
				{
					MainSettings();
					break;
				}
			case 3:
				{
					std::cout << "Quitting the game..." << std::endl;
				}
		}
	}
	while (main_menu_choice != 3);
}
