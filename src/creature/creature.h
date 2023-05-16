#pragma once
#include <string>

class Creature
{
public:
	// Create a new creature with default ability scores (all 10s)
	Creature();
	// Create a new creature with given ability scores
	Creature(int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma);
	// Create a new creature with all essential stats given
	Creature(int hp,
		int ac,
		int speed,
		int strength,
		int dexterity,
		int constitution,
		int intelligence,
		int wisdom,
		int charisma,
		std::string creature_type);

	void PrintStats();

	int get_hp();

	int get_ac();

	int get_speed();

	int get_ability_score(int n);
	
	std::string get_creature_type();

protected:
	int m_hp;
	int m_ac;
	int m_speed;
	int m_ability_scores[6];
	std::string m_creature_type;
};
