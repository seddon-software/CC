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
CMAKE_SOURCE_DIR = "/home/chris/home/workspace/CC/24 Makefiles/CMAKE/src"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/chris/home/workspace/CC/24 Makefiles/CMAKE/build"

# Include any dependencies generated for this target.
include CMakeFiles/g.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/g.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/g.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/g.dir/flags.make

CMakeFiles/g.dir/g1.c.o: CMakeFiles/g.dir/flags.make
CMakeFiles/g.dir/g1.c.o: /home/chris/home/workspace/CC/24\ Makefiles/CMAKE/src/g1.c
CMakeFiles/g.dir/g1.c.o: CMakeFiles/g.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/chris/home/workspace/CC/24 Makefiles/CMAKE/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/g.dir/g1.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/g.dir/g1.c.o -MF CMakeFiles/g.dir/g1.c.o.d -o CMakeFiles/g.dir/g1.c.o -c "/home/chris/home/workspace/CC/24 Makefiles/CMAKE/src/g1.c"

CMakeFiles/g.dir/g1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/g.dir/g1.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/chris/home/workspace/CC/24 Makefiles/CMAKE/src/g1.c" > CMakeFiles/g.dir/g1.c.i

CMakeFiles/g.dir/g1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/g.dir/g1.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/chris/home/workspace/CC/24 Makefiles/CMAKE/src/g1.c" -o CMakeFiles/g.dir/g1.c.s

CMakeFiles/g.dir/g2.c.o: CMakeFiles/g.dir/flags.make
CMakeFiles/g.dir/g2.c.o: /home/chris/home/workspace/CC/24\ Makefiles/CMAKE/src/g2.c
CMakeFiles/g.dir/g2.c.o: CMakeFiles/g.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/chris/home/workspace/CC/24 Makefiles/CMAKE/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/g.dir/g2.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/g.dir/g2.c.o -MF CMakeFiles/g.dir/g2.c.o.d -o CMakeFiles/g.dir/g2.c.o -c "/home/chris/home/workspace/CC/24 Makefiles/CMAKE/src/g2.c"

CMakeFiles/g.dir/g2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/g.dir/g2.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/chris/home/workspace/CC/24 Makefiles/CMAKE/src/g2.c" > CMakeFiles/g.dir/g2.c.i

CMakeFiles/g.dir/g2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/g.dir/g2.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/chris/home/workspace/CC/24 Makefiles/CMAKE/src/g2.c" -o CMakeFiles/g.dir/g2.c.s

CMakeFiles/g.dir/g3.c.o: CMakeFiles/g.dir/flags.make
CMakeFiles/g.dir/g3.c.o: /home/chris/home/workspace/CC/24\ Makefiles/CMAKE/src/g3.c
CMakeFiles/g.dir/g3.c.o: CMakeFiles/g.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/chris/home/workspace/CC/24 Makefiles/CMAKE/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/g.dir/g3.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/g.dir/g3.c.o -MF CMakeFiles/g.dir/g3.c.o.d -o CMakeFiles/g.dir/g3.c.o -c "/home/chris/home/workspace/CC/24 Makefiles/CMAKE/src/g3.c"

CMakeFiles/g.dir/g3.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/g.dir/g3.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/chris/home/workspace/CC/24 Makefiles/CMAKE/src/g3.c" > CMakeFiles/g.dir/g3.c.i

CMakeFiles/g.dir/g3.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/g.dir/g3.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/chris/home/workspace/CC/24 Makefiles/CMAKE/src/g3.c" -o CMakeFiles/g.dir/g3.c.s

CMakeFiles/g.dir/g_main.c.o: CMakeFiles/g.dir/flags.make
CMakeFiles/g.dir/g_main.c.o: /home/chris/home/workspace/CC/24\ Makefiles/CMAKE/src/g_main.c
CMakeFiles/g.dir/g_main.c.o: CMakeFiles/g.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/chris/home/workspace/CC/24 Makefiles/CMAKE/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/g.dir/g_main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/g.dir/g_main.c.o -MF CMakeFiles/g.dir/g_main.c.o.d -o CMakeFiles/g.dir/g_main.c.o -c "/home/chris/home/workspace/CC/24 Makefiles/CMAKE/src/g_main.c"

CMakeFiles/g.dir/g_main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/g.dir/g_main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/chris/home/workspace/CC/24 Makefiles/CMAKE/src/g_main.c" > CMakeFiles/g.dir/g_main.c.i

CMakeFiles/g.dir/g_main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/g.dir/g_main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/chris/home/workspace/CC/24 Makefiles/CMAKE/src/g_main.c" -o CMakeFiles/g.dir/g_main.c.s

# Object files for target g
g_OBJECTS = \
"CMakeFiles/g.dir/g1.c.o" \
"CMakeFiles/g.dir/g2.c.o" \
"CMakeFiles/g.dir/g3.c.o" \
"CMakeFiles/g.dir/g_main.c.o"

# External object files for target g
g_EXTERNAL_OBJECTS =

/home/chris/home/workspace/CC/24\ Makefiles/CMAKE/src/g: CMakeFiles/g.dir/g1.c.o
/home/chris/home/workspace/CC/24\ Makefiles/CMAKE/src/g: CMakeFiles/g.dir/g2.c.o
/home/chris/home/workspace/CC/24\ Makefiles/CMAKE/src/g: CMakeFiles/g.dir/g3.c.o
/home/chris/home/workspace/CC/24\ Makefiles/CMAKE/src/g: CMakeFiles/g.dir/g_main.c.o
/home/chris/home/workspace/CC/24\ Makefiles/CMAKE/src/g: CMakeFiles/g.dir/build.make
/home/chris/home/workspace/CC/24\ Makefiles/CMAKE/src/g: CMakeFiles/g.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/chris/home/workspace/CC/24 Makefiles/CMAKE/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable \"/home/chris/home/workspace/CC/24 Makefiles/CMAKE/src/g\""
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/g.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/g.dir/build: /home/chris/home/workspace/CC/24\ Makefiles/CMAKE/src/g
.PHONY : CMakeFiles/g.dir/build

CMakeFiles/g.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/g.dir/cmake_clean.cmake
.PHONY : CMakeFiles/g.dir/clean

CMakeFiles/g.dir/depend:
	cd "/home/chris/home/workspace/CC/24 Makefiles/CMAKE/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/chris/home/workspace/CC/24 Makefiles/CMAKE/src" "/home/chris/home/workspace/CC/24 Makefiles/CMAKE/src" "/home/chris/home/workspace/CC/24 Makefiles/CMAKE/build" "/home/chris/home/workspace/CC/24 Makefiles/CMAKE/build" "/home/chris/home/workspace/CC/24 Makefiles/CMAKE/build/CMakeFiles/g.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/g.dir/depend

