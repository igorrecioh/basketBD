#!/bin/bash

cd /home/root || exit
ls
g++ main.cpp -o main -lsqlite3
