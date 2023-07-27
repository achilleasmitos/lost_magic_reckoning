#include "main_character_attack.h"
#include "../utils/utils.h"
#include <iostream>

void MainCharacterAttack(MainCharacter* main_character, Creature* target)
{
	int hit_main_character_roll =
		utils::RollDice(1, 20) + (main_character->get_ability_score(0) - 10) / 2;
	std::cout << "The main character rolled " << hit_main_character_roll << std::endl;

	if (hit_main_character_roll >= target->get_ac())
	{
		std::cout << "The main character has better roll than the AC of the "
				  << target->get_creature_type() << ", main character hits!"
				  << std::endl;

		int damage_main_character_roll =
			utils::RollDice(1, 10) + (main_character->get_ability_score(0) - 10) / 2;

		std::cout << "The main character did " << damage_main_character_roll
				  << " to the " << target->get_creature_type() << std::endl;

		target->set_hp(target->get_hp() - damage_main_character_roll);

		std::cout << "The " << target->get_creature_type() << "'s HP is now "
				  << target->get_hp() << std::endl;
	}

	else
	{
		std::cout << "The " << target->get_creature_type() << " has better AC than the attack of the main character, main character misses!"
				  << std::endl;
	}
}
