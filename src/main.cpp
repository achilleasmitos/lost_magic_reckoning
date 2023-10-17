#include "utils/utils.h"
#include "creature/main_character/main_character_prototypes.h"
#include "loading_screen/loading_screen.h"
#include "save_and_load_game/load_game/load_game.h"
#include "start_menu/start_menu.h"

#include <time.h>

int main()
{
	LoadingScreen();

	srand(time(NULL));

	MainCharacterUniquePtr main_character_unique_ptr =
		std::make_unique<MainCharacter>("Player");

	LoadGame(*main_character_unique_ptr);

	StartMenu(*main_character_unique_ptr);

	return 0;
}
