#include "../creature/creature.h"
#include "../creature/creature_prototypes.h"
#include "../creature/main_character/main_character.h"
#include "../creature/main_character/main_character_prototypes.h"
#include <vector>

#pragma once
/**
 * @brief it starts a battle between the main character and his foes. They roll the dice for initiative, hit and damage. The damage is done to the HP of the enemy or the main character, and the first with 0 hp loses the battle.
 */
void TutorialBattle(MainCharacterSharedPtr main_character,
	std::vector<CreatureSharedPtr>& foes);
