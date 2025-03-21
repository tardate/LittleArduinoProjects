# #611 Half-Wave Dickson Charge Pump

Zener-regulated 12V Dickson Charge Pump driven with Arduino PWM using a single pin.

![Build](./assets/HalfWave_build.jpg?raw=true)

## Notes

The [Dickson Charge Pump](https://en.wikipedia.org/wiki/Voltage_multiplier#Dickson_charge_pump) is a very neat trick for multiplying an input voltage.

It is basically a capacitor bucket-brigade, with diodes for flow control, and a switching signal to make it go.

It is not the most efficient voltage booster, and cannot drive very high currents, but may be a convenient
solution depending on the application.

I've already covered this in [LEAP#393 Dickson Charge Pump](../../../../playground/DicksonChargePump/).
In that case it used two PWM signals to drive each stage of the charge pump with alternative voltage.

This project demonstrates a modified version that uses only one signal to drive every other stage of the charge pump ladded,
with intermediate stages coupled to ground.

NB: this was suggested by [@steveschnepp](https://github.com/steveschnepp) on [Issue#25](https://github.com/tardate/LittleArduinoProjects/issues/25).
It is also covered in the [wikipedia article](https://en.wikipedia.org/wiki/Voltage_multiplier#Dickson_charge_pump).

## Switching Signal

I'm using Timer2 Fast PWM to generate a square-wave on
Arduino pin 11 (OCR2A) at 62kHz - OC2A to clear on Compare Match and OC2B disconnected.
The duty cycle is set at 50%.

Here's a scope trace of the waveform.

![pwm_pump_control](./assets/pwm_pump_control.gif?raw=true)

Since we're using the chip's native PWM capabilities, it is not possible
to change the pin that the PWM signals appear on.

Note: it is possible to use other pins by using one of the other timers.
This sketch uses Timer2 as it is generally available and is not used by other standard libraries.

See [LEAP#254 AvrHardwarePWM](../../../../playground/AvrHardwarePWM) for more details on hardware PWM.

## Zener Regulation

Without the zener diode in place, this 4-stage charge pump delivers about 14.5V at the output tap.

The 1N4742 has a nominal zener voltage of 12V. An (optional) 2.2kΩ resistor is in series to soak up some of the voltage drop.

I've included a 10kΩ resistor to simulate a load on the 12V supply.

## Performance

Works great:

* very little ripple, < 20mV
* charge pump and load drawing under 2mA
* Arduino, which is also powering the charge pump, is drawing around 20mA total

## Code

The [HalfWave.ino](./HalfWave.ino) sketch is about as simple as it gets:

* sets up PWM
* in the main loop, demonstrates how to turn on and off the PWM outputs by changing the pin mode (5 seconds on, 5 seconds off)

## Construction

![bb](./assets/HalfWave_bb.jpg?raw=true)

![schematic](./assets/HalfWave_schematic.jpg?raw=true)

![bb_build](./assets/HalfWave_build.jpg?raw=true)

## Credits and References

* [Dickson Charge Pump](https://en.wikipedia.org/wiki/Voltage_multiplier#Dickson_charge_pump) - wikipedia
* [1N4742 datasheet](https://www.futurlec.com/Diodes/1N4742.shtml)
* [LEAP#393 Dickson Charge Pump](../../../../playground/DicksonChargePump)
