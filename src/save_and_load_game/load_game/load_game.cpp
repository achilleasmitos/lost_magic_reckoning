#include "load_game.h"
#include "utils/utils.h"

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using GameStateMap = std::unordered_map<std::string, std::string>;

/**
 * @brief Helper func for @see LoadGame. It updates the game values
 * (like global settings, main character stats etc) with the values
 * gotten from the game_state map.
 */
static void ConvertSaveToState(GameStateMap& game_state, MainCharacter& main_character)
{
	// Update the global variables from the derived game state
	/**
	 * IMPORTANT!!!
	 * Keep the keys defined here up-to-date with those in @see save_game.cpp
	 */
	utils::g_sound_volume = std::stoi(game_state["game_settings_sound_volume"]);
	utils::g_text_size = std::stoi(game_state["game_settings_text_size"]);
	utils::g_sleep_for_ms = std::stoi(game_state["game_settings_sleep_for_ms"]);
	const int text_weight = std::stoi(game_state["game_settings_text_weight"]);
	switch (text_weight)
	{
		case 100:
			{
				utils::g_text_weight = utils::FontWeightValues::Light;
				break;
			}
		case 200:
			{
				utils::g_text_weight = utils::FontWeightValues::SemiLight;
				break;
			}
		case 600:
			{
				utils::g_text_weight = utils::FontWeightValues::SemiBold;
				break;
			}
		case 800:
			{
				utils::g_text_weight = utils::FontWeightValues::Bold;
				break;
			}
		case 400:
		default:
			{
				utils::g_text_weight = utils::FontWeightValues::Normal;
			}
	}
	utils::g_text_face_name = game_state["game_settings_text_face_name"];

	// Enforce the new settings on the current game session
	utils::CustomizeText();

	// Update the main character stats from the derived game state
	/**
	 * IMPORTANT!!!
	 * Keep the keys defined here up-to-date with those in @see save_game.cpp
	 */
	main_character.set_name(game_state["mc_name"]);
	main_character.set_race(game_state["mc_race"]);
	main_character.set_class(game_state["mc_class"]);
	main_character.set_hp(std::stoi(game_state["mc_hp"]));
	main_character.set_ac(std::stoi(game_state["mc_ac"]));
	main_character.set_speed(std::stoi(game_state["mc_speed"]));

	std::string mc_ability_score_names[] = {"mc_strength",
		"mc_dexterity",
		"mc_constitution",
		"mc_intelligence",
		"mc_wisdom",
		"mc_charisma"};
	int mc_ability_scores_length =
		sizeof(mc_ability_score_names) / sizeof(mc_ability_score_names[0]);
	for (int i = 0; i < mc_ability_scores_length; i++)
	{
		main_character.set_ability_score(i,
			std::stoi(game_state[mc_ability_score_names[i]]));
	}
}

void LoadGame(MainCharacter& main_character)
{
	// Create the game_state map from the save file
	GameStateMap game_state = utils::ReadFromJSON("save_file.json");

	if (game_state.empty())
	{
		return; // Save file could not be loaded or was missing
	}

	try
	{
		ConvertSaveToState(game_state, main_character);
	}
	catch (...)
	{
		std::cerr << "Something went wrong while trying to convert the save "
					 "file to game state.\n"
				  << "Your save might be corrupted...\n";
	}
}
