# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.1.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.1.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\patha\Projects\personalCode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\patha\Projects\personalCode\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/testing.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/testing.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/testing.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testing.dir/flags.make

CMakeFiles/testing.dir/testing.cpp.obj: CMakeFiles/testing.dir/flags.make
CMakeFiles/testing.dir/testing.cpp.obj: ../testing.cpp
CMakeFiles/testing.dir/testing.cpp.obj: CMakeFiles/testing.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\patha\Projects\personalCode\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/testing.dir/testing.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/testing.dir/testing.cpp.obj -MF CMakeFiles\testing.dir\testing.cpp.obj.d -o CMakeFiles\testing.dir\testing.cpp.obj -c D:\patha\Projects\personalCode\testing.cpp

CMakeFiles/testing.dir/testing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testing.dir/testing.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\patha\Projects\personalCode\testing.cpp > CMakeFiles\testing.dir\testing.cpp.i

CMakeFiles/testing.dir/testing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testing.dir/testing.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\patha\Projects\personalCode\testing.cpp -o CMakeFiles\testing.dir\testing.cpp.s

# Object files for target testing
testing_OBJECTS = \
"CMakeFiles/testing.dir/testing.cpp.obj"

# External object files for target testing
testing_EXTERNAL_OBJECTS =

testing.exe: CMakeFiles/testing.dir/testing.cpp.obj
testing.exe: CMakeFiles/testing.dir/build.make
testing.exe: CMakeFiles/testing.dir/linklibs.rsp
testing.exe: CMakeFiles/testing.dir/objects1.rsp
testing.exe: CMakeFiles/testing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\patha\Projects\personalCode\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable testing.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\testing.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testing.dir/build: testing.exe
.PHONY : CMakeFiles/testing.dir/build

CMakeFiles/testing.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\testing.dir\cmake_clean.cmake
.PHONY : CMakeFiles/testing.dir/clean

CMakeFiles/testing.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\patha\Projects\personalCode D:\patha\Projects\personalCode D:\patha\Projects\personalCode\cmake-build-debug D:\patha\Projects\personalCode\cmake-build-debug D:\patha\Projects\personalCode\cmake-build-debug\CMakeFiles\testing.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testing.dir/depend

