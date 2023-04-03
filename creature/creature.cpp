#include "creature.h"
#include <iostream>

Creature::Creature()
    : m_hp(10), m_ac(10), m_speed(30), m_ability_scores{10, 10, 10, 10, 10, 10}, m_creature_type("humanoid"){};
Creature::Creature(int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma)
    : m_hp(10), m_ac(10 + (dexterity - 10) / 2), m_speed(30),
      m_ability_scores{strength, dexterity, constitution, intelligence, wisdom, charisma},
      m_creature_type("humanoid"){};
Creature::Creature(int hp, int ac, int speed, int strength, int dexterity, int constitution,
                   int intelligence, int wisdom, int charisma, std::string creature_type)
    : m_hp(hp), m_ac(ac), m_speed(speed),
      m_ability_scores{strength, dexterity, constitution, intelligence, wisdom, charisma},
      m_creature_type(creature_type){};

void Creature::print_stats()
{
    std::cout << "==============================" << std::endl;
    std::cout << "Your stats are: " << std::endl;
    std::cout << "HP: " << m_hp << std::endl;
    std::cout << "AC: " << m_ac << std::endl;
    std::cout << "Speed: " << m_speed << std::endl;
    std::cout << "Strength: " << m_ability_scores[0] << std::endl;
    std::cout << "Dexterity: " << m_ability_scores[1] << std::endl;
    std::cout << "Constitution: " << m_ability_scores[2] << std::endl;
    std::cout << "Intelligence: " << m_ability_scores[3] << std::endl;
    std::cout << "Wisdom: " << m_ability_scores[4] << std::endl;
    std::cout << "Charisma: " << m_ability_scores[5] << std::endl;
    std::cout << "Creature type: " << m_creature_type << std::endl;
    std::cout << "==============================" << std::endl;
}