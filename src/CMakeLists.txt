# Specify the minimum version required
cmake_minimum_required(VERSION 3.16)

# Declare and name the project and its version
project(LostMagicReckoning VERSION 1.0)

# Define the C++ standard version meant to be used by this project
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# Define additional compiler flags
set(ADDITIONAL_COMPILER_FLAGS "-GS -WX -sdl -O2 -MP")
# Append the flags to the corresponding CMake flags
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${ADDITIONAL_COMPILER_FLAGS}")

# Declare a CMake config file and turn it into an importable header file
configure_file(LostMagicReckoningConfig.h.in LostMagicReckoningConfig.h)

# Create sub-projects visible in VS's Solution Explorer
# add_subdirectory(battle)
# add_subdirectory(create_character)
# add_subdirectory(creature)
# add_subdirectory(loading_screen)
# add_subdirectory(read_from_file)
# add_subdirectory(save_and_load_game)
# add_subdirectory(start_menu)
# add_subdirectory(story)
# add_subdirectory(utils)

# Add the source and header files to be compiled into the project
add_executable(LostMagicReckoning
	battle/battle.cpp
	battle/battle.h
	battle/foe_attack_with_disadvantage.cpp
	battle/foe_attack_with_disadvantage.h
	battle/foe_attack.cpp
	battle/foe_attack.h
	battle/main_character_attack.cpp
	battle/main_character_attack.h
	battle/tutorial_battle.cpp
	battle/tutorial_battle.h
	create_character/create_character.cpp
	create_character/create_character.h
	creature/main_character/helpers/helpers_prototypes.h
	creature/main_character/helpers/main_character_class.cpp
	creature/main_character/helpers/main_character_class.h
	creature/main_character/helpers/main_character_race.cpp
	creature/main_character/helpers/main_character_race.h
	creature/main_character/main_character_prototypes.h
	creature/main_character/main_character.cpp
	creature/main_character/main_character.h
	creature/creature_prototypes.h
	creature/creature.cpp
	creature/creature.h
	loading_screen/loading_screen.cpp
	loading_screen/loading_screen.h
	read_from_file/read_from_file.cpp
	read_from_file/read_from_file.h
	read_from_file/handle_battle_cmd.cpp
	read_from_file/handle_battle_cmd.h
	read_from_file/handle_custom_speed_text_cmd.cpp
	read_from_file/handle_custom_speed_text_cmd.h
	read_from_file/handle_sleep_for_cmd.cpp
	read_from_file/handle_sleep_for_cmd.h
	read_from_file/handle_sound_cmd.cpp
	read_from_file/handle_sound_cmd.h
	read_from_file/handle_text_cmd.cpp
	read_from_file/handle_text_cmd.h
	save_and_load_game/load_game/load_game.cpp
	save_and_load_game/load_game/load_game.h
	save_and_load_game/save_game/save_game.cpp
	save_and_load_game/save_game/save_game.h
	start_menu/continue_game/continue_game.cpp
	start_menu/continue_game/continue_game.h
	start_menu/main_settings/change_sound_volume.cpp
	start_menu/main_settings/change_sound_volume.h
	start_menu/main_settings/change_text_font.cpp
	start_menu/main_settings/change_text_font.h
	start_menu/main_settings/change_text_size.cpp
	start_menu/main_settings/change_text_size.h
	start_menu/main_settings/change_text_speed.cpp
	start_menu/main_settings/change_text_speed.h
	start_menu/main_settings/change_text_weight.cpp
	start_menu/main_settings/change_text_weight.h
	start_menu/main_settings/main_settings.cpp
	start_menu/main_settings/main_settings.h
	start_menu/start_game/start_game.cpp
	start_menu/start_game/start_game.h
	start_menu/start_menu.cpp
	start_menu/start_menu.h
	story/prologue.cpp
	story/prologue.h
	utils/alter_text/alter_text.cpp
	utils/alter_text/alter_text.h
	utils/customize_text/customize_text.cpp
	utils/customize_text/customize_text.h
	utils/handle_sound/handle_sound.cpp
	utils/handle_sound/handle_sound.h
	utils/JSON_interaction/JSON_interaction.h
	utils/print_and_clear_screen/clear_screen.cpp
	utils/print_and_clear_screen/clear_screen.h
	utils/print_and_clear_screen/print.cpp
	utils/print_and_clear_screen/print.h
	utils/roll_dice/roll_dice.cpp
	utils/roll_dice/roll_dice.h
	utils/string_sanitization/string_sanitization.cpp
	utils/string_sanitization/string_sanitization.h
	utils/user_choice/helpers/strings_helpers.cpp
	utils/user_choice/helpers/strings_helpers.h
	utils/user_choice/get_user_constrained_choice.cpp
	utils/user_choice/get_user_constrained_choice.h
	utils/user_choice/get_user_free_choice.cpp
	utils/user_choice/get_user_free_choice.h
	utils/user_choice/get_user_input.cpp
	utils/user_choice/get_user_input.h
	utils/user_choice/reserved_words/check_for_reserved_word.cpp
	utils/user_choice/reserved_words/check_for_reserved_word.h
	utils/utils.h
	main.cpp)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT LostMagicReckoning)

# target_link_libraries(LostMagicReckoning
# 	PUBLIC battle
# 	PUBLIC create_character
# 	PUBLIC creature
# 	PUBLIC loading_screen
# 	PUBLIC read_from_file
# 	PUBLIC save_and_load_game
# 	PUBLIC start_menu
# 	PUBLIC story
# 	PUBLIC utils)
target_link_libraries(LostMagicReckoning winmm.lib)

# Add a precompiled header file to this particular project.
# Other projects can define their own files, or reuse this one.
target_precompile_headers(LostMagicReckoning
	PUBLIC pch.h
)

# Where to search for 'include' directives
target_include_directories(LostMagicReckoning PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
