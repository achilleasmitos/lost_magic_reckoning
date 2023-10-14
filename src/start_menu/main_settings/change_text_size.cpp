#include "change_text_size.h"
#include "../../utils/utils.h"
#include <iostream>

void ChangeTextSize()
{
	std::cout << "Your current text size is: " << utils::g_text_size << std::endl;
	std::cout << "Please enter your desired text size.\n";

	int desired_text_size;
	utils::GetUserFreeChoice(desired_text_size);

	while (desired_text_size < 0)
	{
		std::cout << "Sorry, text size must be a positive integer.\nPlease "
					 "choose again.\n";
		utils::GetUserFreeChoice(desired_text_size);
	}

	utils::g_text_size = desired_text_size;
	utils::CustomizeText();
}
