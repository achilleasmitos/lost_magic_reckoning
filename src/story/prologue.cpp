#include "./prologue.h"
#include "../utils/utils.h"
#include "../battle/tutorial_battle.h"
#include "../read_from_file/read_from_file.h"
#include "../save_and_load_game/save_game/save_game.h"

void Prologue(MainCharacter& main_character)
{
	utils::HandleSound(utils::SoundOperations::Open,
		"..\\src\\resources\\music\\exploration.mp3",
		"exploration");
	utils::HandleSound(utils::SoundOperations::Play, "exploration repeat");

	ReadFromFile("..\\src\\resources\\story\\intro.txt", main_character);

	TutorialBattle();

	ReadFromFile("..\\src\\resources\\story\\forgotten_hero.txt", main_character);

	utils::HandleSound(utils::SoundOperations::Close, "exploration");

	SaveGame(main_character);

	system("pause");
}
