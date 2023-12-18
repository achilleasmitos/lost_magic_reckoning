#include "change_text_font.h"
#include "utils/utils.h"

#include <iostream>

void ChangeTextFont()
{
	std::cout << "Pick text font.\n" << std::endl;

	int text_font_choice = utils::GetUserConstrainedChoice(utils::AVAILABLE_TEXT_FACE_NAMES);
	utils::g_text_face_name = utils::AVAILABLE_TEXT_FACE_NAMES[text_font_choice - 1];

	utils::CustomizeText();
}
