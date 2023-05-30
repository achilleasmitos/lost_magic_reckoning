#include "load_game.h"
#include "../utils.h"
#include "../../creature/main_character/main_character.h"
#include <iostream>
#include <fstream>
#include <string>

void LoadSavedGame(MainCharacter& main_character)
{
	std::ifstream file_name("savefile.txt");
	if (file_name.is_open())
	{
		std::string line;
		int lineCount = 0;
		std::string mc_race = "";
		std::string mc_class = "";
		int mc_hp = -1;
		int mc_ac = -1;
		int mc_speed = -1;
		int mc_ability_scores[] = {-1, -1, -1, -1, -1, -1};

		while (std::getline(file_name, line))
		{
			lineCount++;
			switch (lineCount)
			{
				case 5:
					mc_race = line;
					break;
				case 7:
					mc_class = line;
					break;
				case 9:
					mc_hp = std::stoi(line);
					break;
				case 11:
					mc_ac = std::stoi(line);
					break;
				case 13:
					mc_speed = std::stoi(line);
					break;
				case 15:
					mc_ability_scores[0] = std::stoi(line);
					break;
				case 17:
					mc_ability_scores[1] = std::stoi(line);
					break;
				case 19:
					mc_ability_scores[2] = std::stoi(line);
					break;
				case 21:
					mc_ability_scores[3] = std::stoi(line);
					break;
				case 23:
					mc_ability_scores[4] = std::stoi(line);
					break;
				case 25:
					mc_ability_scores[5] = std::stoi(line);
					break;
			}
		}
		file_name.close();

		main_character.set_race(mc_race);
		main_character.set_class(mc_class);
		main_character.set_hp(mc_hp);
		main_character.set_ac(mc_ac);
		main_character.set_speed(mc_speed);
		for (int i = 0; i < 6; i++)
		{
			main_character.set_ability_score(i, mc_ability_scores[i]);
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
	std::ifstream file_name("savefile.txt");
	if (file_name.is_open())
	{
		std::string line;
		int lineCount = 0;

		while (std::getline(file_name, line))
		{
			lineCount++;
			switch (lineCount)
			{
				case 29:
					utils::g_sound_volume = std::stoi(line);
					break;
				case 31:
					utils::g_text_size = std::stoi(line);
					break;
				case 33:
					utils::g_sleep_for_ms = std::stoi(line);
					break;
				case 35:
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
		file_name.close();

		utils::CustomizeText();
	}
}
