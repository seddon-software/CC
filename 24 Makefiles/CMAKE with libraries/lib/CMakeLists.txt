############################################################
# cmake for shared library
############################################################

# set the project name
project(CMAKE_SHARED_LIBS)

cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(BUILD_SHARED_LIBS ON)

# create the library with all the lib/f*.c files
# these are called from src/main.c
file(GLOB SOURCES f*.c)

# create the library
add_library(mylib SHARED ${SOURCES})
