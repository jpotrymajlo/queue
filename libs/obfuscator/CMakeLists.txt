add_library(obfuscator STATIC "")
target_include_directories(obfuscator PRIVATE ${CMAKE_CURRENT_LIST_DIR}/..)

target_sources(obfuscator PRIVATE obfuscator.cpp obfuscator.h)

