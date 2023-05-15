#include "save_game.h"
#include "../utils.h"
#include "../../creature/main_character/main_character.h"
#include <iostream>
#include <fstream>

void SaveGame(MainCharacter& main_characher)
{
	std::ofstream outputFile;

	outputFile.open("settings.txt");

	if (outputFile.is_open())
	{
		outputFile << "Ability Scores for: " << std::endl;
		outputFile << main_characher.get_name() << std::endl;
		outputFile << "==============================" << std::endl;
		outputFile << "HP: " << std::endl;
		outputFile << main_characher.get_hp() << std::endl;
		outputFile << "AC: " << std::endl;
		outputFile << main_characher.get_ac() << std::endl;
		outputFile << "Speed: " << std::endl;
		outputFile << main_characher.get_speed() << std::endl;
		outputFile << "Strength: " << std::endl;
		outputFile << main_characher.get_ability_score(0) << std::endl;
		outputFile << "Dexterity: " << std::endl;
		outputFile << main_characher.get_ability_score(1) << std::endl;
		outputFile << "Constitution: " << std::endl;
		outputFile << main_characher.get_ability_score(2) << std::endl;
		outputFile << "Intelligence: " << std::endl;
		outputFile << main_characher.get_ability_score(3) << std::endl;
		outputFile << "Wisdom: " << std::endl;
		outputFile << main_characher.get_ability_score(4) << std::endl;
		outputFile << "Charisma: " << std::endl;
		outputFile << main_characher.get_ability_score(5) << std::endl;
		outputFile << "==============================" << std::endl;
		outputFile << std::endl;
		outputFile << "Sound Volume: " << std::endl;
		outputFile << utils::g_sound_volume << std::endl;
		outputFile << "Text Size: " << std::endl;
		outputFile << utils::g_text_size << std::endl;
		outputFile << "Text Speed: " << std::endl;
		outputFile << utils::g_sleep_for_ms << std::endl;
		outputFile << "Text Weight: " << std::endl;
		outputFile << utils::g_text_weight << std::endl;

		outputFile.close();

		std::cout << "Game saved successfully to settings.txt" << std::endl;
	}
	else
	{
		std::cerr << "Unable to open file to settings.txt" << std::endl;
	}
}
