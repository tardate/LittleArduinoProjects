#!/usr/bin/env python

import serial
import time
from typing import Optional, Tuple
import argparse
import sys

class XL4015Monitor:
  """
  XL4015 Power Supply Serial Monitor.

  Request frame:
    0xBB 0xCC ADDR CMD XX XX CRC
  Response frame:
    0xBB 0xCC ADDR CMD LSB MSB

  Where:
    * 0xBB 0xCC is the frame header (2 bytes)
    * ADDR is the module address (1 byte)
    * CMD=00 is the current reading command (1 byte)
    * CMD=01 is the command to read voltage (1 byte)
    * XX XX arbitrary value (2 bytes)
    * CRC Check (1 byte)
    * LSB,MSB: 2-byte reading value

  - Baud: 9600 (default)
  - Two CRC strategies supported: additive (sum & 0xFF) and CRC-8 (poly 0x07).
  - There is no CRC on the response, and the request CRC appears to be ignored by the device.
  """

  FRAME_LEN = 6
  CMD_CURRENT = 0x00
  CMD_VOLTAGE = 0x01
  HEADER = (0xBB, 0xCC)

  def __init__(self, port: str, baud: int = 9600, timeout: float = 1.0, debug: bool = False):
    self.port = port
    self.baud = baud
    self.timeout = timeout
    self.debug = debug
    self.ser: Optional[serial.Serial] = None

  def open(self):
    if self.ser and self.ser.is_open:
      return
    self.ser = serial.Serial(self.port, baudrate=self.baud, timeout=self.timeout)

  def close(self):
    if self.ser:
      try:
        self.ser.close()
      finally:
        self.ser = None

  @staticmethod
  def _crc_additive(buf: bytes) -> int:
    return sum(buf) & 0xFF

  @staticmethod
  def _crc8_poly07(buf: bytes) -> int:
    """CRC-8 (poly 0x07), init 0x00, no reflect."""
    crc = 0x00
    for b in buf:
      crc ^= b
      for _ in range(8):
        if crc & 0x80:
          crc = ((crc << 1) ^ 0x07) & 0xFF
        else:
          crc = (crc << 1) & 0xFF
    return crc

  def _build_frame(self, addr: int, cmd: int) -> bytes:
    body = bytes([self.HEADER[0], self.HEADER[1], addr & 0xFF, cmd & 0xFF, 0x00, 0x00])
    crc = self._crc_additive(body)
    return body + bytes([crc])

  def _read_exact(self, n: int) -> bytes:
    """Read exactly n bytes or raise TimeoutError"""
    assert self.ser is not None
    buf = bytearray()
    deadline = time.time() + self.timeout
    while len(buf) < n:
      remaining = deadline - time.time()
      if remaining <= 0:
        break
      chunk = self.ser.read(n - len(buf))
      if not chunk:
        continue
      buf.extend(chunk)
    if len(buf) < n:
      raise TimeoutError(f"Timeout reading {n} bytes (got {len(buf)})")
    return bytes(buf)

  def _sync_and_read_frame(self) -> bytes:
    """
    Read from serial until a valid header is found, then read remaining bytes to make a full frame.
    Raises TimeoutError on timeout.
    """
    assert self.ser is not None
    deadline = time.time() + self.timeout
    while True:
      if time.time() > deadline:
        raise TimeoutError("Timeout waiting for frame header")
      b = self.ser.read(1)
      if not b:
        continue
      if b[0] != self.HEADER[0]:
        continue
      second = self.ser.read(1)
      if not second:
        continue
      if second[0] != self.HEADER[1]:
        continue
      rest = self._read_exact(self.FRAME_LEN - 2)
      return bytes([self.HEADER[0], self.HEADER[1]]) + rest

  def _verify_crc(self, frame: bytes) -> bool:
    """Verify the CRC of a frame, trying all supported methods. Returns True if valid."""
    if len(frame) != self.FRAME_LEN:
      return False
    body = frame[:-1]
    crc_byte = frame[-1]
    if self._crc_additive(body) == crc_byte:
      return True
    if self._crc8_poly07(body) == crc_byte:
      return True
    return False

  def _debug_print_frame(self, name: str, frame: bytes):
    if self.debug:
      frame_hex = " ".join(f"{b:02X}" for b in frame)
      print(f"{name}: {frame_hex}")

  def _parse_frame(self, frame: bytes) -> dict:
    self._debug_print_frame("Received Frame", frame)
    if len(frame) != self.FRAME_LEN:
      raise ValueError("Frame wrong length")
    addr = frame[2]
    cmd = frame[3]
    val = (frame[5] << 8) | frame[4]
    return {"addr": addr, "cmd": cmd, "raw": val}

  def send_and_receive(self, addr: int, cmd: int, timeout: Optional[float] = None) -> dict:
    """
    Send a command frame and wait for a response frame. Returns parsed frame dict.
    Raises TimeoutError on serial timeout.
    """
    if self.ser is None or not self.ser.is_open:
      self.open()
    if timeout is not None:
      original_timeout = self.ser.timeout
      self.ser.timeout = timeout
    try:
      frame_out = self._build_frame(addr, cmd)
      self._debug_print_frame("Sent Frame", frame_out)
      self.ser.reset_input_buffer()
      self.ser.write(frame_out)
      self.ser.flush()
      frame_in = self._sync_and_read_frame()
      parsed = self._parse_frame(frame_in)
      return parsed
    finally:
      if timeout is not None:
        self.ser.timeout = original_timeout

  def read_current(self, addr: int) -> float:
    """
    Read current from module at address. Returns Amps.
    """
    scale = 0.001
    parsed = self.send_and_receive(addr, self.CMD_CURRENT)
    return parsed["raw"] * scale

  def read_voltage(self, addr: int) -> float:
    """
    Read voltage from module at address. Returns Volts.
    """
    scale = 0.001
    parsed = self.send_and_receive(addr, self.CMD_VOLTAGE)
    return parsed["raw"] * scale


if __name__ == "__main__":
  parser = argparse.ArgumentParser(description="XL4015 monitor")
  parser.add_argument("-p", "--port", help="serial port (e.g. /dev/ttyUSB0)")
  parser.add_argument("-a", "--address", type=int, default=0x00, help="module address")
  parser.add_argument("-b", "--baud", type=int, default=9600, help="baud rate")
  parser.add_argument("-t", "--timeout", type=float, default=1.0, help="serial timeout (s)")
  parser.add_argument("-d", "--debug", action="store_true", help="enable debug output")
  args = parser.parse_args()

  if not args.port:
    parser.print_help()
    sys.exit(1)

  try:
    m = XL4015Monitor(port=args.port, baud=args.baud, timeout=args.timeout, debug=args.debug)
    try:
      m.open()
      try:
        amps = m.read_current(addr=args.address)
      except Exception as e:
        print("Current read error:", e)
      try:
        volts = m.read_voltage(addr=args.address)
      except Exception as e:
        print("Voltage read error:", e)
      print(f"Voltage: {volts:.3f} V, Current: {amps:.3f} A")
    finally:
      m.close()
  except KeyboardInterrupt:
    pass
