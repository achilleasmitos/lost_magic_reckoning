#include <iostream>
#include <time.h>
#include "./utils/utils.h"
#include "./utils/get_user_input/get_user_input.h"
#include "./utils/roll_dice/roll_dice.h"
#include "./start_menu/start_menu.h"
#include "./creature/creature.h"
#include "./creature/main_character/main_character.h"

int main()
{
	srand(time(NULL));

	utils::HandleSound(utils::SoundOperations::Open,
		"..\\src\\resources\\music\\boss_battle.mp3",
		"boss_battle");
	utils::HandleSound(utils::SoundOperations::Play, "boss_battle");

	while (start_menu::StartMenu() == 0)
	{
		std::cout << "Give me the time you want between each rendered "
					 "character (in ms): ";
		utils::GetUserInput(utils::g_sleep_for_ms);

		MainCharacter main_character("Traveler");

		std::string new_name;
		std::cout << "Give me a new name for your character: ";
		utils::GetUserInput(new_name);
		main_character.set_name(new_name);
		main_character.PrintStats();

		utils::HandleSound(utils::SoundOperations::Open,
			"..\\src\\resources\\music\\exploration.mp3",
			"exploration");
		utils::HandleSound(utils::SoundOperations::Play, "exploration repeat");

		std::cout << "Give me the name for another character: ";
		utils::GetUserInput(new_name);

		MainCharacter main_2(new_name, 15, 14, 7, 16, 13, 14);
		main_2.PrintStats();

		std::cout << "Give me the name for another character: ";
		utils::GetUserInput(new_name);

		utils::HandleSound(utils::SoundOperations::Close, "boss_battle");

		MainCharacter main_3(new_name, 12, 14, 35, 16, 14, 10, 8, 7, 12, "humanoid");
		main_3.PrintStats();

		utils::HandleSound(utils::SoundOperations::Close, "exploration");

		utils::Print({"This will ", "appear ", std::to_string(3), " times slower", "..."},
			3 * utils::g_sleep_for_ms);

		std::cout << "Rolling 3d6: " << utils::RollDice(3, 6) << std::endl;
		std::cout << "Rolling 3d6 + 2d10: " << utils::RollDice({"3d6", "2d10"})
				  << std::endl;
		std::cout << "Rolling with advantage: " << utils::RollWithAdvantage() << std::endl;
		std::cout << "Rolling with disadvantage: " << utils::RollWithDisadvantage()
				  << std::endl;

		system("pause");
	}
	return 0;
}