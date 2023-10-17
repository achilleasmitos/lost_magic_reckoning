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
	std::cout << "Opening settings...\n";
	std::cout << "Choose the setting that you want to change.\n";
	std::vector<std::string> main_settings_options = {"Text Size",
		"Text Weight",
		"Text Font",
		"Text Speed",
		"Sound Volume"};
	int main_settings_choice = utils::GetUserConstrainedChoice(main_settings_options);

	switch (main_settings_choice)
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
