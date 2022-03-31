#!/bin/bash

INT_COMMAND="build"

if [ "$1" == "" ]; then
   echo "Commands: build, rebuild, clean"
   
else
   INT_COMMAND="$1"

   codelite-make -w codelite-cubegs.workspace -p Import_Database -c Debug -d $INT_COMMAND -e
fi


