# #010 LightOrNot

Reads a photocell/light-dependent resistor and adjusts the blink rate of an LED accordingly.

![The Build](./assets/LightOrNot_build.jpg?raw=true)


## Notes

The LDR and 10k resistor act as a voltage divider. The sequence and resistor selection depends on the LDR.

I haven't been able to find the specific datasheet for the LDR I am using yet, but it runs to over 10k when dark,
and resistance reduces with more light. Note that some LDRs work the other way around (increase resistance with more light).

So in the circuit used here, the A0 reading measures the voltage drop across the 10k resistor,
so this will approach 1023 in strong light, and approach 0 in darkness. So the faster the LED blinks, the "darker" the measurement.

I could swap the 10k resistor and the LDR to switch the readings scale: i.e. approach 1023 when dark, and approach 0 when light.

![The Breadboard Schematic](./assets/LightOrNot_bb.jpg?raw=true)

## Credits and References

* Based on the [Arduino AnalogInput](http://www.arduino.cc/en/Tutorial/AnalogInput) example
* [Simple Light Reading With LDR + Arduino](http://bildr.org/2012/11/photoresistor-arduino/) project and discussion



