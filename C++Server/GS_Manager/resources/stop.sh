#!/bin/sh

DESTINATION_DIRECTORY="/home/alberto/Documents/01_gs4cubesat/Installation"

LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$DESTINATION_DIRECTORY/libs

export LD_LIBRARY_PATH

# Shutting down GS Manager
# --------------------------------------------------------------------
if [ -f gs_manager.pid ]; then
    tmp_pid=`cat gs_manager.pid`

    kill -9 $tmp_pid

    rm gs_manager.pid
fi