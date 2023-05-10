#include "battle.h"
#include "../utils/utils.h"
#include "../creature/creature.h"
#include "../creature/main_character/main_character.h"
#include <iostream>
#include <vector>

void Battle(MainCharacter* main_character, std::vector<Creature*>& foes)
{
	int victories = 0;
	int losses = 0;
	std::cout << "Battle starts!" << std::endl;

	main_character->PrintStats();

	for (const auto& foe : foes)
	{
		std::cout << "Stats for " << foe->get_creature_type() << ":" << std::endl;
		foe->PrintStats();

		int foe_roll = utils::RollDice(1, 20) + foe->get_ability_score(0);
		std::cout << "foe rolled" << foe_roll << std::endl;

		int main_character_roll =
			utils::RollDice(1, 20) + main_character->get_ability_score(0);
		std::cout << "main character rolled" << main_character_roll << std::endl;

		if (foe_roll > main_character_roll)
		{
			std::cout << "The " << foe->get_creature_type()
					  << " has better roll than the main character!,"
					  << foe->get_creature_type() << " wins!" << std::endl;
			losses++;
		}
		else
		{
			std::cout << "The main character has better roll than the "
					  << main_character->get_creature_type() << "! You win!"
					  << std::endl;
			victories++;
		}
	}

	std::cout << "Battle ends!" << std::endl;
	std::cout << "You won " << victories << " battles and lost " << losses
			  << "." << std::endl;

	if (losses <= main_character->get_hp())
	{
		std::cout << "You won the battle!" << std::endl;
	}
	else
	{
		std::cout << "You lost the battle!" << std::endl;
	}
}
