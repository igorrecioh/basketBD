#!/bin/bash

cd /home/root || exit
wget https://github.com/Kitware/CMake/releases/download/v3.15.1/cmake-3.15.1.tar.gz > /dev/null
tar -zxvf cmake-3.15.1.tar.gz > /dev/null
cd cmake-3.15.1
./bootstrap > /dev/null
make
make install
cd ..
mkdir build && cd build
cmake .. && make
#g++ main.cpp -o main -lsqlite3
