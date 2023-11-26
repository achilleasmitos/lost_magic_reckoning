#include "battle.h"
#include "utils/utils.h"
#include "foe_attack.h"
#include "main_character_attack.h"

#include <algorithm>
#include <iostream>
#include <vector>

using CreatureWithInitiative = std::pair<Creature*, int>;
using Combatants = std::vector<CreatureWithInitiative>;

static void OnMainCharacterAttack(MainCharacter* main_character_ptr,
	int main_character_pos,
	Combatants& combatants)
{
	std::cout << "Main character attacks!\n";

	utils::Print({"Please choose your target from the available options."});
	std::vector<std::string> main_character_attack_options;
	main_character_attack_options.reserve(combatants.size() - 1);
	for (size_t iter = 0; iter < combatants.size(); iter++)
	{
		if (combatants[iter].first != main_character_ptr)
		{
			main_character_attack_options.push_back(utils::UppercasedFirstChar(
				combatants[iter].first->get_display_name()));
		}
	}
	int user_choice = utils::GetUserConstrainedChoice(main_character_attack_options);

	// Shift the user choice by one (so that main_character does not get selected as the target)
	if (user_choice <= main_character_pos)
	{
		user_choice--;
	}
	MainCharacterAttack(*main_character_ptr, *(combatants[user_choice].first));

	// Eliminate (erase) foes with 0 hp
	for (int i = combatants.size() - 1; i >= 0; i--)
	{
		if (combatants[i].first->get_hp() == 0)
		{
			std::cout << utils::UppercasedFirstChar(combatants[i].first->get_display_name())
					  << " has been eliminated!\n";
			combatants.erase(combatants.begin() + i);
		}
	}
}

static void OnFoeAttack(MainCharacter* main_character_ptr, Creature* foe)
{
	std::cout << utils::UppercasedFirstChar(foe->get_display_name()) << " attacks!\n";

	FoeAttack(*foe, *main_character_ptr);
}

void Battle(MainCharacter& main_character, std::vector<CreatureSharedPtr> const& foes)
{
	std::cout << "Battle starts!" << std::endl;

	MainCharacter* main_character_ptr = &main_character;

	// All the battle participants (including main character)
	// Contains pairs of type { foe/main_character, initiative_roll }
	Combatants combatants;
	combatants.reserve(foes.size() + 1); // Add +1 to accommodate for the main character

	/**
	 * Roll initiative for main_character and foes,
	 * and initialize the combatants list
	 */

	int dice_roll =
		utils::RollDice(1, 20) + (main_character_ptr->get_ability_score(1) - 10) / 2;
	std::cout << "Main character rolled initiative " << dice_roll << std::endl;

	combatants.push_back({main_character_ptr, dice_roll});

	for (size_t i = 0; i < foes.size(); ++i)
	{
		dice_roll = utils::RollDice(1, 20) + (foes[i]->get_ability_score(1) - 10) / 2;
		std::cout << "Foe rolled initiative " << dice_roll << std::endl;

		combatants.push_back({&(*foes[i]), dice_roll});
	}

	// Sort the combatants list in descending order of initiative rolls
	const auto compareCombatantsInitiative = [](CreatureWithInitiative a,
												 CreatureWithInitiative b) -> bool
	{
		if (a.second == b.second)
		{
			return (a.first->get_ability_score(1) > b.first->get_ability_score(1));
		}
		else
			return (a.second > b.second);
	};
	std::sort(combatants.begin(), combatants.end(), compareCombatantsInitiative);

	const auto printCombatants = [&combatants]()
	{
		std::cout << "=========================\n";
		for (const auto& combatant : combatants)
		{
			std::cout << utils::UppercasedFirstChar(combatant.first->get_display_name())
					  << ": Initiative " << combatant.second << " , HP "
					  << combatant.first->get_hp() << std::endl;
		}
		std::cout << "=========================\n";
	};
	printCombatants();
	std::cout << std::endl;

	// Battle loop
	while (main_character_ptr->get_hp() > 0 && combatants.size() > 1)
	{
		// Go down the initiative order (descending) one by one and act
		for (size_t i = 0; i < combatants.size(); ++i)
		{
			if (combatants[i].first == main_character_ptr)
			{
				OnMainCharacterAttack(main_character_ptr, i, combatants);
			}
			else
			{
				OnFoeAttack(main_character_ptr, combatants[i].first);

				if (main_character_ptr->get_hp() == 0)
				{
					break; // Exit the Battle loop
				}
			}
		}

		utils::ClearScreen();
		printCombatants();
		std::cout << std::endl;
	}

	std::cout << "Battle ends!" << std::endl;

	if (main_character_ptr->get_hp() > 0)
	{
		std::cout << "You won the battle!" << std::endl;
	}
	else
	{
		std::cout << "You lost the battle!" << std::endl;
	}
}
