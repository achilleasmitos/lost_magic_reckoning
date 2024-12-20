add_library(read_from_file 
	read_from_file.cpp
	read_from_file.h
	handle_battle_cmd.cpp
	handle_battle_cmd.h
	handle_custom_speed_text_cmd.cpp
	handle_custom_speed_text_cmd.h
	handle_sleep_for_cmd.cpp
	handle_sleep_for_cmd.h
	handle_sound_cmd.cpp
	handle_sound_cmd.h
	handle_text_cmd.cpp
	handle_text_cmd.h)

target_include_directories(read_from_file INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}")
