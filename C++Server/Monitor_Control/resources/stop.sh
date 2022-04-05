#!/bin/bash


DESTINATION_DIRECTORY="/home/alberto/Documents/01_gs4cubesat/Installation"

LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$DESTINATION_DIRECTORY/libs

export LD_LIBRARY_PATH


# Shutting down M&C
# --------------------------------------------------------------------
if [ -f m_c.pid ]; then
    tmp_pid=`cat m_c.pid`

    kill -9 $tmp_pid

    rm m_c.pid
fi