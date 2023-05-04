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
					Size(); // Call the Size() function to prompt the user for a number and customize text size
					break;
				}
			case 2:
				{
					Weight(); // Call the Weight() function to prompt the user for a weight choice and customize text weight
					break;
				}
			case 3:
				{
					Font(); // Call the Font() function to prompt the user to select the font
					break;
				}
			case 4:
				{
					Speed(); // Call the Speed() function to prompt the user for the time between each rendered character
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
