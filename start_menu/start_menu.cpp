#include "start_menu.h"
#include <iostream>

int start_menu::start_menu()
{
	int go_back = 0;
	std::cout << "Welcome to the game!" << std::endl;
	int choice = -1;

	while (choice != 1)
	{
		std::cout << "Please select an option:" << std::endl;
		std::cout << "1. Start Game" << std::endl;
		std::cout << "2. Settings" << std::endl;
		std::cout << "3. Quit" << std::endl;

		std::cin >> choice;

		switch (choice)
		{
			case 1:
				{
					// code for starting the game
					std::cout << "Starting the game..." << std::endl;
					return 0;
				}
			case 2:
				{
					do
					{
						// code for settings
						std::cout << "Opening settings..." << std::endl;
						std::cout << "chouse a setting you want to change" << std::endl;
						std::cout << "Please select an option:" << std::endl;
						std::cout << "1. Text Size" << std::endl;
						std::cout << "2. Font Weight" << std::endl;
						std::cout << "3. Face Name" << std::endl;
						int Setting_shoice;
						std::cin >> Setting_shoice;
						switch (Setting_shoice)
						{
							case 1:
								{
									std::cout << "Pick Number" << std::endl;
									std::cin >> utils::text_size;
									utils::customize_text(utils::text_size);
									go_back = 1;
									break;
								}
							case 2:
								{
									do
									{
										std::cout << "Pick Weight" << std::endl;
										std::cout << "1. light" << std::endl;
										std::cout << "2. SemiLight" << std::endl;
										std::cout << "3. Normal" << std::endl;
										std::cout << "4. SemiBold" << std::endl;
										std::cout << "5. Bold" << std::endl;
										int weight_shoice;
										std::cin >> weight_shoice;
										if (weight_shoice == 1)
										{
											utils::customize_text(utils::text_size,
												utils::Light);
											break;
										}
										else if (weight_shoice == 2)
										{
											utils::customize_text(utils::text_size,
												utils::SemiLight);
											break;
										}
										else if (weight_shoice == 3)
										{
											utils::customize_text(utils::text_size,
												utils::Normal);
											break;
										}
										else if (weight_shoice == 4)
										{
											utils::customize_text(utils::text_size,
												utils::SemiBold);
											break;
										}
										else if (weight_shoice == 5)
										{
											utils::customize_text(utils::text_size,
												utils::Bold);
											break;
										}
										else
										{
											std::cout << "Invalid choice! "
														 "Please choose again."
													  << std::endl;
											continue;
										}
									}
									while (true);
									go_back = 1;
									break;
								}
							case 3:
								{
									std::cout << "no idea what to do..." << std::endl;
									go_back = 1;
									break;
								}
							default:
								{
									std::cout << "Invalid choice! Please "
												 "choose again."
											  << std::endl;
									go_back = 0;
									continue;
								}
						}
					}
					while (go_back == 0);
					break;
				}
			case 3:
				{
					// code for quitting
					std::cout << "Quitting the game..." << std::endl;
					return 1;
					break;
				}
			default:
				{
					std::cout << "Invalid choice! Please choose again." << std::endl;
					break;
				}
		}
	}
	return -1;
}