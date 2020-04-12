# #393 DicksonChargePump

Zener-regulated 12V Dickson Charge Pump driven with Arduino PWM.

![Build](./assets/DicksonChargePump_build.jpg?raw=true)

## Notes

The [Dickson Charge Pump](https://en.wikipedia.org/wiki/Voltage_multiplier#Dickson_charge_pump) is a very neat trick for multiplying an input voltage.

It is basically a capacitor bucket-brigade, with diodes for flow control, and a switching signal to make it go.

It is not the most efficient voltage booster, and cannot drive very high currents, but may be a convenient
solution depending on the application.

## Switching Signal

I'm using Timer2 Fast PWM to generate a pair of square-waves on Arduino pins 3 and 11 (OCR2B, OCR2A) at 62kHz.
The duty cycle is set at 50%, and the waves are an inverted pair by setting
OC2A to clear on Compare Match and OC2B to set on Compare Match.

Here's a scope trace of the two waveforms (CH2 is offset -6V for clarity).

![pwm_pump_control](./assets/pwm_pump_control.gif?raw=true)

Since we're using the chip's native PWM capabilities, it is not possible
to change the pins that the PWM signals appear on.

Note: it is possible to use other pins by using one of the other timers.
This sketch uses Timer2 as it is generally available and is not used by other standard libraries.

See [LEAP#254 AvrHardwarePWM](../AvrHardwarePWM) for more details on hardware PWM.

## Zener Regulation

Without the zener diode in place, this 4-stage charge pump delivers about 16V at the output tap.

The 1N4742 has a nominal zener voltage of 12V. An (optional) 2.2kΩ resistor is in series to soak up some of the voltage drop.

I've included a 10kΩ resistor to simulate a load on the 12V supply.

## Performance

Works great:

* very little ripple, < 20mV
* charge pump and load drawing under 2mA
* Arduino, which is also powering the charge pump, is drawing around 20mA total

## Code

The [DicksonChargePump.ino](./DicksonChargePump.ino) sketch is about as simple as it gets:

* sets up PWM
* in the main loop, demonstrates how to turn on and off the PWM outputs by changing the pin mode (5 seconds on, 5 seconds off)


## Construction

The capacitors used here are monolithic ceramics, 220nF for the pump stages and 1µF for the final.
The ones I have are rated for at least 25V.

![Breadboard](./assets/DicksonChargePump_bb.jpg?raw=true)

![Schematic](./assets/DicksonChargePump_schematic.jpg?raw=true)

![Build](./assets/DicksonChargePump_build.jpg?raw=true)

## Credits and References

* [Dickson Charge Pump](https://en.wikipedia.org/wiki/Voltage_multiplier#Dickson_charge_pump) - wikipedia
* [1N4742 datahseet](https://www.futurlec.com/Diodes/1N4742.shtml)
* [12 Volt Arduino-based Charge Pump](https://sites.google.com/site/wayneholder/12-volt-charge-pump) - similar project used as inspiration
* [An Arduino-based programmer for the AT89C2051 chip](http://ceptimus.co.uk/?p=216) - another project example of a charge pump used for VPP generation
* [..as mentioned on my blog](https://blog.tardate.com/2018/06/leap393-dickson-charge-pump.html)
