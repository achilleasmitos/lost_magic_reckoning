#include <string>

namespace utils
{
// Number of milliseconds that the 'Print' function waits for in-between character prints.
extern int g_sleep_for_ms;

/**
 * @brief Function to print a list of strings to the console, pausing in-between characters.
 *
 * @param list A comma separated list of std::strings to std::cout
 * @param sleep_for_ms (optional) The amount of milliseconds to sleep between characters.
 */
void Print(std::initializer_list<std::string> list, int sleep_for_ms = g_sleep_for_ms);
} // namespace utils
