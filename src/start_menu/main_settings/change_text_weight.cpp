#include "change_text_weight.h"
#include "../../utils/utils.h"
#include <iostream>

void ChangeTextWeight()
{
	do
	{
		std::cout << "Pick Weight" << std::endl;
		std::cout << "1. light" << std::endl;
		std::cout << "2. SemiLight" << std::endl;
		std::cout << "3. Normal" << std::endl;
		std::cout << "4. SemiBold" << std::endl;
		std::cout << "5. Bold" << std::endl;

		int weight_shoice;
		utils::GetUserInput(weight_shoice);

		switch (weight_shoice)
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
			default:
				{
					std::cout << "Invalid choice! Please choose again." << std::endl;
					continue;
				}
		}

		utils::CustomizeText(); // Make the new changes take effect

		break; // Exit the do...while loop
	}
	while (true);
}
