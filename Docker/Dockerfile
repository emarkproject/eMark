FROM debian:wheezy-slim

MAINTAINER Massimo Wenusch <massimo@wenusch.nl>

RUN apt-get update -y \
  && apt-get install -y build-essential \
  && apt-get install -y libssl-dev \
  && apt-get install -y libdb++-dev \
  && apt-get install -y libboost-all-dev \
  && apt-get install -y libqrencode-dev \
  && apt-get install -y git \
  && apt-get install -y libqt4-dev libminiupnpc-dev

RUN mkdir ~/.ssh/ \
  && touch ~/.ssh/id_rsa \
  && touch ~/.ssh/known_hosts \
  && chmod 400 ~/.ssh/id_rsa

RUN ssh-keyscan github.com >> ~/.ssh/known_hosts \
  && mkdir /emark \
  && git clone https://github.com/emarkproject/eMark.git /emark

RUN cd /emark/src \
  && make -f makefile.unix -e PIC=1

CMD ["/emark/src/eMarkd"]