add_library(creature 
	main_character/main_character_prototypes.h
	main_character/main_character.cpp
	main_character/main_character.h
	creature_prototypes.h
	creature.cpp
	creature.h)

target_include_directories(creature INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}")
