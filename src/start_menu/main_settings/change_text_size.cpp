#include "change_text_size.h"
#include "../../utils/utils.h"
#include <iostream>

void ChangeTextSize()
{
	std::cout << "Pick text size number" << std::endl;
	utils::GetUserInput(utils::g_text_size);
	utils::CustomizeText(utils::g_text_size);
}
