# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /home/artem/Qt/Tools/CMake/bin/cmake

# The command to remove a file.
RM = /home/artem/Qt/Tools/CMake/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/artem/dbus_service

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/artem/dbus_service/build/Desktop_Qt_6_8_0-Debug

# Utility rule file for dbus_service_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/dbus_service_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/dbus_service_autogen.dir/progress.make

CMakeFiles/dbus_service_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/artem/dbus_service/build/Desktop_Qt_6_8_0-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target dbus_service"
	/home/artem/Qt/Tools/CMake/bin/cmake -E cmake_autogen /home/artem/dbus_service/build/Desktop_Qt_6_8_0-Debug/CMakeFiles/dbus_service_autogen.dir/AutogenInfo.json Debug

dbus_service_autogen: CMakeFiles/dbus_service_autogen
dbus_service_autogen: CMakeFiles/dbus_service_autogen.dir/build.make
.PHONY : dbus_service_autogen

# Rule to build all files generated by this target.
CMakeFiles/dbus_service_autogen.dir/build: dbus_service_autogen
.PHONY : CMakeFiles/dbus_service_autogen.dir/build

CMakeFiles/dbus_service_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dbus_service_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dbus_service_autogen.dir/clean

CMakeFiles/dbus_service_autogen.dir/depend:
	cd /home/artem/dbus_service/build/Desktop_Qt_6_8_0-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/artem/dbus_service /home/artem/dbus_service /home/artem/dbus_service/build/Desktop_Qt_6_8_0-Debug /home/artem/dbus_service/build/Desktop_Qt_6_8_0-Debug /home/artem/dbus_service/build/Desktop_Qt_6_8_0-Debug/CMakeFiles/dbus_service_autogen.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/dbus_service_autogen.dir/depend

