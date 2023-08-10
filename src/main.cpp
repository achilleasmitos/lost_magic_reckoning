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

	// MainCharacter will be around for the whole lifetime
	// of the program, therefore, we can have it as a shared_ptr
	MainCharacterSharedPtr main_character =
		std::make_shared<MainCharacter>("Player");

	utils::LoadGame(main_character);

	StartMenu(main_character);

	return 0;
}
