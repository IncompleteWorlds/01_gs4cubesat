#!/bin/bash


for ff in messages/*.avro; do
    echo "Processing file: ["$ff"]"

    # Remove extension
    filename=$(basename $ff ".avro")

    #extension="${filename##*.}"
    #filename="${filename%.*}"

    # Preprocess the file for including the header
    new_filename=$filename".json"
    mv $ff $new_filename
   
done

for ff in data_model/*.avro; do
    echo "Processing file: ["$ff"]"

    # Remove extension
    filename=$(basename $ff ".avro")

    #extension="${filename##*.}"
    #filename="${filename%.*}"

    # Preprocess the file for including the header
    new_filename=$filename".json"
    mv $ff $new_filename
   
done

