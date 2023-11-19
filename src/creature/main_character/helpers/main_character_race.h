#pragma once

#include <memory>
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
	static std::unique_ptr<MainCharacterRace> CreateMainCharacterRace();
	MainCharacterRace();
	main_character_race::MCRace get_race() const;
	// Sets the proper MCRace enum to m_race, based on string input
	void set_race(std::string player_race);
	// Provide a string representation for MainCharacterRace
	operator std::string();

private:
	main_character_race::MCRace m_race;
};
