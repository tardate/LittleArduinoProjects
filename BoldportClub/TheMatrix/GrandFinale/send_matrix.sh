#!/usr/bin/env bash
#
# send-matrix.sh  –  Send an array of fireworks commands to Arduino USB‑serial device on macOS.
#
# Usage:
#   ./send-matrix.sh /dev/cu.wchusbserial2430 "[[10,5,4],[10,5,3]]"
#

DEVICE="$1"
FIREWORKS="$2"
BAUDRATE="9600"

# Note: the baud rate must match the one set in the Arduino sketch.
# 9600 is the most reliable baud rate for USB-serial communication.
# I initially used 115200, but this proved quite unreliable.

# ---- configure the serial port ---------------------------------------------
# 8 data bits, 1 stop bit, no parity (the Arduino / microcontroller default)
echo "Configuring serial port ${DEVICE} at ${BAUDRATE} bps..."
stty -f "$DEVICE" "$BAUDRATE" cs8 -cstopb -parenb raw

# ---- wait for the device to be ready ---------------------------------------
sleep 2

# ---- send the payload -------------------------------------------------------
# printf sends the string *without* automatically appending a newline.
# Add '\r' (carriage return) or '\n' if your device expects it.
printf "${FIREWORKS}\n" > "$DEVICE"

echo "Sent ${FIREWORKS} to ${DEVICE}."
