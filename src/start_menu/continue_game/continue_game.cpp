#include "continue_game.h"
#include "../../utils/utils.h"
#include "../../story/prologue.h"
#include <fstream>

void ContinueGame(MainCharacter& main_character)
{
	utils::Print({"Continuing the game..."});

	utils::ClearScreen();

	std::string file_path = "savefile.txt";

	std::ifstream file(file_path);

	LoadSavedGame(main_character);

	Prologue(main_character);
}
