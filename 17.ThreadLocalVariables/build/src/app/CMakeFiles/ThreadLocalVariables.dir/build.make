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
CMAKE_SOURCE_DIR = /mnt/c/MyWorkspace/MultiThreading/17.ThreadLocalVariables

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/MyWorkspace/MultiThreading/17.ThreadLocalVariables/build

# Include any dependencies generated for this target.
include src/app/CMakeFiles/ThreadLocalVariables.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/app/CMakeFiles/ThreadLocalVariables.dir/compiler_depend.make

# Include the progress variables for this target.
include src/app/CMakeFiles/ThreadLocalVariables.dir/progress.make

# Include the compile flags for this target's objects.
include src/app/CMakeFiles/ThreadLocalVariables.dir/flags.make

src/app/CMakeFiles/ThreadLocalVariables.dir/main.cpp.o: src/app/CMakeFiles/ThreadLocalVariables.dir/flags.make
src/app/CMakeFiles/ThreadLocalVariables.dir/main.cpp.o: ../src/app/main.cpp
src/app/CMakeFiles/ThreadLocalVariables.dir/main.cpp.o: src/app/CMakeFiles/ThreadLocalVariables.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/MyWorkspace/MultiThreading/17.ThreadLocalVariables/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/app/CMakeFiles/ThreadLocalVariables.dir/main.cpp.o"
	cd /mnt/c/MyWorkspace/MultiThreading/17.ThreadLocalVariables/build/src/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/app/CMakeFiles/ThreadLocalVariables.dir/main.cpp.o -MF CMakeFiles/ThreadLocalVariables.dir/main.cpp.o.d -o CMakeFiles/ThreadLocalVariables.dir/main.cpp.o -c /mnt/c/MyWorkspace/MultiThreading/17.ThreadLocalVariables/src/app/main.cpp

src/app/CMakeFiles/ThreadLocalVariables.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ThreadLocalVariables.dir/main.cpp.i"
	cd /mnt/c/MyWorkspace/MultiThreading/17.ThreadLocalVariables/build/src/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/MyWorkspace/MultiThreading/17.ThreadLocalVariables/src/app/main.cpp > CMakeFiles/ThreadLocalVariables.dir/main.cpp.i

src/app/CMakeFiles/ThreadLocalVariables.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ThreadLocalVariables.dir/main.cpp.s"
	cd /mnt/c/MyWorkspace/MultiThreading/17.ThreadLocalVariables/build/src/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/MyWorkspace/MultiThreading/17.ThreadLocalVariables/src/app/main.cpp -o CMakeFiles/ThreadLocalVariables.dir/main.cpp.s

# Object files for target ThreadLocalVariables
ThreadLocalVariables_OBJECTS = \
"CMakeFiles/ThreadLocalVariables.dir/main.cpp.o"

# External object files for target ThreadLocalVariables
ThreadLocalVariables_EXTERNAL_OBJECTS =

src/app/ThreadLocalVariables: src/app/CMakeFiles/ThreadLocalVariables.dir/main.cpp.o
src/app/ThreadLocalVariables: src/app/CMakeFiles/ThreadLocalVariables.dir/build.make
src/app/ThreadLocalVariables: src/app/CMakeFiles/ThreadLocalVariables.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/MyWorkspace/MultiThreading/17.ThreadLocalVariables/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ThreadLocalVariables"
	cd /mnt/c/MyWorkspace/MultiThreading/17.ThreadLocalVariables/build/src/app && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ThreadLocalVariables.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/app/CMakeFiles/ThreadLocalVariables.dir/build: src/app/ThreadLocalVariables
.PHONY : src/app/CMakeFiles/ThreadLocalVariables.dir/build

src/app/CMakeFiles/ThreadLocalVariables.dir/clean:
	cd /mnt/c/MyWorkspace/MultiThreading/17.ThreadLocalVariables/build/src/app && $(CMAKE_COMMAND) -P CMakeFiles/ThreadLocalVariables.dir/cmake_clean.cmake
.PHONY : src/app/CMakeFiles/ThreadLocalVariables.dir/clean

src/app/CMakeFiles/ThreadLocalVariables.dir/depend:
	cd /mnt/c/MyWorkspace/MultiThreading/17.ThreadLocalVariables/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/MyWorkspace/MultiThreading/17.ThreadLocalVariables /mnt/c/MyWorkspace/MultiThreading/17.ThreadLocalVariables/src/app /mnt/c/MyWorkspace/MultiThreading/17.ThreadLocalVariables/build /mnt/c/MyWorkspace/MultiThreading/17.ThreadLocalVariables/build/src/app /mnt/c/MyWorkspace/MultiThreading/17.ThreadLocalVariables/build/src/app/CMakeFiles/ThreadLocalVariables.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/app/CMakeFiles/ThreadLocalVariables.dir/depend
