#include "start_game.h"
#include "../../utils/utils.h"
#include "../../story/prologue.h"

void StartGame()
{
	utils::Print({"Starting the game..."});

	utils::ClearScreen();

	Prologue();
}
