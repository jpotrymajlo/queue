cmake_minimum_required(VERSION 3.14)
project(testapp LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(libs)
add_subdirectory(testapp)

