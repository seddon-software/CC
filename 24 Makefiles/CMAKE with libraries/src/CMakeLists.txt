############################################################
# link with shared library
############################################################

cmake_minimum_required(VERSION 3.10)
# set the project name
project(CMAKE_SHARED_LIBS)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# specify source files
#file(GLOB SOURCES main.c ../lib/*.h)
file(GLOB SOURCES main.c)
link_directories(../build-lib )                 # -L../build-lib

# add the executable
add_executable(main ${SOURCES})
target_include_directories(main PRIVATE ../lib) # -I../lib
target_link_libraries(main mylib)               # -lmylib
