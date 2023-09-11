#include "./prologue.h"
#include "../utils/utils.h"
#include "../battle/battle.h"
#include "../battle/tutorial_battle.h"
#include "../creature/creature.h"

void Prologue(MainCharacterSharedPtr main_character)
{
	utils::HandleSound(utils::SoundOperations::Open,
		"..\\src\\resources\\music\\exploration.mp3",
		"exploration");
	utils::HandleSound(utils::SoundOperations::Play, "exploration repeat");

	utils::ReadFromFile("..\\src\\resources\\story\\prologue.txt", main_character);

	utils::HandleSound(utils::SoundOperations::Close, "exploration");

	utils::SaveGame(main_character);

	system("pause");
}
