FROM ubuntu:23.04  as ubuntu


RUN apt update
RUN apt -y upgrade
RUN echo 'tzdata tzdata/Areas select Europe' | debconf-set-selections
RUN echo 'tzdata tzdata/Zones/Europe select London' | debconf-set-selections
RUN DEBIAN_FRONTEND="noninteractive" apt install -y --no-install-recommends tzdata

RUN apt install -y ssh\ 
                nano \
                telnet \
                iputils-ping \
                git \
                curl \
                wget \
                g++ \
                gcc \
                make \
                gdb \
                net-tools \
                tcpdump
                 
                

EXPOSE 22

ENTRYPOINT service ssh start && sleep infinity
