#!/bin/bash

cd /home/root || exit
wget https://github.com/Kitware/CMake/releases/download/v3.15.1/cmake-3.15.1-Linux-x86_64.tar.gz
tar -zxvf cmake-3.15.1-Linux-x86_64.tar.gz
cd cmake-3.15.1
./bootstrap
make
make install
cd ..
mkdir build && cd build
cmake .. && make
#g++ main.cpp -o main -lsqlite3
