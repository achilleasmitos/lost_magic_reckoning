#include "./create_character.h"
#include "../utils/utils.h"
#include "../creature/main_character/main_character_race_class/main_character_race_class.h"

#include <algorithm>
#include <string>
#include <fstream>

/**
 * @brief Helper function for @see CreateCharacter.
 * Checks if a save_file already exists, and if found
 * asks the player if they want it to be overwritten.
 *
 * @return true If the character creation should continue
 * @return false If the character creation should be aborted
 */
bool CheckAndOverwriteSaveFile()
{
	std::string save_file_path = "save_file.json";
	std::ifstream save_file(save_file_path);

	if (save_file.good())
	{
		utils::Print({"A save file with an already-created character has been "
					  "detected."});
		utils::Print({"Do you want to continue with the character creation and "
					  "overwrite it?"});

		std::vector<std::string> const yes_or_no{"Yes", "No"};
		int overwrite_character = utils::GetUserConstrainedChoice(yes_or_no, true);

		if (overwrite_character == 2)
		{
			return false;
		}
	}
	save_file.close();
	return true;
}

/**
 * @brief Helper function for @see CreateCharacter.
 * It receives the rolled stats for the main character
 * then asks the user where they want to place them
 * for their abilty scores.
 *
 * @param main_character The main character
 * @param ability_score_pos The index of the abilty score currently being placed
 * @param main_stats The stats that have been rolled
 * @param array_length The length of the array of stats still left to be placed
 */
void SetAbilityScore(MainCharacter& main_character, int ability_score_pos, std::vector<int>& main_stats)
{
	std::string ability_scores[6] = {"Strength", "Dexterity", "Consitution", "Intelligence", "Wisdom", "Charisma"};

	// Ask for user input.
	utils::Print({"Which stat would you like for your " +
		ability_scores[ability_score_pos] + "?"});
	int stat_choice = utils::GetUserConstrainedChoice(main_stats);
	main_character.set_ability_score(ability_score_pos, main_stats[stat_choice - 1]);

	main_stats.erase(main_stats.begin() + stat_choice - 1);
}

void CreateCharacter(MainCharacter& main_character)
{
	utils::Print({"You are about to create a new character."});

	if (!CheckAndOverwriteSaveFile())
	{
		return; // Exit CreateCharacter() without modifying the main character.
	}

	// Begin the actual character creation.
	std::string user_answer;
	int user_choice;

	utils::Print({"Please give me your name: "});
	utils::GetUserFreeChoice(user_answer);
	main_character.set_name(user_answer);

	utils::Print({"Please choose your race from the available options."});
	int options_size = main_character_race::AVAILABLE_MCRACES_LIST.size();
	std::vector<std::string> main_character_race_options(options_size, "");
	int iter = 0;
	for (const auto& mc_race : main_character_race::AVAILABLE_MCRACES_LIST)
	{
		main_character_race_options[iter] = main_character_race::MCRaceToString(mc_race);
		iter++;
	}
	user_choice = utils::GetUserConstrainedChoice(main_character_race_options);
	user_answer = main_character_race_options[user_choice - 1];
	main_character.set_race(user_answer);

	utils::Print({"Please choose your class from the available options."});
	options_size = main_character_class::AVAILABLE_MCCLASSES_LIST.size();
	std::vector<std::string> main_character_class_options(options_size, "");
	iter = 0;
	for (const auto& mc_class : main_character_class::AVAILABLE_MCCLASSES_LIST)
	{
		main_character_class_options[iter] =
			main_character_class::MCClassToString(mc_class);
		iter++;
	}
	user_choice = utils::GetUserConstrainedChoice(main_character_class_options);
	user_answer = main_character_class_options[user_choice - 1];
	main_character.set_class(user_answer);

	// Roll the main stats, ala 4d6-drop-lowest style.
	std::vector<int> main_stats(6, 0);
	for (int i = 0; i < 6; i++)
	{
		int rolls[4];
		int lowest_roll_pos = 0;
		int sum_of_rolls = 0;

		for (int j = 0; j < 4; j++)
		{
			rolls[j] = utils::RollDice({"1d6"});
			sum_of_rolls += rolls[j];

			if (rolls[j] < rolls[lowest_roll_pos])
			{
				lowest_roll_pos = j;
			}
		}

		sum_of_rolls -= rolls[lowest_roll_pos]; // Subtract the lowest roll (which has already been added before).

		main_stats[i] = sum_of_rolls;
	}

	std::cout << "You rolled: ";
	for (int i = 0; i < 5; i++)
	{
		std::cout << main_stats[i] << ", ";
	}
	std::cout << main_stats[5] << std::endl; // Special printing for the last abilty score.

	for (int ability_score_pos = 0; ability_score_pos < 6; ability_score_pos++)
	{
		SetAbilityScore(main_character, ability_score_pos, main_stats);
	}
}
