#!/bin/bash

cd /home/root || exit
cmake --version
sudo apt upgrade cmake
cmake --version
mkdir build && cd build
cmake .. && make
#g++ main.cpp -o main -lsqlite3
