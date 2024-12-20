add_library(loading_screen 
	loading_screen.cpp
	loading_screen.h)

target_include_directories(loading_screen INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}")
