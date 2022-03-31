#!/bin/bash

# FDS  GS_Manager 
LIST_DIRECTORIES="Common  Security_Access_Control  Monitor_Control  Tools FDS  MCS"

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

    exit 0
fi

if [ ! -z "$2" ]; then
    INT_PROJECT="$2"

    echo "Compiling "$INT_PROJECT" in mode: "$COMPILE_TYPE

    if [ $COMPILE_TYPE == "debug" ]; then
        codelite-make -w cubegs.workspace -p $INT_PROJECT -c Debug -d build -e

        # Check error code
        if [ $? != 0 ]; then
            echo "ERROR: Stopping the compilation process"
            exit 1
        fi
    fi 

    if [ $COMPILE_TYPE == "release" ]; then
        codelite-make -w cubegs.workspace -p $INT_PROJECT -c Release -d build -e

        # Check error code
        if [ $? != 0 ]; then
            echo "ERROR: Stopping the compilation process"
            exit 1
        fi
    fi 

    if [ $COMPILE_TYPE == "clean" ]; then
        codelite-make -w cubegs.workspace -p $INT_PROJECT -c Release -d clean -e
        # Check error code
        if [ $? != 0 ]; then
            echo "ERROR: Stopping the compilation process"
            exit 1
        fi

        codelite-make -w cubegs.workspace -p $INT_PROJECT -c Debug -d clean -e
        # Check error code
        if [ $? != 0 ]; then
            echo "ERROR: Stopping the compilation process"
            exit 1
        fi
    fi 

else
    echo "Compiling ALL project in mode: "$COMPILE_TYPE

    for dd in $LIST_DIRECTORIES; do
        echo "==========================================================="
        echo "Recompiling: "$dd
        
        if [ $COMPILE_TYPE == "debug" ]; then
            codelite-make -w cubegs.workspace -p $dd -c Debug -d build -e

            # Check error code
            if [ $? != 0 ]; then
                echo "ERROR: Stopping the compilation process"
                exit 1
            fi
        fi 

        if [ $COMPILE_TYPE == "release" ]; then
            codelite-make -w cubegs.workspace -p $dd -c Release -d build -e
            # Check error code
            if [ $? != 0 ]; then
                echo "ERROR: Stopping the compilation process"
                exit 1
            fi        fi 

        if [ $COMPILE_TYPE == "clean" ]; then
            codelite-make -w cubegs.workspace -p $dd -c Release -d clean -e
            # Check error code
            if [ $? != 0 ]; then
                echo "ERROR: Stopping the compilation process"
                exit 1
            fi

            codelite-make -w cubegs.workspace -p $dd -c Debug -d clean -e
            # Check error code
            if [ $? != 0 ]; then
                echo "ERROR: Stopping the compilation process"
                exit 1
            fi
        fi 
        
        echo " "
        echo " "
    done

fi

exit 0



