# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/minamikawa/Opencv

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/minamikawa/Opencv/build

# Include any dependencies generated for this target.
include CMakeFiles/cv19.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cv19.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cv19.dir/flags.make

CMakeFiles/cv19.dir/cv19.cpp.o: CMakeFiles/cv19.dir/flags.make
CMakeFiles/cv19.dir/cv19.cpp.o: ../cv19.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/minamikawa/Opencv/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cv19.dir/cv19.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cv19.dir/cv19.cpp.o -c /home/minamikawa/Opencv/cv19.cpp

CMakeFiles/cv19.dir/cv19.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cv19.dir/cv19.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/minamikawa/Opencv/cv19.cpp > CMakeFiles/cv19.dir/cv19.cpp.i

CMakeFiles/cv19.dir/cv19.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cv19.dir/cv19.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/minamikawa/Opencv/cv19.cpp -o CMakeFiles/cv19.dir/cv19.cpp.s

CMakeFiles/cv19.dir/cv19.cpp.o.requires:

.PHONY : CMakeFiles/cv19.dir/cv19.cpp.o.requires

CMakeFiles/cv19.dir/cv19.cpp.o.provides: CMakeFiles/cv19.dir/cv19.cpp.o.requires
	$(MAKE) -f CMakeFiles/cv19.dir/build.make CMakeFiles/cv19.dir/cv19.cpp.o.provides.build
.PHONY : CMakeFiles/cv19.dir/cv19.cpp.o.provides

CMakeFiles/cv19.dir/cv19.cpp.o.provides.build: CMakeFiles/cv19.dir/cv19.cpp.o


# Object files for target cv19
cv19_OBJECTS = \
"CMakeFiles/cv19.dir/cv19.cpp.o"

# External object files for target cv19
cv19_EXTERNAL_OBJECTS =

cv19: CMakeFiles/cv19.dir/cv19.cpp.o
cv19: CMakeFiles/cv19.dir/build.make
cv19: CMakeFiles/cv19.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/minamikawa/Opencv/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cv19"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cv19.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cv19.dir/build: cv19

.PHONY : CMakeFiles/cv19.dir/build

CMakeFiles/cv19.dir/requires: CMakeFiles/cv19.dir/cv19.cpp.o.requires

.PHONY : CMakeFiles/cv19.dir/requires

CMakeFiles/cv19.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cv19.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cv19.dir/clean

CMakeFiles/cv19.dir/depend:
	cd /home/minamikawa/Opencv/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/minamikawa/Opencv /home/minamikawa/Opencv /home/minamikawa/Opencv/build /home/minamikawa/Opencv/build /home/minamikawa/Opencv/build/CMakeFiles/cv19.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cv19.dir/depend

