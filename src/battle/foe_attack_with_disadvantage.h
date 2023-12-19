#pragma once

#include "creature/creature.h"
#include "creature/main_character/main_character.h"

/**
 * @brief it handles the hit and damage roll for the foe
 */
void FoeAttackWithDisadvantage(Creature& attacker, MainCharacter& main_character);
