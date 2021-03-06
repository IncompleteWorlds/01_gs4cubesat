#!/bin/bash

DESTINATION_DIRECTORY="/home/alberto/Documents/01_gs4cubesat/Installation"

LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$DESTINATION_DIRECTORY/libs

export LD_LIBRARY_PATH


echo "CubeGS. Incomplete Worlds (c) 2017"
echo "Starting CubeGS components"
echo " "

# Start up the Tools
# --------------------------------------------------------------------
if [ -f bin/Tools ]; then
    if [ -f tools.pid ]; then
       rm tools.pid
    fi

   bin/Tools   resources/config.json &
   echo $! > tools.pid
   sleep 2
fi