
add_executable(testapp main.cpp)

target_include_directories(testapp PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../libs)
target_link_libraries(testapp PUBLIC input queue obfuscator)
