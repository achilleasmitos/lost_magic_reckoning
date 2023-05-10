#include "../creature/creature.h"
#include "../creature/main_character/main_character.h"
#include <vector>

#pragma once
/**
 * @brief it starts a static battle between the main character with default stats and hes foes, they roll the dice and the one with the better roll wins, if the main character loses more times than his hp he loses the battle
 */
void Battle(MainCharacter* main_character, std::vector<Creature*>& foes);
