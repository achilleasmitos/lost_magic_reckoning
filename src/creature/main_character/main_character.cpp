#include "main_character.h"
#include "../../utils/utils.h"
#include <iostream>

MainCharacter::MainCharacter(std::string name)
	: m_race(MainCharacterRace()), m_class(MainCharacterClass())
{
	if (CheckForAlphaOrWhitespace(name))
	{
		m_name = name;
		utils::Print({"Welcome to the world, ", m_name, "!"});
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
	if (CheckForAlphaOrWhitespace(name))
	{
		m_name = name;
		utils::Print({"Welcome to the world, ", m_name, "!"});
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
	std::string creature_type)
	: Creature(hp, ac, speed, strength, dexterity, constitution, intelligence, wisdom, charisma, creature_type),
	  m_race(MainCharacterRace()), m_class(MainCharacterClass())
{
	if (CheckForAlphaOrWhitespace(name))
	{
		m_name = name;
		utils::Print({"Welcome to the world, ", m_name, "!"});
	}
}

std::string MainCharacter::get_name() const { return m_name; }

void MainCharacter::set_name(std::string name)
{
	if (CheckForAlphaOrWhitespace(name))
	{
		m_name = name;
		utils::Print({"Your new name is: ", m_name, "."});
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

bool MainCharacter::CheckForAlphaOrWhitespace(std::string string)
{
	bool has_digit = false;

	for (const auto character : string)
	{
		if (!(std::isalpha(character) || character == ' '))
		{
			has_digit = true;
		}
	}

	if (has_digit)
	{
		utils::Print(
			{"Sorry, your name can only contain letters and spaces..."});
		return false;
	}
	else
	{
		return true;
	}
}
