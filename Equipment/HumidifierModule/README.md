# #608 USB Humidifier Module

Testing a cheap USB/5V powered humidifier module the produces prodigious volumes of mist!

![Build](./assets/HumidifierModule_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/2LCTg96Ospw/0.jpg)](https://www.youtube.com/watch?v=2LCTg96Ospw)

## Notes

I've been seeing these cheap humidifier/atomiser modules for some time - for example
[this USB powered device from an aliexpress seller](https://www.aliexpress.com/item/1005002496630103.html).
Of course i needed to get one to see if they are any good - oh, yes, they are amazing!

### Module Details

The module I purchased came with:

* the controller board with micro USB power connector
* the piezo transducer element on a plugged wire connector
* a 10cm length of the absorbent micro-mesh needed to suck the water through for atomisation

![kit_parts](./assets/kit_parts.jpg?raw=true)

The board has all the smarts in a 6-pin microprocessor of some sort (I haven't identified it - no markings),
with supporting circuits for

* push-button input
* LED indicator
* output control FET driver

I haven't measured these to verify, but product details indicate:

* 300mA at 5V
* 110kHz piezo frequency

![kit_board](./assets/kit_board.jpg?raw=true)

### Module Operation

When connected to power, the module is in the "off" state. The push-botton cycles between three modes:

* off (LED off)
* continuously on (LED on)
* intermittent; cycles between on and off every few minutes (LED blinking)

### Demonstration

I was honestly shocked at the volume of vapour the module produces when I first turned it on.

![demo1](./assets/demo1.jpg?raw=true)

Essential for operation is to use the absorbent micro-mesh to conduct water from source to the atomiser.
In this demo I just used a small piece to let the atomiser such water from a sponge in my soldering iron stand.

Just placing the atomiser directly on the sponge does not work.

![demo2](./assets/demo2.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/2LCTg96Ospw/0.jpg)](https://www.youtube.com/watch?v=2LCTg96Ospw)

### Next Steps

This is a great module for building a DIY humidifier. I think that'll be in my near future.

The fact that it is 5V means that a DIY humidifier can be made in a way that is isolated from any mains or dangerous voltages.

Since the module control is via a pushbutton input, it is also trivial to provide alternative control input for example by IR remote
or some other microcontroller-controlled logic.

## Credits and References

* [USB Mini Humidifier DIY Kits Mist Maker and Driver Circuit Board Fogger Atomization Film Atomizer Sheet Mini Oscillating](https://www.aliexpress.com/item/1005002496630103.html) - aliexpress seller
* [name](url)
