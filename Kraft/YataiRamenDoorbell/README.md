# #577 屋台ラーメン The Yatai Ramen Doorbell

A wireless doorbell based on an Arii (Microace) Yatai Ramen model with added lights and sound.

![Build](./assets/YataiRamenDoorbell_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/kObQcingAiM/0.jpg)](https://www.youtube.com/watch?v=kObQcingAiM)

## Notes

I found a cute Yatai Ramen model on sale while browsing [Plaza Japan](https://www.plazajapan.com).
It was originally an Arii kit, but apparently the company was later subsumed by [Microace](http://www.microace-arii.co.jp/).
I have no idea if this kit is still in production, although it is still available for sale at some outlets.

My plan is to turn it into a door bell with appropriate sounds and lights.

## Kit Build

[![kit_box_art](./assets/kit_box_art.jpg?raw=true)](https://www.plazajapan.com/4968279812112/)

The kit is pretty crude - lots of flash and not much detail. I cleaned it up and thinned some of the mouldings e.g. ramen bowls should not be the equivalent of ~2cm thick!

![kit_parts](./assets/kit_parts.jpg?raw=true)

The lamp post was a single plastic moulding, which I converted to hold some LEDs.

![build_lamp](./assets/build_lamp.jpg?raw=true)

The cart has LEDs installed:

![build_yatai](./assets/build_yatai.jpg?raw=true)

The tree provided was quite pitiful, so it got stripped, rewired, and re-foliaged as sakura in full bloom (using a minced pink dishwashing sponge).

![build_tree](./assets/build_tree.jpg?raw=true)

## Electronics Design

The Ramen stall is mounted on a base with built-in electronics for:

* 433 Mhz RF receiver (listens for trigger signal from the remote doorbell)
* control of the LEDs in the lamp post and stall
* load the sound from SD card and playback via an LM386-amplified speaker
* manual trigger switch to run a sound/light demo sequence
* permanently on, powered from 5V USB
* controlled with an Arduino Nano - small form factor, built-in USB, and all the IO ports needed

The remote doorbell:

* 433 Mhz RF transmitter
* Arduino Nano to generate the ASK-encoded transmission
* an auto-sleep circuit (the Arduino cuts power completely after transmission)
* 9V battery power source
  - used to power the transmitter at higher voltage for increased range
  - connects to VIN of the Arduino to take advantage on the on-board regulator

### Radio Module

I'm using a common (LPD433)
[433 Mhz RF Transmitter and Receiver Module](https://www.aliexpress.com/item/32896035786.html)
from aliexpress. With antennas attached, it has reliable performance from one end of my apartment to another.

Under Arduino control, it can handle an encoded transmission. The encoding will hopefully eliminate cross-talk and false triggers from other 433 MHz devices.

![rf_module](./assets/rf_module.jpg?raw=true)

The receiver is designed to operate at 5V. I have added the 32cm external antenna:

* Product Model: MX-05V
* Operating voltage: DC5V
* Quiescent Current: 4MA
* Receiving frequency: 433.92MHZ / 315Mhz (optional)
* Receiver sensitivity: -105DB
* Size: 30 * 14 * 7mm
* External antenna: 32CM single core wire, wound into a spiral

The transmitter can operate from 3.5-12V:

* Product Model: MX-FS-03V
* Launch distance: 20-200 meters (different voltage, different results)
* Operating voltage: 3.5-12V
* Dimensions: 19 * 19mm
* Operating mode: AM
* Transfer rate: 4Kb/s
* Transmitting power: 10mW
* Transmitting frequency: 433Mhz / 315Mhz (optional)
* An external antenna: 25cm ordinary multi-core or single-core line

### Remote Doorbell (Transmitter) Circuit

The remote doorbell is triggered with a push button that turns on the battery power via Q1 p-channel MOSFET and holds it while C1 discharges.
C1 is selected to provide enough time for the Nano to boot and assert power via Q2.

The transmitter uses the [RadioHead library](https://github.com/tardate/RadioHead)
to send a series of ASK-encoded messages (repeated to make sure at least one gets through) and then shuts down by pulling Q2 low.

Code for the transmitter is in [Transmitter/Transmitter.ino](./Transmitter/Transmitter.ino).

![Transmitter_bb](./assets/Transmitter_bb.jpg?raw=true)

![Transmitter_schematic](./assets/Transmitter_schematic.jpg?raw=true)

### Building the Transmitter

Final assembly in my old doorbell housing:

![build_tx](./assets/build_tx.jpg?raw=true)

My notes on the protoboard layout I used:

![build_tx_layout](./assets/build_tx_layout.jpg?raw=true)

### Base Station (Receiver) Circuit

The receiver uses the [RadioHead library](https://github.com/tardate/RadioHead) to listen for transmissions from the bell switch.
When triggered, the code:

* turns on the lights (LEDs in the lamp post and cart) via Q1 low-side n-channel MOSTFET
* turns on the audio power via Q3 high-side p-channel MOSFET
* plays sound file from the SD card using the [TMRpcm library](https://github.com/TMRh20/TMRpcm)

Note that the RH_ASK and TMRpcm libraries both use Timer 1 by default, and this cannot be changed without modifying the library source code.
The sketch avoids the conflict by re-initializing the RH_ASK driver after the sound has played.

Code for the receiver is in [Receiver/Receiver.ino](./Receiver/Receiver.ino).

![Receiver_bb](./assets/Receiver_bb.jpg?raw=true)

![Receiver_schematic](./assets/Receiver_schematic.jpg?raw=true)

Testing transmitter and receiver on breadboards:

![Breadboard Build](./assets/YataiRamenDoorbell_bb_build.jpg?raw=true)

### Building the Receiver

Installed in the base of the kit:

![build_rx](./assets/build_rx.jpg?raw=true)

My notes on the protoboard layout I used:

![build_rx_layout](./assets/build_rx_layout.jpg?raw=true)

Bench-testing the complete build:

![YataiRamenDoorbell_build2](./assets/YataiRamenDoorbell_build2.jpg?raw=true)

## Conclusions / Next Steps

Works pretty well, however the audio volume is a bit low (even with the LM386 wired for maximum 200x amplification).
I'd like to look at some ways to improve that.

## Credits and References

* [this project on scalemates](https://www.scalemates.com/profiles/mate.php?id=74137&p=projects&project=157497)
* [Soba Noodle Stall Micro Ace No. 81211 1:25](https://www.scalemates.com/kits/micro-ace-81211-soba-noodle-stall--1399547)
* [Arii 812112 Japanese Ramen Stall 1/25 Scale Kit (Microace)](https://www.plazajapan.com/4968279812112/) plazajapan ¥1,130
* [Micro ace (Arii)](http://www.microace-arii.co.jp/)
* [433 Mhz RF Transmitter and Receiver Module Link Kit for ARM/MCU WL DIY 315MHZ/433MHZ Wireless Remote Control for arduino Diy Kit](https://www.aliexpress.com/item/32896035786.html) - from aliexpress seller
* [Yatai (food cart)](https://en.wikipedia.org/wiki/Yatai_(food_cart)) - wikipedia
* [RadioHead library](https://github.com/tardate/RadioHead)
* [TMRpcm library](https://github.com/TMRh20/TMRpcm)
