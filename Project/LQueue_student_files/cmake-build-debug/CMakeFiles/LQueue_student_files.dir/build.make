# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/yangliu/Desktop/CPSC221/Project/LQueue_student_files

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/yangliu/Desktop/CPSC221/Project/LQueue_student_files/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/LQueue_student_files.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LQueue_student_files.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LQueue_student_files.dir/flags.make

CMakeFiles/LQueue_student_files.dir/LQueue.C.o: CMakeFiles/LQueue_student_files.dir/flags.make
CMakeFiles/LQueue_student_files.dir/LQueue.C.o: ../LQueue.C
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yangliu/Desktop/CPSC221/Project/LQueue_student_files/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LQueue_student_files.dir/LQueue.C.o"
	/Library/Developer/CommandLineTools/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LQueue_student_files.dir/LQueue.C.o -c /Users/yangliu/Desktop/CPSC221/Project/LQueue_student_files/LQueue.C

CMakeFiles/LQueue_student_files.dir/LQueue.C.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LQueue_student_files.dir/LQueue.C.i"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yangliu/Desktop/CPSC221/Project/LQueue_student_files/LQueue.C > CMakeFiles/LQueue_student_files.dir/LQueue.C.i

CMakeFiles/LQueue_student_files.dir/LQueue.C.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LQueue_student_files.dir/LQueue.C.s"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yangliu/Desktop/CPSC221/Project/LQueue_student_files/LQueue.C -o CMakeFiles/LQueue_student_files.dir/LQueue.C.s

CMakeFiles/LQueue_student_files.dir/LQueue.C.o.requires:

.PHONY : CMakeFiles/LQueue_student_files.dir/LQueue.C.o.requires

CMakeFiles/LQueue_student_files.dir/LQueue.C.o.provides: CMakeFiles/LQueue_student_files.dir/LQueue.C.o.requires
	$(MAKE) -f CMakeFiles/LQueue_student_files.dir/build.make CMakeFiles/LQueue_student_files.dir/LQueue.C.o.provides.build
.PHONY : CMakeFiles/LQueue_student_files.dir/LQueue.C.o.provides

CMakeFiles/LQueue_student_files.dir/LQueue.C.o.provides.build: CMakeFiles/LQueue_student_files.dir/LQueue.C.o


CMakeFiles/LQueue_student_files.dir/LQueue_driver.C.o: CMakeFiles/LQueue_student_files.dir/flags.make
CMakeFiles/LQueue_student_files.dir/LQueue_driver.C.o: ../LQueue_driver.C
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yangliu/Desktop/CPSC221/Project/LQueue_student_files/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/LQueue_student_files.dir/LQueue_driver.C.o"
	/Library/Developer/CommandLineTools/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LQueue_student_files.dir/LQueue_driver.C.o -c /Users/yangliu/Desktop/CPSC221/Project/LQueue_student_files/LQueue_driver.C

CMakeFiles/LQueue_student_files.dir/LQueue_driver.C.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LQueue_student_files.dir/LQueue_driver.C.i"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yangliu/Desktop/CPSC221/Project/LQueue_student_files/LQueue_driver.C > CMakeFiles/LQueue_student_files.dir/LQueue_driver.C.i

CMakeFiles/LQueue_student_files.dir/LQueue_driver.C.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LQueue_student_files.dir/LQueue_driver.C.s"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yangliu/Desktop/CPSC221/Project/LQueue_student_files/LQueue_driver.C -o CMakeFiles/LQueue_student_files.dir/LQueue_driver.C.s

CMakeFiles/LQueue_student_files.dir/LQueue_driver.C.o.requires:

.PHONY : CMakeFiles/LQueue_student_files.dir/LQueue_driver.C.o.requires

CMakeFiles/LQueue_student_files.dir/LQueue_driver.C.o.provides: CMakeFiles/LQueue_student_files.dir/LQueue_driver.C.o.requires
	$(MAKE) -f CMakeFiles/LQueue_student_files.dir/build.make CMakeFiles/LQueue_student_files.dir/LQueue_driver.C.o.provides.build
.PHONY : CMakeFiles/LQueue_student_files.dir/LQueue_driver.C.o.provides

CMakeFiles/LQueue_student_files.dir/LQueue_driver.C.o.provides.build: CMakeFiles/LQueue_student_files.dir/LQueue_driver.C.o


# Object files for target LQueue_student_files
LQueue_student_files_OBJECTS = \
"CMakeFiles/LQueue_student_files.dir/LQueue.C.o" \
"CMakeFiles/LQueue_student_files.dir/LQueue_driver.C.o"

# External object files for target LQueue_student_files
LQueue_student_files_EXTERNAL_OBJECTS =

LQueue_student_files: CMakeFiles/LQueue_student_files.dir/LQueue.C.o
LQueue_student_files: CMakeFiles/LQueue_student_files.dir/LQueue_driver.C.o
LQueue_student_files: CMakeFiles/LQueue_student_files.dir/build.make
LQueue_student_files: CMakeFiles/LQueue_student_files.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/yangliu/Desktop/CPSC221/Project/LQueue_student_files/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable LQueue_student_files"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LQueue_student_files.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LQueue_student_files.dir/build: LQueue_student_files

.PHONY : CMakeFiles/LQueue_student_files.dir/build

CMakeFiles/LQueue_student_files.dir/requires: CMakeFiles/LQueue_student_files.dir/LQueue.C.o.requires
CMakeFiles/LQueue_student_files.dir/requires: CMakeFiles/LQueue_student_files.dir/LQueue_driver.C.o.requires

.PHONY : CMakeFiles/LQueue_student_files.dir/requires

CMakeFiles/LQueue_student_files.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LQueue_student_files.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LQueue_student_files.dir/clean

CMakeFiles/LQueue_student_files.dir/depend:
	cd /Users/yangliu/Desktop/CPSC221/Project/LQueue_student_files/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yangliu/Desktop/CPSC221/Project/LQueue_student_files /Users/yangliu/Desktop/CPSC221/Project/LQueue_student_files /Users/yangliu/Desktop/CPSC221/Project/LQueue_student_files/cmake-build-debug /Users/yangliu/Desktop/CPSC221/Project/LQueue_student_files/cmake-build-debug /Users/yangliu/Desktop/CPSC221/Project/LQueue_student_files/cmake-build-debug/CMakeFiles/LQueue_student_files.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LQueue_student_files.dir/depend

