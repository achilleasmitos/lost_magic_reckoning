#include "weight.h"
#include "../../utils/utils.h"
#include <iostream>

void Weight()
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
		if (weight_shoice == 1)
		{
			utils::CustomizeText(utils::g_text_size, utils::Light);
			break;
		}
		else if (weight_shoice == 2)
		{
			utils::CustomizeText(utils::g_text_size, utils::SemiLight);
			break;
		}
		else if (weight_shoice == 3)
		{
			utils::CustomizeText(utils::g_text_size, utils::Normal);
			break;
		}
		else if (weight_shoice == 4)
		{
			utils::CustomizeText(utils::g_text_size, utils::SemiBold);
			break;
		}
		else if (weight_shoice == 5)
		{
			utils::CustomizeText(utils::g_text_size, utils::Bold);
			break;
		}
		else
		{
			std::cout << "Invalid choice! "
						 "Please choose again."
					  << std::endl;
			continue;
		}
	}
	while (true);
}
