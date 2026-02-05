#!/usr/bin/env bash

if [[ $# -ne 3 ]]; then
  cat << EOF
Remote IPE programming script
Usage: $0 <hostname> <chip_type> <hex_file>
Example: $0 user@remotehost 12F675 mycode.hex
EOF
  exit 1
fi

REMOTE_HOST="$1"
CHIP_TYPE="$2"
HEX_FILE="$3"
PROGRAMMER="${PROGRAMMER:-PK3}"
IPE_FOLDER="/opt/microchip/mplabx/v6.20/mplab_platform/mplab_ipe/"
IPE_CMD="./ipecmd.sh"

if [[ ! -f "$HEX_FILE" ]]; then
  echo "Error: hex file not found: $HEX_FILE"
  exit 1
fi

HEX_FILENAME=$(basename "$HEX_FILE")

# Copy hex file to remote system
scp "$HEX_FILE" "$REMOTE_HOST":/tmp/"$HEX_FILENAME" || exit 1

# Execute IPE on remote system
ssh "$REMOTE_HOST" "cd ${IPE_FOLDER} && ${IPE_CMD} -P${CHIP_TYPE} -F/tmp/${HEX_FILENAME} -E -M -Y -W4.75 -TP${PROGRAMMER}"
