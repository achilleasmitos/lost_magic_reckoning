#include "change_text_weight.h"
#include "utils/utils.h"

#include <iostream>

void ChangeTextWeight()
{
	std::cout << "Pick text weight.\n" << std::endl;
	std::vector<std::string> const text_weight_options{"Light", "Semi-light", "Normal", "Semi-bold", "Bold"};

	int text_weight_choice = utils::GetUserConstrainedChoice(text_weight_options);

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
