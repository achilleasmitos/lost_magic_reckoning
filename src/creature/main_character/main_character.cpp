#include "main_character.h"
#include "utils/utils.h"

#include <iostream>

MainCharacter::MainCharacter(std::string name)
	: m_race(main_character_race::MainCharacterRace::CreateMainCharacterRace()),
	  m_class(main_character_class::MainCharacterClass::CreateMainCharacterClass())
{
	if (utils::CheckForAlphaOrWhitespace(name))
	{
		m_name = name;
	}
	else
	{
		std::cout
			<< "Sorry, your name can only contain letters and spaces...\n\n";
		m_name = "Player";
	}
	m_display_name = "main character";
}

void MainCharacter::ResetToDefault()
{
	// Reset to defaults all member variables inherited from Creature
	this->Creature::ResetToDefault();

	// Reset to defaults all own member variables
	m_name = "Player";
	m_race->ResetToDefault();
	m_class->ResetToDefault();

	m_display_name = "main character";
}

std::string MainCharacter::get_name() const { return m_name; }
void MainCharacter::set_name(std::string name)
{
	if (utils::CheckForAlphaOrWhitespace(name))
	{
		m_name = name;
	}
	else
	{
		std::cout
			<< "Sorry, your name can only contain letters and spaces...\n\n";
		m_name = "Player";
	}
}

std::string MainCharacter::get_race() const { return (std::string)(*m_race); }
void MainCharacter::set_race(std::string player_race)
{
	m_race->set_race(player_race);
}

std::string MainCharacter::get_class() const { return (std::string)(*m_class); }
void MainCharacter::set_class(std::string player_class)
{
	m_class->set_class(player_class);
}
