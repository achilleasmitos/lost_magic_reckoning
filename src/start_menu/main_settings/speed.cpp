#include "speed.h"
#include "../../utils/utils.h"
#include <iostream>

void Speed(){
	std::cout << "Give me the time you want between each rendered "
				 "character (in ms): ";
	utils::GetUserInput(utils::g_sleep_for_ms);
}