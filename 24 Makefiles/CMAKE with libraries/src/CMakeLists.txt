############################################################
# link with shared library
############################################################

cmake_minimum_required(VERSION 3.10)
# set the project name
project(CMAKE2)

#set(CMAKE_C_COMPILER "/usr/bin/gcc")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
file(GLOB SOURCES main.c ../lib/*.h)
set(CMAKE_BUILD_TYPE Debug)
set(PROJECT_LINK_LIBS libmylib.so )
link_directories(../build-lib )

# add the executables
add_executable(main ${SOURCES})
target_include_directories(main PRIVATE ../lib)
target_link_libraries(main mylib)
#link_libraries("/home/chris/home/workspace/CC/24 Makefiles/CMAKE with librariesS/build-lib")
