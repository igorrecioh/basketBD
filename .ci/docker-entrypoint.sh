#!/bin/bash

cd /home/root || exit
mkdir build && cd build
cmake .. && make
#g++ main.cpp -o main -lsqlite3
