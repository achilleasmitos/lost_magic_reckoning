#include "change_sound_volume.h"
#include "../../utils/utils.h"
#include <iostream>

void ChangeSoundVolume()
{
	std::cout << "Your current volume is at: " << utils::g_sound_volume / 10 << std::endl;
	std::cout << "Please enter your desired sound volume (0-100): ";

	int desired_volume;
	utils::GetUserInput(desired_volume);

	while (desired_volume < 0 || desired_volume > 100)
	{
		std::cout << "Sorry, that number is out of bounds.\nPlease choose an "
					 "integer between 0 and 100 for your desired volume: ";
		utils::GetUserInput(desired_volume);
	}

	utils::g_sound_volume = desired_volume * 10;
	utils::HandleSoundVolume();
}
