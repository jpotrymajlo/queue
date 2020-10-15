add_library(queue STATIC "")
target_include_directories(queue PRIVATE ${CMAKE_CURRENT_LIST_DIR}/..)

target_sources(queue PRIVATE queue.cpp queue.h)

