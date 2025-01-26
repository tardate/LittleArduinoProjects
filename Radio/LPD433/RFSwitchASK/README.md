# #064 ASK RF Switch

Simple data communications using ASK protocol over 433Mhz RF transmitter and receiver set.

![The Build](./assets/RFSwitchASK_build.jpg?raw=true)

Here's a quick video of the circuit in action:

[![RFSwitchASK demo](https://img.youtube.com/vi/mY-AEeIW1pc/0.jpg)](https://www.youtube.com/watch?v=mY-AEeIW1pc)


## Notes

This is a continuation of the [LEAP#063 RFSwitch](../RFSwitch) project which demonstrated simple
RF analog communication with a pair of inexpensive 433 MHz modules.

This project adds microcontrollers at both ends and runs a digital transission over the RF link using an
[Amplitude Shift Keying (ASK)](http://en.wikipedia.org/wiki/Amplitude-shift_keying) protocol.

Here I'm using the ASK implementation provided by the [RadioHead](http://www.airspayce.com/mikem/arduino/RadioHead/) library.

One thing that became immediately clear is that the ASK protocol has done an excellent job of dealing with
the noise that was so much in evidence with the analog RFSwitch project.

I've only been transmitting at short distances however (5m max), but I've yet to even need to attach an antenna to the RF modules.

### Sender

The sender is an Arduino Nano (no particular reason why, except it was handy).
It periodically sends an on or off signal, with an LED to indicate what it has sent.

The data sent is actually the bytes representing the actual words "on" or "off", just to play with some different data types on the wire.
The default maximum message length implemented by the ASK library is 60 bytes.

### Receiver

The receiver is an Arduino Uno (again, no particular reason why, except it was handy).

It polls for data, and when it receives a valid packet, it decodes it as a string and checks for the on/off state.
It then sets its LED in accordance. So when sender/receiver are running, their respective LEDs should flash pretty much in unison
(with a slight delay at the receiving end)

### Construction

![The Breadboard](./assets/RFSwitchASK_bb.jpg?raw=true)

![The Schematic](./assets/RFSwitchASK_schematic.jpg?raw=true)


## Credits and References

* [LEAP#063 RFSwitch](../RFSwitch) project - simple RF analog communication without microcontrollers
* [RadioHead](http://www.airspayce.com/mikem/arduino/RadioHead/) library original sources
* [RadioHead on GitHub](https://github.com/tardate/RadioHead) - my fork
* [1 pair (2pcs)433Mhz RF transmitter and receiver link kit](https://www.aliexpress.com/item/Best-prices-1-pair-2pcs-433Mhz-RF-transmitter-and-receiver-link-kit-for-Arduino/1973229871.html) - this is the product I am testing with. Not bad at 0.80USD with free shipping!
* [RF Module datasheet](http://www.robotshop.com/media/files/pdf/datasheet-im120628014.pdf) - not the exact unit I have, but close. This datasheet is more an application guide than technical spec.
* [Wikipedia: short range/low-power devices](http://en.wikipedia.org/wiki/Short_Range_Devices)
* [Wikipedia: LPD433](http://en.wikipedia.org/wiki/LPD433) - info about low power device 433 MHz/70-centimeter band standards.
