#!/bin/bash

INT_PROJECT=""

if [ "$1" == "" ]; then
   echo "Please, enter a project name"
   
else
   INT_PROJECT="$1"

   codelite-make -w ../cubegs.workspace -p $INT_PROJECT -c Release -d build -e
fi


