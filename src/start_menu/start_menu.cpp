#include "start_menu.h"
#include "utils/utils.h"
#include "continue_game/continue_game.h"
#include "main_settings/main_settings.h"
#include "start_game/start_game.h"
#include "save_and_load_game/save_game/save_game.h"

#include <iostream>
#include <string>
#include <fstream>

void StartMenu(MainCharacter& main_character)
{
	std::string file_path = "save_file.json";

	int main_menu_choice = 0;

	while (true)
	{
		std::ifstream savefile(file_path);

		if (savefile)
		{
			utils::ClearScreen();

			std::cout << "Please select an option from the main menu.\n";
			std::vector<std::string> main_menu_options_with_continue{
				"Start Game",
				"Continue Game",
				"Settings",
				"Quit"};
			main_menu_choice =
				utils::GetUserConstrainedChoice(main_menu_options_with_continue);

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
						SaveGame(main_character);
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

			std::cout << "Please select an option from the main menu.\n";
			std::vector<std::string> main_menu_options{"Start Game", "Settings", "Quit"};
			main_menu_choice = utils::GetUserConstrainedChoice(main_menu_options);

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
						SaveGame(main_character);
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
