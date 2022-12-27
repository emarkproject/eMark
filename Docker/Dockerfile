FROM alpine:3.13
RUN apk add --no-cache git make g++ boost-dev openssl-dev db-dev miniupnpc-dev zlib-dev bash


RUN addgroup --gid 1000 emark
RUN adduser \
    --disabled-password \
    --gecos "" \
    --home /emark \
    --ingroup emark \
    --uid 1000 \
    emark

USER emark

RUN git clone https://github.com/emarkproject/eMark.git /emark


WORKDIR /emark/src
RUN make -f makefile.unix

COPY ./entrypoint.sh /
ENTRYPOINT ["/entrypoint.sh"]
EXPOSE 5556/tcp
