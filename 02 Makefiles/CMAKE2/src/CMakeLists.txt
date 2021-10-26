cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set the project name
project(CMAKE2)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../src) 
# add the executables
add_executable(f1 f1.c)
add_executable(f2 f2.c)
add_executable(f3 f3.c)
add_executable(f4 f4.c)

add_subdirectory(d1)
add_subdirectory(d2)
