add_library(start_menu
	continue_game/continue_game.cpp
	continue_game/continue_game.h
	main_settings/change_sound_volume.cpp
	main_settings/change_sound_volume.h
	main_settings/change_text_font.cpp
	main_settings/change_text_font.h
	main_settings/change_text_size.cpp
	main_settings/change_text_size.h
	main_settings/change_text_speed.cpp
	main_settings/change_text_speed.h
	main_settings/change_text_weight.cpp
	main_settings/change_text_weight.h
	start_menu.cpp
	start_menu.h)

target_include_directories(start_menu INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}")
