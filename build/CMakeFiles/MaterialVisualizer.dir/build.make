# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_SOURCE_DIR = /home/berke/Documents/projects/Material-Visualizer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/berke/Documents/projects/Material-Visualizer/build

# Include any dependencies generated for this target.
include CMakeFiles/MaterialVisualizer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MaterialVisualizer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MaterialVisualizer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MaterialVisualizer.dir/flags.make

CMakeFiles/MaterialVisualizer.dir/main.cpp.o: CMakeFiles/MaterialVisualizer.dir/flags.make
CMakeFiles/MaterialVisualizer.dir/main.cpp.o: /home/berke/Documents/projects/Material-Visualizer/main.cpp
CMakeFiles/MaterialVisualizer.dir/main.cpp.o: CMakeFiles/MaterialVisualizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/berke/Documents/projects/Material-Visualizer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MaterialVisualizer.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MaterialVisualizer.dir/main.cpp.o -MF CMakeFiles/MaterialVisualizer.dir/main.cpp.o.d -o CMakeFiles/MaterialVisualizer.dir/main.cpp.o -c /home/berke/Documents/projects/Material-Visualizer/main.cpp

CMakeFiles/MaterialVisualizer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MaterialVisualizer.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/berke/Documents/projects/Material-Visualizer/main.cpp > CMakeFiles/MaterialVisualizer.dir/main.cpp.i

CMakeFiles/MaterialVisualizer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MaterialVisualizer.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/berke/Documents/projects/Material-Visualizer/main.cpp -o CMakeFiles/MaterialVisualizer.dir/main.cpp.s

# Object files for target MaterialVisualizer
MaterialVisualizer_OBJECTS = \
"CMakeFiles/MaterialVisualizer.dir/main.cpp.o"

# External object files for target MaterialVisualizer
MaterialVisualizer_EXTERNAL_OBJECTS =

MaterialVisualizer: CMakeFiles/MaterialVisualizer.dir/main.cpp.o
MaterialVisualizer: CMakeFiles/MaterialVisualizer.dir/build.make
MaterialVisualizer: CMakeFiles/MaterialVisualizer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/berke/Documents/projects/Material-Visualizer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MaterialVisualizer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MaterialVisualizer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MaterialVisualizer.dir/build: MaterialVisualizer
.PHONY : CMakeFiles/MaterialVisualizer.dir/build

CMakeFiles/MaterialVisualizer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MaterialVisualizer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MaterialVisualizer.dir/clean

CMakeFiles/MaterialVisualizer.dir/depend:
	cd /home/berke/Documents/projects/Material-Visualizer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/berke/Documents/projects/Material-Visualizer /home/berke/Documents/projects/Material-Visualizer /home/berke/Documents/projects/Material-Visualizer/build /home/berke/Documents/projects/Material-Visualizer/build /home/berke/Documents/projects/Material-Visualizer/build/CMakeFiles/MaterialVisualizer.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/MaterialVisualizer.dir/depend

