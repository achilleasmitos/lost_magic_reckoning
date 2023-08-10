#pragma once

#include "./main_character.h"
#include <memory>

using MainCharacterUniquePtr = std::unique_ptr<MainCharacter>;
using MainCharacterSharedPtr = std::shared_ptr<MainCharacter>;
using MainCharacterWeakPtr = std::weak_ptr<MainCharacter>;
