#pragma once

#include "../creature/main_character/main_character.h"
#include "../creature/main_character/main_character_prototypes.h"

/**
 * @brief Creates the main character of the game.
 * It first checks for existing save_file (and asks
 * for overwriting it), then asks for the base stats
 * of the MC (name, race, class). Finally, it rolls
 * the MC's ability scores.
 *
 * @param main_character
 */
void CreateCharacter(MainCharacterSharedPtr main_character);
