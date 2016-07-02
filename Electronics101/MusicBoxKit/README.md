# #226 MusicBoxKit

Build and test a Music Box kit, and run a demonstration under Arduino control.

![The Build](./assets/MusicBoxKit_build.jpg?raw=true)

## Notes

This is a pretty common kit available from multiple sources, although it appears to have been originally produced by
[icstation](http://www.icstation.com/music-box16-sound-boxelectronic-productiondiy-kits-p-1750.html).

The heart of the kit is a custom sound generator board with a potted chip,
[like this one](http://www.aliexpress.com/item/KD9561-CK9561-Alarm-sound-chip-Four-voices-Music-IC-Music-integrated-block-Toy-sound-IC/32666515252.html?spm=2114.30010308.3.237.VB9BEX&ws_ab_test=searchweb201556_0,searchweb201602_3_10037_10017_405_507_10033_406_10032,searchweb201603_1&btsid=9e0eeb93-3a5d-405e-bfd5-05782cf1de0c). This is one of a range of boards - all with potted chips - that I believe are primarily produced as the sound effects generators
used in toys.

This kit basically adds supporting circuitry on a PCB to:

* drive a pieze speaker
* decode 4 switch inputs into the necessary signals required to drive the sound board.

I demonstrate driving the module with an Arduino - very simple matter of pulling the inputs A-B-C-D high/low accordingly, master on/off thrown in for good measure. Of course, if you really wanted to use a sound chip like this with an Arduino, you could just control it directly.

### Kit Specs

* Suite name: 16 Music Box
* Kit Model: BOX-16
* Operating voltage :4.5-5V
* PCB size: 48mm (length) * 42mm (W)
* Control modes: manual coding + external coding

16-tone box under your control, arbitrarily issued 16 kinds of interesting analog sound, both an electronic toy can also be used as a doorbell or alarm.

### Kit Parts

The kit I received contained all the parts required, including some extra resistors and a random capacitor!

![MusicBoxKit_kit_parts](./assets/MusicBoxKit_kit_parts.jpg?raw=true)

the piezo buzzer supplied with the kit proved to be very poor match for the circuit.
I replaced it with another I had available and improved the sound quality significantly - though it is still not great.


### Sound Library and Demo Program

The four switches A-B-C-D select the sound to be generated:

| ABCD coding | Sound                   |
|-------------|-------------------------|
| 0000        | Machine gun voice       |
| 0001        | Fire truck voice        |
| 0010        | Ambulance voice         |
| 0011        | The police car voice    |
| 0100        | Crickets sound          |
| 0101        | alarm                   |
| 0110        | Electronic signal sound |
| 0111        | koh                     |
| 1000        | Insect song             |
| 1001        | whistle                 |
| 1010        | Telegraph sound         |
| 1011        | Bird song               |
| 1100        | ChongJi gunfire         |
| 1101        | Car sirens              |
| 1110        | Bass instruments sound  |
| 1111        | Racing sound            |

Breakout pins for A-B-C-D are provided. With the switches open, these pins can be used to control the board from an
external sources. The pins are low by default, and just need to be pulled high.

### Driving the Module with an Arduino

The [MusicBoxKit.ino](./MusicBoxKit.ino) sketch is a simple demonstration of the module.
It runs a demo that cycles through the 16 sounds.

To drive with an Arduino:

* 5V power is supplied from the 5V pin of the Arduino. The board can draw a peak of near 100mA, but that is within the capabilities of the Uno
* a low-side n-channel MOSFET is used to switch the board on and off (controlled by a digital pin)
* 4 digital pins are used to provide the inputs A-B-C-D
* (optional) LEDs are included to indicate the state of the 4 A-B-C-D inputs and the MOSFET gate signal


## Construction

One unclear aspect of the build is how the MusicBox ASIC board is to be connected to the main PCB.

Here's what I figured out after some study:

![MusicBoxKit_connections](./assets/MusicBoxKit_connections.png?raw=true)

The finished build:

![Module](./assets/MusicBoxKit_module.jpg?raw=true)

Wired up with an Arduino for the demo (includes LEDs to indicate signal state):

![The Schematic](./assets/MusicBoxKit_schematic.jpg?raw=true)

## Credits and References
* [DIY Kits BOX-16 16-tone Tool 16 Music Box 16 Sound Box electronic production #70448](http://www.aliexpress.com/item/DIY-Kits-BOX-16-16-tone-Tool-16-Music-Box-16-Sound-Box-electronic-production-70448/32361863021.html) - seller on aliexpress
* [16 Music Box/16 Sound Box/Electronic Production/DIY Kits](http://www.icstation.com/music-box16-sound-boxelectronic-productiondiy-kits-p-1750.html) - icstation
* [KD9561 CK9561 Alarm sound chip Four voices Music IC Music integrated block Toy sound IC](http://www.aliexpress.com/item/KD9561-CK9561-Alarm-sound-chip-Four-voices-Music-IC-Music-integrated-block-Toy-sound-IC/32666515252.html?spm=2114.30010308.3.237.VB9BEX&ws_ab_test=searchweb201556_0,searchweb201602_3_10037_10017_405_507_10033_406_10032,searchweb201603_1&btsid=9e0eeb93-3a5d-405e-bfd5-05782cf1de0c) - the sound chip module used in the kit.
* [CD4011 datasheet](http://www.futurlec.com/4000Series/CD4011.shtml)
* [CD4066 datasheet](http://www.futurlec.com/4000Series/CD4066.shtml)
