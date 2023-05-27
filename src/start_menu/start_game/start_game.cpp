#include "start_game.h"
#include "../../utils/utils.h"
#include "../../story/prologue.h"

void StartGame(MainCharacter& main_character)
{
	utils::Print({"Starting the game..."});

	utils::ClearScreen();

	Prologue(main_character);
}
