cmake_minimum_required(VERSION 3.10)

# set the project name
project(Tutorial)

# add the executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(f5 f5.c)
add_executable(f6 f6.c)
add_executable(f7 f7.c)
add_executable(f8 f8.c)

