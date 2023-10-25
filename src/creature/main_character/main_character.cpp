#include "main_character.h"
#include "helpers/name_helpers.h"

#include <iostream>

MainCharacter::MainCharacter(std::string name)
	: m_race(MainCharacterRace()), m_class(MainCharacterClass())
{
	if (main_character_helpers::CheckForAlphaOrWhitespace(name))
	{
		m_name = name;
	}
}

MainCharacter::MainCharacter(std::string name,
	int strength,
	int dexterity,
	int constitution,
	int intelligence,
	int wisdom,
	int charisma)
	: Creature(strength, dexterity, constitution, intelligence, wisdom, charisma),
	  m_race(MainCharacterRace()), m_class(MainCharacterClass())
{
	if (main_character_helpers::CheckForAlphaOrWhitespace(name))
	{
		m_name = name;
	}
}

MainCharacter::MainCharacter(std::string name,
	int hp,
	int ac,
	int speed,
	int strength,
	int dexterity,
	int constitution,
	int intelligence,
	int wisdom,
	int charisma,
	std::string creature_type,
	std::string display_name)
	: Creature(hp, ac, speed, strength, dexterity, constitution, intelligence, wisdom, charisma, creature_type,display_name),
	  m_race(MainCharacterRace()), m_class(MainCharacterClass())
{
	if (main_character_helpers::CheckForAlphaOrWhitespace(name))
	{
		m_name = name;
	}
}

std::string MainCharacter::get_name() const { return m_name; }

void MainCharacter::set_name(std::string name)
{
	if (main_character_helpers::CheckForAlphaOrWhitespace(name))
	{
		m_name = name;
	}
}

MainCharacterClass MainCharacter::get_class() const { return m_class; }
void MainCharacter::set_class(std::string player_class)
{
	m_class.set_class(player_class);
}

MainCharacterRace MainCharacter::get_race() const { return m_race; }
void MainCharacter::set_race(std::string player_race)
{
	m_race.set_race(player_race);
}
