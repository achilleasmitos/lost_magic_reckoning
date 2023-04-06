#include "../../utils.h"
#include "main_character.h"
#include <iostream>

MainCharacter::MainCharacter(std::string name)
{
    if (check_for_alpha_or_whitespace(name))
    {
        m_name = name;
        print({"Welcome to the world, ", m_name, "!"});
    }
}

MainCharacter::MainCharacter(std::string name, int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma)
    : Creature(strength, dexterity, constitution, intelligence, wisdom, charisma)
{
    if (check_for_alpha_or_whitespace(name))
    {
        m_name = name;
        print({"Welcome to the world, ", m_name, "!"});
    }
}

MainCharacter::MainCharacter(std::string name, int hp, int ac, int speed, int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma, std::string creature_type)
    : Creature(hp, ac, speed, strength, dexterity, constitution, intelligence, wisdom, charisma, creature_type)
{
    if (check_for_alpha_or_whitespace(name))
    {
        m_name = name;
        print({"Welcome to the world, ", m_name, "!"});
    }
}

std::string MainCharacter::get_name()
{
    return m_name;
}

void MainCharacter::set_name(std::string name)
{
    if (check_for_alpha_or_whitespace(name))
    {
        m_name = name;
        print({"Your new name is: ", m_name, "."});
    }
}

bool MainCharacter::check_for_alpha_or_whitespace(std::string string)
{
    bool has_digit = false;

    for (const auto character : string)
    {
        if (!(std::isalpha(character) || character == ' '))
        {
            has_digit = true;
        }
    }

    if (has_digit)
    {
        print({"Sorry, this string can only contain letters and spaces..."});
        return false;
    }
    else
    {
        return true;
    }
}