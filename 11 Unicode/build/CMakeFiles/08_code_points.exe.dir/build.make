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
CMAKE_SOURCE_DIR = /home/chris/home/workspace/cpp/A28_Unicode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chris/home/workspace/cpp/A28_Unicode/build

# Include any dependencies generated for this target.
include CMakeFiles/08_code_points.exe.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/08_code_points.exe.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/08_code_points.exe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/08_code_points.exe.dir/flags.make

CMakeFiles/08_code_points.exe.dir/08_code_points.cpp.o: CMakeFiles/08_code_points.exe.dir/flags.make
CMakeFiles/08_code_points.exe.dir/08_code_points.cpp.o: ../08_code_points.cpp
CMakeFiles/08_code_points.exe.dir/08_code_points.cpp.o: CMakeFiles/08_code_points.exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chris/home/workspace/cpp/A28_Unicode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/08_code_points.exe.dir/08_code_points.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/08_code_points.exe.dir/08_code_points.cpp.o -MF CMakeFiles/08_code_points.exe.dir/08_code_points.cpp.o.d -o CMakeFiles/08_code_points.exe.dir/08_code_points.cpp.o -c /home/chris/home/workspace/cpp/A28_Unicode/08_code_points.cpp

CMakeFiles/08_code_points.exe.dir/08_code_points.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/08_code_points.exe.dir/08_code_points.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chris/home/workspace/cpp/A28_Unicode/08_code_points.cpp > CMakeFiles/08_code_points.exe.dir/08_code_points.cpp.i

CMakeFiles/08_code_points.exe.dir/08_code_points.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/08_code_points.exe.dir/08_code_points.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chris/home/workspace/cpp/A28_Unicode/08_code_points.cpp -o CMakeFiles/08_code_points.exe.dir/08_code_points.cpp.s

# Object files for target 08_code_points.exe
08_code_points_exe_OBJECTS = \
"CMakeFiles/08_code_points.exe.dir/08_code_points.cpp.o"

# External object files for target 08_code_points.exe
08_code_points_exe_EXTERNAL_OBJECTS =

08_code_points.exe: CMakeFiles/08_code_points.exe.dir/08_code_points.cpp.o
08_code_points.exe: CMakeFiles/08_code_points.exe.dir/build.make
08_code_points.exe: CMakeFiles/08_code_points.exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chris/home/workspace/cpp/A28_Unicode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 08_code_points.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/08_code_points.exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/08_code_points.exe.dir/build: 08_code_points.exe
.PHONY : CMakeFiles/08_code_points.exe.dir/build

CMakeFiles/08_code_points.exe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/08_code_points.exe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/08_code_points.exe.dir/clean

CMakeFiles/08_code_points.exe.dir/depend:
	cd /home/chris/home/workspace/cpp/A28_Unicode/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chris/home/workspace/cpp/A28_Unicode /home/chris/home/workspace/cpp/A28_Unicode /home/chris/home/workspace/cpp/A28_Unicode/build /home/chris/home/workspace/cpp/A28_Unicode/build /home/chris/home/workspace/cpp/A28_Unicode/build/CMakeFiles/08_code_points.exe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/08_code_points.exe.dir/depend

