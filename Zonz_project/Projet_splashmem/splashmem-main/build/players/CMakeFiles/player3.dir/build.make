# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main/build"

# Include any dependencies generated for this target.
include players/CMakeFiles/player3.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include players/CMakeFiles/player3.dir/compiler_depend.make

# Include the progress variables for this target.
include players/CMakeFiles/player3.dir/progress.make

# Include the compile flags for this target's objects.
include players/CMakeFiles/player3.dir/flags.make

players/CMakeFiles/player3.dir/player3.c.o: players/CMakeFiles/player3.dir/flags.make
players/CMakeFiles/player3.dir/player3.c.o: /mnt/c/Users/Lycée\ Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main/players/player3.c
players/CMakeFiles/player3.dir/player3.c.o: players/CMakeFiles/player3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object players/CMakeFiles/player3.dir/player3.c.o"
	cd "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main/build/players" && gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT players/CMakeFiles/player3.dir/player3.c.o -MF CMakeFiles/player3.dir/player3.c.o.d -o CMakeFiles/player3.dir/player3.c.o -c "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main/players/player3.c"

players/CMakeFiles/player3.dir/player3.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/player3.dir/player3.c.i"
	cd "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main/build/players" && gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main/players/player3.c" > CMakeFiles/player3.dir/player3.c.i

players/CMakeFiles/player3.dir/player3.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/player3.dir/player3.c.s"
	cd "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main/build/players" && gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main/players/player3.c" -o CMakeFiles/player3.dir/player3.c.s

# Object files for target player3
player3_OBJECTS = \
"CMakeFiles/player3.dir/player3.c.o"

# External object files for target player3
player3_EXTERNAL_OBJECTS =

players/libplayer3.so: players/CMakeFiles/player3.dir/player3.c.o
players/libplayer3.so: players/CMakeFiles/player3.dir/build.make
players/libplayer3.so: players/CMakeFiles/player3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library libplayer3.so"
	cd "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main/build/players" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/player3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
players/CMakeFiles/player3.dir/build: players/libplayer3.so
.PHONY : players/CMakeFiles/player3.dir/build

players/CMakeFiles/player3.dir/clean:
	cd "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main/build/players" && $(CMAKE_COMMAND) -P CMakeFiles/player3.dir/cmake_clean.cmake
.PHONY : players/CMakeFiles/player3.dir/clean

players/CMakeFiles/player3.dir/depend:
	cd "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main" "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main/players" "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main/build" "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main/build/players" "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main/build/players/CMakeFiles/player3.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : players/CMakeFiles/player3.dir/depend

