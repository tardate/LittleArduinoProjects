# #009 Blink

The most basic LED blinking circuit.


[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

There's not much to note in this circuit other than it is a good test that everything is working OK.
Pin 13 has an LED connected on most Arduino boards, so the off-board LED is optional.

I thought I'd measure the electritcal characteristics with various resistors and a Red LED.
My Arduino is supplying 4.98V on the digital GPIO pin when taken high and measured without load.
Here are the figures under load:

| R1nom   | R1act   | Vr     | Vl     | V      | mA    |
| -------:| -------:| ------:| ------:| ------:| -----:|
| 220R    | 218R    | 2.69   | 1.95   | 4.65   | 11.5  |
| 1kR     | 989R    | 3.04   | 1.85   | 4.90   | 3.0   |
| 10kR    | 9.86kR  | 3.22   | 1.73   | 4.96   | 0.32  |

* Vr = voltage drop over resistor
* Vl = voltage drop over LED
* V  = voltage drop over resistor + LED
* mA = current

It seems the current is a little lower than [theoretical](http://www.ohmslawcalculator.com/led_resistor_calculator.php)
I guess that's the accuracy and the affect of my multimeter on the circuit when doing the current measurement.

## Construction

![The Breadboard](./assets/Blink_bb.jpg?raw=true)

![The Schematic](./assets/Blink_schematic.jpg?raw=true)

![The Build](./assets/Blink_build.jpg?raw=true)

## Credits and references
* [Arduino Blink tutorial](http://www.arduino.cc/en/Tutorial/Blink)

