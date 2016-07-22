#!/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/sam/Documents/GNU_RADIO/blocks/gr-lets_test_some_stuff/lib
export GR_CONF_CONTROLPORT_ON=False
export PATH=/home/sam/Documents/GNU_RADIO/blocks/gr-lets_test_some_stuff/build/lib:$PATH
export LD_LIBRARY_PATH=/home/sam/Documents/GNU_RADIO/blocks/gr-lets_test_some_stuff/build/lib:$LD_LIBRARY_PATH
export PYTHONPATH=$PYTHONPATH
test-lets_test_some_stuff 
