FROM ubuntu:latest

WORKDIR /home/root/

RUN \
  apt update -qq && apt upgrade g++ libsqlite3-dev -y \
  && rm -rf /var/lib/apt/lists/*
COPY ./docker-entrypoint.sh /docker-entrypoint.sh
#RUN g++ /home/root/main.cpp -o main -lsqlite3

ENTRYPOINT ["/docker-entrypoint.sh"]
