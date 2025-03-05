#!/usr/bin/env python

import time
import RPi.GPIO as GPIO

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
led1 = 16

try:
  GPIO.setup(led1, GPIO.OUT)
  while True:
    GPIO.output(led1, True)
    time.sleep(0.5)
    GPIO.output(led1, False)
    time.sleep(0.5)
except KeyboardInterrupt:
  pass
finally:
  GPIO.cleanup(led1)
