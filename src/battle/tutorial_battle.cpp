#include "tutorial_battle.h"
#include "../utils/utils.h"
#include "foe_attack.h"
#include "main_character_attack.h"
#include <algorithm>
#include <iostream>
#include <vector>

void TutorialBattle(MainCharacterSharedPtr main_character,
	std::vector<CreatureSharedPtr>& foes)
{
	std::cout << "Battle starts!" << std::endl;
	utils::ClearScreen();

	std::cout
		<< "At the start of the battle all the characters involved will roll "
		   "for initiative, the character with the highest initiative score "
		   "goes first. The initiative score is a R20 + DEXTERITY modifier\n"
		<< std::endl;

	system("pause");
	std::cout << std::endl;

	// All the battle participants (including main character)
	// Contains pairs of type { foe/main_character, initiative_roll }
	std::vector<std::pair<CreatureSharedPtr, int>> combatants(foes.size() + 1,
		{foes[0], 0}); // Add +1 to accommodate for the main character

	/**
	 * Roll initiative for main_character and foes,
	 * and initialize the combatants list
	 */

	int main_character_initiative_roll =
		utils::RollDice(1, 20) + (main_character->get_ability_score(1) - 10) / 2;
	std::cout << "Main character rolled initiative "
			  << main_character_initiative_roll << std::endl;

	combatants[0] = {main_character, main_character_initiative_roll};

	for (size_t i = 0; i < foes.size(); ++i)
	{
		int foe_initiative_roll =
			utils::RollDice(1, 20) + (foes[i]->get_ability_score(1) - 10) / 2;
		std::cout << "Foe rolled initiative " << foe_initiative_roll << std::endl;

		combatants[i + 1] = {foes[i], foe_initiative_roll};
	}

	// Sort the combatants list in descending order of initiative rolls
	const auto compareCombatantsInitiative = [](std::pair<CreatureSharedPtr, int> a,
												 std::pair<CreatureSharedPtr, int> b) -> bool
	{
		if (a.second == b.second)
		{
			return (a.first->get_ability_score(1) > b.first->get_ability_score(1));
		}
		else
			return (a.second > b.second);
	};
	std::sort(combatants.begin(), combatants.end(), compareCombatantsInitiative);

	utils::ClearScreen();
	std::cout
		<< "When the attack order is determined the characters begin their "
		   "iniciative attacks, the attack roll is R20 + STRENGTH modifier. if "
		   "the attack it higher that the AC of the enemy the attack passes "
		   "and now you can roll for damage, the damage roll is usually R10 + "
		   "STRENGTH modifier\n"
		<< std::endl;

	system("pause");
	std::cout << std::endl;

	const auto printCombatants = [&combatants]()
	{
		std::cout << "=========================\n";
		for (const auto combatant : combatants)
		{
			std::cout << combatant.first->get_creature_type() << ": Initiative "
					  << combatant.second << " , HP "
					  << combatant.first->get_hp() << std::endl;
		}
		std::cout << "=========================\n";
	};
	printCombatants();
	std::cout << std::endl;

	// Battle loop
	while (main_character->get_hp() > 0 && combatants.size() > 1)
	{
		// Go down the initiative order (descending) one by one and act
		for (int i = 0; i < combatants.size(); ++i)
		{
			if (combatants[i].first == main_character)
			{
				std::cout << "Main character attacks!\n";

				MainCharacterAttack(main_character, foes[foes.size() - 1]);

				// Eliminate (erase) foes with 0 hp
				if (foes[foes.size() - 1]->get_hp() == 0)
				{
					std::cout << foes[foes.size() - 1]->get_creature_type()
							  << " has been eliminated!\n";
					for (int j = foes.size() - 1; j >= 0; j--)
					{
						if (foes[j]->get_hp() == 0)
						{
							foes.erase(foes.begin() + j);
						}
					}
					for (int j = combatants.size() - 1; j >= 0; j--)
					{
						if (combatants[j].first->get_hp() == 0)
						{
							combatants.erase(combatants.begin() + j);
						}
					}
				}
			}
			else
			{
				std::cout << combatants[i].first->get_creature_type() << " attacks!\n";

				FoeAttack(combatants[i].first, main_character);

				if (main_character->get_hp() == 0)
				{
					break; // Exit the Battle loop
				}
			}
		}

		utils::ClearScreen();
		printCombatants();
		std::cout << std::endl;
	}
}
