FROM alpine:3.13

RUN apk add --no-cache git make g++ boost-dev openssl-dev db-dev miniupnpc-dev zlib-dev

RUN mkdir /emark
RUN git clone https://github.com/emarkproject/eMark.git /emark

WORKDIR /emark/src
RUN make -f makefile.unix
CMD /emark/src/eMarkd ; sleep infinity
