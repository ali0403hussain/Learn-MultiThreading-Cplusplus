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
CMAKE_SOURCE_DIR = /mnt/c/MyWorkspace/MultiThreading/04.ChronoDurations

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/MyWorkspace/MultiThreading/04.ChronoDurations/build

# Include any dependencies generated for this target.
include src/app/CMakeFiles/ChronoDurations.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/app/CMakeFiles/ChronoDurations.dir/compiler_depend.make

# Include the progress variables for this target.
include src/app/CMakeFiles/ChronoDurations.dir/progress.make

# Include the compile flags for this target's objects.
include src/app/CMakeFiles/ChronoDurations.dir/flags.make

src/app/CMakeFiles/ChronoDurations.dir/main.cpp.o: src/app/CMakeFiles/ChronoDurations.dir/flags.make
src/app/CMakeFiles/ChronoDurations.dir/main.cpp.o: ../src/app/main.cpp
src/app/CMakeFiles/ChronoDurations.dir/main.cpp.o: src/app/CMakeFiles/ChronoDurations.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/MyWorkspace/MultiThreading/04.ChronoDurations/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/app/CMakeFiles/ChronoDurations.dir/main.cpp.o"
	cd /mnt/c/MyWorkspace/MultiThreading/04.ChronoDurations/build/src/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/app/CMakeFiles/ChronoDurations.dir/main.cpp.o -MF CMakeFiles/ChronoDurations.dir/main.cpp.o.d -o CMakeFiles/ChronoDurations.dir/main.cpp.o -c /mnt/c/MyWorkspace/MultiThreading/04.ChronoDurations/src/app/main.cpp

src/app/CMakeFiles/ChronoDurations.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChronoDurations.dir/main.cpp.i"
	cd /mnt/c/MyWorkspace/MultiThreading/04.ChronoDurations/build/src/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/MyWorkspace/MultiThreading/04.ChronoDurations/src/app/main.cpp > CMakeFiles/ChronoDurations.dir/main.cpp.i

src/app/CMakeFiles/ChronoDurations.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChronoDurations.dir/main.cpp.s"
	cd /mnt/c/MyWorkspace/MultiThreading/04.ChronoDurations/build/src/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/MyWorkspace/MultiThreading/04.ChronoDurations/src/app/main.cpp -o CMakeFiles/ChronoDurations.dir/main.cpp.s

# Object files for target ChronoDurations
ChronoDurations_OBJECTS = \
"CMakeFiles/ChronoDurations.dir/main.cpp.o"

# External object files for target ChronoDurations
ChronoDurations_EXTERNAL_OBJECTS =

src/app/ChronoDurations: src/app/CMakeFiles/ChronoDurations.dir/main.cpp.o
src/app/ChronoDurations: src/app/CMakeFiles/ChronoDurations.dir/build.make
src/app/ChronoDurations: src/app/CMakeFiles/ChronoDurations.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/MyWorkspace/MultiThreading/04.ChronoDurations/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ChronoDurations"
	cd /mnt/c/MyWorkspace/MultiThreading/04.ChronoDurations/build/src/app && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ChronoDurations.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/app/CMakeFiles/ChronoDurations.dir/build: src/app/ChronoDurations
.PHONY : src/app/CMakeFiles/ChronoDurations.dir/build

src/app/CMakeFiles/ChronoDurations.dir/clean:
	cd /mnt/c/MyWorkspace/MultiThreading/04.ChronoDurations/build/src/app && $(CMAKE_COMMAND) -P CMakeFiles/ChronoDurations.dir/cmake_clean.cmake
.PHONY : src/app/CMakeFiles/ChronoDurations.dir/clean

src/app/CMakeFiles/ChronoDurations.dir/depend:
	cd /mnt/c/MyWorkspace/MultiThreading/04.ChronoDurations/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/MyWorkspace/MultiThreading/04.ChronoDurations /mnt/c/MyWorkspace/MultiThreading/04.ChronoDurations/src/app /mnt/c/MyWorkspace/MultiThreading/04.ChronoDurations/build /mnt/c/MyWorkspace/MultiThreading/04.ChronoDurations/build/src/app /mnt/c/MyWorkspace/MultiThreading/04.ChronoDurations/build/src/app/CMakeFiles/ChronoDurations.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/app/CMakeFiles/ChronoDurations.dir/depend

