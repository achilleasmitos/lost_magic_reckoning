#include "load_game.h"
#include "../../creature/main_character/main_character.h"
#include "../utils.h"
#include <iostream>
#include <fstream>
#include <string>

// struct GameData
// {
// 	int hp;
// 	int ac;
// 	int speed;
// 	int strength;
// 	int dexterity;
// 	int constitution;
// 	int intelligence;
// 	int wisdom;
// 	int charisma;
// };

void LoadSavedGame(MainCharacter& main_character)
{
	std::ifstream in_file("savefile.txt");
	if (in_file.is_open())
	{
		std::string line;
		int lineCount = 0;
		int game_data[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};

		while (std::getline(in_file, line))
		{
			lineCount++;
			switch (lineCount)
			{
				case 5:
					game_data[0] = std::stoi(line);
					break;
				case 7:
					game_data[1] = std::stoi(line);
					break;
				case 9:
					game_data[2] = std::stoi(line);
					break;
				case 11:
					game_data[3] = std::stoi(line);
					break;
				case 13:
					game_data[4] = std::stoi(line);
					break;
				case 15:
					game_data[5] = std::stoi(line);
					break;
				case 17:
					game_data[6] = std::stoi(line);
					break;
				case 19:
					game_data[7] = std::stoi(line);
					break;
				case 21:
					game_data[8] = std::stoi(line);
					break;
			}
		}
		in_file.close();

		main_character.set_hp(game_data[0]);
		main_character.set_ac(game_data[1]);
		main_character.set_speed(game_data[2]);
		for (int i = 0; i < 6; i++)
		{
			main_character.set_ability_score(i, game_data[i]);
		}
	}
	else
	{
		std::cout << "Unable to open file." << std::endl;
		throw std::runtime_error("Unable to open file."); // Throw an exception to indicate the error
	}
}
void LoadSettings()
{
	std::ifstream in_file("savefile.txt");
	if (in_file.is_open())
	{
		std::string line;
		int lineCount = 0;

		while (std::getline(in_file, line))
		{
			lineCount++;
			switch (lineCount)
			{
				case 25:
					utils::g_sound_volume = std::stoi(line);
					break;
				case 27:
					utils::g_text_size = std::stoi(line);
					break;
				case 29:
					utils::g_sleep_for_ms = std::stoi(line);
					break;
				case 31:
					{
						int weight_choice = std::stoi(line);

						if (weight_choice == 100)
							utils::g_text_weight = utils::FontWeightValues::Light;
						else if (weight_choice == 200)
							utils::g_text_weight = utils::FontWeightValues::SemiLight;
						else if (weight_choice == 400)
							utils::g_text_weight = utils::FontWeightValues::Normal;
						else if (weight_choice == 600)
							utils::g_text_weight = utils::FontWeightValues::SemiBold;
						else if (weight_choice == 800)
							utils::g_text_weight = utils::FontWeightValues::Bold;
						break;
					}
			}
		}
		in_file.close();

		utils::CustomizeText();
	}
}
