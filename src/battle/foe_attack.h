#pragma once

#include "../creature/creature.h"
#include "../creature/creature_prototypes.h"
#include "../creature/main_character/main_character.h"
#include "../creature/main_character/main_character_prototypes.h"

/**
 * @brief it handles the hit and damage roll for the foe
 */
void FoeAttack(CreatureSharedPtr attacker, MainCharacterSharedPtr main_character);
