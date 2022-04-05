#!/bin/sh


LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$PWD/libs

export LD_LIBRARY_PATH

DESTINATION_DIRECTORY="/home/alberto/Documents/01_gs4cubesat/Installation"


# Shutdown all process
# Send a command to the M&C process

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

# Shutting down GS Manager
# --------------------------------------------------------------------
if [ -f gs_manager.pid ]; then
    tmp_pid=`cat gs_manager.pid`

    kill -9 $tmp_pid

    rm gs_manager.pid
fi

# Shutting down Tools
# --------------------------------------------------------------------
if [ -f tools.pid ]; then
    tmp_pid=`cat tools.pid`

    kill -9 $tmp_pid

    rm tools.pid
fi

# Shutting down FDS
# --------------------------------------------------------------------
if [ -f fds.pid ]; then
    tmp_pid=`cat fds.pid`

    kill -9 $tmp_pid

    rm fds.pid
fi

# Shutting down M&C
# --------------------------------------------------------------------
if [ -f m_c.pid ]; then
    tmp_pid=`cat m_c.pid`

    kill -9 $tmp_pid

    rm m_c.pid
fi
