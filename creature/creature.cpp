#include "creature.h"
#include <iostream>

Creature::Creature() : m_stats{10, 10, 10, 10, 10, 10} {};
Creature::Creature(int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma)
    : m_stats{strength, dexterity, constitution, intelligence, wisdom, charisma} {};

void Creature::print_stats()
{
    std::cout << "Your stats are: " << std::endl;
    std::cout << "Strength: " << m_stats[0] << std::endl;
    std::cout << "Dexterity: " << m_stats[1] << std::endl;
    std::cout << "Constitution: " << m_stats[2] << std::endl;
    std::cout << "Intelligence: " << m_stats[3] << std::endl;
    std::cout << "Wisdom: " << m_stats[4] << std::endl;
    std::cout << "Charisma: " << m_stats[5] << std::endl;
}