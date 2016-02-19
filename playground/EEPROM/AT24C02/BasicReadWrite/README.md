# #188 EEPROM/AT24C02/BasicReadWrite

Basic read/write operations to external EEPROM (AT24C02) with the Wire library

![The Build](./assets/BasicReadWrite_build.jpg?raw=true)

## Notes

I have some AT24C02BN Two-wire Serial EEPROM chips with a whopping capacity of 2K! (256 x 8)
That's not a whole lot more than the onboard EEPROM in an Arduino, but it does have the advantage of being external:
* it can stay in place even if the Arduino is exchanged
* multiple devices can share access

There are a few libraries available that encapsulate the interaction with external EEPROM.
All that I've seen use the Wire library under the covers.
Some like the [AH_24Cxx library](http://arduino.alhin.de/index.php?n=61) seem to do a really good job
of providing compatibility across the whole range of EEPROM chips and protecting/avoiding
issues with page addressing etc - things you otherwise need to take care of youself.

For this simple test of the basic read and write capability, I'm going to use the Wire library directly.
That means the code is necessarily only good for chips that work in the same way as the AT24C02
(that basically means nothing over 16k in memory).

So first as always: read the datasheet. And I immediately note **Not Recommended for New Design** ;-)
It looks like AT24C02C and AT24C02D variants are current. No matter, AT24C02BN is good enough for me now.
It seems the later version don't change the basic behaviour.

### Device Addressing

Each AT24C02 has an 8-bit device address word used in communications.

The device address word consists of a mandatory one, zero sequence for the first four most significant bits.
This is common to all the EEPROM devices.

The next 3 bits are the A2, A1 and A0 device address bits corresponding to the hard-wired input pins.

|MSB|   |   |   |    |    |    | LSB |
|---|---|---|---|----|----|----|-----|
| 1 | 0 | 1 | 0 | A2 | A1 | A0 | R/W |

The Wire library takes care of the R/W bit and in fact just expects the 7-bit address (shifted right 1 bit).

So if A2=0, A1=0, A0=1, the address expected by the Wire library would be 0x51.

### Memory Addressing

With such a small memory size, that's easy here - a single 8-bit word is used for the address.
Note that for chips with larger memory, the address size does increase (and this code wont work).

### The Test Program

The code here just runs a simple counter:
* on startup, it loads last value from EEPROM, else initialises to 0

Every second, it:
* increments the counter
* echoes the new value to the Serial console
* saves the new value in EEPROM
* reads the value back from EEPROM and echos this value to the console

So nothing real exciting, just proving it works. This is what it looks like in the coneols:

![Console](./assets/BasicReadWrite_console.png?raw=true)

## Construction

Note that I have surface mount AT24C02BN chips, so I used a SO-16 to DIP breadboard adapter to mount the chips for testing purposes.

![Breadboard](./assets/BasicReadWrite_bb.jpg?raw=true)

![The Schematic](./assets/BasicReadWrite_schematic.jpg?raw=true)

![The Build](./assets/BasicReadWrite_build.jpg?raw=true)

## Credits and References
* [AT24C02B datasheet](http://www.atmel.com/Images/doc5126.pdf)
* [Wire library](https://www.arduino.cc/en/Reference/Wire)
* [Adding External I2C EEPROM to Arduino (24LC256)](http://www.hobbytronics.co.uk/arduino-external-eeprom)
* [AH_24Cxx EEPROM library](http://arduino.alhin.de/index.php?n=61) - looks like a pretty good wrapper library around the Wire library
* [EEPROM Library](https://www.arduino.cc/en/Reference/EEPROM) - the standard library for accessing onboard EEPROM (not what I'm doing here)
* [..as mentioned on my blog](http://blog.tardate.com/2016/02/littlearduinoprojects188-readwrite.html)
