#include "battle.h"
#include "utils/utils.h"
#include "foe_attack.h"
#include "foe_attack_with_disadvantage.h"
#include "main_character_attack.h"

#include <algorithm>
#include <iostream>
#include <vector>

void Battle(MainCharacter& main_character, std::vector<Creature>& foes)
{
	std::cout << "Battle starts!" << std::endl;

	MainCharacter* main_character_ptr = &main_character;
	std::vector<Creature*> foes_ptrs;
	for (size_t i = 0; i < foes.size(); i++)
	{
		foes_ptrs.push_back(&(foes[i]));
	}

	// All the battle participants (including main character)
	// Contains pairs of type { foe/main_character, initiative_roll }
	std::vector<std::pair<Creature*, int>> combatants(foes_ptrs.size() + 1,
		{foes_ptrs[0], 0}); // Add +1 to accommodate for the main character

	/**
	 * Roll initiative for main_character and foes,
	 * and initialize the combatants list
	 */

	int main_character_initiative_roll =
		utils::RollDice(1, 20) + (main_character_ptr->get_ability_score(1) - 10) / 2;
	std::cout << "Main character rolled initiative "
			  << main_character_initiative_roll << std::endl;

	combatants[0] = {main_character_ptr, main_character_initiative_roll};

	for (size_t i = 0; i < foes.size(); ++i)
	{
		int foe_initiative_roll =
			utils::RollDice(1, 20) + (foes_ptrs[i]->get_ability_score(1) - 10) / 2;
		std::cout << "Foe rolled initiative " << foe_initiative_roll << std::endl;

		combatants[i + 1] = {foes_ptrs[i], foe_initiative_roll};
	}

	// Sort the combatants list in descending order of initiative rolls
	const auto compareCombatantsInitiative = [](std::pair<Creature*, int> a,
												 std::pair<Creature*, int> b) -> bool
	{
		if (a.second == b.second)
		{
			return (a.first->get_ability_score(1) > b.first->get_ability_score(1));
		}
		else
			return (a.second > b.second);
	};
	std::sort(combatants.begin(), combatants.end(), compareCombatantsInitiative);

	int foes_i = 0;

	for (size_t i = 0; i < combatants.size(); i++)
	{
		if (combatants[i].first->get_display_name() != "main character")
		{
			foes_ptrs[foes_i] = combatants[i].first;
			foes_i++;
		}
	}

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

	int user_choice;
	bool dodge_action = false;
	bool flee = false;

	// Battle loop
	while (main_character_ptr->get_hp() > 0 && combatants.size() > 1 && flee == false)
	{
		// Go down the initiative order (descending) one by one and act
		for (size_t i = 0; i < combatants.size(); ++i)
		{
			if (combatants[i].first == main_character_ptr)
			{
				dodge_action = false;
				std::cout << "Main character attacks!\n";

				int battle_options_choice = 0;
				std::vector<std::string> battle_options{"Attack", "Dodge", "Flee"};

				// Ask for user input.
				utils::Print({"Please choose from the available options."});
				battle_options_choice = utils::GetUserConstrainedChoice(battle_options);

				switch (battle_options_choice)
				{
					// Attack option
					case 1:
						{
							utils::Print({"Please choose your target from the "
										  "available options."});
							int options_size = foes_ptrs.size();
							std::vector<std::string> main_character_attack_options(options_size,
								"");
							for (size_t iter = 0; iter < foes_ptrs.size(); iter++)
							{
								main_character_attack_options[iter] = utils::UppercasedFirstChar(
									foes_ptrs[iter]->get_display_name());
							}
							user_choice = utils::GetUserConstrainedChoice(
								main_character_attack_options);

							MainCharacterAttack(*main_character_ptr,
								*(foes_ptrs[user_choice - 1]));

							// Eliminate (erase) foes with 0 hp
							if (foes_ptrs[user_choice - 1]->get_hp() == 0)
							{
								std::cout
									<< utils::UppercasedFirstChar(
										   foes_ptrs[user_choice - 1]->get_display_name())
									<< " has been eliminated!\n";
								for (int j = foes_ptrs.size() - 1; j >= 0; j--)
								{
									if (foes_ptrs[j]->get_hp() == 0)
									{
										foes_ptrs.erase(foes_ptrs.begin() + j);
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
							break;
						}
					// Dodge option
					case 2:
						{
							std::cout << "You have taken the Dodge action." << std::endl;
							dodge_action = true;
							break;
						}
					// Flee option
					case 3:
						{
							int flee_roll = utils::RollDice(1, 20) +
								(main_character_ptr->get_ability_score(1) - 10) / 2;
							std::cout << "The main character rolled "
									  << flee_roll << std::endl;
							if (flee_roll >= 12)
							{
								flee = true;
							}
							else
							{
								std::cout << "Your attempt to flee has failed "
										  << std::endl;
							}
							break;
						}
				}
			}
			else
			{
				std::cout << utils::UppercasedFirstChar(
								 combatants[i].first->get_display_name())
						  << " attacks!\n";
				if (dodge_action == false)
				{
					FoeAttack(*combatants[i].first, *main_character_ptr);
				}
				else
				{
					FoeAttackWithDisadvantage(*combatants[i].first, *main_character_ptr);
				}

				if (main_character_ptr->get_hp() == 0)
				{
					break; // Exit the Battle loop
				}
			}
			if (flee == true)
			{
				break; // Exit the Battle loop if flee was successful
			}
		}

		utils::ClearScreen();
		printCombatants();
		std::cout << std::endl;
	}

	std::cout << "Battle ends!" << std::endl;
	if (flee == true)
	{
		std::cout << "You have fled the battle" << std::endl;
	}
	else
	{
		if (main_character_ptr->get_hp() > 0)
		{
			std::cout << "You won the battle!" << std::endl;
		}
		else
		{
			std::cout << "You lost the battle!" << std::endl;
		}
	}
}
