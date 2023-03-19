FROM alpine:3.13
RUN apk add --no-cache git make g++ boost-dev openssl-dev db-dev miniupnpc-dev zlib-dev bash curl

RUN addgroup --gid 1000 emark
RUN adduser \
    --disabled-password \
    --gecos "" \
    --home /emark \
    --ingroup emark \
    --uid 1000 \
    emark

USER emark
RUN mkdir /emark/.eMark-volume-2
VOLUME /emark/.eMark-volume-2

RUN git clone https://github.com/emarkproject/eMark.git /emark/eMark
WORKDIR /emark/eMark
RUN git checkout tags/2.0.1

WORKDIR /emark/eMark/src
RUN make -f makefile.unix
COPY ./entrypoint.sh /
ENTRYPOINT ["/entrypoint.sh"]
EXPOSE 4555/tcp
EXPOSE 4444/tcp
