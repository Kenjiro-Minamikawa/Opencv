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
include CMakeFiles/detectFace.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/detectFace.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/detectFace.dir/flags.make

CMakeFiles/detectFace.dir/detectFace.cpp.o: CMakeFiles/detectFace.dir/flags.make
CMakeFiles/detectFace.dir/detectFace.cpp.o: ../detectFace.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/minamikawa/Opencv/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/detectFace.dir/detectFace.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/detectFace.dir/detectFace.cpp.o -c /home/minamikawa/Opencv/detectFace.cpp

CMakeFiles/detectFace.dir/detectFace.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/detectFace.dir/detectFace.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/minamikawa/Opencv/detectFace.cpp > CMakeFiles/detectFace.dir/detectFace.cpp.i

CMakeFiles/detectFace.dir/detectFace.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/detectFace.dir/detectFace.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/minamikawa/Opencv/detectFace.cpp -o CMakeFiles/detectFace.dir/detectFace.cpp.s

CMakeFiles/detectFace.dir/detectFace.cpp.o.requires:

.PHONY : CMakeFiles/detectFace.dir/detectFace.cpp.o.requires

CMakeFiles/detectFace.dir/detectFace.cpp.o.provides: CMakeFiles/detectFace.dir/detectFace.cpp.o.requires
	$(MAKE) -f CMakeFiles/detectFace.dir/build.make CMakeFiles/detectFace.dir/detectFace.cpp.o.provides.build
.PHONY : CMakeFiles/detectFace.dir/detectFace.cpp.o.provides

CMakeFiles/detectFace.dir/detectFace.cpp.o.provides.build: CMakeFiles/detectFace.dir/detectFace.cpp.o


# Object files for target detectFace
detectFace_OBJECTS = \
"CMakeFiles/detectFace.dir/detectFace.cpp.o"

# External object files for target detectFace
detectFace_EXTERNAL_OBJECTS =

detectFace: CMakeFiles/detectFace.dir/detectFace.cpp.o
detectFace: CMakeFiles/detectFace.dir/build.make
detectFace: CMakeFiles/detectFace.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/minamikawa/Opencv/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable detectFace"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/detectFace.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/detectFace.dir/build: detectFace

.PHONY : CMakeFiles/detectFace.dir/build

CMakeFiles/detectFace.dir/requires: CMakeFiles/detectFace.dir/detectFace.cpp.o.requires

.PHONY : CMakeFiles/detectFace.dir/requires

CMakeFiles/detectFace.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/detectFace.dir/cmake_clean.cmake
.PHONY : CMakeFiles/detectFace.dir/clean

CMakeFiles/detectFace.dir/depend:
	cd /home/minamikawa/Opencv/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/minamikawa/Opencv /home/minamikawa/Opencv /home/minamikawa/Opencv/build /home/minamikawa/Opencv/build /home/minamikawa/Opencv/build/CMakeFiles/detectFace.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/detectFace.dir/depend

