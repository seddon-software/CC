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
CMAKE_SOURCE_DIR = "/home/chris/home/workspace/CC/02 Makefiles/CMAKE2/src"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/chris/home/workspace/CC/02 Makefiles/CMAKE2/build"

# Include any dependencies generated for this target.
include d1/CMakeFiles/f6.dir/depend.make

# Include the progress variables for this target.
include d1/CMakeFiles/f6.dir/progress.make

# Include the compile flags for this target's objects.
include d1/CMakeFiles/f6.dir/flags.make

d1/CMakeFiles/f6.dir/f6.c.o: d1/CMakeFiles/f6.dir/flags.make
d1/CMakeFiles/f6.dir/f6.c.o: /home/chris/home/workspace/CC/02\ Makefiles/CMAKE2/src/d1/f6.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/chris/home/workspace/CC/02 Makefiles/CMAKE2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object d1/CMakeFiles/f6.dir/f6.c.o"
	cd "/home/chris/home/workspace/CC/02 Makefiles/CMAKE2/build/d1" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/f6.dir/f6.c.o   -c "/home/chris/home/workspace/CC/02 Makefiles/CMAKE2/src/d1/f6.c"

d1/CMakeFiles/f6.dir/f6.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/f6.dir/f6.c.i"
	cd "/home/chris/home/workspace/CC/02 Makefiles/CMAKE2/build/d1" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/chris/home/workspace/CC/02 Makefiles/CMAKE2/src/d1/f6.c" > CMakeFiles/f6.dir/f6.c.i

d1/CMakeFiles/f6.dir/f6.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/f6.dir/f6.c.s"
	cd "/home/chris/home/workspace/CC/02 Makefiles/CMAKE2/build/d1" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/chris/home/workspace/CC/02 Makefiles/CMAKE2/src/d1/f6.c" -o CMakeFiles/f6.dir/f6.c.s

# Object files for target f6
f6_OBJECTS = \
"CMakeFiles/f6.dir/f6.c.o"

# External object files for target f6
f6_EXTERNAL_OBJECTS =

/home/chris/home/workspace/CC/02\ Makefiles/CMAKE2/src/d1/f6: d1/CMakeFiles/f6.dir/f6.c.o
/home/chris/home/workspace/CC/02\ Makefiles/CMAKE2/src/d1/f6: d1/CMakeFiles/f6.dir/build.make
/home/chris/home/workspace/CC/02\ Makefiles/CMAKE2/src/d1/f6: d1/CMakeFiles/f6.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/chris/home/workspace/CC/02 Makefiles/CMAKE2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable \"/home/chris/home/workspace/CC/02 Makefiles/CMAKE2/src/d1/f6\""
	cd "/home/chris/home/workspace/CC/02 Makefiles/CMAKE2/build/d1" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/f6.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
d1/CMakeFiles/f6.dir/build: /home/chris/home/workspace/CC/02\ Makefiles/CMAKE2/src/d1/f6

.PHONY : d1/CMakeFiles/f6.dir/build

d1/CMakeFiles/f6.dir/clean:
	cd "/home/chris/home/workspace/CC/02 Makefiles/CMAKE2/build/d1" && $(CMAKE_COMMAND) -P CMakeFiles/f6.dir/cmake_clean.cmake
.PHONY : d1/CMakeFiles/f6.dir/clean

d1/CMakeFiles/f6.dir/depend:
	cd "/home/chris/home/workspace/CC/02 Makefiles/CMAKE2/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/chris/home/workspace/CC/02 Makefiles/CMAKE2/src" "/home/chris/home/workspace/CC/02 Makefiles/CMAKE2/src/d1" "/home/chris/home/workspace/CC/02 Makefiles/CMAKE2/build" "/home/chris/home/workspace/CC/02 Makefiles/CMAKE2/build/d1" "/home/chris/home/workspace/CC/02 Makefiles/CMAKE2/build/d1/CMakeFiles/f6.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : d1/CMakeFiles/f6.dir/depend

