# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2024.1\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2024.1\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\maced\Documents\GitHub\Domino\Game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\maced\Documents\GitHub\Domino\Game\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Domino.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Domino.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Domino.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Domino.dir/flags.make

CMakeFiles/Domino.dir/main.c.obj: CMakeFiles/Domino.dir/flags.make
CMakeFiles/Domino.dir/main.c.obj: CMakeFiles/Domino.dir/includes_C.rsp
CMakeFiles/Domino.dir/main.c.obj: C:/Users/maced/Documents/GitHub/Domino/Game/main.c
CMakeFiles/Domino.dir/main.c.obj: CMakeFiles/Domino.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\maced\Documents\GitHub\Domino\Game\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Domino.dir/main.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Domino.dir/main.c.obj -MF CMakeFiles\Domino.dir\main.c.obj.d -o CMakeFiles\Domino.dir\main.c.obj -c C:\Users\maced\Documents\GitHub\Domino\Game\main.c

CMakeFiles/Domino.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Domino.dir/main.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\maced\Documents\GitHub\Domino\Game\main.c > CMakeFiles\Domino.dir\main.c.i

CMakeFiles/Domino.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Domino.dir/main.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\maced\Documents\GitHub\Domino\Game\main.c -o CMakeFiles\Domino.dir\main.c.s

# Object files for target Domino
Domino_OBJECTS = \
"CMakeFiles/Domino.dir/main.c.obj"

# External object files for target Domino
Domino_EXTERNAL_OBJECTS =

Domino.exe: CMakeFiles/Domino.dir/main.c.obj
Domino.exe: CMakeFiles/Domino.dir/build.make
Domino.exe: CMakeFiles/Domino.dir/linkLibs.rsp
Domino.exe: CMakeFiles/Domino.dir/objects1.rsp
Domino.exe: CMakeFiles/Domino.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\maced\Documents\GitHub\Domino\Game\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Domino.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Domino.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Domino.dir/build: Domino.exe
.PHONY : CMakeFiles/Domino.dir/build

CMakeFiles/Domino.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Domino.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Domino.dir/clean

CMakeFiles/Domino.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\maced\Documents\GitHub\Domino\Game C:\Users\maced\Documents\GitHub\Domino\Game C:\Users\maced\Documents\GitHub\Domino\Game\cmake-build-debug C:\Users\maced\Documents\GitHub\Domino\Game\cmake-build-debug C:\Users\maced\Documents\GitHub\Domino\Game\cmake-build-debug\CMakeFiles\Domino.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Domino.dir/depend

