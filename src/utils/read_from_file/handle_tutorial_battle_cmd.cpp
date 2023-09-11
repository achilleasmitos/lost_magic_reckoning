#include "./handle_tutorial_battle_cmd.h"
#include "../JSON_interaction/JSON_interaction.h"
#include "../../battle/tutorial_battle.h"
#include "../../creature/creature.h"
#include "../../creature/creature_prototypes.h"

#include <iostream>
#include <memory>


void ExtractCreatureFromFile(std::string& foe_name, std::vector<CreatureSharedPtr>& foes);

void ReadToEndOfCmd(std::ifstream& source_file,
	std::string& text,
	const std::function<bool()>& cmd_begins_ends);

void utils::HandleTutorialBattleCmd(std::ifstream& source_file,
	std::string& text,
	const std::function<bool()>& cmd_begins_ends,
	MainCharacterSharedPtr main_character)
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
			<< "Invalid arguments provided for TUTORIALBATTLE command.\n"
			<< "The second argument should start with { on its own line.\n"
			<< "Aborting further reading of this command...\n";

		ReadToEndOfCmd(source_file, text, cmd_begins_ends);
		return;
	}

	// The foes to be passed into the `Battle()` func
	std::vector<CreatureSharedPtr> foes;

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
				<< "Aborting further reading of TUTORIALBATTLE command...\n";
			ReadToEndOfCmd(source_file, text, cmd_begins_ends);
			return;
		}
	}

	if (foes.empty())
	{
		std::cerr << "Tried to initiate TUTORIALBATTLE with no foes.\n"
				  << "Aborting further reading of TUTORIALBATTLE command...\n";
		ReadToEndOfCmd(source_file, text, cmd_begins_ends);
		return;
	}

	// Finished reading parameters, read to the end of the TUTORIALBATTLE command
	ReadToEndOfCmd(source_file, text, cmd_begins_ends);

	// Initiate the actual battle
	TutorialBattle(main_character, foes);

	return;
}
