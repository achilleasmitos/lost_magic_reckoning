#include "main_character_race.h"

#include <iostream>

const std::vector<main_character_race::MCRace> main_character_race::AVAILABLE_MCRACES_LIST = {
	main_character_race::MCRace::DwarfHill,
	main_character_race::MCRace::DwarfMountain,
	main_character_race::MCRace::ElfHigh,
	main_character_race::MCRace::ElfWood,
	main_character_race::MCRace::Human,
	main_character_race::MCRace::Tiefling};

std::string main_character_race::MCRaceToString(main_character_race::MCRace player_race)
{
	switch (player_race)
	{
		case main_character_race::MCRace::DwarfHill:
			return "Hill Dwarf";
			break;
		case main_character_race::MCRace::DwarfMountain:
			return "Mountain Dwarf";
			break;
		case main_character_race::MCRace::ElfHigh:
			return "High Elf";
			break;
		case main_character_race::MCRace::ElfWood:
			return "Wood Elf";
			break;
		case main_character_race::MCRace::Human:
			return "Human";
			break;
		case main_character_race::MCRace::Tiefling:
			return "Tiefling";
			break;
		case main_character_race::MCRace::Undefined:
		default:
			return "Undefined";
	}
}

main_character_race::MCRace main_character_race::StringToMCRace(std::string player_race)
{
	if (player_race == "Hill Dwarf")
	{
		return main_character_race::MCRace::DwarfHill;
	}
	else if (player_race == "Mountain Dwarf")
	{
		return main_character_race::MCRace::DwarfMountain;
	}
	else if (player_race == "High Elf")
	{
		return main_character_race::MCRace::ElfHigh;
	}
	else if (player_race == "Wood Elf")
	{
		return main_character_race::MCRace::ElfWood;
	}
	else if (player_race == "Human")
	{
		return main_character_race::MCRace::Human;
	}
	else if (player_race == "Tiefling")
	{
		return main_character_race::MCRace::Tiefling;
	}
	else if (player_race == "Undefined")
	{
		return main_character_race::MCRace::Undefined;
	}
	else
	{
		std::cerr << "Race \"" << player_race
				  << "\" not recognized. Setting it to \"Undefined\".\n";
		return main_character_race::MCRace::Undefined;
	}
}

std::unique_ptr<MainCharacterRace> MainCharacterRace::CreateMainCharacterRace()
{
	return std::make_unique<MainCharacterRace>();
}

MainCharacterRace::MainCharacterRace()
	: m_race(main_character_race::MCRace::Undefined){};

main_character_race::MCRace MainCharacterRace::get_race() const
{
	return m_race;
};

void MainCharacterRace::set_race(std::string player_race)
{
	m_race = main_character_race::StringToMCRace(player_race);
};

MainCharacterRace::operator std::string()
{
	return (main_character_race::MCRaceToString(m_race));
};
