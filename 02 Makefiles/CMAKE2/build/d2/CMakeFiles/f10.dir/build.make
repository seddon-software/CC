# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/chris/CMAKE_DEMO/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chris/CMAKE_DEMO/build

# Include any dependencies generated for this target.
include d2/CMakeFiles/f10.dir/depend.make

# Include the progress variables for this target.
include d2/CMakeFiles/f10.dir/progress.make

# Include the compile flags for this target's objects.
include d2/CMakeFiles/f10.dir/flags.make

d2/CMakeFiles/f10.dir/f10.c.o: d2/CMakeFiles/f10.dir/flags.make
d2/CMakeFiles/f10.dir/f10.c.o: /home/chris/CMAKE_DEMO/src/d2/f10.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chris/CMAKE_DEMO/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object d2/CMakeFiles/f10.dir/f10.c.o"
	cd /home/chris/CMAKE_DEMO/build/d2 && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/f10.dir/f10.c.o   -c /home/chris/CMAKE_DEMO/src/d2/f10.c

d2/CMakeFiles/f10.dir/f10.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/f10.dir/f10.c.i"
	cd /home/chris/CMAKE_DEMO/build/d2 && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chris/CMAKE_DEMO/src/d2/f10.c > CMakeFiles/f10.dir/f10.c.i

d2/CMakeFiles/f10.dir/f10.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/f10.dir/f10.c.s"
	cd /home/chris/CMAKE_DEMO/build/d2 && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chris/CMAKE_DEMO/src/d2/f10.c -o CMakeFiles/f10.dir/f10.c.s

# Object files for target f10
f10_OBJECTS = \
"CMakeFiles/f10.dir/f10.c.o"

# External object files for target f10
f10_EXTERNAL_OBJECTS =

/home/chris/CMAKE_DEMO/src/d2/f10: d2/CMakeFiles/f10.dir/f10.c.o
/home/chris/CMAKE_DEMO/src/d2/f10: d2/CMakeFiles/f10.dir/build.make
/home/chris/CMAKE_DEMO/src/d2/f10: d2/CMakeFiles/f10.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chris/CMAKE_DEMO/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable /home/chris/CMAKE_DEMO/src/d2/f10"
	cd /home/chris/CMAKE_DEMO/build/d2 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/f10.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
d2/CMakeFiles/f10.dir/build: /home/chris/CMAKE_DEMO/src/d2/f10

.PHONY : d2/CMakeFiles/f10.dir/build

d2/CMakeFiles/f10.dir/clean:
	cd /home/chris/CMAKE_DEMO/build/d2 && $(CMAKE_COMMAND) -P CMakeFiles/f10.dir/cmake_clean.cmake
.PHONY : d2/CMakeFiles/f10.dir/clean

d2/CMakeFiles/f10.dir/depend:
	cd /home/chris/CMAKE_DEMO/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chris/CMAKE_DEMO/src /home/chris/CMAKE_DEMO/src/d2 /home/chris/CMAKE_DEMO/build /home/chris/CMAKE_DEMO/build/d2 /home/chris/CMAKE_DEMO/build/d2/CMakeFiles/f10.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : d2/CMakeFiles/f10.dir/depend

