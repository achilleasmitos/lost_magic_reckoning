#include "change_text_font.h"
#include "utils/utils.h"

#include <iostream>

void ChangeTextFont()
{
	std::cout << "Pick text font.\n" << std::endl;
	std::vector<std::string> const text_font_options{"Consolas",
		"DejaVu Sans Mono",
		"Liberation Mono",
		"Lucida Console",
		"MS Gothic"};

	int text_font_choice = utils::GetUserConstrainedChoice(text_font_options);

	switch (text_font_choice)
	{
		case 1:
			{
				utils::g_text_face_name = "Consolas";
				break;
			}
		case 2:
			{
				utils::g_text_face_name = "DejaVu Sans Mono";
				break;
			}
		case 3:
			{
				utils::g_text_face_name = "Liberation Mono";
				break;
			}
		case 4:
			{
				utils::g_text_face_name = "Lucida Console";
				break;
			}
		case 5:
			{
				utils::g_text_face_name = "MS Gothic";
				break;
			}
	}

	utils::CustomizeText();
}
