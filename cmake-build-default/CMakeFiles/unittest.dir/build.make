# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/haoyangwu/Desktop/cmu/coursework/2021fall/15618-Parallel Computing/15618-Lock-Free-Queue"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/haoyangwu/Desktop/cmu/coursework/2021fall/15618-Parallel Computing/15618-Lock-Free-Queue/cmake-build-default"

# Include any dependencies generated for this target.
include CMakeFiles/unittest.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/unittest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/unittest.dir/flags.make

CMakeFiles/unittest.dir/test/testCASQueue.cpp.o: CMakeFiles/unittest.dir/flags.make
CMakeFiles/unittest.dir/test/testCASQueue.cpp.o: ../test/testCASQueue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/haoyangwu/Desktop/cmu/coursework/2021fall/15618-Parallel Computing/15618-Lock-Free-Queue/cmake-build-default/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/unittest.dir/test/testCASQueue.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/unittest.dir/test/testCASQueue.cpp.o -c "/Users/haoyangwu/Desktop/cmu/coursework/2021fall/15618-Parallel Computing/15618-Lock-Free-Queue/test/testCASQueue.cpp"

CMakeFiles/unittest.dir/test/testCASQueue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unittest.dir/test/testCASQueue.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/haoyangwu/Desktop/cmu/coursework/2021fall/15618-Parallel Computing/15618-Lock-Free-Queue/test/testCASQueue.cpp" > CMakeFiles/unittest.dir/test/testCASQueue.cpp.i

CMakeFiles/unittest.dir/test/testCASQueue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unittest.dir/test/testCASQueue.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/haoyangwu/Desktop/cmu/coursework/2021fall/15618-Parallel Computing/15618-Lock-Free-Queue/test/testCASQueue.cpp" -o CMakeFiles/unittest.dir/test/testCASQueue.cpp.s

CMakeFiles/unittest.dir/test/testCourseLockQueue.cpp.o: CMakeFiles/unittest.dir/flags.make
CMakeFiles/unittest.dir/test/testCourseLockQueue.cpp.o: ../test/testCourseLockQueue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/haoyangwu/Desktop/cmu/coursework/2021fall/15618-Parallel Computing/15618-Lock-Free-Queue/cmake-build-default/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/unittest.dir/test/testCourseLockQueue.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/unittest.dir/test/testCourseLockQueue.cpp.o -c "/Users/haoyangwu/Desktop/cmu/coursework/2021fall/15618-Parallel Computing/15618-Lock-Free-Queue/test/testCourseLockQueue.cpp"

CMakeFiles/unittest.dir/test/testCourseLockQueue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unittest.dir/test/testCourseLockQueue.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/haoyangwu/Desktop/cmu/coursework/2021fall/15618-Parallel Computing/15618-Lock-Free-Queue/test/testCourseLockQueue.cpp" > CMakeFiles/unittest.dir/test/testCourseLockQueue.cpp.i

CMakeFiles/unittest.dir/test/testCourseLockQueue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unittest.dir/test/testCourseLockQueue.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/haoyangwu/Desktop/cmu/coursework/2021fall/15618-Parallel Computing/15618-Lock-Free-Queue/test/testCourseLockQueue.cpp" -o CMakeFiles/unittest.dir/test/testCourseLockQueue.cpp.s

CMakeFiles/unittest.dir/test/testFineLockQueue.cpp.o: CMakeFiles/unittest.dir/flags.make
CMakeFiles/unittest.dir/test/testFineLockQueue.cpp.o: ../test/testFineLockQueue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/haoyangwu/Desktop/cmu/coursework/2021fall/15618-Parallel Computing/15618-Lock-Free-Queue/cmake-build-default/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/unittest.dir/test/testFineLockQueue.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/unittest.dir/test/testFineLockQueue.cpp.o -c "/Users/haoyangwu/Desktop/cmu/coursework/2021fall/15618-Parallel Computing/15618-Lock-Free-Queue/test/testFineLockQueue.cpp"

CMakeFiles/unittest.dir/test/testFineLockQueue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unittest.dir/test/testFineLockQueue.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/haoyangwu/Desktop/cmu/coursework/2021fall/15618-Parallel Computing/15618-Lock-Free-Queue/test/testFineLockQueue.cpp" > CMakeFiles/unittest.dir/test/testFineLockQueue.cpp.i

CMakeFiles/unittest.dir/test/testFineLockQueue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unittest.dir/test/testFineLockQueue.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/haoyangwu/Desktop/cmu/coursework/2021fall/15618-Parallel Computing/15618-Lock-Free-Queue/test/testFineLockQueue.cpp" -o CMakeFiles/unittest.dir/test/testFineLockQueue.cpp.s

# Object files for target unittest
unittest_OBJECTS = \
"CMakeFiles/unittest.dir/test/testCASQueue.cpp.o" \
"CMakeFiles/unittest.dir/test/testCourseLockQueue.cpp.o" \
"CMakeFiles/unittest.dir/test/testFineLockQueue.cpp.o"

# External object files for target unittest
unittest_EXTERNAL_OBJECTS =

unittest: CMakeFiles/unittest.dir/test/testCASQueue.cpp.o
unittest: CMakeFiles/unittest.dir/test/testCourseLockQueue.cpp.o
unittest: CMakeFiles/unittest.dir/test/testFineLockQueue.cpp.o
unittest: CMakeFiles/unittest.dir/build.make
unittest: lib/libgtest.a
unittest: lib/libgtest_main.a
unittest: lib/libgtest.a
unittest: CMakeFiles/unittest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/haoyangwu/Desktop/cmu/coursework/2021fall/15618-Parallel Computing/15618-Lock-Free-Queue/cmake-build-default/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable unittest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/unittest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/unittest.dir/build: unittest
.PHONY : CMakeFiles/unittest.dir/build

CMakeFiles/unittest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/unittest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/unittest.dir/clean

CMakeFiles/unittest.dir/depend:
	cd "/Users/haoyangwu/Desktop/cmu/coursework/2021fall/15618-Parallel Computing/15618-Lock-Free-Queue/cmake-build-default" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/haoyangwu/Desktop/cmu/coursework/2021fall/15618-Parallel Computing/15618-Lock-Free-Queue" "/Users/haoyangwu/Desktop/cmu/coursework/2021fall/15618-Parallel Computing/15618-Lock-Free-Queue" "/Users/haoyangwu/Desktop/cmu/coursework/2021fall/15618-Parallel Computing/15618-Lock-Free-Queue/cmake-build-default" "/Users/haoyangwu/Desktop/cmu/coursework/2021fall/15618-Parallel Computing/15618-Lock-Free-Queue/cmake-build-default" "/Users/haoyangwu/Desktop/cmu/coursework/2021fall/15618-Parallel Computing/15618-Lock-Free-Queue/cmake-build-default/CMakeFiles/unittest.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/unittest.dir/depend

