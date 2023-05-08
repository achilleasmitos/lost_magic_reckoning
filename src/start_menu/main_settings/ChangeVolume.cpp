#include "ChangeVolume.h"
#include "../../utils/utils.h"
#include <iostream>
#include <windows.h>
#include <string>

void ChangeVolume()
{
	// Prompt user for volume level
	std::cout << "Enter volume level (0-100): ";
	int volume;
	utils::GetUserInput(volume);
	volume = std::min(std::max(volume, 0), 100); // clamp value between 0 and 100

	// Set volume
	DWORD dwVolume = ((DWORD) volume << 16) | volume;
	if (waveOutSetVolume(NULL, dwVolume) != MMSYSERR_NOERROR)
	{
		std::cout << "Error: Unable to set volume.\n";
		return;
	}

	std::cout << "Volume set to " << volume << ".\n";

	// Close audio device
	waveOutClose(NULL);
}
