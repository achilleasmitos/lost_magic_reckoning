#include "prologue.h"
#include "../utils/utils.h"
#include "../battle/battle.h"
#include "../creature/creature.h"
#include "../creature/main_character/main_character.h"

void Prologue(MainCharacter& main_character)
{
	utils::HandleSound(utils::SoundOperations::Open,
		"..\\src\\resources\\music\\exploration.mp3",
		"exploration");
	utils::HandleSound(utils::SoundOperations::Play, "exploration repeat");

	utils::ReadFromFile("..\\src\\resources\\story\\prologue.txt");

	utils::HandleSound(utils::SoundOperations::Close, "exploration");

	utils::HandleSound(utils::SoundOperations::Open,
		"..\\src\\resources\\music\\boss_battle.mp3",
		"boss_battle");
	utils::HandleSound(utils::SoundOperations::Play, "boss_battle repeat");

	main_character.PrintStats();

	SaveGame(main_character);

	Creature* minotaur1 =
		new Creature(76, 14, 40, 18, 11, 16, 6, 16, 9, "large monstrosity");
	Creature* minotaur2 =
		new Creature(76, 14, 40, 18, 11, 16, 6, 16, 9, "large monstrosity");

	std::vector<Creature*> foes = {minotaur1, minotaur2};

	Battle(&main_character, foes);

	delete minotaur1;
	delete minotaur2;

	utils::HandleSound(utils::SoundOperations::Close, "boss_battle");

	system("pause");
}
