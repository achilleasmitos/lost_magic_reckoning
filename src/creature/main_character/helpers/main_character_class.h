#pragma once

#include <memory>
#include <string>
#include <vector>

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
	static std::unique_ptr<MainCharacterClass> CreateMainCharacterClass();
	MainCharacterClass();
	main_character_class::MCClass get_class() const;
	// Sets the proper MCClass enum to m_class, based on string input
	void set_class(std::string player_class);
	// Provide a string representation for MainCharacterClass
	operator std::string();

private:
	main_character_class::MCClass m_class;
};
