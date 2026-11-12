#! /usr/bin/env python
import argparse
from re import VERBOSE
import sys
import serial
import time

RESET_DELAY = 0.05 # 50 ms reset delay for WS2812B
verbose = False

def revert_bits(b):
  result = 0
  for i in range(8):
    result <<= 1
    result |= (b & 1)
    b >>= 1
  return result

def convert(color):
  per8 = bytearray(8)
  per8[:] = [0b00100100] * 8  # Default all zero incoming

  for i in range(24):
    bit = (color >> (24 - i)) & 0x01
    idx = i // 3
    off = i % 3

    if bit:
      if off == 0:
        per8[idx] |= 0b10000000
      elif off == 1:
        per8[idx] |= 0b00110000
      elif off == 2:
        per8[idx] |= 0b00000100

  for i in range(8):
    per8[i] = revert_bits(per8[i])

  return bytes(~b & 0xFF for b in per8)

def scan_input_line():
  line = sys.stdin.readline()
  colors = []
  duration_ms = 0

  if line:
    tokens = line.split()
    for i, token in enumerate(tokens):
      if token.strip():
        v = int(token, 16)
        if i == 0:
          duration_ms = (v >> 24) * 10
        colors.append(v & 0x00FFFFFF)

  return colors, duration_ms

def buffer_colors(colors):
  buffer = bytearray()
  for color in colors:
    buffer.extend(convert(color))
  return buffer

def scan_input_lines():
  global verbose

  line_buffers = []
  while True:
    colors, duration_ms = scan_input_line()
    if not colors:
      break

    buffer = buffer_colors(colors)

    if verbose:
      print(f"Read line: {len(colors)} colors, duration: {duration_ms} ms, buffer size: {len(buffer)} bytes")
      print(f"Buffer content: {buffer.hex()}")

    line_buffers.append((buffer, duration_ms))
  return line_buffers

def send_buffers(line_buffers, port, baudrate):
  print(f"Sending buffered data to {port} at {baudrate} baud...")
  ser = serial.Serial(port, baudrate=baudrate, timeout=1)

  for buffer, duration_ms in line_buffers:
    ser.write(buffer)
    ser.flush()
    time.sleep(RESET_DELAY)
    time.sleep(duration_ms / 1000.0)

  ser.close()

def stream_input_lines(port, baudrate):
  global verbose

  print(f"Streaming data to {port} at {baudrate} baud...")
  ser = serial.Serial(port, baudrate=baudrate, timeout=1)

  while True:
    colors, duration_ms = scan_input_line()
    if not colors:
      break

    buffer = buffer_colors(colors)

    if verbose:
      print(f"Read line: {len(colors)} colors, duration: {duration_ms} ms, buffer size: {len(buffer)} bytes")
      print(f"Buffer content: {buffer.hex()}")

    ser.write(buffer)
    ser.flush()
    time.sleep(RESET_DELAY)
    time.sleep(duration_ms / 1000.0)

  ser.close()

def main():
  parser = argparse.ArgumentParser(
    description='WS2812B Control. ' \
      'Reads NUA-format color data from stdin and sends it to a serial device. ' \
      'NUA hex format: [DD]RRGGBB[ RRGGBB[ RRGGBB] ... ] ' \
      'where DD is the duration in 10ms units, and RRGGBB is the color, ' \
      'though some devices read the color as GGRRBB.'
  )
  parser.add_argument('-p', '--port', required=True, help='Serial device name')
  parser.add_argument('-b', '--baudrate', type=int, default=2500000, help='Baud rate for serial communication')
  parser.add_argument('-s', '--stream', action='store_true', default=False, help='Stream each line as received, default is to read all lines before sending')
  parser.add_argument('-v', '--verbose', action='store_true', default=False, help='Enable verbose output')
  args = parser.parse_args()

  global verbose
  verbose = args.verbose

  if args.stream:
    stream_input_lines(args.port, args.baudrate)
  else:
    send_buffers(scan_input_lines(), args.port, args.baudrate)

if __name__ == '__main__':
  main()
