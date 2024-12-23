#!/bin/bash

mkdir -p build
cd build
cmake ..
# DEBUG:
# cmake .. -DCMAKE_BUILD_TYPE=Debug
make
./game
cd ..
