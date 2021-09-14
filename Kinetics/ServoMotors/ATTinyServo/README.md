# #603 ATTiny Servo Drive

Testing various methods and libraries for driving servo motors with an ATtiny85.

![Build](./assets/ATTinyServo_build.jpg?raw=true)

## Notes

I'd like to use some mini servo motors with an ATtiny85.
The standard Arduino
[Servo library](https://www.arduino.cc/reference/en/libraries/servo/)
doesn't work with the ATtiny, so this project is a survey and test of available techniques.

TBH, I thought this would be an easy proposition, but I ran into trouble with many of the sources I found

## Construction

Here's the basic setup. By default I have the ATtiny85 flashed for 8MHz internal clock,
and I'm using PB4 (pin 3 on the DIP8 ATTiny85) as the servo control pin.

![Breadboard](./assets/ATTinyServo_bb.jpg?raw=true)

![Schematic](./assets/ATTinyServo_schematic.jpg?raw=true)

## SoftwareServo

There are a few versions of the [SoftwareServo](https://github.com/ttseng/SoftwareServo) library floating around the web,
so I cloned the most recent (as none are setup to be imported as a module).

This is the most bare-bones approach - it doesn't modify timers or PWM, but just requires a callback that uses the
current Timer0 count to figure out what to do next with the servo.

Aside from needing to ensure the refresh callback is made, this library is a win - simple and it works.

See [UsingSoftwareServo.ino](./UsingSoftwareServo/UsingSoftwareServo.ino) for the sketch I used for testing.

Here's a quick demo..

[![clip](https://img.youtube.com/vi/Q-Hs6pHNgcE/0.jpg)](https://www.youtube.com/watch?v=Q-Hs6pHNgcE)

## PrecisionServo

The [PrecisionServo](https://github.com/ElizabethTeaches/PrecisionServo) library promises more bells an whistles.
I had to clone the library as it was not setup to be imported as a module.


There seems to be a baked-in timing assumption somewhere (I haven't found yet), as it doesn't work properly when
the ATtiny85 is set to run at 8MHz internal clock.

When I reduce the ATtiny to 1MHz internal clock, it works fine.

See [UsingPrecisionServo.ino](./UsingPrecisionServo/UsingPrecisionServo.ino) for the sketch I used for testing.

## Servo8Bit

The [Servo8Bit](https://github.com/fri000/Servo8Bit) library is specifically designed to work with 8-bit timers (e.g ATTiny),
using timer interrupts to avoid needing callbacks.

But - it doesn't work. The code looks like it is doing all the right things, but I've yet to discover what is going wrong.

I am little suspicious - the "examples" shown on the web have the servo plugged into PB1.
When I initialise the Servo8Bit, I see what I think is the OC1A counter output on PB1, but no output changes on the servo pin I have configured.
It looks like the library is not initializing the timer register correctly, but I haven't gone any further than that.

See [UsingServo8Bit.ino](./UsingServo8Bit/UsingServo8Bit.ino) for the sketch I used for testing.

## Credits and References

* [ATTINY HACKS: ATTINY45/85 SERVO LIBRARY](https://hackaday.com/2011/09/25/attiny-hacks-attiny4585-servo-library/)
* [Servo8Bit](https://github.com/fri000/Servo8Bit) - servo control with 8-bit timers (e.g ATTiny)
* [PrecisionServo](https://github.com/ElizabethTeaches/PrecisionServo)
* [SoftwareServo](https://github.com/ttseng/SoftwareServo)
