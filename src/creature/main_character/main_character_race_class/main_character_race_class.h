#pragma once

#include <string>
#include <vector>

namespace main_character_race
{
enum MCRace
{
	Undefined = 0,
	DwarfHill,
	DwarfMountain,
	ElfHigh,
	ElfWood,
	Human,
	Tiefling,
};

// A vector containing all the MCRace enum values, excluding Undefined.
extern const std::vector<MCRace> AVAILABLE_MCRACES_LIST;

std::string MCRaceToString(MCRace player_race);
MCRace StringToMCRace(std::string player_race);
} // namespace main_character_race

class MainCharacterRace
{
public:
	MainCharacterRace();
	main_character_race::MCRace get_race() const;
	// Sets the proper MCRace enum to m_race, based on string input
	void set_race(std::string player_race);
	// Provide a string representation for MainCharacterRace
	operator std::string();

private:
	main_character_race::MCRace m_race;
};

namespace main_character_class
{
enum MCClass
{
	Undefined = 0,
	Barbarian,
	Bard,
	Cleric,
	Druid,
	Fighter,
	Paladin,
	Wizard,
};

// A vector containing all the MCClass enum values, excluding Undefined.
extern const std::vector<MCClass> AVAILABLE_MCCLASSES_LIST;

std::string MCClassToString(MCClass player_class);
MCClass StringToMCClass(std::string player_class);
} // namespace main_character_class

class MainCharacterClass
{
public:
	MainCharacterClass();
	main_character_class::MCClass get_class() const;
	// Sets the proper MCClass enum to m_class, based on string input
	void set_class(std::string player_class);
	// Provide a string representation for MainCharacterClass
	operator std::string();

private:
	main_character_class::MCClass m_class;
};
