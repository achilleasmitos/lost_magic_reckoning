#pragma once
#include "../utils.h"

namespace start_menu
{
/**
 * @brief A function that takes you to the start menu of the gamne, where you can:
 * 1. Start the game
 * 2. Change the settings (text size, text weigth etc)
 * 3. Quit the game
 *
 * @return An integer to check for when to exit this function.
 * TODO: This function should be refactored to return void.
 */
int start_menu();
} // namespace start_menu
