cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set the project name
project(CMAKE)

# create runtime files in src directory
# however, this makes it difficult to clean up
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../src) 

# add the executables
file(GLOB F_FILES "f*.c")
file(GLOB G_FILES "f*.c")
add_executable(f ${F_FILES})
add_executable(g ${G_FILES})
