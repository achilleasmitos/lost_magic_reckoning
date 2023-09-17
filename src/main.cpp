#include "./utils/utils.h"
#include "./creature/main_character/main_character_prototypes.h"
#include "./loading_screen/loading_screen.h"
#include "./start_menu/start_menu.h"
#include "./story/prologue.h"
#include <iostream>
#include <time.h>

int main()
{
	LoadingScreen();

	srand(time(NULL));

	MainCharacterUniquePtr main_character_unique_ptr =
		std::make_unique<MainCharacter>("Player");

	utils::LoadGame(*main_character_unique_ptr);

	StartMenu(*main_character_unique_ptr);

	return 0;
}
