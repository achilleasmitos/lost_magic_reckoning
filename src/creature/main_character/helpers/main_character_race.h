#pragma once

#include <memory>
#include <string>
#include <vector>

namespace main_character_race
{
extern std::vector<std::string> const AVAILABLE_RACES;

class MainCharacterRace
{
public:
	static std::unique_ptr<MainCharacterRace> CreateMainCharacterRace();

	MainCharacterRace();

	void ResetToDefault();

	std::string get_race() const;
	void set_race(std::string player_race);

	// Provide a string representation for MainCharacterRace
	operator std::string();

private:
	std::string m_race;
};
} // namespace main_character_race
