# #485 RFID Card Counter

Simple demonstratration of reading an writing value blocks with an RC522 RFID reader and MIFARE Classic cards.

![Build](./assets/CardCounter_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/GDU3mLvzJfo/0.jpg)](https://www.youtube.com/watch?v=GDU3mLvzJfo)

## Notes

See [LEAP#438 RFID/DeviceDumper](../DeviceDumper) for more notes on RFID.
This project is a simple extension - using the [MFRC522 RFID Library](https://github.com/miguelbalboa/rfid) to
demonstrate working with value blocks on a MIFARE Classic card.

## Value Blocks

Value blocks are intended for electronic purse applications.

A data block in a sector is configured as a value block by setting the corresponding access bits to either:

* 001b: non-rechargeble, write and increment disabled; only read, decrement, transfer and restore allowed
* 110b: rechargable, allows write and increment when authenticated with key B

A value block contains a 32-bit signed integer value and a 1 byte address, stored redundantly for data integrity:

|Byte | Content  |
|-----|----------|
|0-3  | value    |
|4-7  | ~value   |
|8-11 | value    |
|12   | address  |
|13   | ~address |
|14   | address  |
|15   | ~address |

The initial address and value must be set with a write command.
Subsequently, the value is adjusted with the following operations:

* Increment(source block address, operand): adds the operand to the value of the addressed block, and stores the result in the Transfer Buffer
* Decrement(source block address, operand): subtracts the operand from the value of the addressed block, and stores the result in the Transfer Buffer
* Restore(source block address): copies the value of the addressed block into the Transfer Buffer
* Transfer(destination block address): writes the value stored in the Transfer Buffer to the addressed block

So typically a transaction will involve two commands: an increment, decrement or restore followed by a transfer.

## Demonstration Application

This is a trivial example, but demonstrates:

* personalisation and charging - occurs when a blank/factory default card is presented
* increment - stores a running total of the number of times the card was scanned
* decrement - deducts an "amount" on each scan
* reset the card to factory/transport configuration when the card "amount" reaches 0

I won't bother with a sophistocated user interface, simply:

* green LED to indicate successful card charge
* yellow LED to flash on each use
* red LED when the card is fully deducted and reset to factory
* detailed transcript in the console

![console](./assets/console.png?raw=true)

## Structuring the Code

See [CardCounter.ino](./CardCounter.ino) for the main application. I've split the code into some supporting classes:

* card_interface - encapsulates communication with the reader
* charge_indicator - manages the charge/card control indicator LEDs

## Construction

There's not much to this - simple connecting up the RFID module to an Arduino.

Power: the MFRC522 is 3.3V device, and officially tolerant up to around 4V.
So, running it with the 5V Uno is not strictly legit. Power is supplied
correctly at 3.3V, but data lines will stray up to 5V.
But it does seem to work, as many have proven before, though I wouldn't do it this way
for anything other than short tests.

![Breadboard](./assets/CardCounter_bb.jpg?raw=true)

![Schematic](./assets/CardCounter_schematic.jpg?raw=true)

## Full Console Transcript

The following  is a full transcript of a session.
It shows a new card being initialised with "3 usages"; scanned 3 times, and reset to factory on the final scan..

    CardCounter MIFARE Classic value block demonstration.
    Using key A/B =  FF FF FF FF FF FF
    BEWARE: Data will be written to the PICC in sector #1
    Scan a card...
    Card UID: EB CC 0C C5
    PICC type: MIFARE 1KB
    Authenticating using key A...
    Reading sector trailer...
    Current data in sector:
       1      7   00 00 00 00  00 00 FF 07  80 00 FF FF  FF FF FF FF  [ 0 0 1 ]
              6   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
              5   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
              4   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]

    Personalizing the card and applying initial charge in sector #1
    Reading block 4
    Formatting as Value Block...
    Reading block 5
    Formatting as Value Block...
    Personalization complete.
    Current data in sector:
       1      7   00 00 00 00  00 00 4C 37  8B 00 00 00  00 00 00 00  [ 0 1 1 ]
              6   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
              5   00 00 00 00  FF FF FF FF  00 00 00 00  0F F0 0F F0  [ 1 1 0 ]  Value=0x0 Adr=0xF
              4   03 00 00 00  FC FF FF FF  03 00 00 00  F0 0F F0 0F  [ 1 1 0 ]  Value=0x3 Adr=0xF0

    Ending card communication.
    Card UID: EB CC 0C C5
    PICC type: MIFARE 1KB
    Authenticating using key A...
    Reading sector trailer...
    Current data in sector:
       1      7   00 00 00 00  00 00 4C 37  8B 00 00 00  00 00 00 00  [ 0 1 1 ]
              6   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
              5   00 00 00 00  FF FF FF FF  00 00 00 00  0F F0 0F F0  [ 1 1 0 ]  Value=0x0 Adr=0xF
              4   03 00 00 00  FC FF FF FF  03 00 00 00  F0 0F F0 0F  [ 1 1 0 ]  Value=0x3 Adr=0xF0

    Performing deduction from the card..
    Authenticating using key B...
    Authenticating using key A...
    Current data in sector:
       1      7   00 00 00 00  00 00 4C 37  8B 00 00 00  00 00 00 00  [ 0 1 1 ]
              6   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
              5   01 00 00 00  FE FF FF FF  01 00 00 00  0F F0 0F F0  [ 1 1 0 ]  Value=0x1 Adr=0xF
              4   02 00 00 00  FD FF FF FF  02 00 00 00  F0 0F F0 0F  [ 1 1 0 ]  Value=0x2 Adr=0xF0

    Ending card communication.
    Card UID: EB CC 0C C5
    PICC type: MIFARE 1KB
    Authenticating using key A...
    Reading sector trailer...
    Current data in sector:
       1      7   00 00 00 00  00 00 4C 37  8B 00 00 00  00 00 00 00  [ 0 1 1 ]
              6   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
              5   01 00 00 00  FE FF FF FF  01 00 00 00  0F F0 0F F0  [ 1 1 0 ]  Value=0x1 Adr=0xF
              4   02 00 00 00  FD FF FF FF  02 00 00 00  F0 0F F0 0F  [ 1 1 0 ]  Value=0x2 Adr=0xF0

    Performing deduction from the card..
    Authenticating using key B...
    Authenticating using key A...
    Current data in sector:
       1      7   00 00 00 00  00 00 4C 37  8B 00 00 00  00 00 00 00  [ 0 1 1 ]
              6   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
              5   02 00 00 00  FD FF FF FF  02 00 00 00  0F F0 0F F0  [ 1 1 0 ]  Value=0x2 Adr=0xF
              4   01 00 00 00  FE FF FF FF  01 00 00 00  F0 0F F0 0F  [ 1 1 0 ]  Value=0x1 Adr=0xF0

    Ending card communication.
    Card UID: EB CC 0C C5
    PICC type: MIFARE 1KB
    Authenticating using key A...
    Reading sector trailer...
    Current data in sector:
       1      7   00 00 00 00  00 00 4C 37  8B 00 00 00  00 00 00 00  [ 0 1 1 ]
              6   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
              5   02 00 00 00  FD FF FF FF  02 00 00 00  0F F0 0F F0  [ 1 1 0 ]  Value=0x2 Adr=0xF
              4   01 00 00 00  FE FF FF FF  01 00 00 00  F0 0F F0 0F  [ 1 1 0 ]  Value=0x1 Adr=0xF0

    Performing deduction from the card..
    Authenticating using key B...
    Authenticating using key A...
    Current data in sector:
       1      7   00 00 00 00  00 00 4C 37  8B 00 00 00  00 00 00 00  [ 0 1 1 ]
              6   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
              5   03 00 00 00  FC FF FF FF  03 00 00 00  0F F0 0F F0  [ 1 1 0 ]  Value=0x3 Adr=0xF
              4   00 00 00 00  FF FF FF FF  00 00 00 00  F0 0F F0 0F  [ 1 1 0 ]  Value=0x0 Adr=0xF0

    Ending card communication.
    Card UID: EB CC 0C C5
    PICC type: MIFARE 1KB
    Authenticating using key A...
    Reading sector trailer...
    Current data in sector:
       1      7   00 00 00 00  00 00 4C 37  8B 00 00 00  00 00 00 00  [ 0 1 1 ]
              6   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
              5   03 00 00 00  FC FF FF FF  03 00 00 00  0F F0 0F F0  [ 1 1 0 ]  Value=0x3 Adr=0xF
              4   00 00 00 00  FF FF FF FF  00 00 00 00  F0 0F F0 0F  [ 1 1 0 ]  Value=0x0 Adr=0xF0

    Reseting transport configuration for sector #1
    Authenticating using key B...
    Reset complete.
    Authenticating using key A...
    Current data in sector:
       1      7   00 00 00 00  00 00 FF 07  80 00 FF FF  FF FF FF FF  [ 0 0 1 ]
              6   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
              5   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
              4   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]

    Ending card communication.

## Credits and References

* [RFID module RC522 Kits](https://www.aliexpress.com/item/Free-Shipping-RFID-module-RC522-Kits-S50-13-56-Mhz-6cm-With-Tags-SPI-Write-Read/32523771442.html) - examples from a seller on aliexpress
* [MFRC522 Datasheet](https://www.nxp.com/docs/en/data-sheet/MFRC522.pdf)
* [MFRC522 RFID Library](https://github.com/miguelbalboa/rfid)
