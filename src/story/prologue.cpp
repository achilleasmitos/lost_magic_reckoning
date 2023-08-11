#include "./prologue.h"
#include "../utils/utils.h"
#include "../battle/battle.h"
#include "../creature/creature.h"

void Prologue(MainCharacterSharedPtr main_character)
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

	main_character->PrintStats();

	utils::SaveGame(main_character);

	CreatureSharedPtr minotaur1 =
		std::make_shared<Creature>(76, 14, 40, 18, 11, 16, 6, 16, 9, "large monstrosity");
	CreatureSharedPtr minotaur2 =
		std::make_shared<Creature>(76, 14, 40, 18, 11, 16, 6, 16, 9, "large monstrosity");

	std::vector<CreatureSharedPtr> foes = {minotaur1, minotaur2};

	Battle(main_character, foes);

	utils::HandleSound(utils::SoundOperations::Close, "boss_battle");

	system("pause");
}
