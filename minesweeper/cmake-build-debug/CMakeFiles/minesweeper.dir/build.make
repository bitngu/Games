# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/bitnguyen/Desktop/UCDavis/Review/ECS/Intro-to-Programming-in-C-course-work--master/Final Project/minesweeper"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/bitnguyen/Desktop/UCDavis/Review/ECS/Intro-to-Programming-in-C-course-work--master/Final Project/minesweeper/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/minesweeper.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/minesweeper.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/minesweeper.dir/flags.make

CMakeFiles/minesweeper.dir/main.c.o: CMakeFiles/minesweeper.dir/flags.make
CMakeFiles/minesweeper.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/bitnguyen/Desktop/UCDavis/Review/ECS/Intro-to-Programming-in-C-course-work--master/Final Project/minesweeper/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/minesweeper.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minesweeper.dir/main.c.o   -c "/Users/bitnguyen/Desktop/UCDavis/Review/ECS/Intro-to-Programming-in-C-course-work--master/Final Project/minesweeper/main.c"

CMakeFiles/minesweeper.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minesweeper.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/bitnguyen/Desktop/UCDavis/Review/ECS/Intro-to-Programming-in-C-course-work--master/Final Project/minesweeper/main.c" > CMakeFiles/minesweeper.dir/main.c.i

CMakeFiles/minesweeper.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minesweeper.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/bitnguyen/Desktop/UCDavis/Review/ECS/Intro-to-Programming-in-C-course-work--master/Final Project/minesweeper/main.c" -o CMakeFiles/minesweeper.dir/main.c.s

CMakeFiles/minesweeper.dir/move.c.o: CMakeFiles/minesweeper.dir/flags.make
CMakeFiles/minesweeper.dir/move.c.o: ../move.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/bitnguyen/Desktop/UCDavis/Review/ECS/Intro-to-Programming-in-C-course-work--master/Final Project/minesweeper/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/minesweeper.dir/move.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minesweeper.dir/move.c.o   -c "/Users/bitnguyen/Desktop/UCDavis/Review/ECS/Intro-to-Programming-in-C-course-work--master/Final Project/minesweeper/move.c"

CMakeFiles/minesweeper.dir/move.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minesweeper.dir/move.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/bitnguyen/Desktop/UCDavis/Review/ECS/Intro-to-Programming-in-C-course-work--master/Final Project/minesweeper/move.c" > CMakeFiles/minesweeper.dir/move.c.i

CMakeFiles/minesweeper.dir/move.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minesweeper.dir/move.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/bitnguyen/Desktop/UCDavis/Review/ECS/Intro-to-Programming-in-C-course-work--master/Final Project/minesweeper/move.c" -o CMakeFiles/minesweeper.dir/move.c.s

CMakeFiles/minesweeper.dir/inputValidation.c.o: CMakeFiles/minesweeper.dir/flags.make
CMakeFiles/minesweeper.dir/inputValidation.c.o: ../inputValidation.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/bitnguyen/Desktop/UCDavis/Review/ECS/Intro-to-Programming-in-C-course-work--master/Final Project/minesweeper/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/minesweeper.dir/inputValidation.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minesweeper.dir/inputValidation.c.o   -c "/Users/bitnguyen/Desktop/UCDavis/Review/ECS/Intro-to-Programming-in-C-course-work--master/Final Project/minesweeper/inputValidation.c"

CMakeFiles/minesweeper.dir/inputValidation.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minesweeper.dir/inputValidation.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/bitnguyen/Desktop/UCDavis/Review/ECS/Intro-to-Programming-in-C-course-work--master/Final Project/minesweeper/inputValidation.c" > CMakeFiles/minesweeper.dir/inputValidation.c.i

CMakeFiles/minesweeper.dir/inputValidation.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minesweeper.dir/inputValidation.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/bitnguyen/Desktop/UCDavis/Review/ECS/Intro-to-Programming-in-C-course-work--master/Final Project/minesweeper/inputValidation.c" -o CMakeFiles/minesweeper.dir/inputValidation.c.s

CMakeFiles/minesweeper.dir/win.c.o: CMakeFiles/minesweeper.dir/flags.make
CMakeFiles/minesweeper.dir/win.c.o: ../win.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/bitnguyen/Desktop/UCDavis/Review/ECS/Intro-to-Programming-in-C-course-work--master/Final Project/minesweeper/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/minesweeper.dir/win.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minesweeper.dir/win.c.o   -c "/Users/bitnguyen/Desktop/UCDavis/Review/ECS/Intro-to-Programming-in-C-course-work--master/Final Project/minesweeper/win.c"

CMakeFiles/minesweeper.dir/win.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minesweeper.dir/win.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/bitnguyen/Desktop/UCDavis/Review/ECS/Intro-to-Programming-in-C-course-work--master/Final Project/minesweeper/win.c" > CMakeFiles/minesweeper.dir/win.c.i

CMakeFiles/minesweeper.dir/win.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minesweeper.dir/win.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/bitnguyen/Desktop/UCDavis/Review/ECS/Intro-to-Programming-in-C-course-work--master/Final Project/minesweeper/win.c" -o CMakeFiles/minesweeper.dir/win.c.s

CMakeFiles/minesweeper.dir/board.c.o: CMakeFiles/minesweeper.dir/flags.make
CMakeFiles/minesweeper.dir/board.c.o: ../board.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/bitnguyen/Desktop/UCDavis/Review/ECS/Intro-to-Programming-in-C-course-work--master/Final Project/minesweeper/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/minesweeper.dir/board.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minesweeper.dir/board.c.o   -c "/Users/bitnguyen/Desktop/UCDavis/Review/ECS/Intro-to-Programming-in-C-course-work--master/Final Project/minesweeper/board.c"

CMakeFiles/minesweeper.dir/board.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minesweeper.dir/board.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/bitnguyen/Desktop/UCDavis/Review/ECS/Intro-to-Programming-in-C-course-work--master/Final Project/minesweeper/board.c" > CMakeFiles/minesweeper.dir/board.c.i

CMakeFiles/minesweeper.dir/board.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minesweeper.dir/board.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/bitnguyen/Desktop/UCDavis/Review/ECS/Intro-to-Programming-in-C-course-work--master/Final Project/minesweeper/board.c" -o CMakeFiles/minesweeper.dir/board.c.s

# Object files for target minesweeper
minesweeper_OBJECTS = \
"CMakeFiles/minesweeper.dir/main.c.o" \
"CMakeFiles/minesweeper.dir/move.c.o" \
"CMakeFiles/minesweeper.dir/inputValidation.c.o" \
"CMakeFiles/minesweeper.dir/win.c.o" \
"CMakeFiles/minesweeper.dir/board.c.o"

# External object files for target minesweeper
minesweeper_EXTERNAL_OBJECTS =

minesweeper: CMakeFiles/minesweeper.dir/main.c.o
minesweeper: CMakeFiles/minesweeper.dir/move.c.o
minesweeper: CMakeFiles/minesweeper.dir/inputValidation.c.o
minesweeper: CMakeFiles/minesweeper.dir/win.c.o
minesweeper: CMakeFiles/minesweeper.dir/board.c.o
minesweeper: CMakeFiles/minesweeper.dir/build.make
minesweeper: CMakeFiles/minesweeper.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/bitnguyen/Desktop/UCDavis/Review/ECS/Intro-to-Programming-in-C-course-work--master/Final Project/minesweeper/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable minesweeper"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/minesweeper.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/minesweeper.dir/build: minesweeper

.PHONY : CMakeFiles/minesweeper.dir/build

CMakeFiles/minesweeper.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/minesweeper.dir/cmake_clean.cmake
.PHONY : CMakeFiles/minesweeper.dir/clean

CMakeFiles/minesweeper.dir/depend:
	cd "/Users/bitnguyen/Desktop/UCDavis/Review/ECS/Intro-to-Programming-in-C-course-work--master/Final Project/minesweeper/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/bitnguyen/Desktop/UCDavis/Review/ECS/Intro-to-Programming-in-C-course-work--master/Final Project/minesweeper" "/Users/bitnguyen/Desktop/UCDavis/Review/ECS/Intro-to-Programming-in-C-course-work--master/Final Project/minesweeper" "/Users/bitnguyen/Desktop/UCDavis/Review/ECS/Intro-to-Programming-in-C-course-work--master/Final Project/minesweeper/cmake-build-debug" "/Users/bitnguyen/Desktop/UCDavis/Review/ECS/Intro-to-Programming-in-C-course-work--master/Final Project/minesweeper/cmake-build-debug" "/Users/bitnguyen/Desktop/UCDavis/Review/ECS/Intro-to-Programming-in-C-course-work--master/Final Project/minesweeper/cmake-build-debug/CMakeFiles/minesweeper.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/minesweeper.dir/depend
