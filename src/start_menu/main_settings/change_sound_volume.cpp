#include "change_sound_volume.h"
#include "../../utils/utils.h"
#include <iostream>

void ChangeSoundVolume()
{
	std::cout << "Your current volume is at: " << utils::g_sound_volume << std::endl;
	std::cout << "Please enter your desired sound volume (0-1000): ";

	int desired_volume;
	utils::GetUserInput(desired_volume);

	while (desired_volume < 0 || desired_volume > 1000)
	{
		std::cout << "Sorry, that number is out of bounds.\nPlease choose an "
					 "integer between 0 and 1000 for your desired volume: ";
		utils::GetUserInput(desired_volume);
	}

	utils::g_sound_volume = desired_volume;
	utils::HandleSoundVolume();
}
