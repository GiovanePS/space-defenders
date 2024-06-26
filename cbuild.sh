#!/bin/bash
mkdir -p build
cd build
if [ -f main ]; then
	./main
else
	cmake --build . --target all
	./game
fi
