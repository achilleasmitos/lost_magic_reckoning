#include "main_settings.h"
#include "ChangeTextWeight.h"
#include "ChangeTextfont.h"
#include "ChangeTextsize.h"
#include "ChangeTextspeed.h"
#include "ChangeVolume.h"
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
		std::cout << "5. Change Volume" << std::endl;

		int setting_shoice;
		utils::GetUserInput(setting_shoice);

		switch (setting_shoice)
		{
			case 1:
				{
					ChangeTextSize();
					break;
				}
			case 2:
				{
					ChangeTextWeight();
					break;
				}
			case 3:
				{
					ChangeTextFont();
					break;
				}
			case 4:
				{
					ChangeTextSpeed();
					break;
				}
			case 5:
				{
					ChangeVolume();
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
