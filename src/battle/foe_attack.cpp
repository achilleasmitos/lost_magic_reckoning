#include "foe_attack.h"
#include "main_character_attack.h"
#include "utils/utils.h"

#include <iostream>

void FoeAttack(Creature& attacker, MainCharacter& main_character)
{
	int hit_foe_roll = utils::RollDice(1, 20) + (attacker.get_ability_score(0) - 10) / 2;
	std::cout << utils::UppercasedFirstChar(attacker.get_display_name())
			  << " rolled " << hit_foe_roll << std::endl;

	if (hit_foe_roll >= main_character.get_ac())
	{
		std::cout << "The " << attacker.get_display_name()
				  << " has better roll than the AC of the main character! "
				  << utils::UppercasedFirstChar(attacker.get_display_name())
				  << " hits!" << std::endl;

		int damage_foe_roll =
			utils::RollDice(1, 10) + (attacker.get_ability_score(0) - 10) / 2;

		std::cout << utils::UppercasedFirstChar(attacker.get_display_name())
				  << " did " << damage_foe_roll
				  << " damage to the main character..." << std::endl;

		main_character.set_hp(main_character.get_hp() - damage_foe_roll);

		std::cout << "The main character's HP is now "
				  << main_character.get_hp() << std::endl;
	}
	else
	{
		std::cout << "The main character has better AC than the attack of the "
				  << attacker.get_display_name() << ", "
				  << attacker.get_display_name() << " misses!" << std::endl;
	}
}
