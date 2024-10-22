# #528 ATtiny IxpandO

Using an ATtiny85 to drive the Boldport IxpandO MCP23017-based I²C IO expansion board.

![Build](./assets/ATtinyController_build.jpg?raw=true)

## Notes

I like Arduino - mainly because it is always surprising to find how much can be done with such a constrained microprocessor.
But sometimes even an ATmega328 is overkill, in which case it is fun to try and squeeze a project into an ATtiny instead.

One of the challenges with the ATtiny is that the [Arduino Wire library](https://www.arduino.cc/en/reference/wire)
is not supported, so there's no direct support for I²C.

A leading alternative is the Adafruit [TinyWireM](https://github.com/adafruit/TinyWireM) I²C for the ATtiny,
so I wanted to test it out. The library already comes with examples for how to use it with temperature sensors, LCDs and RTCs,
so I though I'd try something different - the MCP23017 port expander, which could be a useful tool in
cases where the ATtiny has all the processing power and memory required, but it just needs more I/O.

To test this, I'm using the
[Boldport IxpandO](../) - an input/output expansion board based on Microchip's MCP23017 (BoldportClub Project #16).

## Code Modifications

I'm using the [ATtinyController.ino](./ATtinyController.ino?raw=true) sketch for the demo, which is a modified version
of the demo sketch I used with an Arduino when I first built the [Boldport IxpandO](../).

Key modifications:

* a different library name, although I've obfusticated this with a `#define Wire TinyWireM`
* the extended form of `requestFrom` is not supported, so `readRegister` needed to be re-written with more fundamental commands.
* the hardware I²C SDA pin is shared with INT0, so I couldn't directly use the MCP23017 interrupt. While I think I could switch to pin change interrupts, for now I've just replaced the interrupt-driven input with polling

## Construction

It's pretty simple! On the ATtiny85 PDIP/SOIC/TSSOP package, hardware I²C is enabled on pins 5 and 7:

| Pin | Function | Other functions                    |
|-----|----------|------------------------------------|
| 5   | SDA      | USCK/SCL/ADC1/T0/INT0/PCINT2       |
| 7   | SCK      | MOSI/DI/AIN0/OC0A/OC1A/AREF/PCINT0 |

I programmed the ATtiny85 with my DiY programmer shield for an Arduino Uno running the Arduino ISP sketch.
Because of the use of pins 5 and 7 during programming, it means the ATtiny can't run the sketch successfully
while still on the programming board.

![Breadboard](./assets/ATtinyController_bb.jpg?raw=true)

![Schematic](./assets/ATtinyController_schematic.jpg?raw=true)

Testing things out on a breadboard:

![ATtinyController_bb_build](./assets/ATtinyController_bb_build.jpg?raw=true)

## Building an Adapter Board

To clean things up a bit, I made a small mounting board for the ATtiny in a DIP8 adapter,
with a micro USB adapter for 5V supply.
The 8-pin header allows the IxpandO to be connected with press fit.

![adapter_board](./assets/adapter_board.jpg?raw=true)

![Build](./assets/ATtinyController_build.jpg?raw=true)

## Credits and References

* [Atmel ATtiny85 Product Info](http://www.atmel.com/devices/ATTINY85.aspx)
* [Arduino Wire library](https://www.arduino.cc/en/reference/wire)
* [Adafruit-TinyWireM](https://github.com/adafruit/TinyWireM) - I²C for the ATtiny
