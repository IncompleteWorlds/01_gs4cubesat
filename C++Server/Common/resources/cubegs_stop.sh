#!/bin/sh


LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$PWD/libs

export LD_LIBRARY_PATH

DESTINATION_DIRECTORY="/home/alberto/Documents/01_gs4cubesat/Installation"


# Shutdown all process
# Send a command to the M&C process

# Shutting down MCS
# --------------------------------------------------------------------

# Shutting down GS Manager
# --------------------------------------------------------------------

# Shutting down Tools
# --------------------------------------------------------------------
cd Tools
./stop.sh
cd ..

# Shutting down FDS
# --------------------------------------------------------------------
cd FDS
./stop.sh
cd ..

# Shutting down M&C
# --------------------------------------------------------------------
cd Monitor_Control
./stop.sh
cd ..