# #127 SleepMode

Test sleep mode with an ATtiny85 processor on a breadboard.

Here's a quick video of the circuit in action:

[![SleepMode](https://img.youtube.com/vi/WhtLly1BM0U/0.jpg)](https://www.youtube.com/watch?v=WhtLly1BM0U)

## Notes

This is a little test of sleep mode with an ATtiny85 microcontroller (8-pin DIP).

I'm using an Arduino Uno as an in-system programmer, using the technique described in the [ProgrammingWithArduinoISP](../ProgrammingWithArduinoISP) project.

Once the ATtiny is programmed, the Arduino Uno ISP is detached, and it will run independently.
The ATtiny85 requires 1.8-5.5V to operate. I successfully tested with 3.3V and 5V supplies.

A push-button is attached to normally pull D2 high (pin 7 of the chip)
and a hardware interrupt service routine activates on LOW signal.
The interrupt acts as a "wake-up" call to the CPU.

The standard `loop` simply runs an LED sequence (for demo purposes) and then sends the processor to sleep.

The AVR library `set_sleep_mode` function and `sleep_mode` macro are use to put the processor to sleep.

Using `SLEEP_MODE_PWR_DOWN` .. apparently the most power-efficient, I measure power consumption falling to about 238µA at 3.3V
when asleep. Not bad, but definitly not as low as you'd like for long periods of inactivity.

Lately I've been reading Sparkfun's [Adventures in Low Power Land](https://www.sparkfun.com/tutorials/309),
with some excellent coverage of how to get power consumption down to 1µA!
The main extra change is to disable brownout detection, which requires a change to the chip fuses. A test for another day!

## Construction

![Breadboard](./assets/SleepMode_bb.jpg?raw=true)

![The Schematic](./assets/SleepMode_schematic.jpg?raw=true)

![The Build](./assets/SleepMode_build.jpg?raw=true)

## Credits and References
* [ATtiny85 datasheet](http://www.atmel.com/devices/ATTINY85.aspx)
* [ArduinoSleepCode](http://playground.arduino.cc/Learning/ArduinoSleepCode)
* [<avr/sleep.h>: Power Management and Sleep Modes](http://www.nongnu.org/avr-libc/user-manual/group__avr__sleep.html)
* [Adventures in Low Power Land](https://www.sparkfun.com/tutorials/309) - excellent sparkfun tutorial
