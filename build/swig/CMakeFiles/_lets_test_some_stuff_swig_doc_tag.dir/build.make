# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sam/Documents/GNU_RADIO/blocks/gr-lets_test_some_stuff

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sam/Documents/GNU_RADIO/blocks/gr-lets_test_some_stuff/build

# Include any dependencies generated for this target.
include swig/CMakeFiles/_lets_test_some_stuff_swig_doc_tag.dir/depend.make

# Include the progress variables for this target.
include swig/CMakeFiles/_lets_test_some_stuff_swig_doc_tag.dir/progress.make

# Include the compile flags for this target's objects.
include swig/CMakeFiles/_lets_test_some_stuff_swig_doc_tag.dir/flags.make

swig/CMakeFiles/_lets_test_some_stuff_swig_doc_tag.dir/_lets_test_some_stuff_swig_doc_tag.cpp.o: swig/CMakeFiles/_lets_test_some_stuff_swig_doc_tag.dir/flags.make
swig/CMakeFiles/_lets_test_some_stuff_swig_doc_tag.dir/_lets_test_some_stuff_swig_doc_tag.cpp.o: swig/_lets_test_some_stuff_swig_doc_tag.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sam/Documents/GNU_RADIO/blocks/gr-lets_test_some_stuff/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object swig/CMakeFiles/_lets_test_some_stuff_swig_doc_tag.dir/_lets_test_some_stuff_swig_doc_tag.cpp.o"
	cd /home/sam/Documents/GNU_RADIO/blocks/gr-lets_test_some_stuff/build/swig && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/_lets_test_some_stuff_swig_doc_tag.dir/_lets_test_some_stuff_swig_doc_tag.cpp.o -c /home/sam/Documents/GNU_RADIO/blocks/gr-lets_test_some_stuff/build/swig/_lets_test_some_stuff_swig_doc_tag.cpp

swig/CMakeFiles/_lets_test_some_stuff_swig_doc_tag.dir/_lets_test_some_stuff_swig_doc_tag.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/_lets_test_some_stuff_swig_doc_tag.dir/_lets_test_some_stuff_swig_doc_tag.cpp.i"
	cd /home/sam/Documents/GNU_RADIO/blocks/gr-lets_test_some_stuff/build/swig && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sam/Documents/GNU_RADIO/blocks/gr-lets_test_some_stuff/build/swig/_lets_test_some_stuff_swig_doc_tag.cpp > CMakeFiles/_lets_test_some_stuff_swig_doc_tag.dir/_lets_test_some_stuff_swig_doc_tag.cpp.i

swig/CMakeFiles/_lets_test_some_stuff_swig_doc_tag.dir/_lets_test_some_stuff_swig_doc_tag.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/_lets_test_some_stuff_swig_doc_tag.dir/_lets_test_some_stuff_swig_doc_tag.cpp.s"
	cd /home/sam/Documents/GNU_RADIO/blocks/gr-lets_test_some_stuff/build/swig && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sam/Documents/GNU_RADIO/blocks/gr-lets_test_some_stuff/build/swig/_lets_test_some_stuff_swig_doc_tag.cpp -o CMakeFiles/_lets_test_some_stuff_swig_doc_tag.dir/_lets_test_some_stuff_swig_doc_tag.cpp.s

swig/CMakeFiles/_lets_test_some_stuff_swig_doc_tag.dir/_lets_test_some_stuff_swig_doc_tag.cpp.o.requires:

.PHONY : swig/CMakeFiles/_lets_test_some_stuff_swig_doc_tag.dir/_lets_test_some_stuff_swig_doc_tag.cpp.o.requires

swig/CMakeFiles/_lets_test_some_stuff_swig_doc_tag.dir/_lets_test_some_stuff_swig_doc_tag.cpp.o.provides: swig/CMakeFiles/_lets_test_some_stuff_swig_doc_tag.dir/_lets_test_some_stuff_swig_doc_tag.cpp.o.requires
	$(MAKE) -f swig/CMakeFiles/_lets_test_some_stuff_swig_doc_tag.dir/build.make swig/CMakeFiles/_lets_test_some_stuff_swig_doc_tag.dir/_lets_test_some_stuff_swig_doc_tag.cpp.o.provides.build
.PHONY : swig/CMakeFiles/_lets_test_some_stuff_swig_doc_tag.dir/_lets_test_some_stuff_swig_doc_tag.cpp.o.provides

swig/CMakeFiles/_lets_test_some_stuff_swig_doc_tag.dir/_lets_test_some_stuff_swig_doc_tag.cpp.o.provides.build: swig/CMakeFiles/_lets_test_some_stuff_swig_doc_tag.dir/_lets_test_some_stuff_swig_doc_tag.cpp.o


# Object files for target _lets_test_some_stuff_swig_doc_tag
_lets_test_some_stuff_swig_doc_tag_OBJECTS = \
"CMakeFiles/_lets_test_some_stuff_swig_doc_tag.dir/_lets_test_some_stuff_swig_doc_tag.cpp.o"

# External object files for target _lets_test_some_stuff_swig_doc_tag
_lets_test_some_stuff_swig_doc_tag_EXTERNAL_OBJECTS =

swig/_lets_test_some_stuff_swig_doc_tag: swig/CMakeFiles/_lets_test_some_stuff_swig_doc_tag.dir/_lets_test_some_stuff_swig_doc_tag.cpp.o
swig/_lets_test_some_stuff_swig_doc_tag: swig/CMakeFiles/_lets_test_some_stuff_swig_doc_tag.dir/build.make
swig/_lets_test_some_stuff_swig_doc_tag: swig/CMakeFiles/_lets_test_some_stuff_swig_doc_tag.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sam/Documents/GNU_RADIO/blocks/gr-lets_test_some_stuff/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable _lets_test_some_stuff_swig_doc_tag"
	cd /home/sam/Documents/GNU_RADIO/blocks/gr-lets_test_some_stuff/build/swig && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/_lets_test_some_stuff_swig_doc_tag.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
swig/CMakeFiles/_lets_test_some_stuff_swig_doc_tag.dir/build: swig/_lets_test_some_stuff_swig_doc_tag

.PHONY : swig/CMakeFiles/_lets_test_some_stuff_swig_doc_tag.dir/build

swig/CMakeFiles/_lets_test_some_stuff_swig_doc_tag.dir/requires: swig/CMakeFiles/_lets_test_some_stuff_swig_doc_tag.dir/_lets_test_some_stuff_swig_doc_tag.cpp.o.requires

.PHONY : swig/CMakeFiles/_lets_test_some_stuff_swig_doc_tag.dir/requires

swig/CMakeFiles/_lets_test_some_stuff_swig_doc_tag.dir/clean:
	cd /home/sam/Documents/GNU_RADIO/blocks/gr-lets_test_some_stuff/build/swig && $(CMAKE_COMMAND) -P CMakeFiles/_lets_test_some_stuff_swig_doc_tag.dir/cmake_clean.cmake
.PHONY : swig/CMakeFiles/_lets_test_some_stuff_swig_doc_tag.dir/clean

swig/CMakeFiles/_lets_test_some_stuff_swig_doc_tag.dir/depend:
	cd /home/sam/Documents/GNU_RADIO/blocks/gr-lets_test_some_stuff/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sam/Documents/GNU_RADIO/blocks/gr-lets_test_some_stuff /home/sam/Documents/GNU_RADIO/blocks/gr-lets_test_some_stuff/swig /home/sam/Documents/GNU_RADIO/blocks/gr-lets_test_some_stuff/build /home/sam/Documents/GNU_RADIO/blocks/gr-lets_test_some_stuff/build/swig /home/sam/Documents/GNU_RADIO/blocks/gr-lets_test_some_stuff/build/swig/CMakeFiles/_lets_test_some_stuff_swig_doc_tag.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : swig/CMakeFiles/_lets_test_some_stuff_swig_doc_tag.dir/depend
