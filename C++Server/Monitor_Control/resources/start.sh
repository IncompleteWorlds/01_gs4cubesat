#!/bin/bash

DESTINATION_DIRECTORY="/home/alberto/Documents/01_gs4cubesat/Installation"

LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$DESTINATION_DIRECTORY/libs

export LD_LIBRARY_PATH


echo "CubeGS. Incomplete Worlds (c) 2017"
echo "Starting CubeGS components"
echo " "


# M&C has to be the first component to be started up
#
# Start up the Monitor_Control
# --------------------------------------------------------------------
if [ -f m_c.pid ]; then
    rm m_c.pid
fi

bin/Monitor_Control      resources/config.json &
echo $! > m_c.pid

sleep 2
