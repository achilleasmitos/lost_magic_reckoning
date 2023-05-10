#include "change_text_speed.h"
#include "../../utils/utils.h"
#include <iostream>

void ChangeTextSpeed()
{
	std::cout << "Give me the time you want between each rendered character "
				 "(in ms): ";
	utils::GetUserInput(utils::g_sleep_for_ms);
}
