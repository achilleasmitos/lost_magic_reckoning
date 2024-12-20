add_library(battle 
	battle.cpp
	battle.h
	foe_attack_with_disadvantage.cpp
	foe_attack_with_disadvantage.h
	foe_attack.cpp
	foe_attack.h
	main_character_attack.cpp
	main_character_attack.h
	tutorial_battle.cpp
	tutorial_battle.h)

target_include_directories(battle INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}")
