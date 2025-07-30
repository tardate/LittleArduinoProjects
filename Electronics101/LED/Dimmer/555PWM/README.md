# #232 555 PWM LED Dimmer

Test a PWM LED dimmer circuit using a 555 timer.

![The Build](./assets/555PWM_build.jpg?raw=true)

## Notes

This common circuit uses a 555 Timer-based PWM circuit to dim a LED strip.
Similar circuits can be found in many sources, such as:

* [LED Dimmer](https://www.talkingelectronics.com/projects/50%20-%20555%20Circuits/50%20-%20555%20Circuits.html) on Talking Electronics
* [LED Dimmer](https://www.555-timer-circuits.com/led-dimmer.html) on 555 Timer Circuits
* [LED Dimmer Circuit](http://www.reuk.co.uk/wordpress/lighting/led-dimmer-circuit/) - reuk.co.uk
* [PWM LED Dimmer/ Brightness Control by 555 Timer With Video Simulation](http://www.circuitsgallery.com/2013/02/pwm-led-dimmer.html)
* Power FET Lamp Dimmer in the [Engineer's Mini-Notebook 555 Timer IC Circuits](../../../../books/engineers-mini-notebook-555-timer-ic-circuits/)

Steering diodes in the 555 timing circuit allow adjustment of the duty cycle
with little change to the ~1kHz frequency.

The 555 Timer signal is used to switch the LED strip with a low-side n-channel MOSFET.

I'm using a 1m (60 LED) stretch of a 12V LED strip, and the maximum current draw is 133mA.
Since this is quite low power, I'm using a 2N7000 MOSFET which is rated for
200mA continuous/500mA pulsed.

### Performance

At maximum duty cycle (almost 100%), LED current measures 133mA
and the voltage drop over the FET drain-source is 0.71 V.

The minimum duty cycle of ~1.25% does not completely turn off the LEDs.
At this point the LED current measures 3.2mA
and the voltage drop over the FET drain-source is 4.45 V.

![scope_min](./assets/scope_min.gif?raw=true)

At midpoint of the pot, duty cycle is ~50%:

![scope_mid](./assets/scope_mid.gif?raw=true)

### LED Strip Specifications

I'm using this (very) cheap [3014 Led Strip Light](https://www.aliexpress.com/item/5M-60LED-M-Led-Strip-Light-3014-SMD-Fiexble-Light-Non-waterproof-Indoor-Outdoor-Lighting-Holiday/32287328315.html). According to the seller specs:

| Attribute           | Specification                  |
|---------------------|--------------------------------|
| Length              | 5m                             |
| LED Density         | 60 LED/m                       |
| Color               | cold white                     |
| View angle          | 120°                           |
| Working Voltage     | 12V DC                         |
| Power consumption   | 20W, 4W/m, ~67mW/LED           |
| Working Temperature | -40 to 70°                     |
| Luminous Flux       | 880-1080 Lumens/Meter          |
| Size                | L500cm (5M) x W0.5cm x T0.20cm |
| lifespan            | >100,000 hours                 |

## Construction

![Breadboard](./assets/555PWM_bb.jpg?raw=true)

![The Schematic](./assets/555PWM_schematic.jpg?raw=true)

![555PWM_bb_build](./assets/555PWM_bb_build.jpg?raw=true)

## Credits and References

* [LM555 Datasheet](https://www.futurlec.com/Linear/LM555CN.shtml)
* [2N7000 datasheet](https://www.futurlec.com/Transistors/2N7000.shtml)
* Reference Circuits:
    * [LED Dimmer](https://www.talkingelectronics.com/projects/50%20-%20555%20Circuits/50%20-%20555%20Circuits.html) on Talking Electronics
    * [LED Dimmer](https://www.555-timer-circuits.com/led-dimmer.html) on 555 Timer Circuits
    * [LED Dimmer Circuit](http://www.reuk.co.uk/wordpress/lighting/led-dimmer-circuit/) - reuk.co.uk
    * [PWM LED Dimmer/ Brightness Control by 555 Timer With Video Simulation](http://www.circuitsgallery.com/2013/02/pwm-led-dimmer.html)
    * Power FET Lamp Dimmer in the [Engineer's Mini-Notebook 555 Timer IC Circuits](../../../../books/engineers-mini-notebook-555-timer-ic-circuits/)
* [..as mentioned on my blog](https://blog.tardate.com/2017/01/leap232-led-dimmer-pwm.html)
