#pragma once

#include <memory>

namespace main_character_class
{
class MainCharacterClass;
}
using MainCharacterClassUniquePtr =
	std::unique_ptr<main_character_class::MainCharacterClass>;
using MainCharacterClassSharedPtr =
	std::shared_ptr<main_character_class::MainCharacterClass>;
using MainCharacterClassWeakPtr = std::weak_ptr<main_character_class::MainCharacterClass>;

namespace main_character_race
{
class MainCharacterRace;
}
using MainCharacterRaceUniquePtr = std::unique_ptr<main_character_race::MainCharacterRace>;
using MainCharacterRaceSharedPtr = std::shared_ptr<main_character_race::MainCharacterRace>;
using MainCharacterRaceWeakPtr = std::weak_ptr<main_character_race::MainCharacterRace>;
