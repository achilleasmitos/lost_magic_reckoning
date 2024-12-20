add_library(save_and_load_game 
	load_game/load_game.cpp
	load_game/load_game.h
	save_game/save_game.cpp
	save_game/save_game.h)

target_include_directories(save_and_load_game INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}")
