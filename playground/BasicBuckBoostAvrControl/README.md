# BasicBuckBoostAvrControl

Build and test an inverting buck-boost converter controlled by an ATtiny85.

![Build](./assets/BasicBuckBoostAvrControl_build.jpg?raw=true)

## Notes

I've based this on the [DIY Buck/Boost Converter](https://www.youtube.com/watch?v=ZiD_X-uo_TQ) video by GreatScott!

An overview of the circuit:

* basic inverting Buck-Boost configuration (inductor-diode-capacitor)
* n-channel MOSFET low-side switching
* ATtiny85 controls the MOSFET with PWM output proportional to the actual/desired output differential
* rail-to-rail OpAmp provides actual voltage feedback, scaled to 0-5V for the ATtiny
* L7805 taps a 5V supply for the ATtiny and OpAmp


### Performance Analysis

Settings (buck mode):

* Vout = -9V
* Vin = 12V
* fs = 3.947 kHz
* Rload = 10kΩ

#### Theoretical Performance - Buck Mode

Required duty cycle:
```
D = Vout/(Vout - Vin) = [42.86%](http://www.wolframalpha.com/input/?i=9V%2F(12V+-+-9V))
```

Output ripple voltage:
```
Ia = Vout/Rload = [0.9mA](http://www.wolframalpha.com/input/?i=9V%2F10k%CE%A9)
∆Vc = Ia * D / (fs * C) = [0.4 mV](http://www.wolframalpha.com/input/?i=0.9mA+*+0.4286+%2F+(3.947kHz+*+220%C2%B5F))
```

Average input current:
```
Is = Ia * D / (1 - D) = [0.68mA](http://www.wolframalpha.com/input/?i=0.9mA+*+0.4286+%2F+(1+-+0.4286))
```

Average inductor current:
```
Il = Ia / (1 - D) = [1.58mA](http://www.wolframalpha.com/input/?i=0.9mA+*+0.4286+%2F+(1+-+0.4286))
```

Inductor peak-peak ripple current:
```
∆Ii = Vin * D / (fs * L) = [3.949A](http://www.wolframalpha.com/input/?i=12V+*+0.4286+%2F+(3.947+kHz+*+330%C2%B5H))
```

#### Actual Performance



### PWM Control

The [BasicBuckBoostAvrControl.ino](./BasicBuckBoostAvrControl.ino) sketch
is based on on original script from [instructables](http://www.instructables.com/id/DIY-BuckBoost-Converter-Flyback/?ALLSTEPS).

The original sketch uses 8-bit Timer/Counter0 Fast PWM with no clock prescaling (CS=0b001).
Using default internal clock of 1MHz, this generates a PWM signal on PB1 (pin 6) of
[3.906 kHz](http://www.wolframalpha.com/input/?i=1MHz%2F1%2F256) [measured: 3.947 kHz].

It uses [analogWrite](https://www.arduino.cc/en/Reference/analogWrite) to adjust the duty cycle:

* value: the duty cycle: between 0 (always off) and 255 (always on), but is limited in code to a maximum of 203 max (~80% duty cycle).
* note that analogWrite resets timer COM settings, so much of the setup in the original sketch is redundant

Here's a scope trace of the PWM signal in action (CH1 - yellow). CH2 (blue) is the VSET input.

![scope_original_pwm](./assets/scope_original_pwm.gif?raw=true)


## Construction

![Breadboard](./assets/BasicBuckBoostAvrControl_bb.jpg?raw=true)

![Schematic](./assets/BasicBuckBoostAvrControl_schematic.jpg?raw=true)

![Build](./assets/BasicBuckBoostAvrControl_build.jpg?raw=true)

## Credits and References
* [DIY Buck/Boost Converter (Flyback) || How to step up/down DC voltage efficiently](https://www.youtube.com/watch?v=ZiD_X-uo_TQ) - video by GreatScott!
* [DIY Buck/Boost Converter](http://www.instructables.com/id/DIY-BuckBoost-Converter-Flyback/?ALLSTEPS) - instructables
* [Buck–boost converter](https://en.wikipedia.org/wiki/Buck%E2%80%93boost_converter) - wikipedia
* [Power-Switching Converters](https://www.goodreads.com/book/show/1908950.Power_Switching_Converters) - Simon Ang, Alejandro Oliva
* [IRF3205 datasheet](http://parts.io/detail/215337130/IRF3205PBF) - parts.io
* [LMC6482 datasheet](http://parts.io/detail/11889183/LMC6482AIMX%2FNOPB) - parts.io
* [ATTINY85 datasheet](http://parts.io/detail/1452093/ATTINY85-20PU) - parts.io
* [L7805 datasheet](http://parts.io/detail/6811412/L7805) - parts.io
