#include "ChangeFontWeight.h"
#include "../../utils/utils.h"
#include <iostream>

void ChangeFontWeight()
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
					utils::CustomizeText(utils::g_text_size, utils::Light);
					break;
				}
			case 2:
				{
					utils::CustomizeText(utils::g_text_size, utils::SemiLight);
					break;
				}
			case 3:
				{
					utils::CustomizeText(utils::g_text_size, utils::Normal);
					break;
				}
			case 4:
				{
					utils::CustomizeText(utils::g_text_size, utils::SemiBold);
					break;
				}
			case 5:
				{
					utils::CustomizeText(utils::g_text_size, utils::Bold);
					break;
				}
			default:
				{
					std::cout << "Invalid choice! Please choose again." << std::endl;
					continue;
				}
		}
		break;
	}
	while (true);
}
