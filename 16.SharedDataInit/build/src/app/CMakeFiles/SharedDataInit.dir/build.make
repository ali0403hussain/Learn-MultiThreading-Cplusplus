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
CMAKE_SOURCE_DIR = /mnt/c/MyWorkspace/MultiThreading/16.SharedDataInit

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/MyWorkspace/MultiThreading/16.SharedDataInit/build

# Include any dependencies generated for this target.
include src/app/CMakeFiles/SharedDataInit.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/app/CMakeFiles/SharedDataInit.dir/compiler_depend.make

# Include the progress variables for this target.
include src/app/CMakeFiles/SharedDataInit.dir/progress.make

# Include the compile flags for this target's objects.
include src/app/CMakeFiles/SharedDataInit.dir/flags.make

src/app/CMakeFiles/SharedDataInit.dir/main.cpp.o: src/app/CMakeFiles/SharedDataInit.dir/flags.make
src/app/CMakeFiles/SharedDataInit.dir/main.cpp.o: ../src/app/main.cpp
src/app/CMakeFiles/SharedDataInit.dir/main.cpp.o: src/app/CMakeFiles/SharedDataInit.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/MyWorkspace/MultiThreading/16.SharedDataInit/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/app/CMakeFiles/SharedDataInit.dir/main.cpp.o"
	cd /mnt/c/MyWorkspace/MultiThreading/16.SharedDataInit/build/src/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/app/CMakeFiles/SharedDataInit.dir/main.cpp.o -MF CMakeFiles/SharedDataInit.dir/main.cpp.o.d -o CMakeFiles/SharedDataInit.dir/main.cpp.o -c /mnt/c/MyWorkspace/MultiThreading/16.SharedDataInit/src/app/main.cpp

src/app/CMakeFiles/SharedDataInit.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SharedDataInit.dir/main.cpp.i"
	cd /mnt/c/MyWorkspace/MultiThreading/16.SharedDataInit/build/src/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/MyWorkspace/MultiThreading/16.SharedDataInit/src/app/main.cpp > CMakeFiles/SharedDataInit.dir/main.cpp.i

src/app/CMakeFiles/SharedDataInit.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SharedDataInit.dir/main.cpp.s"
	cd /mnt/c/MyWorkspace/MultiThreading/16.SharedDataInit/build/src/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/MyWorkspace/MultiThreading/16.SharedDataInit/src/app/main.cpp -o CMakeFiles/SharedDataInit.dir/main.cpp.s

# Object files for target SharedDataInit
SharedDataInit_OBJECTS = \
"CMakeFiles/SharedDataInit.dir/main.cpp.o"

# External object files for target SharedDataInit
SharedDataInit_EXTERNAL_OBJECTS =

src/app/SharedDataInit: src/app/CMakeFiles/SharedDataInit.dir/main.cpp.o
src/app/SharedDataInit: src/app/CMakeFiles/SharedDataInit.dir/build.make
src/app/SharedDataInit: src/lib/classicSingleton/libSingletonLib.a
src/app/SharedDataInit: src/lib/cppSingleton/libCppSingletonLib.a
src/app/SharedDataInit: src/app/CMakeFiles/SharedDataInit.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/MyWorkspace/MultiThreading/16.SharedDataInit/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SharedDataInit"
	cd /mnt/c/MyWorkspace/MultiThreading/16.SharedDataInit/build/src/app && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SharedDataInit.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/app/CMakeFiles/SharedDataInit.dir/build: src/app/SharedDataInit
.PHONY : src/app/CMakeFiles/SharedDataInit.dir/build

src/app/CMakeFiles/SharedDataInit.dir/clean:
	cd /mnt/c/MyWorkspace/MultiThreading/16.SharedDataInit/build/src/app && $(CMAKE_COMMAND) -P CMakeFiles/SharedDataInit.dir/cmake_clean.cmake
.PHONY : src/app/CMakeFiles/SharedDataInit.dir/clean

src/app/CMakeFiles/SharedDataInit.dir/depend:
	cd /mnt/c/MyWorkspace/MultiThreading/16.SharedDataInit/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/MyWorkspace/MultiThreading/16.SharedDataInit /mnt/c/MyWorkspace/MultiThreading/16.SharedDataInit/src/app /mnt/c/MyWorkspace/MultiThreading/16.SharedDataInit/build /mnt/c/MyWorkspace/MultiThreading/16.SharedDataInit/build/src/app /mnt/c/MyWorkspace/MultiThreading/16.SharedDataInit/build/src/app/CMakeFiles/SharedDataInit.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/app/CMakeFiles/SharedDataInit.dir/depend
