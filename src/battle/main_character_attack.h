#pragma once

#include "../creature/creature.h"
#include "../creature/main_character/main_character.h"

/**
 * @brief it handles the hit and damage roll for the main character
 */
void MainCharacterAttack(MainCharacter& main_character, Creature& target);
