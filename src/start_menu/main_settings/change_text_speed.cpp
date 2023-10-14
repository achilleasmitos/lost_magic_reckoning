#include "change_text_speed.h"
#include "../../utils/utils.h"
#include <iostream>

void ChangeTextSpeed()
{
	std::cout << "The current time to wait between each rendered character is: "
			  << utils::g_sleep_for_ms << "ms." << std::endl;
	std::cout << "Please enter your desired time to wait.\n";

	int desired_text_speed;
	utils::GetUserFreeChoice(desired_text_speed);

	while (desired_text_speed < 0)
	{
		std::cout << "Sorry, text speed must be 0 or a positive "
					 "integer.\nPlease choose again.\n";
		utils::GetUserFreeChoice(desired_text_speed);
	}

	utils::g_sleep_for_ms = desired_text_speed;
}
