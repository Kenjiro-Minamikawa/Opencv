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
include CMakeFiles/cv26.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cv26.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cv26.dir/flags.make

CMakeFiles/cv26.dir/cv26.cpp.o: CMakeFiles/cv26.dir/flags.make
CMakeFiles/cv26.dir/cv26.cpp.o: ../cv26.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/minamikawa/Opencv/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cv26.dir/cv26.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cv26.dir/cv26.cpp.o -c /home/minamikawa/Opencv/cv26.cpp

CMakeFiles/cv26.dir/cv26.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cv26.dir/cv26.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/minamikawa/Opencv/cv26.cpp > CMakeFiles/cv26.dir/cv26.cpp.i

CMakeFiles/cv26.dir/cv26.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cv26.dir/cv26.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/minamikawa/Opencv/cv26.cpp -o CMakeFiles/cv26.dir/cv26.cpp.s

CMakeFiles/cv26.dir/cv26.cpp.o.requires:

.PHONY : CMakeFiles/cv26.dir/cv26.cpp.o.requires

CMakeFiles/cv26.dir/cv26.cpp.o.provides: CMakeFiles/cv26.dir/cv26.cpp.o.requires
	$(MAKE) -f CMakeFiles/cv26.dir/build.make CMakeFiles/cv26.dir/cv26.cpp.o.provides.build
.PHONY : CMakeFiles/cv26.dir/cv26.cpp.o.provides

CMakeFiles/cv26.dir/cv26.cpp.o.provides.build: CMakeFiles/cv26.dir/cv26.cpp.o


# Object files for target cv26
cv26_OBJECTS = \
"CMakeFiles/cv26.dir/cv26.cpp.o"

# External object files for target cv26
cv26_EXTERNAL_OBJECTS =

cv26: CMakeFiles/cv26.dir/cv26.cpp.o
cv26: CMakeFiles/cv26.dir/build.make
cv26: CMakeFiles/cv26.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/minamikawa/Opencv/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cv26"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cv26.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cv26.dir/build: cv26

.PHONY : CMakeFiles/cv26.dir/build

CMakeFiles/cv26.dir/requires: CMakeFiles/cv26.dir/cv26.cpp.o.requires

.PHONY : CMakeFiles/cv26.dir/requires

CMakeFiles/cv26.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cv26.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cv26.dir/clean

CMakeFiles/cv26.dir/depend:
	cd /home/minamikawa/Opencv/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/minamikawa/Opencv /home/minamikawa/Opencv /home/minamikawa/Opencv/build /home/minamikawa/Opencv/build /home/minamikawa/Opencv/build/CMakeFiles/cv26.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cv26.dir/depend

