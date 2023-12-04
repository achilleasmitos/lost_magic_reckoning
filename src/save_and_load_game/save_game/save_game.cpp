#include "save_game.h"
#include "utils/utils.h"

#include <iostream>
#include <fstream>
#include <unordered_map>

void SaveGame(MainCharacter& main_character)
{
	std::unordered_map<std::string, std::string> game_state;

	// Main character stats
	/**
	 * IMPORTANT!!!
	 * Keep the keys defined here up-to-date with those in @see load_game.cpp
	 */
	game_state.insert({"mc_name", main_character.get_name()});
	game_state.insert({"mc_race", main_character.get_race()});
	game_state.insert({"mc_class", main_character.get_class()});
	game_state.insert({"mc_hp", std::to_string(main_character.get_hp())});
	game_state.insert({"mc_ac", std::to_string(main_character.get_ac())});
	game_state.insert({"mc_speed", std::to_string(main_character.get_speed())});

	std::string mc_ability_scores[] = {"mc_strength",
		"mc_dexterity",
		"mc_constitution",
		"mc_intelligence",
		"mc_wisdom",
		"mc_charisma"};
	int mc_ability_scores_length =
		sizeof(mc_ability_scores) / sizeof(mc_ability_scores[0]);
	for (int i = 0; i < mc_ability_scores_length; i++)
	{
		game_state.insert({mc_ability_scores[i],
			std::to_string(main_character.get_ability_score(i))});
	}

	// Game settings
	/**
	 * IMPORTANT!!!
	 * Keep the keys defined here up-to-date with those in @see load_game.cpp
	 */
	game_state.insert({"game_settings_sound_volume", std::to_string(utils::g_sound_volume)});
	game_state.insert({"game_settings_text_size", std::to_string(utils::g_text_size)});
	game_state.insert({"game_settings_sleep_for_ms", std::to_string(utils::g_sleep_for_ms)});
	game_state.insert({"game_settings_text_weight", std::to_string(utils::g_text_weight)});
	game_state.insert({"game_settings_text_face_name", utils::g_text_face_name});

	// Done creating the game_state map. Proceed with saving it to JSON.
	utils::WriteToJSON(game_state, "save_file.json");
}
