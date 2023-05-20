#include "./utils/utils.h"
#include "./loading_screen/loading_screen.h"
#include "./start_menu/start_menu.h"
#include "./story/prologue.h"
#include <iostream>
#include <time.h>

int main()
{
	LoadingScreen();

	LoadSettings();

	srand(time(NULL));

	MainCharacter main_character("Achilleas");

	StartMenu(main_character);

	return 0;
}
