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
CMAKE_BINARY_DIR = "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/build"

# Include any dependencies generated for this target.
include src/CMakeFiles/splashmem.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/splashmem.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/splashmem.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/splashmem.dir/flags.make

src/CMakeFiles/splashmem.dir/actions.c.o: src/CMakeFiles/splashmem.dir/flags.make
src/CMakeFiles/splashmem.dir/actions.c.o: /mnt/c/Users/Lycée\ Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main/src/actions.c
src/CMakeFiles/splashmem.dir/actions.c.o: src/CMakeFiles/splashmem.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/splashmem.dir/actions.c.o"
	cd "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/build/src" && gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/splashmem.dir/actions.c.o -MF CMakeFiles/splashmem.dir/actions.c.o.d -o CMakeFiles/splashmem.dir/actions.c.o -c "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main/src/actions.c"

src/CMakeFiles/splashmem.dir/actions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/splashmem.dir/actions.c.i"
	cd "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/build/src" && gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main/src/actions.c" > CMakeFiles/splashmem.dir/actions.c.i

src/CMakeFiles/splashmem.dir/actions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/splashmem.dir/actions.c.s"
	cd "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/build/src" && gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main/src/actions.c" -o CMakeFiles/splashmem.dir/actions.c.s

src/CMakeFiles/splashmem.dir/init.c.o: src/CMakeFiles/splashmem.dir/flags.make
src/CMakeFiles/splashmem.dir/init.c.o: /mnt/c/Users/Lycée\ Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main/src/init.c
src/CMakeFiles/splashmem.dir/init.c.o: src/CMakeFiles/splashmem.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/CMakeFiles/splashmem.dir/init.c.o"
	cd "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/build/src" && gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/splashmem.dir/init.c.o -MF CMakeFiles/splashmem.dir/init.c.o.d -o CMakeFiles/splashmem.dir/init.c.o -c "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main/src/init.c"

src/CMakeFiles/splashmem.dir/init.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/splashmem.dir/init.c.i"
	cd "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/build/src" && gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main/src/init.c" > CMakeFiles/splashmem.dir/init.c.i

src/CMakeFiles/splashmem.dir/init.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/splashmem.dir/init.c.s"
	cd "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/build/src" && gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main/src/init.c" -o CMakeFiles/splashmem.dir/init.c.s

src/CMakeFiles/splashmem.dir/main.c.o: src/CMakeFiles/splashmem.dir/flags.make
src/CMakeFiles/splashmem.dir/main.c.o: /mnt/c/Users/Lycée\ Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main/src/main.c
src/CMakeFiles/splashmem.dir/main.c.o: src/CMakeFiles/splashmem.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/CMakeFiles/splashmem.dir/main.c.o"
	cd "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/build/src" && gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/splashmem.dir/main.c.o -MF CMakeFiles/splashmem.dir/main.c.o.d -o CMakeFiles/splashmem.dir/main.c.o -c "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main/src/main.c"

src/CMakeFiles/splashmem.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/splashmem.dir/main.c.i"
	cd "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/build/src" && gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main/src/main.c" > CMakeFiles/splashmem.dir/main.c.i

src/CMakeFiles/splashmem.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/splashmem.dir/main.c.s"
	cd "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/build/src" && gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main/src/main.c" -o CMakeFiles/splashmem.dir/main.c.s

src/CMakeFiles/splashmem.dir/player.c.o: src/CMakeFiles/splashmem.dir/flags.make
src/CMakeFiles/splashmem.dir/player.c.o: /mnt/c/Users/Lycée\ Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main/src/player.c
src/CMakeFiles/splashmem.dir/player.c.o: src/CMakeFiles/splashmem.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object src/CMakeFiles/splashmem.dir/player.c.o"
	cd "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/build/src" && gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/splashmem.dir/player.c.o -MF CMakeFiles/splashmem.dir/player.c.o.d -o CMakeFiles/splashmem.dir/player.c.o -c "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main/src/player.c"

src/CMakeFiles/splashmem.dir/player.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/splashmem.dir/player.c.i"
	cd "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/build/src" && gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main/src/player.c" > CMakeFiles/splashmem.dir/player.c.i

src/CMakeFiles/splashmem.dir/player.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/splashmem.dir/player.c.s"
	cd "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/build/src" && gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main/src/player.c" -o CMakeFiles/splashmem.dir/player.c.s

src/CMakeFiles/splashmem.dir/render.c.o: src/CMakeFiles/splashmem.dir/flags.make
src/CMakeFiles/splashmem.dir/render.c.o: /mnt/c/Users/Lycée\ Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main/src/render.c
src/CMakeFiles/splashmem.dir/render.c.o: src/CMakeFiles/splashmem.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building C object src/CMakeFiles/splashmem.dir/render.c.o"
	cd "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/build/src" && gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/splashmem.dir/render.c.o -MF CMakeFiles/splashmem.dir/render.c.o.d -o CMakeFiles/splashmem.dir/render.c.o -c "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main/src/render.c"

src/CMakeFiles/splashmem.dir/render.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/splashmem.dir/render.c.i"
	cd "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/build/src" && gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main/src/render.c" > CMakeFiles/splashmem.dir/render.c.i

src/CMakeFiles/splashmem.dir/render.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/splashmem.dir/render.c.s"
	cd "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/build/src" && gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main/src/render.c" -o CMakeFiles/splashmem.dir/render.c.s

src/CMakeFiles/splashmem.dir/world.c.o: src/CMakeFiles/splashmem.dir/flags.make
src/CMakeFiles/splashmem.dir/world.c.o: /mnt/c/Users/Lycée\ Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main/src/world.c
src/CMakeFiles/splashmem.dir/world.c.o: src/CMakeFiles/splashmem.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building C object src/CMakeFiles/splashmem.dir/world.c.o"
	cd "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/build/src" && gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/splashmem.dir/world.c.o -MF CMakeFiles/splashmem.dir/world.c.o.d -o CMakeFiles/splashmem.dir/world.c.o -c "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main/src/world.c"

src/CMakeFiles/splashmem.dir/world.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/splashmem.dir/world.c.i"
	cd "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/build/src" && gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main/src/world.c" > CMakeFiles/splashmem.dir/world.c.i

src/CMakeFiles/splashmem.dir/world.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/splashmem.dir/world.c.s"
	cd "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/build/src" && gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main/src/world.c" -o CMakeFiles/splashmem.dir/world.c.s

# Object files for target splashmem
splashmem_OBJECTS = \
"CMakeFiles/splashmem.dir/actions.c.o" \
"CMakeFiles/splashmem.dir/init.c.o" \
"CMakeFiles/splashmem.dir/main.c.o" \
"CMakeFiles/splashmem.dir/player.c.o" \
"CMakeFiles/splashmem.dir/render.c.o" \
"CMakeFiles/splashmem.dir/world.c.o"

# External object files for target splashmem
splashmem_EXTERNAL_OBJECTS =

src/splashmem: src/CMakeFiles/splashmem.dir/actions.c.o
src/splashmem: src/CMakeFiles/splashmem.dir/init.c.o
src/splashmem: src/CMakeFiles/splashmem.dir/main.c.o
src/splashmem: src/CMakeFiles/splashmem.dir/player.c.o
src/splashmem: src/CMakeFiles/splashmem.dir/render.c.o
src/splashmem: src/CMakeFiles/splashmem.dir/world.c.o
src/splashmem: src/CMakeFiles/splashmem.dir/build.make
src/splashmem: src/CMakeFiles/splashmem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable splashmem"
	cd "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/build/src" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/splashmem.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/splashmem.dir/build: src/splashmem
.PHONY : src/CMakeFiles/splashmem.dir/build

src/CMakeFiles/splashmem.dir/clean:
	cd "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/build/src" && $(CMAKE_COMMAND) -P CMakeFiles/splashmem.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/splashmem.dir/clean

src/CMakeFiles/splashmem.dir/depend:
	cd "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main" "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/Projet_splashmem/splashmem-main/src" "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/build" "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/build/src" "/mnt/c/Users/Lycée Grandmont/Desktop/Polytech/1er_annee/Projet_tutoré/Zonz_project/Zonz_project/build/src/CMakeFiles/splashmem.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : src/CMakeFiles/splashmem.dir/depend

