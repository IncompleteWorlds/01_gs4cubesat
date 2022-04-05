#!/bin/bash

LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$PWD/libs

export LD_LIBRARY_PATH

DESTINATION_DIRECTORY="/home/alberto/Documents/01_gs4cubesat/Installation"


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
xterm -hold -e "cd Monitor_Control;    bin/Monitor_Control      resources/config.json" &
echo $! > m_c.pid

sleep 2


# Start up the Tools
# --------------------------------------------------------------------
if [ -f Tools/bin/Tools ]; then
    if [ -f tools.pid ]; then
       rm tools.pid
    fi

   xterm -hold  -e "cd Tools;     bin/Tools   resources/config.json" &
   echo $! > tools.pid
   sleep 2
fi



# Start up the MCS
# --------------------------------------------------------------------
if [ -f MCS/bin/MCS ]; then
    if [ -f mcs.pid ]; then
       rm mcs.pid
    fi
    if [ -f tm_archive.pid ]; then
       rm tm_archive.pid
    fi
    if [ -f hktm_processor.pid ]; then
       rm hktm_processor.pid
    fi
    if [ -f tc_processor.pid ]; then
       rm tc_processor.pid
    fi

   xterm -hold  -e "cd MCS;    bin/MCS       resources/config.json" &
   echo $! > mcs.pid
   sleep 2

   xterm -hold  -e "MCS/bin/TM_Archive       MCS/resources/TM_Archive_config.json" &
   echo $! > tm_archive.pid
   sleep 2

   xterm -hold  -e "MCS/bin/HKTM_Processor       MCS/resources/HKTM_Processor_config.json" &
   echo $! > hktm_processor.pid
   sleep 2

   xterm -hold  -e "MCS/bin/TC_Processor       MCS/resources/TC_Processor_config.json" &
   echo $! > tc_processor.pid
   sleep 2

fi


# Start up the GS Manager
# --------------------------------------------------------------------
if [ -f GS_Manager/bin/GS_Manager ]; then
    if [ -f gs_manager.pid ]; then
       rm gs_manager.pid
    fi
    
   xterm -hold  -e "cd GS_Manager;    bin/GS_Manager        resources/config.json" &
   echo $! > gs_manager.pid
   sleep 2
fi


# Start up the FDS
# --------------------------------------------------------------------
if [ -f FDS/bin/FDS ]; then
    if [ -f fds.pid ]; then
       rm fds.pid
    fi

   xterm -hold  -e "cd FDS;   bin/FDS       resources/config.json" &
   echo $! > fds.pid
   sleep 2
fi

