#include "main_character.h"
#include <iostream>

MainCharacter::MainCharacter(std::string name)
{
    if (check_name(name))
    {
        m_name = name;
        std::cout << "Welcome to the world, " << m_name << std::endl;
    }
}

MainCharacter::MainCharacter(std::string name, int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma)
    : Creature(strength, dexterity, constitution, intelligence, wisdom, charisma)
{
    if (check_name(name))
    {
        m_name = name;
        std::cout << "Welcome to the world, " << m_name << std::endl;
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
        std::cout << "Your new name is: " << m_name << std::endl;
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
        std::cout << "Sorry, your name can only contain letters..." << std::endl;
        return false;
    }
    else
    {
        return true;
    }
}