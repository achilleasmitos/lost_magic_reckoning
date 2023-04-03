#include "../../utils.h"
#include "main_character.h"
#include <iostream>

MainCharacter::MainCharacter(std::string name)
{
    if (check_name(name))
    {
        m_name = name;
        print({"Welcome to the world, ", m_name, "!"});
    }
}

MainCharacter::MainCharacter(std::string name, int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma)
    : Creature(strength, dexterity, constitution, intelligence, wisdom, charisma)
{
    if (check_name(name))
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
    if (check_name(name))
    {
        m_name = name;
        print({"Your new name is: ", m_name, "."});
    }
}

bool MainCharacter::check_name(std::string name)
{
    bool has_digit = false;

    for (const auto character : name)
    {
        if (!(std::isalpha(character) || character == ' '))
        {
            has_digit = true;
        }
    }

    if (has_digit)
    {
        print({"Sorry, your name can only contain letters and spaces..."});
        return false;
    }
    else
    {
        return true;
    }
}