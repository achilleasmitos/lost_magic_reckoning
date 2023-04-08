#include <iostream>
#include "utils.h"
#include "./creature/creature.cpp"
#include "./creature/main_character/main_character.cpp"

int main()
{
    // Creature goblin({10, 11, 12, 13, 14, 15});
    // goblin.print_stats();

    // Creature archer;
    // archer.print_stats();

    // std::cout << "=======================" << std::endl;
    utils::handle_sound(utils::SoundOperations::Open, "..\\resources\\music\\boss_battle.mp3", "boss_battle");
    utils::handle_sound(utils::SoundOperations::Play, "boss_battle");

    std::cout << "Give me the time you want between each rendered character (in ms): ";
    std::cin >> utils::sleep_for_ms;

    MainCharacter main_character("Achilleas Mitos");

    std::string new_name;
    std::cout << "Give me a new name for your character: ";
    utils::get_sanitized_string(new_name);
    main_character.set_name(new_name);
    main_character.print_stats();

    utils::handle_sound(utils::SoundOperations::Open, "..\\resources\\music\\exploration.mp3", "exploration");
    utils::handle_sound(utils::SoundOperations::Play, "exploration repeat");

    std::cout << "Give me the name for another character: ";
    utils::get_sanitized_string(new_name);

    MainCharacter main_2(new_name, 15, 14, 7, 16, 13, 14);
    main_2.print_stats();

    utils::customize_text(24);

    std::cout << "Give me the name for another character: ";
    utils::get_sanitized_string(new_name);

    utils::handle_sound(utils::SoundOperations::Close, "boss_battle");

    MainCharacter main_3(new_name, 12, 14, 35, 16, 14, 10, 8, 7, 12, "humanoid");
    main_3.print_stats();

    utils::handle_sound(utils::SoundOperations::Close, "exploration");

    utils::print({"This will ", "appear ", std::to_string(3), " times slower", "..."}, 3 * utils::sleep_for_ms);

    system("pause");
    return 0;
}