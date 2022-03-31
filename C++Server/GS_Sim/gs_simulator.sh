#!/bin/bash

LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/alberto/Documents/01_gs4cubesat/C++Server/Common/bin/Debug

export LD_LIBRARY_PATH

./gs_simulator $1 $2 $3 $4 $5
