#pragma once

#include <memory>

class MainCharacterClass;
using MainCharacterClassUniquePtr = std::unique_ptr<MainCharacterClass>;
using MainCharacterClassSharedPtr = std::shared_ptr<MainCharacterClass>;
using MainCharacterClassWeakPtr = std::weak_ptr<MainCharacterClass>;

class MainCharacterRace;
using MainCharacterRaceUniquePtr = std::unique_ptr<MainCharacterRace>;
using MainCharacterRaceSharedPtr = std::shared_ptr<MainCharacterRace>;
using MainCharacterRaceWeakPtr = std::weak_ptr<MainCharacterRace>;
