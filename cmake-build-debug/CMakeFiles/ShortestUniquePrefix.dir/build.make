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
include CMakeFiles/ShortestUniquePrefix.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ShortestUniquePrefix.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ShortestUniquePrefix.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ShortestUniquePrefix.dir/flags.make

CMakeFiles/ShortestUniquePrefix.dir/ShortestUniquePrefix.cpp.obj: CMakeFiles/ShortestUniquePrefix.dir/flags.make
CMakeFiles/ShortestUniquePrefix.dir/ShortestUniquePrefix.cpp.obj: ../ShortestUniquePrefix.cpp
CMakeFiles/ShortestUniquePrefix.dir/ShortestUniquePrefix.cpp.obj: CMakeFiles/ShortestUniquePrefix.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\patha\Projects\personalCode\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ShortestUniquePrefix.dir/ShortestUniquePrefix.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ShortestUniquePrefix.dir/ShortestUniquePrefix.cpp.obj -MF CMakeFiles\ShortestUniquePrefix.dir\ShortestUniquePrefix.cpp.obj.d -o CMakeFiles\ShortestUniquePrefix.dir\ShortestUniquePrefix.cpp.obj -c D:\patha\Projects\personalCode\ShortestUniquePrefix.cpp

CMakeFiles/ShortestUniquePrefix.dir/ShortestUniquePrefix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ShortestUniquePrefix.dir/ShortestUniquePrefix.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\patha\Projects\personalCode\ShortestUniquePrefix.cpp > CMakeFiles\ShortestUniquePrefix.dir\ShortestUniquePrefix.cpp.i

CMakeFiles/ShortestUniquePrefix.dir/ShortestUniquePrefix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ShortestUniquePrefix.dir/ShortestUniquePrefix.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\patha\Projects\personalCode\ShortestUniquePrefix.cpp -o CMakeFiles\ShortestUniquePrefix.dir\ShortestUniquePrefix.cpp.s

# Object files for target ShortestUniquePrefix
ShortestUniquePrefix_OBJECTS = \
"CMakeFiles/ShortestUniquePrefix.dir/ShortestUniquePrefix.cpp.obj"

# External object files for target ShortestUniquePrefix
ShortestUniquePrefix_EXTERNAL_OBJECTS =

ShortestUniquePrefix.exe: CMakeFiles/ShortestUniquePrefix.dir/ShortestUniquePrefix.cpp.obj
ShortestUniquePrefix.exe: CMakeFiles/ShortestUniquePrefix.dir/build.make
ShortestUniquePrefix.exe: CMakeFiles/ShortestUniquePrefix.dir/linklibs.rsp
ShortestUniquePrefix.exe: CMakeFiles/ShortestUniquePrefix.dir/objects1.rsp
ShortestUniquePrefix.exe: CMakeFiles/ShortestUniquePrefix.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\patha\Projects\personalCode\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ShortestUniquePrefix.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ShortestUniquePrefix.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ShortestUniquePrefix.dir/build: ShortestUniquePrefix.exe
.PHONY : CMakeFiles/ShortestUniquePrefix.dir/build

CMakeFiles/ShortestUniquePrefix.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ShortestUniquePrefix.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ShortestUniquePrefix.dir/clean

CMakeFiles/ShortestUniquePrefix.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\patha\Projects\personalCode D:\patha\Projects\personalCode D:\patha\Projects\personalCode\cmake-build-debug D:\patha\Projects\personalCode\cmake-build-debug D:\patha\Projects\personalCode\cmake-build-debug\CMakeFiles\ShortestUniquePrefix.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ShortestUniquePrefix.dir/depend

