#pragma once

#include "creature/creature.h"
#include "creature/main_character/main_character.h"
#include <vector>
#include <memory>

/**
 * @brief it starts a battle between the main character and his foes. They roll the dice for initiative, hit and damage. The damage is done to the HP of the enemy or the main character, and the first with 0 hp loses the battle.
 */
void Battle(MainCharacter& main_character, std::vector<Creature>& foes);
