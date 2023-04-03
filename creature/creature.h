#pragma once

class Creature
{
public:
    Creature();                                                                                          // Create a new creature with default stats (all 10s)
    Creature(int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma); // Create a new creature with given stats

    void print_stats();

protected:
    int m_stats[6];
};