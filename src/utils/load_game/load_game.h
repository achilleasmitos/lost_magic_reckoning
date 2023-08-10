#pragma once

#include "../../creature/main_character/main_character.h"
#include "../../creature/main_character/main_character_prototypes.h"
#include <iostream>

namespace utils
{
/**
 * @brief A function that saves character stats in a txt document
 */
void LoadGame(MainCharacterSharedPtr main_character);
} // namespace utils
