#pragma once

#include "creature/creature.h"
#include "helpers/helpers_prototypes.h"
#include "helpers/main_character_class.h"
#include "helpers/main_character_race.h"

#include <string>

class MainCharacter final : public Creature
{
public:
	// Handle the special member functions
	MainCharacter() = delete;
	MainCharacter(MainCharacter const& source) = delete;
	MainCharacter& operator=(MainCharacter const& source) = delete;
	MainCharacter(MainCharacter&& source) = delete;
	MainCharacter& operator=(MainCharacter&& source) = delete;
	~MainCharacter() = default;

	// Create a main character with default stats and the given name.
	// This is the only constructor we should need.
	MainCharacter(std::string name);

	// Reset all the member variables of this MainCharacter to their default
	// values. Calls Creature::ResetToDefault() internally.
	virtual void ResetToDefault() override;

	std::string get_name() const;
	void set_name(std::string name);

	std::string get_race() const;
	void set_race(std::string player_race);

	std::string get_class() const;
	void set_class(std::string player_class);

private:
	std::string m_name;
	MainCharacterRaceUniquePtr m_race;
	MainCharacterClassUniquePtr m_class;
};
