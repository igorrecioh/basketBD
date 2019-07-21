FROM ubuntu:latest

WORKDIR /home/root/

RUN \
apt update -qq && apt upgrade -y

RUN apt install g++ -y
COPY ./docker-entrypoint.sh /home/root
#RUN g++ /home/root/main.cpp -o main -lsqlite3

ENTRYPOINT ["/docker-entrypoint.sh"]
