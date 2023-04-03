#pragma once

#include "../creature.h"
#include <string>

class MainCharacter : public Creature
{
public:
    MainCharacter(std::string name);
    MainCharacter(std::string name, int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma);

    std::string get_name();
    void set_name(std::string name);

private:
    std::string m_name;

    bool check_name(std::string name);
};