#!/bin/sh

echo "Installation script of CubeGS"
echo "(c) 2019 Incomplete Worlds"

SOURCE_DIRECTORY="/home/alberto/Projects/01_gs4cubesat/C++Server"

DESTINATION_DIRECTORY="/home/alberto/Projects/01_gs4cubesat/Installation"

echo "Installing into directory: "$DESTINATION_DIRECTORY

# Common
##########################################
mkdir -p $DESTINATION_DIRECTORY/libs
cp $SOURCE_DIRECTORY/Common/bin/Release/libCommon.so    $DESTINATION_DIRECTORY/libs


# Security & Access Controls
##########################################
mkdir -p $DESTINATION_DIRECTORY/libs
cp $SOURCE_DIRECTORY/Security_Access_Control/bin/Release/libSecurity_Access_Control.so    $DESTINATION_DIRECTORY/libs


# Monitor & Control
##########################################
mkdir -p $DESTINATION_DIRECTORY/Monitor_Control/bin
mkdir -p $DESTINATION_DIRECTORY/Monitor_Control/resources

cp $SOURCE_DIRECTORY/Monitor_Control/bin/Release/Monitor_Control      $DESTINATION_DIRECTORY/Monitor_Control/bin
cp $SOURCE_DIRECTORY/Monitor_Control/resources/config.json            $DESTINATION_DIRECTORY/Monitor_Control/resources
cp $SOURCE_DIRECTORY/Monitor_Control/resources/log4cpp.properties     $DESTINATION_DIRECTORY/Monitor_Control/resources
cp $SOURCE_DIRECTORY/Monitor_Control/resources/start.sh               $DESTINATION_DIRECTORY/Monitor_Control/
cp $SOURCE_DIRECTORY/Monitor_Control/resources/stop.sh                $DESTINATION_DIRECTORY/Monitor_Control/

chmod +x $DESTINATION_DIRECTORY/Monitor_Control/bin/Monitor_Control
chmod +x $DESTINATION_DIRECTORY/Monitor_Control/start.sh
chmod +x $DESTINATION_DIRECTORY/Monitor_Control/stop.sh


# MCS
##########################################
# Check whether it exists
mkdir -p $DESTINATION_DIRECTORY/MCS/bin
mkdir -p $DESTINATION_DIRECTORY/MCS/resources

cp $SOURCE_DIRECTORY/MCS/bin/Release/MCS                    $DESTINATION_DIRECTORY/MCS/bin
cp $SOURCE_DIRECTORY/MCS/resources/config.json              $DESTINATION_DIRECTORY/MCS/resources
cp $SOURCE_DIRECTORY/MCS/resources/log4cpp.properties       $DESTINATION_DIRECTORY/MCS/resources

cp $SOURCE_DIRECTORY/TM_Archive/bin/Release/TM_Archive         $DESTINATION_DIRECTORY/MCS/bin
cp $SOURCE_DIRECTORY/TM_Archive/resources/config.json          $DESTINATION_DIRECTORY/MCS/resources/TM_Archive_config.json
cp $SOURCE_DIRECTORY/TM_Archive/resources/log4cpp.properties   $DESTINATION_DIRECTORY/MCS/resources/TM_Archive_log4cpp.properties
cp $SOURCE_DIRECTORY/TM_Archive/resources/tm_archive.db        $DESTINATION_DIRECTORY/MCS/resources

cp $SOURCE_DIRECTORY/HKTM_Processor/bin/Release/HKTM_Processor       $DESTINATION_DIRECTORY/MCS/bin
cp $SOURCE_DIRECTORY/HKTM_Processor/resources/config.json            $DESTINATION_DIRECTORY/MCS/resources/HKTM_Processor_config.json
cp $SOURCE_DIRECTORY/HKTM_Processor/resources/log4cpp.properties     $DESTINATION_DIRECTORY/MCS/resources/HKTM_Processor_log4cpp.properties

cp $SOURCE_DIRECTORY/TC_Processor/bin/Release/TC_Processor           $DESTINATION_DIRECTORY/MCS/bin
cp $SOURCE_DIRECTORY/TC_Processor/resources/config.json              $DESTINATION_DIRECTORY/MCS/resources/TC_Processor_config.json
cp $SOURCE_DIRECTORY/TC_Processor/resources/log4cpp.properties       $DESTINATION_DIRECTORY/MCS/resources/TC_Processor_log4cpp.properties

cp $SOURCE_DIRECTORY/MCS/resources/start.sh                 $DESTINATION_DIRECTORY/MCS/
cp $SOURCE_DIRECTORY/MCS/resources/stop.sh                  $DESTINATION_DIRECTORY/MCS/

chmod +x $DESTINATION_DIRECTORY/MCS/bin/MCS
chmod +x $DESTINATION_DIRECTORY/MCS/bin/TM_Archive
chmod +x $DESTINATION_DIRECTORY/MCS/bin/HKTM_Processor
chmod +x $DESTINATION_DIRECTORY/MCS/bin/TC_Processor
chmod +x $DESTINATION_DIRECTORY/MCS/start.sh
chmod +x $DESTINATION_DIRECTORY/MCS/stop.sh


# FDS
##########################################
mkdir -p $DESTINATION_DIRECTORY/FDS/bin
mkdir -p $DESTINATION_DIRECTORY/FDS/resources

cp $SOURCE_DIRECTORY/FDS/bin/Release/FDS                    $DESTINATION_DIRECTORY/FDS/bin
cp $SOURCE_DIRECTORY/FDS/resources/config.json              $DESTINATION_DIRECTORY/FDS/resources
cp $SOURCE_DIRECTORY/FDS/resources/log4cpp.properties       $DESTINATION_DIRECTORY/FDS/resources
cp $SOURCE_DIRECTORY/FDS/resources/start.sh                 $DESTINATION_DIRECTORY/FDS/
cp $SOURCE_DIRECTORY/FDS/resources/stop.sh                  $DESTINATION_DIRECTORY/FDS/

chmod +x $DESTINATION_DIRECTORY/FDS/bin/FDS
chmod +x $DESTINATION_DIRECTORY/FDS/start.sh
chmod +x $DESTINATION_DIRECTORY/FDS/stop.sh


# Tools
##########################################
mkdir -p $DESTINATION_DIRECTORY/Tools/bin
mkdir -p $DESTINATION_DIRECTORY/Tools/resources

cp $SOURCE_DIRECTORY/Tools/bin/Release/Tools                $DESTINATION_DIRECTORY/Tools/bin
cp $SOURCE_DIRECTORY/Tools/resources/config.json            $DESTINATION_DIRECTORY/Tools/resources
cp $SOURCE_DIRECTORY/Tools/resources/log4cpp.properties     $DESTINATION_DIRECTORY/Tools/resources
cp $SOURCE_DIRECTORY/Tools/resources/tools.db               $DESTINATION_DIRECTORY/Tools/resources
cp $SOURCE_DIRECTORY/Tools/resources/start.sh               $DESTINATION_DIRECTORY/Tools/
cp $SOURCE_DIRECTORY/Tools/resources/stop.sh                $DESTINATION_DIRECTORY/Tools/


chmod +x $DESTINATION_DIRECTORY/Tools/bin/Tools
chmod +x $DESTINATION_DIRECTORY/Tools/start.sh
chmod +x $DESTINATION_DIRECTORY/Tools/stop.sh


# GS Manager
##########################################
mkdir -p $DESTINATION_DIRECTORY/GS_Manager/bin
mkdir -p $DESTINATION_DIRECTORY/GS_Manager/resources

cp $SOURCE_DIRECTORY/GS_Manager/bin/Release/GS_Manager         $DESTINATION_DIRECTORY/GS_Manager/bin
cp $SOURCE_DIRECTORY/GS_Manager/resources/config.json          $DESTINATION_DIRECTORY/GS_Manager/resources
cp $SOURCE_DIRECTORY/GS_Manager/resources/log4cpp.properties   $DESTINATION_DIRECTORY/GS_Manager/resources
cp $SOURCE_DIRECTORY/GS_Manager/resources/gs_manager.db        $DESTINATION_DIRECTORY/GS_Manager/resources
cp $SOURCE_DIRECTORY/GS_Manager/resources/start.sh             $DESTINATION_DIRECTORY/GS_Manager/
cp $SOURCE_DIRECTORY/GS_Manager/resources/stop.sh              $DESTINATION_DIRECTORY/GS_Manager/


chmod +x $DESTINATION_DIRECTORY/GS_Manager/bin/GS_Manager
chmod +x $DESTINATION_DIRECTORY/GS_Manager/start.sh
chmod +x $DESTINATION_DIRECTORY/GS_Manager/stop.sh


# WUI
##########################################


# Others
##########################################
cp cubegs_start.sh    $DESTINATION_DIRECTORY
cp cubegs_stop.sh     $DESTINATION_DIRECTORY

chmod +x $DESTINATION_DIRECTORY/cubegs_start.sh
chmod +x $DESTINATION_DIRECTORY/cubegs_stop.sh

echo "Installation successfully done"