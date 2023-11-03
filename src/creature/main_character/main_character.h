#pragma once

#include "creature/creature.h"
#include "main_character_race_class/main_character_race_class.h"

#include <string>

class MainCharacter : public Creature
{
public:
	// Create a main character with default stats.
	MainCharacter(std::string name);
	// Create a main character with the given ability scores.
	MainCharacter(std::string name,
		int strength,
		int dexterity,
		int constitution,
		int intelligence,
		int wisdom,
		int charisma);
	// Create a main character with all the essential stats given.
	MainCharacter(std::string name,
		int hp,
		int ac,
		int speed,
		int strength,
		int dexterity,
		int constitution,
		int intelligence,
		int wisdom,
		int charisma,
		std::string creature_type);

	std::string get_name() const;
	void set_name(std::string name);

	MainCharacterClass get_class() const;
	void set_class(std::string player_class);

	MainCharacterRace get_race() const;
	void set_race(std::string player_race);

private:
	std::string m_name;
	MainCharacterRace m_race;
	MainCharacterClass m_class;
};
