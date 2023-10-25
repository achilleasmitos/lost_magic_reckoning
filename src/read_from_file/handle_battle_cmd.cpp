#include "handle_battle_cmd.h"
#include "utils/utils.h"
#include "battle/battle.h"
#include "creature/creature.h"

#include <iostream>
#include <memory>

/**
 * @brief Helper func for `HandleBattleCmd()` below.
 * It reads from the appropriate JSON file the stats of the creature
 * specified as `foe_name` and pushes it to the `foes` vector.
 */
static void ExtractCreatureFromFile(std::string& foe_name, std::vector<Creature>& foes)
{
	// The resources file with the stats of the supplied foe with foe_name
	const std::string file_path = "..\\src\\resources\\creatures\\" + foe_name + ".json";
	// Extract a map object with the values read from the JSON
	std::unordered_map<std::string, std::string> foe_stats_map =
		utils::ReadFromJSON(file_path);

	std::string foe_display_name = foe_name;

	for (size_t i = 0; i < foe_display_name.length(); i++)
	{
		if (foe_display_name[i] == '_')
		{
			foe_display_name[i] = ' ';
		}
	}

	// Create the foe creature to be added to the `foes` vector
	Creature foe(std::stoi(foe_stats_map["hp"]),
		std::stoi(foe_stats_map["ac"]),
		std::stoi(foe_stats_map["speed"]),
		std::stoi(foe_stats_map["strength"]),
		std::stoi(foe_stats_map["dexterity"]),
		std::stoi(foe_stats_map["constitution"]),
		std::stoi(foe_stats_map["intelligence"]),
		std::stoi(foe_stats_map["wisdom"]),
		std::stoi(foe_stats_map["charisma"]),
		foe_stats_map["creature_type"],
		foe_display_name);

	// Add the foe to the foes vector
	foes.push_back(foe);
}

/**
 * @brief Helper func for `HandleBattleCmd()` below.
 * It advances the reading of the open file to the end
 * of the command. Used in error handling.
 */
static void ReadToEndOfCmd(std::ifstream& source_file,
	std::string& text,
	const std::function<bool()>& cmd_begins_ends)
{
	while (std::getline(source_file, text))
	{
		if (cmd_begins_ends())
		{
			return;
		}
	}
}

void HandleBattleCmd(std::ifstream& source_file,
	std::string& text,
	const std::function<bool()>& cmd_begins_ends,
	MainCharacter& main_character)
{
	/**
	 * @brief Start reading the next lines and extract the Battle params
	 */

	std::getline(source_file, text);
	if (text != "MAIN_CHARACTER")
	{
		std::cerr << "Invalid arguments provided for BATTLE command.\n"
				  << "The first argument should be MAIN_CHARACTER.\n"
				  << "Aborting further reading of this command...\n";

		ReadToEndOfCmd(source_file, text, cmd_begins_ends);
		return;
	}

	std::getline(source_file, text);
	if (text != "{")
	{
		std::cerr
			<< "Invalid arguments provided for BATTLE command.\n"
			<< "The second argument should start with { on its own line.\n"
			<< "Aborting further reading of this command...\n";

		ReadToEndOfCmd(source_file, text, cmd_begins_ends);
		return;
	}

	// The foes to be passed into the `Battle()` func
	std::vector<Creature> foes;

	// Reading argument list for foes
	while (std::getline(source_file, text) && text != "}")
	{
		try
		{
			ExtractCreatureFromFile(text, foes);
		}
		catch (...)
		{
			std::cerr
				<< "Stats file for " << text << " could not be found or was corrupted...\n"
				<< "Please make sure you have spelled the name correctly\n"
				<< "in this command's arguments and the intended stats file.\n"
				<< "Aborting further reading of BATTLE command...\n";
			ReadToEndOfCmd(source_file, text, cmd_begins_ends);
			return;
		}
	}

	if (foes.empty())
	{
		std::cerr << "Tried to initiate BATTLE with no foes.\n"
				  << "Aborting further reading of BATTLE command...\n";
		ReadToEndOfCmd(source_file, text, cmd_begins_ends);
		return;
	}

	// Finished reading parameters, read to the end of the BATTLE command
	ReadToEndOfCmd(source_file, text, cmd_begins_ends);

	// Initiate the actual battle
	Battle(main_character, foes);

	return;
}
