FROM ubuntu:latest

WORKDIR /home/root/

RUN \
apt update -qq && apt upgrade -y

RUN apt install g++ -y
RUN ls
RUN g++ main.cpp -o main -lsqlite3
