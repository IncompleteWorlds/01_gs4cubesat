#/bin/bash

#
# IMPORTANT NOTE
#
# Namespace tag "namespace" is mandatory. It has to be included in the .avro files
# otherwise Java classes will be generated in the src directory
#

# PROJECT_DIRECTORY=/home/alberto/Documents/01_gs4cubesat/WUI/GsCommon
PROJECT_DIRECTORY=/home/03_Linux/01_gs4cubesat/C++Server/XtceProcessor

TARGET_MESSAGES_DIRECTORY=$PROJECT_DIRECTORY/src


if [ ! -d "$TARGET_MESSAGES_DIRECTORY" ]; then
   mkdir -p $TARGET_MESSAGES_DIRECTORY
fi


for ff in *.avro; do
    echo "Processing file: ["$ff"]"

    # Remove extension
    filename=$(basename $ff ".avro")

    #extension="${filename##*.}"
    #filename="${filename%.*}"

    # Preprocess the file for including the header
    proc_filename=$filename".proc"
    cpp -P $ff $proc_filename

    # java -jar ../../libs/avro-tools-1.8.1.jar compile
    # Usage: [-encoding <outputencoding>] [-string] (schema|protocol) input... outputdir
    #  input - input files or directories
    #  outputdir - directory to write generated java
    #  -string - use java.lang.String instead of Utf8

    java -jar ../../libs/avro-tools-1.8.1.jar compile -string schema $proc_filename    $TARGET_MESSAGES_DIRECTORY
    #avrogencpp -n IW -i $proc_filename            -o $filename".h"

    # Move, if exists
    #if [ -f $filename".h" ]; then
    #    mv $filename".h" ../../include/messages

    #    
    #fi
    
    if [ $? == 0 ]; then
        rm $proc_filename
    fi

done

