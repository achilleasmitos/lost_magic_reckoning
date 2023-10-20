#include "roll_dice.h"
#include <iostream>

int utils::RollDice(int number_of_dice, int number_of_faces)
{
	int sum{0};

	for (int i{0}; i < number_of_dice; i++)
	{
		sum += rand() % number_of_faces + 1;
	}

	return sum;
}

int utils::RollDice(std::vector<std::string> const& list)
{
	int sum{0};

	for (const auto& dice_group : list)
	{
		try
		{
			std::size_t index_of_d;
			int number_of_dice = std::stoi(dice_group, &index_of_d);
			int number_of_faces = std::stoi(dice_group.substr(index_of_d + 1));

			sum += utils::RollDice(number_of_dice, number_of_faces);
		}
		catch (const std::exception& e)
		{
			std::cerr
				<< e.what() << '\n'
				<< "Invalid arguments for RollDice! Problematic argument: " << dice_group
				<< std::endl;
			return -1;
		}
	}

	return sum;
}

int utils::RollWithAdvantage()
{
	int first_die = utils::RollDice(1, 20);
	int second_die = utils::RollDice(1, 20);

	return first_die > second_die ? first_die : second_die;
}

int utils::RollWithDisadvantage()
{
	int first_die = utils::RollDice(1, 20);
	int second_die = utils::RollDice(1, 20);

	return first_die < second_die ? first_die : second_die;
}
