#include "get_user_free_choice.h"
#include "get_user_input.h"
#include "helpers/strings_helpers.h"
#include "reserved_words/check_for_reserved_word.h"

#include <algorithm>
#include <iostream>
#include <stdexcept>

void utils::GetUserFreeChoice(std::string& user_choice,
	std::vector<std::string> const& expected_answers)
{
	if (expected_answers.size() > 0)
	{
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
				user_choice = "";
				return;
			}
			is_input_valid = true;

			// Match answer against expected answers (string version)
			std::vector<std::string> lower_cased_expected_answers = expected_answers;
			for (auto& answer : lower_cased_expected_answers)
			{
				answer = user_choice_helpers::ToLowerCase(answer);
			}

			const auto found = std::find(std::begin(lower_cased_expected_answers),
				std::end(lower_cased_expected_answers),
				user_choice_helpers::ToLowerCase(user_choice));
			if (found != std::end(lower_cased_expected_answers))
			{
				// Assign the expected_answer to the user_choice
				int position =
					std::distance(std::begin(lower_cased_expected_answers), found);
				user_choice = expected_answers.begin()[position];
				break;
			}

			// Match answer against expected answers (number version)
			int user_choice_int{0};
			try
			{
				user_choice_int = std::stoi(user_choice);
				if (0 < user_choice_int && user_choice_int <= iter)
				{
					// Assign the expected_answer to the user_choice
					user_choice = expected_answers.begin()[user_choice_int - 1];
					break;
				}
				else
				{
					is_input_valid = false;
					throw std::invalid_argument(
						"Tried to read input as number, "
						"but input is out of bounds!");
				}
			}
			catch (...)
			{
			}
		}
		return;
	}

	std::cout << "Your answer: ";
	utils::GetUserInput(user_choice);
	std::cout << "\n";
}

void utils::GetUserFreeChoice(int& user_choice, std::vector<int> const& expected_answers)
{
	// Create the string counterparts of the inputs
	std::string str_user_choice;
	std::vector<std::string> str_expected_answers(expected_answers.size(), "");

	int iter{0};
	for (const auto& expected_answer : expected_answers)
	{
		str_expected_answers[iter] = std::to_string(expected_answer);
		iter++;
	}

	bool can_get_digit{false};

	while (!can_get_digit)
	{
		utils::GetUserFreeChoice(str_user_choice, str_expected_answers);

		try
		{
			can_get_digit = true;
			user_choice = std::stoi(str_user_choice);
		}
		catch (const std::exception& e)
		{
			can_get_digit = false;
			std::cerr << e.what() << '\n';
			std::cout << "\nCould not extract a number from your answer. "
						 "Please try again.\n";
		}
	}
}
