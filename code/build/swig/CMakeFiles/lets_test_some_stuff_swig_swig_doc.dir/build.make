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
CMAKE_SOURCE_DIR = /home/sam/git_repos/NSF_IRES_TUTORIAL/code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sam/git_repos/NSF_IRES_TUTORIAL/code/build

# Utility rule file for lets_test_some_stuff_swig_swig_doc.

# Include the progress variables for this target.
include swig/CMakeFiles/lets_test_some_stuff_swig_swig_doc.dir/progress.make

swig/CMakeFiles/lets_test_some_stuff_swig_swig_doc: swig/lets_test_some_stuff_swig_doc.i


swig/lets_test_some_stuff_swig_doc.i: swig/lets_test_some_stuff_swig_doc_swig_docs/xml/index.xml
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/sam/git_repos/NSF_IRES_TUTORIAL/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating python docstrings for lets_test_some_stuff_swig_doc"
	cd /home/sam/git_repos/NSF_IRES_TUTORIAL/code/docs/doxygen && /usr/bin/python2 -B /home/sam/git_repos/NSF_IRES_TUTORIAL/code/docs/doxygen/swig_doc.py /home/sam/git_repos/NSF_IRES_TUTORIAL/code/build/swig/lets_test_some_stuff_swig_doc_swig_docs/xml /home/sam/git_repos/NSF_IRES_TUTORIAL/code/build/swig/lets_test_some_stuff_swig_doc.i

swig/lets_test_some_stuff_swig_doc_swig_docs/xml/index.xml: swig/_lets_test_some_stuff_swig_doc_tag
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/sam/git_repos/NSF_IRES_TUTORIAL/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating doxygen xml for lets_test_some_stuff_swig_doc docs"
	cd /home/sam/git_repos/NSF_IRES_TUTORIAL/code/build/swig && ./_lets_test_some_stuff_swig_doc_tag
	cd /home/sam/git_repos/NSF_IRES_TUTORIAL/code/build/swig && /usr/bin/doxygen /home/sam/git_repos/NSF_IRES_TUTORIAL/code/build/swig/lets_test_some_stuff_swig_doc_swig_docs/Doxyfile

lets_test_some_stuff_swig_swig_doc: swig/CMakeFiles/lets_test_some_stuff_swig_swig_doc
lets_test_some_stuff_swig_swig_doc: swig/lets_test_some_stuff_swig_doc.i
lets_test_some_stuff_swig_swig_doc: swig/lets_test_some_stuff_swig_doc_swig_docs/xml/index.xml
lets_test_some_stuff_swig_swig_doc: swig/CMakeFiles/lets_test_some_stuff_swig_swig_doc.dir/build.make

.PHONY : lets_test_some_stuff_swig_swig_doc

# Rule to build all files generated by this target.
swig/CMakeFiles/lets_test_some_stuff_swig_swig_doc.dir/build: lets_test_some_stuff_swig_swig_doc

.PHONY : swig/CMakeFiles/lets_test_some_stuff_swig_swig_doc.dir/build

swig/CMakeFiles/lets_test_some_stuff_swig_swig_doc.dir/clean:
	cd /home/sam/git_repos/NSF_IRES_TUTORIAL/code/build/swig && $(CMAKE_COMMAND) -P CMakeFiles/lets_test_some_stuff_swig_swig_doc.dir/cmake_clean.cmake
.PHONY : swig/CMakeFiles/lets_test_some_stuff_swig_swig_doc.dir/clean

swig/CMakeFiles/lets_test_some_stuff_swig_swig_doc.dir/depend:
	cd /home/sam/git_repos/NSF_IRES_TUTORIAL/code/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sam/git_repos/NSF_IRES_TUTORIAL/code /home/sam/git_repos/NSF_IRES_TUTORIAL/code/swig /home/sam/git_repos/NSF_IRES_TUTORIAL/code/build /home/sam/git_repos/NSF_IRES_TUTORIAL/code/build/swig /home/sam/git_repos/NSF_IRES_TUTORIAL/code/build/swig/CMakeFiles/lets_test_some_stuff_swig_swig_doc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : swig/CMakeFiles/lets_test_some_stuff_swig_swig_doc.dir/depend

