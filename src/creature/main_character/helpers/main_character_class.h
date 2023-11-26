#pragma once

#include <memory>
#include <string>
#include <vector>

namespace main_character_class
{
extern std::vector<std::string> const AVAILABLE_CLASSES;

class MainCharacterClass
{
public:
	static std::unique_ptr<MainCharacterClass> CreateMainCharacterClass();

	MainCharacterClass();

	void ResetToDefault();

	std::string get_class() const;
	void set_class(std::string player_class);

	// Provide a string representation for MainCharacterClass
	operator std::string();

private:
	std::string m_class;
};
} // namespace main_character_class
