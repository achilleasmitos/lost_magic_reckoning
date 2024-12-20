add_library(create_character 
	create_character.cpp
	create_character.h)

target_include_directories(create_character INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}")
