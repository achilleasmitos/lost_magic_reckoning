#include "main_character_race_class.h"

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
			return "Dwarf (Hill)";
			break;
		case main_character_race::MCRace::DwarfMountain:
			return "Dwarf (Mountain)";
			break;
		case main_character_race::MCRace::ElfHigh:
			return "Elf (High)";
			break;
		case main_character_race::MCRace::ElfWood:
			return "Elf (Wood)";
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
	else
	{
		std::cerr << "Race \"" << player_race
				  << "\" not recognized. Setting it to \"Undefined\".\n";
		return main_character_race::MCRace::Undefined;
	}
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

const std::vector<main_character_class::MCClass> main_character_class::AVAILABLE_MCCLASSES_LIST = {
	main_character_class::MCClass::Barbarian,
	main_character_class::MCClass::Bard,
	main_character_class::MCClass::Cleric,
	main_character_class::MCClass::Druid,
	main_character_class::MCClass::Fighter,
	main_character_class::MCClass::Paladin,
	main_character_class::MCClass::Wizard};

std::string main_character_class::MCClassToString(main_character_class::MCClass player_class)
{
	switch (player_class)
	{
		case main_character_class::MCClass::Barbarian:
			return "Barbarian";
			break;
		case main_character_class::MCClass::Bard:
			return "Bard";
			break;
		case main_character_class::MCClass::Cleric:
			return "Cleric";
			break;
		case main_character_class::MCClass::Druid:
			return "Druid";
			break;
		case main_character_class::MCClass::Fighter:
			return "Fighter";
			break;
		case main_character_class::MCClass::Paladin:
			return "Paladin";
			break;
		case main_character_class::MCClass::Wizard:
			return "Wizard";
			break;
		case main_character_class::MCClass::Undefined:
		default:
			return "Undefined";
	}
}

main_character_class::MCClass main_character_class::StringToMCClass(std::string player_class)
{
	if (player_class == "Barbarian")
	{
		return main_character_class::MCClass::Barbarian;
	}
	else if (player_class == "Bard")
	{
		return main_character_class::MCClass::Bard;
	}
	else if (player_class == "Cleric")
	{
		return main_character_class::MCClass::Cleric;
	}
	else if (player_class == "Druid")
	{
		return main_character_class::MCClass::Druid;
	}
	else if (player_class == "Fighter")
	{
		return main_character_class::MCClass::Fighter;
	}
	else if (player_class == "Paladin")
	{
		return main_character_class::MCClass::Paladin;
	}
	else if (player_class == "Wizard")
	{
		return main_character_class::MCClass::Wizard;
	}
	else
	{
		std::cerr << "Class \"" << player_class
				  << "\" not recognized. Setting it to \"Undefined\".\n";
		return main_character_class::MCClass::Undefined;
	}
}

MainCharacterClass::MainCharacterClass()
	: m_class(main_character_class::MCClass::Undefined){};

main_character_class::MCClass MainCharacterClass::get_class() const
{
	return m_class;
};

void MainCharacterClass::set_class(std::string player_class)
{
	m_class = main_character_class::StringToMCClass(player_class);
};

MainCharacterClass::operator std::string()
{
	return (main_character_class::MCClassToString(m_class));
};
