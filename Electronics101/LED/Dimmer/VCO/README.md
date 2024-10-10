# #632 Voltage Controlled LED Dimmer

Demonstrating a voltage-controlled LED current source with a triangle wave generator.

![Build](./assets/VCO_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/feXL85_2WCg/0.jpg)](https://www.youtube.com/watch?v=feXL85_2WCg)

## Notes

The brightness of an LED is proportional to the current, not the voltage.

Adjusting LED brightness is best achieved by controlling the current.
PWM techniques "trick" the eye into seeing different levels of brightness by rapidly switching the LED on and off.

The circuit presented here demonstrates an FET current-mirror with current determined by input voltage.
For demonstration purposes, it uses an Op-amp triangle wave generator as a source.

The circuit is similar to the Arduino-controlled [LEAP#608 LED Current Control](../../../../playground/LedCurrentControl)

### Circuit Design

![bb](./assets/VCO_bb.jpg?raw=true)

![schematic](./assets/VCO_schematic.jpg?raw=true)

### Oscillator

Uses two op-amp units:

* first configured as a Square Wave Generator
    * operating at [3.279 Hz](https://www.wolframalpha.com/input?i=1%2F%282+*+ln%282%29+*+22k%CE%A9+*+10%C2%B5F%29)
* with the output fed into a second unit configured as an integrating amplifier, resulting in a triangle wave

![scope](./assets/scope.gif?raw=true)

### Current Mirror

The basic current mirror provides a 1:1 current source.
Dissimilar resistors in the tail of the input/output current source set up proportional current control.
Essential current is proportional to the input/out source resistor values.

I've tested an output source resistor of 46Ω with input source resistors of both 4.7kΩ and 47kΩ. Results are tabulated below.

4.7kΩ : 47Ω

| V(cl)  | I(cl)     | V(rl) | I(rl)     |
|--------|-----------|-------|-----------|
| 200mV  | [0.043mA](https://www.wolframalpha.com/input?i=0.20V%2F4.7k%CE%A9) | 64mV   | [1.36mA](https://www.wolframalpha.com/input?i=0.064V%2F47%CE%A9) |
| 400mV  | [0.085mA](https://www.wolframalpha.com/input?i=0.40V%2F4.7k%CE%A9) | 176mV  | [3.745mA](https://www.wolframalpha.com/input?i=0.176V%2F47%CE%A9) |
| 600mV  | [0.128mA](https://www.wolframalpha.com/input?i=0.60V%2F4.7k%CE%A9) | 328mV  | [6.979mA](https://www.wolframalpha.com/input?i=0.328V%2F47%CE%A9) |
| 800mV  | [0.170mA](https://www.wolframalpha.com/input?i=0.80V%2F4.7k%CE%A9) | 500mV  | [10.600mA](https://www.wolframalpha.com/input?i=0.500V%2F47%CE%A9) |
|

47kΩ : 47Ω

| 200mV  | [0.004mA](https://www.wolframalpha.com/input?i=0.200V%2F47k%CE%A9) | 40mV  | [0.851mA](https://www.wolframalpha.com/input?i=0.040V%2F47%CE%A9) |
| 400mV  | [0.009mA](https://www.wolframalpha.com/input?i=0.400V%2F47k%CE%A9) | 104mV  | [2.213mA](https://www.wolframalpha.com/input?i=0.104V%2F47%CE%A9) |
| 600mV  | [0.013mA](https://www.wolframalpha.com/input?i=0.600V%2F47k%CE%A9) | 232mV  | [4.936mA](https://www.wolframalpha.com/input?i=0.232V%2F47%CE%A9) |
| 800mV  | [0.017mA](https://www.wolframalpha.com/input?i=0.800V%2F47k%CE%A9) | 384mV  | [8.170mA](https://www.wolframalpha.com/input?i=0.384V%2F47%CE%A9) |

## Credits and References

* [100pcs=5colors x 20pcs 5050 LED Diode Assortment SMD LED Diode Kit Green/ RED / White / Blue / Yellow](https://www.aliexpress.com/item/32995153991.html)
* [LM358N Datasheet](https://www.futurlec.com/Linear/LM358N.shtml)
* [LEAP#608 LED Current Control](../../../../playground/LedCurrentControl)
* [Op-amp Astables](https://learnabout-electronics.org/Oscillators/osc42.php)
* [Op-amp Integrator](https://www.electronics-tutorials.ws/opamp/opamp_6.html)
