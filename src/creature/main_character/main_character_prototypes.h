#pragma once

#include <memory>

class MainCharacter;
using MainCharacterUniquePtr = std::unique_ptr<MainCharacter>;
using MainCharacterSharedPtr = std::shared_ptr<MainCharacter>;
using MainCharacterWeakPtr = std::weak_ptr<MainCharacter>;
