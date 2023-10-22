#include "prologue.h"
#include "battle/tutorial_battle.h"
#include "read_from_file/read_from_file.h"
#include "save_and_load_game/save_game/save_game.h"

#ifdef RELEASE_BUILD
std::string const PATH_TO_RESOURCES_STORY{"resources\\story\\"};
#else
std::string const PATH_TO_RESOURCES_STORY{"..\\src\\resources\\story\\"};
#endif

void Prologue(MainCharacter& main_character)
{
	ReadFromFile(PATH_TO_RESOURCES_STORY + "intro.txt", main_character);

	TutorialBattle();

	ReadFromFile(PATH_TO_RESOURCES_STORY + "forgotten_hero.txt", main_character);

	SaveGame(main_character);

	system("pause");
}
