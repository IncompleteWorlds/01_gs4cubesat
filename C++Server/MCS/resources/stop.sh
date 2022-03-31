#!/bin/bash

DESTINATION_DIRECTORY="/home/alberto/Documents/01_gs4cubesat/Installation"

LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$DESTINATION_DIRECTORY/libs

export LD_LIBRARY_PATH


# Shutting down MCS
# --------------------------------------------------------------------
if [ -f mcs.pid ]; then
    tmp_pid=`cat mcs.pid`

    kill -9 $tmp_pid

    rm mcs.pid

    tmp_pid=`cat tm_archive.pid`

    kill -9 $tmp_pid

    rm tm_archive.pid

    tmp_pid=`cat hktm_processor.pid`

    kill -9 $tmp_pid

    rm hktm_processor.pid

    tmp_pid=`cat tc_processor.pid`

    kill -9 $tmp_pid

    rm tc_processor.pid
fi
