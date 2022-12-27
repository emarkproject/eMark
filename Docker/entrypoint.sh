#!/bin/bash

set -meuo pipefail

EMARK_DIR=/emark/.eMark/
EMARK_CONF=/emark/.eMark/eMark.conf

if [ -z "${EMARK_RPCPASSWORD:-}" ]; then
  # Provide a random password.
  EMARK_RPCPASSWORD=$(head /dev/urandom | tr -dc A-Za-z0-9 | head -c 24 ; echo '')
fi

if [ ! -e "${EMARK_CONF}" ]; then
  tee -a >${EMARK_CONF} <<EOF

server=1
daemon=1
rpcuser=${EMARK_RPCUSER:-emark}
rpcpassword=${EMARK_RPCPASSWORD}

rpcclienttimeout=${EMARK_RPCCLIENTTIMEOUT:-30}
rpcallowip=${EMARK_RPCALLOWIP:-::/0}
rpcport=${EMARK_RPCPORT:-7777}
rpcbind=${EMARK_RPCBIND:-127.0.0.1}


EOF
echo "Created new configuration at ${EMARK_CONF}"
fi

# We have to somehow keep the container running because eMarkd forks and exits
sleep infinity &

if [ $# -eq 0 ]; then
  /emark/src/eMarkd
  fg %1
else
  exec "$@"
  fg %1
fi
