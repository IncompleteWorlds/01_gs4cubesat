#!/usr/bin/bash

TARGET_DIRECTORY=./include/

if [ ! -d $TARGET_DIRECTORY ]; then
   mkdir -p $TARGET_DIRECTORY
fi

LIST_FILES=`ls *.avro`

for ff in $LIST_FILES; do
    echo "Processing file: ["$ff"]"

    # Remove extension
    filename=$(basename $ff ".avro")

    #extension="${filename##*.}"
    #filename="${filename%.*}"

    # Preprocess the file for including the header
    proc_filename=$filename".proc"
    cpp -P $ff $proc_filename

    avrogencpp -n IW -i $proc_filename            -o $filename".h"

    # Move, if exists
    if [ -f $filename".h" ]; then
        mv $filename".h" $TARGET_DIRECTORY

        rm $proc_filename
    fi

done

echo "***************************************************"
echo "REMINDER:    UPDATE THE SCHEMAS AND REGENERATE THEM"
echo "***************************************************"
