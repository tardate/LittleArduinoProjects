# #423 MakerUno

Checking out the Maker UNO, a feature-packed Arduino-compatible board from Cytron in Penang, Malaysia.

![Build](./assets/MakerUno_build.jpg?raw=true)

Here's a quick video of the board in action:

[![clip](http://img.youtube.com/vi/YXwNq41K2Ik/0.jpg)](http://www.youtube.com/watch?v=YXwNq41K2Ik)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)


## Notes

I was recently shown an Arduino-compatible board made by Cytron in Penang, Malaysia
called the [Maker UNO](https://www.cytron.io/p-maker-uno?search=maker%20uno&description=1).
I gather it began life as a
[very successful kickstarter](https://www.kickstarter.com/projects/1685732347/6-maker-uno-simplifying-arduino-for-education)
that aimed to produce a better board and associated teaching materials for K-12 education.

It packs quite a few additional features in the Uno form-factor:

* LEDs on all digital pins
* a piezo buzzer on pin 8
* a push-button on pin 2

It uses the CH340G USB-UART chip for USB connectivity, so additional drivers may be required.
See [LEAP#405 ATmegaSerialProgrammer](../ATmegaSerialProgrammer) for a deeper dive on the CH340G.

And a really nice feature is the price - currently listing for
RM15 ([~$3.60 USD](https://www.google.com/search?q=myr+15+in+usd)).

It also looks pretty spiffy to boot:

![kit_front](./assets/kit_front.jpg?raw=true)

![kit_rear](./assets/kit_rear.jpg?raw=true)


## Construction

The full schematic is available from Cytron:

[![MakerUno_schematic](./assets/MakerUno_schematic.jpg?raw=true)](https://cdn.cytron.io/makeruno/MAKER-UNO.pdf)

Here's a re-drawing that focuses on the details of the digital pin features.
In particular, note:

* LEDs are indirectly driven with low-side n-channel MOSFETs
    - presents a high impedance to the pin, so its normal function is largely unaffected
    - a high-value (3.3MΩ) pull-down resistor ensures the gate doesn't float
* The piezo buzzer on pin 8:
    - connected in addition to the LED
    - switched with an NPN and 1kΩ base resistor
    - has a manual SPDT switch that can be used to disable the buzzer
* Push-button on pin 2:
    - with resistor that pulls the pin low when the button is pressed
    - should be used with `INPUT_PULLUP` pin mode
    - pin 2 supports hardware interrupts, so allows interrupt-driven coding rather than polling of the button state
    - connected in addition to the LED (the LED will normally be on, and go off when the button is pressed)

![MakerUno_partial_schematic](./assets/MakerUno_partial_schematic.jpg?raw=true)


## Code Demonstration

The [MakerUno.ino](./MakerUno.ino) sketch is a simple demonstration of the features, requiring no additional components:

* steps through the digital pins (except 2 and 8), lighting the LED
* plays a tone proportional to the pin number
* on a falling interrupt from a button press, reverses the order that it is cycling through the pins/tones

## Credits and References
* [Maker Uno](https://www.cytron.io/p-maker-uno?search=maker%20uno&description=1) - Cytron listing
* [Cytron](https://www.cytron.io/about-us)
* [..as mentioned on my blog](https://blog.tardate.com/2018/10/leap423-the-maker-uno.html)
