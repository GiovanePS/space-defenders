#!/bin/bash

mkdir -p build
cd build
cmake ..
make
./game
cd ..
