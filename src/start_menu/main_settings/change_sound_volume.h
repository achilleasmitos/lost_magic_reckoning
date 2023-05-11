#pragma once

/**
 * @brief This function notifies the player of the current master volume,
 * then asks them to input their new preferred sound volume. The value
 * (an integer between 0 and 100) is then stored in `g_sound_volume`,
 * and the `HandleSoundVolume()` function is called.
 *
 */
void ChangeSoundVolume();
