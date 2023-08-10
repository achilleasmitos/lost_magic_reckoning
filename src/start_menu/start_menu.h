#pragma once

#include "../creature/main_character/main_character.h"
#include "../creature/main_character/main_character_prototypes.h"

/**
 * @brief A function that takes you to the start menu of the gamne, where you can:
 * 1. Start the game
 * 2. Change the settings (text size, text weight etc)
 * 3. Quit the game
 */
void StartMenu(MainCharacterSharedPtr main_character);
