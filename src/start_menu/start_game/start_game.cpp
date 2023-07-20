#include "start_game.h"
#include "../../utils/utils.h"
#include "../../create_character/create_character.h"
#include "../../story/prologue.h"

void StartGame(MainCharacter& main_character)
{
	utils::Print({"Starting the game..."});

	utils::ClearScreen();

	std::cout << "Give me the time you want between each rendered "
				 "character (in ms): ";
	utils::GetUserInput(utils::g_sleep_for_ms);

	utils::ClearScreen();

	CreateCharacter(main_character);

	SaveGame(main_character);

	utils::ClearScreen();

	Prologue(main_character);
}
