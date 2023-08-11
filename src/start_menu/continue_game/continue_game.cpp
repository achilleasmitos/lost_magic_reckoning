#include "continue_game.h"
#include "../../utils/utils.h"
#include "../../story/prologue.h"

void ContinueGame(MainCharacterSharedPtr main_character)
{
	utils::Print({"Continuing the game..."});

	utils::ClearScreen();

	utils::LoadGame(main_character);

	Prologue(main_character);
}
