# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/usuario/COURSE/monte-carlo-method-in-7-minutes/projects/montecarlo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/usuario/COURSE/monte-carlo-method-in-7-minutes/projects/montecarlo

# Include any dependencies generated for this target.
include rectangle/CMakeFiles/Rectangle.dir/depend.make

# Include the progress variables for this target.
include rectangle/CMakeFiles/Rectangle.dir/progress.make

# Include the compile flags for this target's objects.
include rectangle/CMakeFiles/Rectangle.dir/flags.make

rectangle/CMakeFiles/Rectangle.dir/rectangle.cpp.o: rectangle/CMakeFiles/Rectangle.dir/flags.make
rectangle/CMakeFiles/Rectangle.dir/rectangle.cpp.o: rectangle/rectangle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/usuario/COURSE/monte-carlo-method-in-7-minutes/projects/montecarlo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object rectangle/CMakeFiles/Rectangle.dir/rectangle.cpp.o"
	cd /home/usuario/COURSE/monte-carlo-method-in-7-minutes/projects/montecarlo/rectangle && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Rectangle.dir/rectangle.cpp.o -c /home/usuario/COURSE/monte-carlo-method-in-7-minutes/projects/montecarlo/rectangle/rectangle.cpp

rectangle/CMakeFiles/Rectangle.dir/rectangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Rectangle.dir/rectangle.cpp.i"
	cd /home/usuario/COURSE/monte-carlo-method-in-7-minutes/projects/montecarlo/rectangle && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/usuario/COURSE/monte-carlo-method-in-7-minutes/projects/montecarlo/rectangle/rectangle.cpp > CMakeFiles/Rectangle.dir/rectangle.cpp.i

rectangle/CMakeFiles/Rectangle.dir/rectangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Rectangle.dir/rectangle.cpp.s"
	cd /home/usuario/COURSE/monte-carlo-method-in-7-minutes/projects/montecarlo/rectangle && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/usuario/COURSE/monte-carlo-method-in-7-minutes/projects/montecarlo/rectangle/rectangle.cpp -o CMakeFiles/Rectangle.dir/rectangle.cpp.s

rectangle/CMakeFiles/Rectangle.dir/rectangle.cpp.o.requires:

.PHONY : rectangle/CMakeFiles/Rectangle.dir/rectangle.cpp.o.requires

rectangle/CMakeFiles/Rectangle.dir/rectangle.cpp.o.provides: rectangle/CMakeFiles/Rectangle.dir/rectangle.cpp.o.requires
	$(MAKE) -f rectangle/CMakeFiles/Rectangle.dir/build.make rectangle/CMakeFiles/Rectangle.dir/rectangle.cpp.o.provides.build
.PHONY : rectangle/CMakeFiles/Rectangle.dir/rectangle.cpp.o.provides

rectangle/CMakeFiles/Rectangle.dir/rectangle.cpp.o.provides.build: rectangle/CMakeFiles/Rectangle.dir/rectangle.cpp.o


# Object files for target Rectangle
Rectangle_OBJECTS = \
"CMakeFiles/Rectangle.dir/rectangle.cpp.o"

# External object files for target Rectangle
Rectangle_EXTERNAL_OBJECTS =

rectangle/Rectangle: rectangle/CMakeFiles/Rectangle.dir/rectangle.cpp.o
rectangle/Rectangle: rectangle/CMakeFiles/Rectangle.dir/build.make
rectangle/Rectangle: rectangle/CMakeFiles/Rectangle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/usuario/COURSE/monte-carlo-method-in-7-minutes/projects/montecarlo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Rectangle"
	cd /home/usuario/COURSE/monte-carlo-method-in-7-minutes/projects/montecarlo/rectangle && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Rectangle.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
rectangle/CMakeFiles/Rectangle.dir/build: rectangle/Rectangle

.PHONY : rectangle/CMakeFiles/Rectangle.dir/build

rectangle/CMakeFiles/Rectangle.dir/requires: rectangle/CMakeFiles/Rectangle.dir/rectangle.cpp.o.requires

.PHONY : rectangle/CMakeFiles/Rectangle.dir/requires

rectangle/CMakeFiles/Rectangle.dir/clean:
	cd /home/usuario/COURSE/monte-carlo-method-in-7-minutes/projects/montecarlo/rectangle && $(CMAKE_COMMAND) -P CMakeFiles/Rectangle.dir/cmake_clean.cmake
.PHONY : rectangle/CMakeFiles/Rectangle.dir/clean

rectangle/CMakeFiles/Rectangle.dir/depend:
	cd /home/usuario/COURSE/monte-carlo-method-in-7-minutes/projects/montecarlo && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/usuario/COURSE/monte-carlo-method-in-7-minutes/projects/montecarlo /home/usuario/COURSE/monte-carlo-method-in-7-minutes/projects/montecarlo/rectangle /home/usuario/COURSE/monte-carlo-method-in-7-minutes/projects/montecarlo /home/usuario/COURSE/monte-carlo-method-in-7-minutes/projects/montecarlo/rectangle /home/usuario/COURSE/monte-carlo-method-in-7-minutes/projects/montecarlo/rectangle/CMakeFiles/Rectangle.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : rectangle/CMakeFiles/Rectangle.dir/depend

