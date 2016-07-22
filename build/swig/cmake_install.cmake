# Install script for directory: /home/sam/Documents/GNU_RADIO/blocks/gr-lets_test_some_stuff/swig

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python2.7/site-packages/lets_test_some_stuff/_lets_test_some_stuff_swig.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python2.7/site-packages/lets_test_some_stuff/_lets_test_some_stuff_swig.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python2.7/site-packages/lets_test_some_stuff/_lets_test_some_stuff_swig.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/site-packages/lets_test_some_stuff" TYPE MODULE FILES "/home/sam/Documents/GNU_RADIO/blocks/gr-lets_test_some_stuff/build/swig/_lets_test_some_stuff_swig.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python2.7/site-packages/lets_test_some_stuff/_lets_test_some_stuff_swig.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python2.7/site-packages/lets_test_some_stuff/_lets_test_some_stuff_swig.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python2.7/site-packages/lets_test_some_stuff/_lets_test_some_stuff_swig.so"
         OLD_RPATH "/home/sam/Documents/GNU_RADIO/blocks/gr-lets_test_some_stuff/build/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python2.7/site-packages/lets_test_some_stuff/_lets_test_some_stuff_swig.so")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/site-packages/lets_test_some_stuff" TYPE FILE FILES "/home/sam/Documents/GNU_RADIO/blocks/gr-lets_test_some_stuff/build/swig/lets_test_some_stuff_swig.py")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/site-packages/lets_test_some_stuff" TYPE FILE FILES
    "/home/sam/Documents/GNU_RADIO/blocks/gr-lets_test_some_stuff/build/swig/lets_test_some_stuff_swig.pyc"
    "/home/sam/Documents/GNU_RADIO/blocks/gr-lets_test_some_stuff/build/swig/lets_test_some_stuff_swig.pyo"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/lets_test_some_stuff/lets_test_some_stuff/swig" TYPE FILE FILES
    "/home/sam/Documents/GNU_RADIO/blocks/gr-lets_test_some_stuff/swig/lets_test_some_stuff_swig.i"
    "/home/sam/Documents/GNU_RADIO/blocks/gr-lets_test_some_stuff/build/swig/lets_test_some_stuff_swig_doc.i"
    )
endif()
