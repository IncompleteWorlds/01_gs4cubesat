#!/bin/bash

# FIX ME
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$PWD/../libs

export LD_LIBRARY_PATH

# Shutting down Fds
# --------------------------------------------------------------------
if [ -f fds.pid ]; then
    tmp_pid=`cat fds.pid`

    kill -9 $tmp_pid

    rm fds.pid
fi
