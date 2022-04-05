#!/bin/bash

INC_DIRECTORY="../include"

if [ ! -d $INC_DIRECTORY ]; then
   mkdir -p $INC_DIRECTORY
fi


LIST_FILES=`ls *.avro`

for ff in $LIST_FILES; do
    echo " "
    echo "Processing file: ["$ff"]"

    # Remove extension
    filename=$(basename $ff ".avro")

    #extension="${filename##*.}"
    #filename="${filename%.*}"

    # Preprocess the file for including the header
    proc_filename=$filename".proc"
    cpp -P $ff $proc_filename
    
    if [ $? -eq 0 ]; then
        avrogencpp -n IW -i $proc_filename            -o $filename".h"

        # Move, if exists
        if [ -f $filename".h" ]; then
            mv $filename".h" $INC_DIRECTORY

            # TestTool will use this file for parsing the complete scheme
            #rm $proc_filename
        fi
    fi
done

