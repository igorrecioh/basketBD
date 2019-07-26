#!/bin/bash

cd /home/root || exit
ls
mkdir build && cd build
cmake .. && make
#g++ main.cpp -o main -lsqlite3
