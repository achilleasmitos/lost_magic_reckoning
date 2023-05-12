#include "./utils/utils.h"
#include "./loading_screen/loading_screen.h"
#include "./start_menu/start_menu.h"
#include "./story/prologue.h"
#include <iostream>
#include <time.h>

int main()
{
	LoadingScreen();

	srand(time(NULL));

	while (start_menu::StartMenu() == 0)
	{
		Prologue();
	}
	return 0;
}
