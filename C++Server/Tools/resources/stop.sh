#!/bin/bash

LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$PWD/../libs

export LD_LIBRARY_PATH


# Shutting down Tools
# --------------------------------------------------------------------
if [ -f tools.pid ]; then
    tmp_pid=`cat tools.pid`

    kill -9 $tmp_pid

    rm tools.pid
fi