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
include CMakeFiles/rs-imshow.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rs-imshow.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rs-imshow.dir/flags.make

CMakeFiles/rs-imshow.dir/rs-imshow.cpp.o: CMakeFiles/rs-imshow.dir/flags.make
CMakeFiles/rs-imshow.dir/rs-imshow.cpp.o: ../rs-imshow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/minamikawa/Opencv/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rs-imshow.dir/rs-imshow.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rs-imshow.dir/rs-imshow.cpp.o -c /home/minamikawa/Opencv/rs-imshow.cpp

CMakeFiles/rs-imshow.dir/rs-imshow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rs-imshow.dir/rs-imshow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/minamikawa/Opencv/rs-imshow.cpp > CMakeFiles/rs-imshow.dir/rs-imshow.cpp.i

CMakeFiles/rs-imshow.dir/rs-imshow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rs-imshow.dir/rs-imshow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/minamikawa/Opencv/rs-imshow.cpp -o CMakeFiles/rs-imshow.dir/rs-imshow.cpp.s

CMakeFiles/rs-imshow.dir/rs-imshow.cpp.o.requires:

.PHONY : CMakeFiles/rs-imshow.dir/rs-imshow.cpp.o.requires

CMakeFiles/rs-imshow.dir/rs-imshow.cpp.o.provides: CMakeFiles/rs-imshow.dir/rs-imshow.cpp.o.requires
	$(MAKE) -f CMakeFiles/rs-imshow.dir/build.make CMakeFiles/rs-imshow.dir/rs-imshow.cpp.o.provides.build
.PHONY : CMakeFiles/rs-imshow.dir/rs-imshow.cpp.o.provides

CMakeFiles/rs-imshow.dir/rs-imshow.cpp.o.provides.build: CMakeFiles/rs-imshow.dir/rs-imshow.cpp.o


# Object files for target rs-imshow
rs__imshow_OBJECTS = \
"CMakeFiles/rs-imshow.dir/rs-imshow.cpp.o"

# External object files for target rs-imshow
rs__imshow_EXTERNAL_OBJECTS =

rs-imshow: CMakeFiles/rs-imshow.dir/rs-imshow.cpp.o
rs-imshow: CMakeFiles/rs-imshow.dir/build.make
rs-imshow: CMakeFiles/rs-imshow.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/minamikawa/Opencv/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable rs-imshow"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rs-imshow.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rs-imshow.dir/build: rs-imshow

.PHONY : CMakeFiles/rs-imshow.dir/build

CMakeFiles/rs-imshow.dir/requires: CMakeFiles/rs-imshow.dir/rs-imshow.cpp.o.requires

.PHONY : CMakeFiles/rs-imshow.dir/requires

CMakeFiles/rs-imshow.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rs-imshow.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rs-imshow.dir/clean

CMakeFiles/rs-imshow.dir/depend:
	cd /home/minamikawa/Opencv/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/minamikawa/Opencv /home/minamikawa/Opencv /home/minamikawa/Opencv/build /home/minamikawa/Opencv/build /home/minamikawa/Opencv/build/CMakeFiles/rs-imshow.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rs-imshow.dir/depend

