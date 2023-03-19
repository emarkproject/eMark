#!/bin/bash

set -meuo pipefail

EMARK_DIR=/emark/.eMark-volume-2/
EMARK_CONF=/emark/.eMark-volume-2/eMark.conf

if [ -z "${EMARK_RPCPASSWORD:-}" ]; then
  # Provide a random password.
  EMARK_RPCPASSWORD=$(head /dev/urandom | tr -dc A-Za-z0-9 | head -c 24 ; echo '')
fi

if [ ! -e "${EMARK_CONF}" ]; then
  tee -a >${EMARK_CONF} <<EOF

server=1
rpcuser=${EMARK_RPCUSER:-emark}
rpcpassword=${EMARK_RPCPASSWORD}

rpcclienttimeout=${EMARK_RPCCLIENTTIMEOUT:-30}
rpcallowip=${EMARK_RPCALLOWIP:-::/0}
rpcport=${EMARK_RPCPORT:-4444}
rpcbind=${EMARK_RPCBIND:-127.0.0.1}


EOF
echo "Created new configuration at ${EMARK_CONF}"
fi

if [ $# -eq 0 ]; then
  /emark/eMark/src/eMarkd
else
  exec "$@"
fi
