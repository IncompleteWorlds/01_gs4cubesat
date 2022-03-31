#!/bin/sh

DESTINATION_DIRECTORY="/home/alberto/Documents/01_gs4cubesat/Installation"

LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$DESTINATION_DIRECTORY/libs

export LD_LIBRARY_PATH



echo "CubeGS. Incomplete Worlds (c) 2017"
echo "Starting CubeGS components"
echo " "

# Start up the GS Manager
# --------------------------------------------------------------------
if [ -f bin/GS_Manager ]; then
    if [ -f gs_manager.pid ]; then
       rm gs_manager.pid
    fi
    
   bin/GS_Manager        resources/config.json &
   echo $! > gs_manager.pid
   sleep 2
fi