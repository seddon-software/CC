# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/chris/home/workspace/CC/24 Makefiles/CMAKE2/src"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/chris/home/workspace/CC/24 Makefiles/CMAKE2/build"

# Include any dependencies generated for this target.
include d1/CMakeFiles/f8.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include d1/CMakeFiles/f8.dir/compiler_depend.make

# Include the progress variables for this target.
include d1/CMakeFiles/f8.dir/progress.make

# Include the compile flags for this target's objects.
include d1/CMakeFiles/f8.dir/flags.make

d1/CMakeFiles/f8.dir/f8.c.o: d1/CMakeFiles/f8.dir/flags.make
d1/CMakeFiles/f8.dir/f8.c.o: /home/chris/home/workspace/CC/24\ Makefiles/CMAKE2/src/d1/f8.c
d1/CMakeFiles/f8.dir/f8.c.o: d1/CMakeFiles/f8.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/chris/home/workspace/CC/24 Makefiles/CMAKE2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object d1/CMakeFiles/f8.dir/f8.c.o"
	cd "/home/chris/home/workspace/CC/24 Makefiles/CMAKE2/build/d1" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT d1/CMakeFiles/f8.dir/f8.c.o -MF CMakeFiles/f8.dir/f8.c.o.d -o CMakeFiles/f8.dir/f8.c.o -c "/home/chris/home/workspace/CC/24 Makefiles/CMAKE2/src/d1/f8.c"

d1/CMakeFiles/f8.dir/f8.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/f8.dir/f8.c.i"
	cd "/home/chris/home/workspace/CC/24 Makefiles/CMAKE2/build/d1" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/chris/home/workspace/CC/24 Makefiles/CMAKE2/src/d1/f8.c" > CMakeFiles/f8.dir/f8.c.i

d1/CMakeFiles/f8.dir/f8.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/f8.dir/f8.c.s"
	cd "/home/chris/home/workspace/CC/24 Makefiles/CMAKE2/build/d1" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/chris/home/workspace/CC/24 Makefiles/CMAKE2/src/d1/f8.c" -o CMakeFiles/f8.dir/f8.c.s

# Object files for target f8
f8_OBJECTS = \
"CMakeFiles/f8.dir/f8.c.o"

# External object files for target f8
f8_EXTERNAL_OBJECTS =

/home/chris/home/workspace/CC/24\ Makefiles/CMAKE2/src/d1/f8: d1/CMakeFiles/f8.dir/f8.c.o
/home/chris/home/workspace/CC/24\ Makefiles/CMAKE2/src/d1/f8: d1/CMakeFiles/f8.dir/build.make
/home/chris/home/workspace/CC/24\ Makefiles/CMAKE2/src/d1/f8: d1/CMakeFiles/f8.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/chris/home/workspace/CC/24 Makefiles/CMAKE2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable \"/home/chris/home/workspace/CC/24 Makefiles/CMAKE2/src/d1/f8\""
	cd "/home/chris/home/workspace/CC/24 Makefiles/CMAKE2/build/d1" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/f8.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
d1/CMakeFiles/f8.dir/build: /home/chris/home/workspace/CC/24\ Makefiles/CMAKE2/src/d1/f8
.PHONY : d1/CMakeFiles/f8.dir/build

d1/CMakeFiles/f8.dir/clean:
	cd "/home/chris/home/workspace/CC/24 Makefiles/CMAKE2/build/d1" && $(CMAKE_COMMAND) -P CMakeFiles/f8.dir/cmake_clean.cmake
.PHONY : d1/CMakeFiles/f8.dir/clean

d1/CMakeFiles/f8.dir/depend:
	cd "/home/chris/home/workspace/CC/24 Makefiles/CMAKE2/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/chris/home/workspace/CC/24 Makefiles/CMAKE2/src" "/home/chris/home/workspace/CC/24 Makefiles/CMAKE2/src/d1" "/home/chris/home/workspace/CC/24 Makefiles/CMAKE2/build" "/home/chris/home/workspace/CC/24 Makefiles/CMAKE2/build/d1" "/home/chris/home/workspace/CC/24 Makefiles/CMAKE2/build/d1/CMakeFiles/f8.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : d1/CMakeFiles/f8.dir/depend

