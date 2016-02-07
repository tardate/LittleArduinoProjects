# #063 RFSwitch

The simplest analog RF switch, using a 433Mhz RF transmitter and receiver set. No microcontrollers here!

Here's a quick video of the circuit in action:

[![RFSwitch demo](http://img.youtube.com/vi/s8yCbDe15ms/0.jpg)](http://www.youtube.com/watch?v=s8yCbDe15ms)

## Notes

Paired RF transmit/receive modules are widely available at low cost.
The modules I have came from
[aliexpress](http://www.aliexpress.com/item/Best-prices-1-pair-2pcs-433Mhz-RF-transmitter-and-receiver-link-kit-for-Arduino/1973229871.html)
for 0.80USD with free shipping. Can't ask for a much better deal than that!

I beleive that these devices fit into the geneal category of
[short range/low-power devices](http://en.wikipedia.org/wiki/Short_Range_Devices)
and this unit operates in the 433 MHz UHF/70-centimeter band.

Before diving into using higher-level data protocols over the RF link, I was inspired by various youtube videos to test the devices with the simplest analogue switch circuit. A sampling of the many youtube videos on the subject:

* [Wireless RF Links Tutorial & Noise Reduction by EEEnthusiast](https://youtu.be/RHJVyMYJ1XQ)
* [Cheaper Wireless for Arduino by Kyle Fieldus](https://youtu.be/U839NZ78EOo) which is a nice detailed walkthrough but using the older VirtualWire library.

So in this circuit, there's no microcontroller or anytgin fancy, just the RF modules communicating with each other and transmitting a button press to blink a remote LED.

### Sender

Simply has a button wired up with LED indicator. When not pressed, the Data line is pulled low. When the button is pressed, it pulls the data pin high.
The LEd incdicator on the sender-side is mrely to confirm that a data signal was raised.
I've wired up the sender to a 9V battery.

### Receiver
The receiver is powered with 5V. When data is received, it takes the data line high.

Initially, I just had an LED wired to the data line. That worked reasonably well: press the button on the sender, and the receiver blinks the LED! How simple is that?

However, when the sender is not transmitting, the receiver does seem to pick up quite a bit of noise.
I managed to filter out the noise to the point where it is 90%+ clean with two simple measures:

* add a 1μF and 100nF capacitors for medium-high frequency filtering
* send the data into an LM324 OpAmp comparator, with reference voltage set at 10kΩ/(4.7kΩ + 10kΩ) * Vcc i.e. ~68% Vcc or 3.4V

Next up I'll be looking at using the RF links with an Arduino. I'm interested to see if libraries like [RadioHead](http://www.airspayce.com/mikem/arduino/RadioHead/) obviate the need to do this analog signal processing (answer is yes!):

* [RFSwitchASK](../../playground/RFSwitchASK) - adding microcontrollers and demonstrating simple data communications using ASK protocol


### Construction

![The Breadboard](./assets/RFSwitch_bb.jpg?raw=true)

![The Schematic](./assets/RFSwitch_schematic.jpg?raw=true)

![The Build](./assets/RFSwitch_build.jpg?raw=true)


## Credits and References
* [1 pair (2pcs)433Mhz RF transmitter and receiver link kit](http://www.aliexpress.com/item/Best-prices-1-pair-2pcs-433Mhz-RF-transmitter-and-receiver-link-kit-for-Arduino/1973229871.html) - this is the product I am testing with. Not bad at 0.80USD with free shipping!
* [RF Module datasheet](http://www.robotshop.com/media/files/pdf/datasheet-im120628014.pdf) - not the exact unit I have, but close. This datasheet is more an application guide than technical spec.
* [Wikipedia: short range/low-power devices](http://en.wikipedia.org/wiki/Short_Range_Devices)
* [Wikipedia: LPD433](http://en.wikipedia.org/wiki/LPD433) - info about low power device 433 MHz/70-centimeter band standards.
