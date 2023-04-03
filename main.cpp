#include <iostream>
#include "utils.h"
#include "./creature/creature.cpp"
#include "./creature/main_character/main_character.cpp"

int main()
{
    // Creature goblin({10, 11, 12, 13, 14, 15});
    // goblin.print_stats();

    // std::cout << "=======================" << std::endl;

    // Creature archer;
    // archer.print_stats();

    // std::cout << "=======================" << std::endl;

    MainCharacter main_character("Achilleas Mitos");

    std::string new_name;
    std::cout << "Give me a new name for your character: ";
    get_sanitized_string(new_name);
    main_character.set_name(new_name);

    main_character.print_stats();

    std::cout << "=======================" << std::endl;

    std::cout << "Give me the name for another character: ";
    get_sanitized_string(new_name);

    MainCharacter main_2(new_name, 15, 14, 7, 16, 13, 14);

    main_2.print_stats();

    print({"This will ", "appear ", std::to_string(3), " times slower", "..."}, 300);

    system("pause");
    return 0;
}