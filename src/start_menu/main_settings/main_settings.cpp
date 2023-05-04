#include "main_settings.h"
#include "ChangeFontWeight.h"
#include "font.h"
#include "size.h"
#include "speed.h"
#include "../../utils/utils.h"
#include <iostream>

void MainSettings()
{
	do
	{
		// code for settings
		std::cout << "Opening settings..." << std::endl;
		std::cout << "Choose the setting that you want to change" << std::endl;
		std::cout << "Please select an option:" << std::endl;
		std::cout << "1. Text Size" << std::endl;
		std::cout << "2. Font Weight" << std::endl;
		std::cout << "3. Font Name" << std::endl;
		std::cout << "4. Text Speed" << std::endl;

		int setting_shoice;
		utils::GetUserInput(setting_shoice);

		switch (setting_shoice)
		{
			case 1:
				{
					Size();
					break;
				}
			case 2:
				{
					ChangeFontWeight();
					break;
				}
			case 3:
				{
					Font();
					break;
				}
			case 4:
				{
					Speed();
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
