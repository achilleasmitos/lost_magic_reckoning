#include "continue_game.h"
#include "../../utils/utils.h"
#include "../../story/prologue.h"

void ContinueGame(MainCharacter& main_character)
{
	utils::Print({"Continuing the game..."});

	utils::ClearScreen();

	Prologue(main_character);
}
