add_library(utils 
	alter_text/alter_text.cpp
	alter_text/alter_text.h
	customize_text/customize_text.cpp
	customize_text/customize_text.h
	handle_sound/handle_sound.cpp
	handle_sound/handle_sound.h
	JSON_interaction/JSON_interaction.h
	print_and_clear_screen/clear_screen.cpp
	print_and_clear_screen/clear_screen.h
	print_and_clear_screen/print.cpp
	print_and_clear_screen/print.h
	roll_dice/roll_dice.cpp
	roll_dice/roll_dice.h
	string_sanitization/string_sanitization.cpp
	string_sanitization/string_sanitization.h
	user_choice/get_user_constrained_choice.cpp
	user_choice/get_user_constrained_choice.h
	user_choice/get_user_free_choice.cpp
	user_choice/get_user_free_choice.h
	user_choice/get_user_input.cpp
	user_choice/get_user_input.h
	utils.h)

target_include_directories(utils INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}")
