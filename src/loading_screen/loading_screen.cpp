#include "loading_screen.h"
#include "../utils/utils.h"
#include <iostream>

void LoadingScreen()
{
	std::cout << "Welcome to our text-based game! Get ready to explore a world "
				 "of adventure, where every choice counts. Have fun!"
			  << std::endl;
	std::cout << "Give me the time you want between each rendered "
				 "character (in ms): ";
	utils::GetUserInput(utils::g_sleep_for_ms);
}
