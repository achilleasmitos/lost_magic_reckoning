#include "get_user_constrained_choice.h"
#include "get_user_input.h"
#include "helpers/strings_helpers.h"
#include "reserved_words/check_for_reserved_word.h"

#include <algorithm>
#include <iostream>
#include <stdexcept>

int utils::GetUserConstrainedChoice(std::vector<std::string> const& expected_answers,
	bool use_strict_comparison)
{
	std::string user_choice;
	int return_value{0};

	bool is_input_valid{false};
	while (!is_input_valid)
	{
		// Print expected_answers
		int iter{0};
		for (const auto& expected_answer : expected_answers)
		{
			iter++;
			std::cout << iter << ". " << expected_answer << "\n";
		}

		// Ask the user for their answer
		std::cout << "Your answer: ";
		utils::GetUserInput(user_choice);
		std::cout << "\n";
		if (reserved_words::CheckForReservedWord(user_choice))
		{
			return 0;
		}
		is_input_valid = true;

		// Match answer against expected answers (string version)
		std::vector<std::string> lower_cased_expected_answers = expected_answers;
		if (!use_strict_comparison)
		{
			for (auto& answer : lower_cased_expected_answers)
			{
				answer = user_choice_helpers::ToLowerCase(answer);
			}
		}

		const auto found = std::find(std::begin(lower_cased_expected_answers),
			std::end(lower_cased_expected_answers),
			use_strict_comparison ? user_choice
								  : user_choice_helpers::ToLowerCase(user_choice));
		if (found != std::end(lower_cased_expected_answers))
		{
			// Assign the expected_answer position to the return_value
			return_value =
				std::distance(std::begin(lower_cased_expected_answers), found) + 1;
			break;
		}

		if (!use_strict_comparison)
		{
			// Match answer against expected answers (number version)
			int user_choice_int{0};
			try
			{
				user_choice_int = std::stoi(user_choice);
				if (0 < user_choice_int && user_choice_int <= iter)
				{
					return_value = user_choice_int;
					break;
				}
				else
				{
					throw std::invalid_argument(
						"Tried to read input as number, "
						"but input is out of bounds!");
				}
			}
			catch (...)
			{
			}
		}

		// User's choice did not match any expected answer, ask for input again.
		is_input_valid = false;
		std::cout << "Invalid answer. Please choose one of the available "
					 "options";
		if (!use_strict_comparison)
		{
			std::cout << "\nor a number between 1 and " << iter;
		}
		std::cout << ".\n";
		if (use_strict_comparison)
		{
			std::cout
				<< "Make sure to completely match your input with one of the "
				   "options,\nlower/upper case letters, spaces etc.\n";
		}
		std::cout << "\n";
	}
	return return_value;
}

int utils::GetUserConstrainedChoice(std::vector<int> const& expected_answers)
{
	std::vector<std::string> stringified_expected_answers(expected_answers.size(), "");

	int iter{0};
	for (const auto& expected_answer : expected_answers)
	{
		stringified_expected_answers[iter] = std::to_string(expected_answer);
		iter++;
	}

	return utils::GetUserConstrainedChoice(stringified_expected_answers, true);
}
