#include "battle.h"
#include "../utils/utils.h"
#include "../creature/creature.h"
#include "../creature/main_character/main_character.h"
#include <iostream>

void Battle()
{
	std::cout << "Battle starts!" << std::endl;
	Creature Goblin(10, 14, 35, 16, 14, 10, 8, 7, 12, "Goblin");
	Goblin.PrintStats();
	MainCharacter main_character("Traveler");
	main_character.PrintStats();
	if (Goblin.GetHP() >= main_character.GetHP())
	{
		std::cout
			<< "The Goblin has more HP than the main character!, Goblin wins!"
			<< std::endl;
		}
	else if (Goblin.GetHP() < main_character.GetHP())
	{
		std::cout << "The main character has more HP than the Goblin! You win!"
				  << std::endl;
		std::cout << "Battle ends" << std::endl;
	}
}