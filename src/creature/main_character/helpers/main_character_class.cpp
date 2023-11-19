#include "main_character_class.h"

#include <iostream>

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
	else if (player_class == "Undefined")
	{
		return main_character_class::MCClass::Undefined;
	}
	else
	{
		std::cerr << "Class \"" << player_class
				  << "\" not recognized. Setting it to \"Undefined\".\n";
		return main_character_class::MCClass::Undefined;
	}
}

std::unique_ptr<MainCharacterClass> MainCharacterClass::CreateMainCharacterClass()
{
	return std::make_unique<MainCharacterClass>();
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
