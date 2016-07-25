/* -*- c++ -*- */

#define LETS_TEST_SOME_STUFF_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "lets_test_some_stuff_swig_doc.i"

%{
#include "lets_test_some_stuff/taggedFileSource.h"
#include "lets_test_some_stuff/taggedHeader.h"
#include "lets_test_some_stuff/taggedAccessCode.h"
#include "lets_test_some_stuff/taggedPacketGate.h"
%}

%include "lets_test_some_stuff/taggedFileSource.h"
GR_SWIG_BLOCK_MAGIC2(lets_test_some_stuff, taggedFileSource);
%include "lets_test_some_stuff/taggedHeader.h"
GR_SWIG_BLOCK_MAGIC2(lets_test_some_stuff, taggedHeader);
%include "lets_test_some_stuff/taggedAccessCode.h"
GR_SWIG_BLOCK_MAGIC2(lets_test_some_stuff, taggedAccessCode);

%include "lets_test_some_stuff/taggedPacketGate.h"
GR_SWIG_BLOCK_MAGIC2(lets_test_some_stuff, taggedPacketGate);
