# #522 Remote Doorbell

A simple doorbell using a 433MHz transmitter/receiver pair for remote signalling, and an HS-088 sound chip for a doorbell effect.

![Build](./assets/RFDoorbell_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/OvMDlvUOnRA/0.jpg)](https://www.youtube.com/watch?v=OvMDlvUOnRA)

## Notes

I can't hear my doorbell when I'm in the workshop, which often means an extra trip to the post office when I miss a bulky aliexpress delivery.

This is a quick build of a wireless doorbell using:

* a cheap [433Mhz RF transmitter and receiver kit](https://www.aliexpress.com/item/1850319332.html)
* and an [HS-088 ding-dong sound chip](https://www.aliexpress.com/item/32661936820.html)

I decided not to use any encoding over the wireless link, so I'm using it more like a spark-gap transmitter.
So far in my experiments, I'm not seeing enough interference to get false positives ringing the doorbell.
If that changes, I'd probably add an ATtiny and run a simple ASK signal over the connection. We'll see how this goes..

### RF Module Specs

Receiver:

* Model MX-05V
* Working voltage : DC5V
* Quiescent current : 4MA
* Receiving frequency :  433MHZ
* Receiver sensitivity : -105DB
* Size : 30*14*7mm external antenna : 32CM single core wire , wound into a spiral shape

Transmitter:

* Product number : MX-FS-03V
* Transmission distance : 20-200 meter ( different voltage , the effect is different )
* Operating voltage : 3.5-12V
* Dimensions : 19*19mm

### Incoming Signals

The incoming signal (DATA pin output) looks like this when the doorbell is pressed.
The positive pulse is a fixed-width signal on incoming data.
The pulse goes to 0V and stays low for the full duration of the incoming signal.

![scope_inbound_pulse](./assets/scope_inbound_pulse.gif?raw=true)

## Circuit

The transmitter is configured to power up and send a signal when the doorbell is pressed.

The transmitter uses an opamp to perform a peak-detection on the incoming signal to identify a doorbell press,
and then fire the HS-088 module.

A speaker is connected with R2 selected between say 0-47Ω depending on the desired volume.

![Breadboard](./assets/RFDoorbell_bb.jpg?raw=true)

![Schematic](./assets/RFDoorbell_schematic.jpg?raw=true)

Testing on a breadboard:

![RFDoorbell_bb_build](./assets/RFDoorbell_bb_build.jpg?raw=true)

## Antenna

For good reception over about 30m with a few blocking walls and doors, I found the following antennas worked just fine:

* Receiver: 32cm of 0.55mm copper wire wound ø5mm air coil
* Transmitter: 25cm of 0.55mm copper wire wound ø5mm air coil

## Construction

I put the receiver circuit on a small piece of protoboard and mounted in a project box with a speaker
and a micro-USB adapter (for power only)

![build_rx_1](./assets/build_rx_1.jpg?raw=true)

![build_rx_2](./assets/build_rx_2.jpg?raw=true)

The transmitter is powered by a 9V battery. I put a mini-pushbutton on the board for testing,
and a JST connector for the doorbell wiring.

![build_tx_1](./assets/build_tx_1.jpg?raw=true)

## Credits and References

* [1Lot= 1 pair (2pcs) 433Mhz RF transmitter and receiver Module link kit for arduino/ARM/MCU WL diy 315mhz wireless](https://www.aliexpress.com/item/1850319332.html) - aliexpress
* [Sound Board IC Chip Module For DIY Toy 10pcs/lot Dingdong Tone Doorbell Music Voice Module](https://www.aliexpress.com/item/32661936820.html) - aliexpress
* [LEAP#359 HS-088](../../../Audio/AudioEffectsChips/HS088)
* [UA741CN datasheet](http://www.ti.com/lit/ds/symlink/ua741.pdf)
