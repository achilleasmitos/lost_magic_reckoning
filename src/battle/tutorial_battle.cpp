#include "tutorial_battle.h"
#include "../utils/utils.h"
#include <iostream>

void TutorialBattle()
{
	std::cout << "Battle starts!" << std::endl;
	utils::ClearScreen();

	std::cout
		<< "At the start of the battle all the characters involved will roll "
		   "for initiative.\nThe character with the highest initiative score "
		   "goes first.\nThe initiative score is a 1d20 + DEXTERITY modifier.\n"
		<< std::endl;

	system("pause");
	std::cout << std::endl;

	std::cout << "Main character rolled initiative 16" << std::endl;
	std::cout << "Foe rolled initiative 11" << std::endl;

	utils::ClearScreen();
	std::cout
		<< "When the attack order is determined, the characters begin their "
		   "initiative attacks.\nThe attack roll is 1d20 + STRENGTH modifier. "
		   "If the attack is higher than the AC of the enemy,\nthe attack "
		   "passes and now you can roll for damage. The damage roll is usually "
		   "1d10 + STRENGTH modifier.\n"
		<< std::endl;

	system("pause");
	std::cout << std::endl;

	std::cout << "=========================\n";
	std::cout << "Main character: Initiative 16 , HP 10\n";
	std::cout << "Minotaur: Initiative 11, HP 76\n";
	std::cout << "=========================\n";

	std::cout << std::endl;

	int tutorial_choice = 0;
	// Battle loop

	std::cout << "Please select the Attack option:" << std::endl;
	std::cout << "1. Attack" << std::endl;
	std::cout << "2. Dodge" << std::endl;
	std::cout << "3. Flee" << std::endl;

	utils::GetUserInput(tutorial_choice);
	std::cout << std::endl;
	while (tutorial_choice != 1)
	{
		std::cout << "Invalid choice! Please choose again: " << std::endl;
		utils::GetUserInput(tutorial_choice);
	}

	std::cout << "Main character attacks!" << std::endl;
	std::cout << "The main character rolled 17" << std::endl;
	std::cout << "The main character has better roll than the AC of the "
				 "Minotaur, main character hits!"
			  << std::endl;
	std::cout << "The main character did 6 damage to the Minotaur" << std::endl;
	std::cout << "The Minotaur's HP is now 70" << std::endl;
	std::cout << "Minotaur attacks!" << std::endl;
	std::cout << "Minotaur rolled 9" << std::endl;
	std::cout << "The main character has better AC than the attack of the "
				 "Minotaur, Minotaur misses!"
			  << std::endl;
	std::cout << std::endl;

	std::cout << "Please select the Attack option:" << std::endl;
	std::cout << "1. Attack" << std::endl;
	std::cout << "2. Dodge" << std::endl;
	std::cout << "3. Flee" << std::endl;

	utils::GetUserInput(tutorial_choice);
	std::cout << std::endl;
	while (tutorial_choice != 1)
	{
		std::cout << "Invalid choice! Please choose again: " << std::endl;
		utils::GetUserInput(tutorial_choice);
	}
	std::cout << "Main character attacks!" << std::endl;
	std::cout
		<< "The main character rolled 20, a critical hit! Your dice damage "
		   "roll will be doubled"
		<< std::endl;
	std::cout << "The main character has better roll than the AC of the "
				 "Minotaur, main character hits!"
			  << std::endl;
	std::cout << "The main character did 15 damage to the Minotaur" << std::endl;
	std::cout << "The Minotaur's HP is now 55" << std::endl;
	std::cout << "Minotaur attacks!" << std::endl;
	std::cout << "Minotaur rolled 16" << std::endl;
	std::cout << "The Minotaur has better roll than the AC of the "
				 "main character, Minotaur hits!"
			  << std::endl;
	std::cout << "The Minotaur did 8  damage to the main character" << std::endl;
	std::cout << "The main character's HP is now 2" << std::endl;
	std::cout << std::endl;

	std::cout << "Please select the dodge option:" << std::endl;
	std::cout << "1. Attack" << std::endl;
	std::cout << "2. Dodge" << std::endl;
	std::cout << "3. Flee" << std::endl;

	utils::GetUserInput(tutorial_choice);
	std::cout << std::endl;
	while (tutorial_choice != 2)
	{
		std::cout << "Invalid choice! Please choose again: " << std::endl;
		utils::GetUserInput(tutorial_choice);
	}

	std::cout << "Main character takes a dodge action! The enemy has "
				 "disadvantage on their next attack roll. "
			  << std::endl;
	std::cout << "Minotaur attacks!" << std::endl;
	std::cout << "Minotaur rolled 8" << std::endl;
	std::cout << "The main character has better AC than the attack of the "
				 "Minotaur, Minotaur misses!";
	std::cout << std::endl;

	std::cout << "Please select the flee option:" << std::endl;
	std::cout << "1. Attack" << std::endl;
	std::cout << "2. Dodge" << std::endl;
	std::cout << "3. Flee" << std::endl;

	utils::GetUserInput(tutorial_choice);
	std::cout << std::endl;
	while (tutorial_choice != 3)
	{
		std::cout << "Invalid choice! Please choose again: " << std::endl;
		utils::GetUserInput(tutorial_choice);
	}
	std::cout << "You look around to find an opening to flee, but find none in "
				 "this locked up arena."
			  << std::endl;
	std::cout << "Main character's flee fails!" << std::endl;
	std::cout << "Minotaur attacks!" << std::endl;
	std::cout << std::endl;
	utils::ClearScreen();
}
