#include "continue_game.h"
#include "utils/utils.h"
#include "save_and_load_game/load_game/load_game.h"
#include "story/prologue.h"

void ContinueGame(MainCharacter& main_character)
{
	utils::Print({"Continuing the game..."});

	utils::ClearScreen();

	LoadGame(main_character);

	Prologue(main_character);
}
