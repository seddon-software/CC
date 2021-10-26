cmake_minimum_required(VERSION 3.10)

# set the project name
project(Tutorial)

# add the executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(f9 f9.c)
add_executable(f10 f10.c)
add_executable(f11 f11.c)
add_executable(f12 f12.c)

