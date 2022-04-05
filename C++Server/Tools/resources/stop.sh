#!/bin/bash

DESTINATION_DIRECTORY="/home/alberto/Documents/01_gs4cubesat/Installation"

LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$DESTINATION_DIRECTORY/libs

export LD_LIBRARY_PATH


# Shutting down Tools
# --------------------------------------------------------------------
if [ -f tools.pid ]; then
    tmp_pid=`cat tools.pid`

    kill -9 $tmp_pid

    rm tools.pid
fi