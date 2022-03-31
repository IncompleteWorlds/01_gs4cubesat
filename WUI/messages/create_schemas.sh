#!/usr/bin/bash

TARGET_DIRECTORY=./schemas
#
#if [ ! -d $TARGET_DIRECTORY ]; then
#   mkdir -p $TARGET_DIRECTORY
#fi

#LIST_FILES=`ls ${TARGET_DIRECTORY}/*.avro`
#
#for ff in $LIST_FILES; do
#    echo "Processing file: ["$ff"]"
#
#    # Remove extension
#    filename=$(basename $ff ".avro")
#
#    #extension="${filename##*.}"
#    #filename="${filename%.*}"
#
#    # Preprocess the file for including the header
#    proc_filename=${filename}".json"
#    cpp -P $ff ${TARGET_DIRECTORY}/$proc_filename
#
#done


cd $TARGET_DIRECTORY

../compile_schemas.py

cd -
