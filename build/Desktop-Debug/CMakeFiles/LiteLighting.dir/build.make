# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /snap/cmake/1435/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1435/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ivan/LiteLighting

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ivan/LiteLighting/build/Desktop-Debug

# Include any dependencies generated for this target.
include CMakeFiles/LiteLighting.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/LiteLighting.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/LiteLighting.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LiteLighting.dir/flags.make

LiteLighting_autogen/timestamp: /usr/lib/qt6/libexec/moc
LiteLighting_autogen/timestamp: /usr/lib/qt6/libexec/uic
LiteLighting_autogen/timestamp: CMakeFiles/LiteLighting.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/ivan/LiteLighting/build/Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target LiteLighting"
	/snap/cmake/1435/bin/cmake -E cmake_autogen /home/ivan/LiteLighting/build/Desktop-Debug/CMakeFiles/LiteLighting_autogen.dir/AutogenInfo.json Debug
	/snap/cmake/1435/bin/cmake -E touch /home/ivan/LiteLighting/build/Desktop-Debug/LiteLighting_autogen/timestamp

CMakeFiles/LiteLighting.dir/codegen:
.PHONY : CMakeFiles/LiteLighting.dir/codegen

CMakeFiles/LiteLighting.dir/LiteLighting_autogen/mocs_compilation.cpp.o: CMakeFiles/LiteLighting.dir/flags.make
CMakeFiles/LiteLighting.dir/LiteLighting_autogen/mocs_compilation.cpp.o: LiteLighting_autogen/mocs_compilation.cpp
CMakeFiles/LiteLighting.dir/LiteLighting_autogen/mocs_compilation.cpp.o: CMakeFiles/LiteLighting.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ivan/LiteLighting/build/Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/LiteLighting.dir/LiteLighting_autogen/mocs_compilation.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/LiteLighting.dir/LiteLighting_autogen/mocs_compilation.cpp.o -MF CMakeFiles/LiteLighting.dir/LiteLighting_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/LiteLighting.dir/LiteLighting_autogen/mocs_compilation.cpp.o -c /home/ivan/LiteLighting/build/Desktop-Debug/LiteLighting_autogen/mocs_compilation.cpp

CMakeFiles/LiteLighting.dir/LiteLighting_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/LiteLighting.dir/LiteLighting_autogen/mocs_compilation.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/LiteLighting/build/Desktop-Debug/LiteLighting_autogen/mocs_compilation.cpp > CMakeFiles/LiteLighting.dir/LiteLighting_autogen/mocs_compilation.cpp.i

CMakeFiles/LiteLighting.dir/LiteLighting_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/LiteLighting.dir/LiteLighting_autogen/mocs_compilation.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/LiteLighting/build/Desktop-Debug/LiteLighting_autogen/mocs_compilation.cpp -o CMakeFiles/LiteLighting.dir/LiteLighting_autogen/mocs_compilation.cpp.s

CMakeFiles/LiteLighting.dir/main.cpp.o: CMakeFiles/LiteLighting.dir/flags.make
CMakeFiles/LiteLighting.dir/main.cpp.o: /home/ivan/LiteLighting/main.cpp
CMakeFiles/LiteLighting.dir/main.cpp.o: CMakeFiles/LiteLighting.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ivan/LiteLighting/build/Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/LiteLighting.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/LiteLighting.dir/main.cpp.o -MF CMakeFiles/LiteLighting.dir/main.cpp.o.d -o CMakeFiles/LiteLighting.dir/main.cpp.o -c /home/ivan/LiteLighting/main.cpp

CMakeFiles/LiteLighting.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/LiteLighting.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/LiteLighting/main.cpp > CMakeFiles/LiteLighting.dir/main.cpp.i

CMakeFiles/LiteLighting.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/LiteLighting.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/LiteLighting/main.cpp -o CMakeFiles/LiteLighting.dir/main.cpp.s

CMakeFiles/LiteLighting.dir/mainwindow.cpp.o: CMakeFiles/LiteLighting.dir/flags.make
CMakeFiles/LiteLighting.dir/mainwindow.cpp.o: /home/ivan/LiteLighting/mainwindow.cpp
CMakeFiles/LiteLighting.dir/mainwindow.cpp.o: CMakeFiles/LiteLighting.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ivan/LiteLighting/build/Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/LiteLighting.dir/mainwindow.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/LiteLighting.dir/mainwindow.cpp.o -MF CMakeFiles/LiteLighting.dir/mainwindow.cpp.o.d -o CMakeFiles/LiteLighting.dir/mainwindow.cpp.o -c /home/ivan/LiteLighting/mainwindow.cpp

CMakeFiles/LiteLighting.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/LiteLighting.dir/mainwindow.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/LiteLighting/mainwindow.cpp > CMakeFiles/LiteLighting.dir/mainwindow.cpp.i

CMakeFiles/LiteLighting.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/LiteLighting.dir/mainwindow.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/LiteLighting/mainwindow.cpp -o CMakeFiles/LiteLighting.dir/mainwindow.cpp.s

CMakeFiles/LiteLighting.dir/src/Fixture.cpp.o: CMakeFiles/LiteLighting.dir/flags.make
CMakeFiles/LiteLighting.dir/src/Fixture.cpp.o: /home/ivan/LiteLighting/src/Fixture.cpp
CMakeFiles/LiteLighting.dir/src/Fixture.cpp.o: CMakeFiles/LiteLighting.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ivan/LiteLighting/build/Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/LiteLighting.dir/src/Fixture.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/LiteLighting.dir/src/Fixture.cpp.o -MF CMakeFiles/LiteLighting.dir/src/Fixture.cpp.o.d -o CMakeFiles/LiteLighting.dir/src/Fixture.cpp.o -c /home/ivan/LiteLighting/src/Fixture.cpp

CMakeFiles/LiteLighting.dir/src/Fixture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/LiteLighting.dir/src/Fixture.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/LiteLighting/src/Fixture.cpp > CMakeFiles/LiteLighting.dir/src/Fixture.cpp.i

CMakeFiles/LiteLighting.dir/src/Fixture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/LiteLighting.dir/src/Fixture.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/LiteLighting/src/Fixture.cpp -o CMakeFiles/LiteLighting.dir/src/Fixture.cpp.s

# Object files for target LiteLighting
LiteLighting_OBJECTS = \
"CMakeFiles/LiteLighting.dir/LiteLighting_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/LiteLighting.dir/main.cpp.o" \
"CMakeFiles/LiteLighting.dir/mainwindow.cpp.o" \
"CMakeFiles/LiteLighting.dir/src/Fixture.cpp.o"

# External object files for target LiteLighting
LiteLighting_EXTERNAL_OBJECTS =

LiteLighting: CMakeFiles/LiteLighting.dir/LiteLighting_autogen/mocs_compilation.cpp.o
LiteLighting: CMakeFiles/LiteLighting.dir/main.cpp.o
LiteLighting: CMakeFiles/LiteLighting.dir/mainwindow.cpp.o
LiteLighting: CMakeFiles/LiteLighting.dir/src/Fixture.cpp.o
LiteLighting: CMakeFiles/LiteLighting.dir/build.make
LiteLighting: CMakeFiles/LiteLighting.dir/compiler_depend.ts
LiteLighting: /usr/lib/x86_64-linux-gnu/libQt6Widgets.so.6.4.2
LiteLighting: /usr/lib/x86_64-linux-gnu/libQt6Gui.so.6.4.2
LiteLighting: /usr/lib/x86_64-linux-gnu/libQt6Core.so.6.4.2
LiteLighting: /usr/lib/x86_64-linux-gnu/libGLX.so
LiteLighting: /usr/lib/x86_64-linux-gnu/libOpenGL.so
LiteLighting: CMakeFiles/LiteLighting.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/ivan/LiteLighting/build/Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable LiteLighting"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LiteLighting.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LiteLighting.dir/build: LiteLighting
.PHONY : CMakeFiles/LiteLighting.dir/build

CMakeFiles/LiteLighting.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LiteLighting.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LiteLighting.dir/clean

CMakeFiles/LiteLighting.dir/depend: LiteLighting_autogen/timestamp
	cd /home/ivan/LiteLighting/build/Desktop-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ivan/LiteLighting /home/ivan/LiteLighting /home/ivan/LiteLighting/build/Desktop-Debug /home/ivan/LiteLighting/build/Desktop-Debug /home/ivan/LiteLighting/build/Desktop-Debug/CMakeFiles/LiteLighting.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/LiteLighting.dir/depend

