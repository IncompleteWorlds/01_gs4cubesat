#!/bin/bash

DESTINATION_DIRECTORY="/home/alberto/Documents/01_gs4cubesat/Installation"

LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$DESTINATION_DIRECTORY/libs

export LD_LIBRARY_PATH


# Start up the MCS
# --------------------------------------------------------------------
if [ -f bin/MCS ]; then
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

   bin/MCS              resources/config.json &
   echo $! > mcs.pid
   sleep 2

   bin/TM_Archive       resources/TM_Archive_config.json &
   echo $! > tm_archive.pid
   sleep 2

   bin/HKTM_Processor   resources/HKTM_Processor_config.json &
   echo $! > hktm_processor.pid
   sleep 2

   bin/TC_Processor     resources/TC_Processor_config.json &
   echo $! > tc_processor.pid
   sleep 2

fi