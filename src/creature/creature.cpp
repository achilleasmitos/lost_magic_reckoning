#include "creature.h"

#include <iostream>
#include <string>

struct DefaultStats
{
	static int const hp;
	static int const ac;
	static int const speed;
	static int const ability_scores[6];
	static std::string const creature_type;
	static std::string const display_name;
};

int const DefaultStats::hp{10};
int const DefaultStats::ac{10};
int const DefaultStats::speed{10};
int const DefaultStats::ability_scores[6] = {10, 10, 10, 10, 10, 10};
std::string const DefaultStats::creature_type{"humanoid"};
std::string const DefaultStats::display_name{"creature"};

Creature::Creature()
	: m_hp(DefaultStats::hp), m_ac(DefaultStats::ac), m_speed(DefaultStats::speed),
	  m_ability_scores{DefaultStats::ability_scores[0],
		  DefaultStats::ability_scores[1],
		  DefaultStats::ability_scores[2],
		  DefaultStats::ability_scores[3],
		  DefaultStats::ability_scores[4],
		  DefaultStats::ability_scores[5]},
	  m_creature_type(DefaultStats::creature_type),
	  m_display_name(DefaultStats::display_name){};

Creature::Creature(int hp,
	int ac,
	int speed,
	int strength,
	int dexterity,
	int constitution,
	int intelligence,
	int wisdom,
	int charisma,
	std::string creature_type,
	std::string display_name)
	: m_hp(hp), m_ac(ac), m_speed(speed),
	  m_ability_scores{strength, dexterity, constitution, intelligence, wisdom, charisma},
	  m_creature_type(creature_type), m_display_name(display_name){};

void Creature::ResetToDefault()
{
	m_hp = DefaultStats::hp;
	m_ac = DefaultStats::ac;
	m_speed = DefaultStats::speed;
	for (int i = 0; i < 6; i++)
	{
		m_ability_scores[i] = DefaultStats::ability_scores[i];
	}
	m_creature_type = DefaultStats::creature_type;
	m_display_name = DefaultStats::display_name;
}

void Creature::PrintStats()
{
	std::cout << "==============================" << std::endl;
	std::cout << "Stats for: " << m_display_name << std::endl;
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

int Creature::get_hp() const { return m_hp; };
void Creature::set_hp(int hp)
{
	if (hp >= 0)
	{
		m_hp = hp;
	}
	else
	{
		m_hp = 0;
		// std::cerr << "The HP stat of Creature cannot be negative!\n";
	}
}

int Creature::get_ac() const { return m_ac; };
void Creature::set_ac(int ac)
{
	if (ac >= 0)
	{
		m_ac = ac;
	}
	else
	{
		std::cerr << "The AC stat of Creature cannot be negative!\n";
	}
}

int Creature::get_speed() const { return m_speed; };
void Creature::set_speed(int speed)
{
	if (speed >= 0)
	{
		m_speed = speed;
	}
	else
	{
		std::cerr << "The SPEED stat of Creature cannot be negative!\n";
	}
}

int Creature::get_ability_score(int n) const
{
	if (n > -1 && n < 6)
	{
		return m_ability_scores[n];
	}
	else
	{
		std::cerr << "You have asked for an invalid ability score. Valid "
					 "values are between 0 and 6."
				  << std::endl;
		return -1;
	}
}
void Creature::set_ability_score(int ability_score, int value)
{
	if (ability_score > -1 && ability_score < 6 && value > -1)
	{
		m_ability_scores[ability_score] = value;
	}
	else
	{
		std::cerr << "The ability scores of Creature cannot be negative!\n";
	}

	// AC may also need to be updated (when dexterity score changes)
	if (ability_score == 1)
	{
		m_ac = 10 + (m_ability_scores[1] - 10) / 2;
	}
}

std::string Creature::get_creature_type() const { return m_creature_type; };
void Creature::set_creature_type(std::string creature_type)
{
	m_creature_type = creature_type;
}

std::string Creature::get_display_name() const { return m_display_name; };
void Creature::set_display_name(std::string const& display_name)
{
	m_display_name = display_name;
}
