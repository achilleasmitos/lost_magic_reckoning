#include "change_text_weight.h"
#include "../../utils/utils.h"
#include <iostream>

void ChangeTextWeight()
{
	std::cout << "Pick text weight:" << std::endl;
	std::cout << "1. Light" << std::endl;
	std::cout << "2. SemiLight" << std::endl;
	std::cout << "3. Normal" << std::endl;
	std::cout << "4. SemiBold" << std::endl;
	std::cout << "5. Bold" << std::endl;

	int text_weight_choice = 0;
	utils::GetUserInput(text_weight_choice);

	while (text_weight_choice < 1 || text_weight_choice > 5)
	{
		std::cout << "Sorry, this option is not supported yet.\nPlease choose "
					 "one of the options provided: ";
		utils::GetUserInput(text_weight_choice);
	}

	switch (text_weight_choice)
	{
		case 1:
			{
				utils::g_text_weight = utils::FontWeightValues::Light;
				break;
			}
		case 2:
			{
				utils::g_text_weight = utils::FontWeightValues::SemiLight;
				break;
			}
		case 3:
			{
				utils::g_text_weight = utils::FontWeightValues::Normal;
				break;
			}
		case 4:
			{
				utils::g_text_weight = utils::FontWeightValues::SemiBold;
				break;
			}
		case 5:
			{
				utils::g_text_weight = utils::FontWeightValues::Bold;
				break;
			}
	}

	utils::CustomizeText();
}
