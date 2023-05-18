#include "main_settings.h"
#include "change_sound_volume.h"
#include "change_text_font.h"
#include "change_text_size.h"
#include "change_text_speed.h"
#include "change_text_weight.h"
#include "../../utils/utils.h"
#include <iostream>

void MainSettings()
{
	std::cout << "Opening settings..." << std::endl;
	std::cout << "Choose the setting that you want to change:" << std::endl;
	std::cout << "1. Text Size" << std::endl;
	std::cout << "2. Text Weight" << std::endl;
	std::cout << "3. Text Font" << std::endl;
	std::cout << "4. Text Speed" << std::endl;
	std::cout << "5. Sound Volume" << std::endl;

	int main_settings_shoice;
	utils::GetUserInput(main_settings_shoice);

	while (main_settings_shoice < 1 || main_settings_shoice > 5)
	{
		std::cout << "Invalid choice!\nPlease choose an option from above: ";
		utils::GetUserInput(main_settings_shoice);
	}

	switch (main_settings_shoice)
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
				ChangeSoundVolume();
				break;
			}
	}
}
