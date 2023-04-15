#pragma once
#include <string>

namespace utils
{
/**
 * @brief A function that accepts two integer numbers, one for the number of dice,
 * and one for the type (number of faces) for the dice, and randomly generates the total sum of their rolls.
 *
 * @param number_of_dice The number of dice to roll.
 * @param number_of_faces The number of faces on (aka the type of) the die to use.
 * @return int The sum of the random rolls.
 */
int RollDice(int number_of_dice, int number_of_faces);

/**
 * @brief A function that accepts a list of strings (in the form { string1 , string2 , ... } )
 * where each string is in the form <number_of_dice>d<number_of_faces>,
 * and returns the total sum of their random rolls.
 *
 * @param list A comma separated list of strings in the form "5d10".
 * @return The total sum of the random dice rolls. If an error occurs, -1 is returned instead.
 */
int RollDice(std::initializer_list<std::string> list);

/**
 * @brief Rolls 2d20 with advantage.
 *
 * @return The highest roll.
 */
int RollWithAdvantage();

/**
 * @brief Rolls 2d20 with disadvantage.
 *
 * @return The lowest roll.
 */
int RollWithDisadvantage();
} // namespace utils