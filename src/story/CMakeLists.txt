add_library(story 
	prologue.cpp
	prologue.h)

target_include_directories(story INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}")
