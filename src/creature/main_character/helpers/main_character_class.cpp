#include "main_character_class.h"

#include <algorithm>
#include <iostream>

using namespace main_character_class;

struct AllMainCharacterClasses
{
	static std::string const Undefined;
	static std::string const Barbarian;
	static std::string const Bard;
	static std::string const Cleric;
	static std::string const Druid;
	static std::string const Fighter;
	static std::string const Paladin;
	static std::string const Wizard;
};

std::string const AllMainCharacterClasses::Undefined{"Undefined"};
std::string const AllMainCharacterClasses::Barbarian{"Barbarian"};
std::string const AllMainCharacterClasses::Bard{"Bard"};
std::string const AllMainCharacterClasses::Cleric{"Cleric"};
std::string const AllMainCharacterClasses::Druid{"Druid"};
std::string const AllMainCharacterClasses::Fighter{"Fighter"};
std::string const AllMainCharacterClasses::Paladin{"Paladin"};
std::string const AllMainCharacterClasses::Wizard{"Wizard"};

std::vector<std::string> const main_character_class::AVAILABLE_CLASSES = {
	AllMainCharacterClasses::Barbarian,
	AllMainCharacterClasses::Bard,
	AllMainCharacterClasses::Cleric,
	AllMainCharacterClasses::Druid,
	AllMainCharacterClasses::Fighter,
	AllMainCharacterClasses::Paladin,
	AllMainCharacterClasses::Wizard,
};

std::unique_ptr<MainCharacterClass> MainCharacterClass::CreateMainCharacterClass()
{
	return std::make_unique<MainCharacterClass>();
}

MainCharacterClass::MainCharacterClass()
	: m_class(AllMainCharacterClasses::Undefined){};

void MainCharacterClass::ResetToDefault()
{
	m_class = AllMainCharacterClasses::Undefined;
}

std::string MainCharacterClass::get_class() const { return m_class; };
void MainCharacterClass::set_class(std::string player_class)
{
	const auto it =
		std::find(AVAILABLE_CLASSES.begin(), AVAILABLE_CLASSES.end(), player_class);
	if (it == AVAILABLE_CLASSES.end())
	{
		std::cerr << "Class " << player_class
				  << " is not a valid main character class." << std::endl
				  << "Setting main character class to \"Undefined\"." << std::endl;
		player_class = AllMainCharacterClasses::Undefined;
	}
	m_class = player_class;
};

MainCharacterClass::operator std::string() { return m_class; };
