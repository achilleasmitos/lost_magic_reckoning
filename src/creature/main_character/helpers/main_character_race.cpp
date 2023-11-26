#include "main_character_race.h"

#include <algorithm>
#include <iostream>

using namespace main_character_race;

struct AllMainCharacterRaces
{
	static std::string const Undefined;
	static std::string const DwarfHill;
	static std::string const DwarfMountain;
	static std::string const ElfHigh;
	static std::string const ElfWood;
	static std::string const Human;
	static std::string const Tiefling;
};

std::string const AllMainCharacterRaces::Undefined{"Undefined"};
std::string const AllMainCharacterRaces::DwarfHill{"Hill Dwarf"};
std::string const AllMainCharacterRaces::DwarfMountain{"Mountain Dwarf"};
std::string const AllMainCharacterRaces::ElfHigh{"High Elf"};
std::string const AllMainCharacterRaces::ElfWood{"Wood Elf"};
std::string const AllMainCharacterRaces::Human{"Human"};
std::string const AllMainCharacterRaces::Tiefling{"Tiefling"};

std::vector<std::string> const main_character_race::AVAILABLE_RACES = {
	AllMainCharacterRaces::DwarfHill,
	AllMainCharacterRaces::DwarfMountain,
	AllMainCharacterRaces::ElfHigh,
	AllMainCharacterRaces::ElfWood,
	AllMainCharacterRaces::Human,
	AllMainCharacterRaces::Tiefling,
};

std::unique_ptr<MainCharacterRace> MainCharacterRace::CreateMainCharacterRace()
{
	return std::make_unique<MainCharacterRace>();
}

MainCharacterRace::MainCharacterRace()
	: m_race(AllMainCharacterRaces::Undefined){};

void MainCharacterRace::ResetToDefault()
{
	m_race = AllMainCharacterRaces::Undefined;
}

std::string MainCharacterRace::get_race() const { return m_race; };
void MainCharacterRace::set_race(std::string player_race)
{
	const auto it = std::find(AVAILABLE_RACES.begin(), AVAILABLE_RACES.end(), player_race);
	if (it == AVAILABLE_RACES.end())
	{
		std::cerr << "Race " << player_race
				  << " is not a valid main character race." << std::endl
				  << "Setting main character race to \"Undefined\"." << std::endl;
		player_race = AllMainCharacterRaces::Undefined;
	}
	m_race = player_race;
};

MainCharacterRace::operator std::string() { return m_race; };
