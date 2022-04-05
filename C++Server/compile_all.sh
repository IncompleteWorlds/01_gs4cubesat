#!/bin/bash

# FDS  
LIST_DIRECTORIES="Common  Security_Access_Control  Monitor_Control  GS_Manager  MCS  Tools"

COMPILE_TYPE="debug"

if [ ! -z "$1" ]; then
    COMPILE_TYPE="$1"
    
else
    echo "Usage: "
    echo "  $ compile_all.sh   [ clean | debug | release | install ]"
    exit 1
fi

if [ $COMPILE_TYPE == "install" ]; then
    cd Common/resources
    ./cubegs_install.sh
    
else
    echo "Compiling in mode: "$COMPILE_TYPE

    for dd in $LIST_DIRECTORIES; do
        echo "==========================================================="
        echo "Recompiling: "$dd
        
        cd $dd
        make $COMPILE_TYPE
        
        # Check error code
        if [ $? != 0 ]; then
            echo "ERROR: Stopping the compilatino process"
            exit 1
        fi
        
        cd -

        echo " "
        echo " "
    done

fi


exit 0



