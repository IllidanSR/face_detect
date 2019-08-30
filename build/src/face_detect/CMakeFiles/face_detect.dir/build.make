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
CMAKE_SOURCE_DIR = /home/illidansr/CLionProjects/face_detection

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/illidansr/CLionProjects/face_detection/build

# Include any dependencies generated for this target.
include src/face_detect/CMakeFiles/face_detect.dir/depend.make

# Include the progress variables for this target.
include src/face_detect/CMakeFiles/face_detect.dir/progress.make

# Include the compile flags for this target's objects.
include src/face_detect/CMakeFiles/face_detect.dir/flags.make

src/face_detect/CMakeFiles/face_detect.dir/face_detect.cpp.o: src/face_detect/CMakeFiles/face_detect.dir/flags.make
src/face_detect/CMakeFiles/face_detect.dir/face_detect.cpp.o: ../src/face_detect/face_detect.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/illidansr/CLionProjects/face_detection/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/face_detect/CMakeFiles/face_detect.dir/face_detect.cpp.o"
	cd /home/illidansr/CLionProjects/face_detection/build/src/face_detect && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/face_detect.dir/face_detect.cpp.o -c /home/illidansr/CLionProjects/face_detection/src/face_detect/face_detect.cpp

src/face_detect/CMakeFiles/face_detect.dir/face_detect.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/face_detect.dir/face_detect.cpp.i"
	cd /home/illidansr/CLionProjects/face_detection/build/src/face_detect && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/illidansr/CLionProjects/face_detection/src/face_detect/face_detect.cpp > CMakeFiles/face_detect.dir/face_detect.cpp.i

src/face_detect/CMakeFiles/face_detect.dir/face_detect.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/face_detect.dir/face_detect.cpp.s"
	cd /home/illidansr/CLionProjects/face_detection/build/src/face_detect && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/illidansr/CLionProjects/face_detection/src/face_detect/face_detect.cpp -o CMakeFiles/face_detect.dir/face_detect.cpp.s

src/face_detect/CMakeFiles/face_detect.dir/face_detect.cpp.o.requires:

.PHONY : src/face_detect/CMakeFiles/face_detect.dir/face_detect.cpp.o.requires

src/face_detect/CMakeFiles/face_detect.dir/face_detect.cpp.o.provides: src/face_detect/CMakeFiles/face_detect.dir/face_detect.cpp.o.requires
	$(MAKE) -f src/face_detect/CMakeFiles/face_detect.dir/build.make src/face_detect/CMakeFiles/face_detect.dir/face_detect.cpp.o.provides.build
.PHONY : src/face_detect/CMakeFiles/face_detect.dir/face_detect.cpp.o.provides

src/face_detect/CMakeFiles/face_detect.dir/face_detect.cpp.o.provides.build: src/face_detect/CMakeFiles/face_detect.dir/face_detect.cpp.o


# Object files for target face_detect
face_detect_OBJECTS = \
"CMakeFiles/face_detect.dir/face_detect.cpp.o"

# External object files for target face_detect
face_detect_EXTERNAL_OBJECTS =

lib/libface_detect.a: src/face_detect/CMakeFiles/face_detect.dir/face_detect.cpp.o
lib/libface_detect.a: src/face_detect/CMakeFiles/face_detect.dir/build.make
lib/libface_detect.a: src/face_detect/CMakeFiles/face_detect.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/illidansr/CLionProjects/face_detection/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../lib/libface_detect.a"
	cd /home/illidansr/CLionProjects/face_detection/build/src/face_detect && $(CMAKE_COMMAND) -P CMakeFiles/face_detect.dir/cmake_clean_target.cmake
	cd /home/illidansr/CLionProjects/face_detection/build/src/face_detect && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/face_detect.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/face_detect/CMakeFiles/face_detect.dir/build: lib/libface_detect.a

.PHONY : src/face_detect/CMakeFiles/face_detect.dir/build

src/face_detect/CMakeFiles/face_detect.dir/requires: src/face_detect/CMakeFiles/face_detect.dir/face_detect.cpp.o.requires

.PHONY : src/face_detect/CMakeFiles/face_detect.dir/requires

src/face_detect/CMakeFiles/face_detect.dir/clean:
	cd /home/illidansr/CLionProjects/face_detection/build/src/face_detect && $(CMAKE_COMMAND) -P CMakeFiles/face_detect.dir/cmake_clean.cmake
.PHONY : src/face_detect/CMakeFiles/face_detect.dir/clean

src/face_detect/CMakeFiles/face_detect.dir/depend:
	cd /home/illidansr/CLionProjects/face_detection/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/illidansr/CLionProjects/face_detection /home/illidansr/CLionProjects/face_detection/src/face_detect /home/illidansr/CLionProjects/face_detection/build /home/illidansr/CLionProjects/face_detection/build/src/face_detect /home/illidansr/CLionProjects/face_detection/build/src/face_detect/CMakeFiles/face_detect.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/face_detect/CMakeFiles/face_detect.dir/depend

