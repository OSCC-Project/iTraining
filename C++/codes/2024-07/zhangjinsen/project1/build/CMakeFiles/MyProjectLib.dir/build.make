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
CMAKE_SOURCE_DIR = /home/zjs/modern-cpp-template

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zjs/modern-cpp-template/build

# Include any dependencies generated for this target.
include CMakeFiles/MyProjectLib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MyProjectLib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MyProjectLib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MyProjectLib.dir/flags.make

CMakeFiles/MyProjectLib.dir/src/main.cpp.o: CMakeFiles/MyProjectLib.dir/flags.make
CMakeFiles/MyProjectLib.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/MyProjectLib.dir/src/main.cpp.o: CMakeFiles/MyProjectLib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zjs/modern-cpp-template/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MyProjectLib.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MyProjectLib.dir/src/main.cpp.o -MF CMakeFiles/MyProjectLib.dir/src/main.cpp.o.d -o CMakeFiles/MyProjectLib.dir/src/main.cpp.o -c /home/zjs/modern-cpp-template/src/main.cpp

CMakeFiles/MyProjectLib.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyProjectLib.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zjs/modern-cpp-template/src/main.cpp > CMakeFiles/MyProjectLib.dir/src/main.cpp.i

CMakeFiles/MyProjectLib.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyProjectLib.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zjs/modern-cpp-template/src/main.cpp -o CMakeFiles/MyProjectLib.dir/src/main.cpp.s

# Object files for target MyProjectLib
MyProjectLib_OBJECTS = \
"CMakeFiles/MyProjectLib.dir/src/main.cpp.o"

# External object files for target MyProjectLib
MyProjectLib_EXTERNAL_OBJECTS =

libMyProjectLib.a: CMakeFiles/MyProjectLib.dir/src/main.cpp.o
libMyProjectLib.a: CMakeFiles/MyProjectLib.dir/build.make
libMyProjectLib.a: CMakeFiles/MyProjectLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zjs/modern-cpp-template/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libMyProjectLib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/MyProjectLib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MyProjectLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MyProjectLib.dir/build: libMyProjectLib.a
.PHONY : CMakeFiles/MyProjectLib.dir/build

CMakeFiles/MyProjectLib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MyProjectLib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MyProjectLib.dir/clean

CMakeFiles/MyProjectLib.dir/depend:
	cd /home/zjs/modern-cpp-template/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zjs/modern-cpp-template /home/zjs/modern-cpp-template /home/zjs/modern-cpp-template/build /home/zjs/modern-cpp-template/build /home/zjs/modern-cpp-template/build/CMakeFiles/MyProjectLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MyProjectLib.dir/depend
