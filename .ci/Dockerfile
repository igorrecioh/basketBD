FROM ubuntu:latest

WORKDIR /home/root/

RUN \
  apt update -qq && apt upgrade g++ libsqlite3-dev cmake -y \
  && rm -rf /var/lib/apt/lists/*
COPY ./docker-entrypoint.sh /docker-entrypoint.sh

ENTRYPOINT ["/docker-entrypoint.sh"]
