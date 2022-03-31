#!/bin/bash

LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$PWD/../libs

export LD_LIBRARY_PATH

echo "CubeGS. Incomplete Worlds (c) 2019"
echo "Starting CubeGS components"
echo " "

# Start up the FDS
# --------------------------------------------------------------------
if [ -f bin/FDS ]; then
    if [ -f fds.pid ]; then
       rm fds.pid
    fi

   bin/FDS  resources/config.json &
   echo $! > fds.pid
   sleep 2
fi
