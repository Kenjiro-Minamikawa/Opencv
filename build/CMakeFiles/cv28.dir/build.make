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
include CMakeFiles/cv28.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cv28.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cv28.dir/flags.make

CMakeFiles/cv28.dir/cv28.cpp.o: CMakeFiles/cv28.dir/flags.make
CMakeFiles/cv28.dir/cv28.cpp.o: ../cv28.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/minamikawa/Opencv/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cv28.dir/cv28.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cv28.dir/cv28.cpp.o -c /home/minamikawa/Opencv/cv28.cpp

CMakeFiles/cv28.dir/cv28.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cv28.dir/cv28.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/minamikawa/Opencv/cv28.cpp > CMakeFiles/cv28.dir/cv28.cpp.i

CMakeFiles/cv28.dir/cv28.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cv28.dir/cv28.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/minamikawa/Opencv/cv28.cpp -o CMakeFiles/cv28.dir/cv28.cpp.s

CMakeFiles/cv28.dir/cv28.cpp.o.requires:

.PHONY : CMakeFiles/cv28.dir/cv28.cpp.o.requires

CMakeFiles/cv28.dir/cv28.cpp.o.provides: CMakeFiles/cv28.dir/cv28.cpp.o.requires
	$(MAKE) -f CMakeFiles/cv28.dir/build.make CMakeFiles/cv28.dir/cv28.cpp.o.provides.build
.PHONY : CMakeFiles/cv28.dir/cv28.cpp.o.provides

CMakeFiles/cv28.dir/cv28.cpp.o.provides.build: CMakeFiles/cv28.dir/cv28.cpp.o


# Object files for target cv28
cv28_OBJECTS = \
"CMakeFiles/cv28.dir/cv28.cpp.o"

# External object files for target cv28
cv28_EXTERNAL_OBJECTS =

cv28: CMakeFiles/cv28.dir/cv28.cpp.o
cv28: CMakeFiles/cv28.dir/build.make
cv28: CMakeFiles/cv28.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/minamikawa/Opencv/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cv28"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cv28.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cv28.dir/build: cv28

.PHONY : CMakeFiles/cv28.dir/build

CMakeFiles/cv28.dir/requires: CMakeFiles/cv28.dir/cv28.cpp.o.requires

.PHONY : CMakeFiles/cv28.dir/requires

CMakeFiles/cv28.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cv28.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cv28.dir/clean

CMakeFiles/cv28.dir/depend:
	cd /home/minamikawa/Opencv/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/minamikawa/Opencv /home/minamikawa/Opencv /home/minamikawa/Opencv/build /home/minamikawa/Opencv/build /home/minamikawa/Opencv/build/CMakeFiles/cv28.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cv28.dir/depend

