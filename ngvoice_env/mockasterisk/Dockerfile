FROM ubuntu:23.04  as ubuntu


RUN apt update
RUN apt -y upgrade
RUN echo 'tzdata tzdata/Areas select Europe' | debconf-set-selections
RUN echo 'tzdata tzdata/Zones/Europe select London' | debconf-set-selections
RUN DEBIAN_FRONTEND="noninteractive" apt install -y --no-install-recommends tzdata

RUN apt install -y ssh\ 
                asterisk \
                nano \
                telnet \
                iputils-ping \
                git \
                curl \
                wget \
                net-tools
                 
                

EXPOSE 22

ENTRYPOINT service ssh start && service asterisk start && sleep infinity
