# #586 Mini Linear Servos

Testing some mini/micro linear servo motors with an ATtiny85.

![Build](./assets/MiniLinearServos_build.jpg?raw=true)

## Notes

Most common servos are of the rotary kind.
Linear servos are a little more rare and tend to be a bit more expensive but they do have some advantages,
such as generally more compact design.

In this project note, I'll be putting a few mini/micro linear servos through some basic tests.

## Construction

Here's the basic setup. By default I have the ATtiny85 flashed for 8MHz internal clock,
and I'm using PB4 (pin 3 on the DIP8 ATTiny85) as the servo control pin.


![Breadboard](./assets/MiniLinearServos_bb.jpg?raw=true)

![Schematic](./assets/MiniLinearServos_schematic.jpg?raw=true)

## Test Sketch

See [MiniLinearServos.ino](./MiniLinearServos.ino) for the test sketch.
It uses the [SoftwareServo](https://github.com/ttseng/SoftwareServo) library.
These servos can easily be used from as Arduino by switching to the
standard Arduino
[Servo library](https://www.arduino.cc/reference/en/libraries/servo/).


## 1.5g Micro Linear Servo GS-1502

These GS-1502 servos were from a [seller on shopee.sg](https://shopee.sg/2x-1.5g-Digital-Ultra-Micro-Linear-Servo-V-Tail-Function-GS-1502-Left-Right-i.70675888.1608865461), and come in a matched left/right handed pair.

![gs1502](./assets/gs1502.jpg?raw=true)

| Item        | Specifications               |
|-------------|------------------------------|
| Weight      | 1.8g(include connector wire) |
| Speed       | 0.11 sec @3.7v               |
| Torque      | 29.5g of force               |
| Rotation    | maximum 180°                 |
| Voltage     | 3.7V-5V                      |
| Gear        | Nylon                        |
| Dimensions  | 21 x 15 x 12mm (L*W*H)       |
| Tye         | digital.                     |
| Application | Ultra Micro aircraft         |

This serve works very well. I had to adjust the minimum pulse width to 832µs
with the command `myServo.setMinimumPulse(832);` to allow a full range potisioning from 0˚ to 180˚.

With the 540µs default setting, the servo would automatically return to "home" (180˚)
whenever positioned below 27˚.

Here's a quick demo..

[![clip](https://img.youtube.com/vi/RXflNAJlG2s/0.jpg)](https://www.youtube.com/watch?v=RXflNAJlG2s)

## Credits and References

* [SoftwareServo](https://github.com/ttseng/SoftwareServo) library
* [1.5g Micro Linear Servo GS-1502](https://shopee.sg/2x-1.5g-Digital-Ultra-Micro-Linear-Servo-V-Tail-Function-GS-1502-Left-Right-i.70675888.1608865461)
