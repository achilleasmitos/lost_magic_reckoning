#include "start_menu.h"
#include "./continue_game/continue_game.h"
#include "./main_settings/main_settings.h"
#include "./start_game/start_game.h"
#include "../utils/utils.h"
#include <iostream>
#include <string>
#include <fstream>

void StartMenu(MainCharacterSharedPtr main_character)
{
	std::string file_path = "save_file.json";

	int main_menu_choice = 0;

	while (true)
	{
		std::ifstream savefile(file_path);

		if (savefile)
		{
			utils::ClearScreen();

			std::cout << "Please select an option:" << std::endl;
			std::cout << "1. Start Game" << std::endl;
			std::cout << "2. Continue Game" << std::endl;
			std::cout << "3. Settings" << std::endl;
			std::cout << "4. Quit" << std::endl;

			utils::GetUserInput(main_menu_choice);

			while (main_menu_choice < 1 || main_menu_choice > 4)
			{
				std::cout << "Invalid choice! Please choose again: " << std::endl;
				utils::GetUserInput(main_menu_choice);
			}

			switch (main_menu_choice)
			{
				case 1:
					{
						StartGame(main_character);
						break;
					}
				case 2:
					{
						ContinueGame(main_character);
						break;
					}
				case 3:
					{
						MainSettings();
						break;
					}
				case 4:
					{
						std::cout << "Quitting the game..." << std::endl;
						return;
					}
			}
		}
		else
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
						StartGame(main_character);
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
						return;
					}
			}
		}

		savefile.close(); // Close the opened save_file before doing another loop
	}
}
