# ATtinySleep

Test sleep mode with an ATtiny85 processor on a breadboard.

Here's a quick video of the circuit in action:

[![ATtinySleep](http://img.youtube.com/vi/WhtLly1BM0U/0.jpg)](http://www.youtube.com/watch?v=WhtLly1BM0U)

## Notes

This is a little test of sleep mode with an ATtiny85 microcontroller (8-pin DIP).

I'm using an Arduino Uno as an in-system programmer, using teh technique described in the [ATtinyWithArduinoISP](../ATtinyWithArduinoISP) project.

Once the ATtiny is programmed, the Arduino Uno ISP is detached, and it will run independently.
The ATtiny85 requires 1.8-5.5V to operate. I successfully tested with 3.3V and 5V supplies.

A push-button is attached to normally pull D2 high (pin 7 of the chip)
and a hardware interrupt service routine activates on LOW signal.
The interrupt acts as a "wake-up" call to the CPU.

The standard `loop` simply runs an LED sequence (for demo purposes) and then sends the processor to sleep.

The AVR library `set_sleep_mode` function and `sleep_mode` macro are use to put the processor to sleep.

Using `SLEEP_MODE_PWR_DOWN` .. apparently the most power-efficient, I measure power consumption falling to about 238µA at 3.3V
when asleep. Not bad, but definitly not as low as you'd like for long periods of inactivity.

## Construction

![Breadboard](./assets/ATtinySleep_bb.jpg?raw=true)

![The Schematic](./assets/ATtinySleep_schematic.jpg?raw=true)

![The Build](./assets/ATtinySleep_build.jpg?raw=true)

## Credits and References
* [ATtiny85 datasheet](http://www.atmel.com/devices/ATTINY85.aspx)
* [ArduinoSleepCode](http://playground.arduino.cc/Learning/ArduinoSleepCode)
* [<avr/sleep.h>: Power Management and Sleep Modes](http://www.nongnu.org/avr-libc/user-manual/group__avr__sleep.html)
