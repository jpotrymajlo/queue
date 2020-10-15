add_library(input STATIC "")
target_sources(input PRIVATE input.cpp input.h)
target_include_directories(input PRIVATE ${CMAKE_CURRENT_LIST_DIR}/..)

