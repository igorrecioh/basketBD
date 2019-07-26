#!/bin/bash

cd /home/root || exit
cmake --version
apt remove cmake
add-apt-repository -y ppa:george-edison55/cmake-3.x
apt update
apt install cmake
cmake --version
mkdir build && cd build
cmake .. && make
#g++ main.cpp -o main -lsqlite3
