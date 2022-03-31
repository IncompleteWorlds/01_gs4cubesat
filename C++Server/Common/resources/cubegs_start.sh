#!/bin/bash

LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$PWD/libs

export LD_LIBRARY_PATH

DESTINATION_DIRECTORY="/home/alberto/Documents/01_gs4cubesat/Installation"

TERM_APP=mate-terminal

echo "CubeGS. Incomplete Worlds (c) 2019"
echo "Starting CubeGS components"
echo " "


# M&C has to be the first component to be started up
#
# Start up the Monitor_Control
# --------------------------------------------------------------------
cd Monitor_Control
./start.sh
cd ..


# Start up the Tools
# --------------------------------------------------------------------
cd Tools
./start.sh
cd ..



# Start up the MCS
# --------------------------------------------------------------------


# Start up the GS Manager
# --------------------------------------------------------------------


# Start up the FDS
# --------------------------------------------------------------------
cd FDS
./start.sh
cd ..

