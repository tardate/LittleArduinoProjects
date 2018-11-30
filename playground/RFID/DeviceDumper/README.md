# #438 RFID/DeviceDumper

Getting started with some RFID research and using an RC522 RFID reader with MIFARE Classic cards and tags.

![Build](./assets/DeviceDumper_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

[RC522 RFID modules](https://www.aliexpress.com/item/Free-Shipping-RFID-module-RC522-Kits-S50-13-56-Mhz-6cm-With-Tags-SPI-Write-Read/32523771442.html)
are widely available for no more than a few dollars. These typically come with a card and tag.

The module embeds the NXP MFRC522 Contactless Reader IC. Technically, this is known as the PCD (Proximity Coupling Device)
The MFRC522 is an integrated reader/writer IC for contactless communication at 13.56 MHz, and supports ISO/IEC 14443 A/MIFARE and NTAG standards.

The cards and tags provided use the ISO 14443A/MIFARE standard. These are generically known as a PICC (Proximity Integrated Circuit Card).

![kit_parts](./assets/kit_parts.jpg?raw=true)


### RFID Standards

The [Wikipedia RFID](https://en.wikipedia.org/wiki/Radio-frequency_identification) page is a good place to start,
along with the
[MFRC522](https://www.nxp.com/products/identification-and-security/nfc/nfc-reader-ics/standard-performance-mifare-and-ntag-frontend:MFRC52202HN1)
and
[MIFARE Classic](https://www.nxp.com/products/identification-and-security/mifare-ics/mifare-classic:MC_41863)
product documentation from NXP.

The first thing to note is that RFID is a generic term that covers a wide variety of systems, applications and standards.

Most "smart cards" operate in the 13.56 MHz HF band and comply with on of the standards:

* [ISO/IEC 14443](https://en.wikipedia.org/wiki/ISO/IEC_14443) - proximity (close range), such as the NXP MFRC522 and MIFARE
* [ISO/IEC 15693](https://en.wikipedia.org/wiki/ISO/IEC_15693) - vicinity cards, read at distances of 1–1.5 meters


Simple identification tags (such as used with inventory or livestock) operate around ~125kHz,
and seem to mainly follow properitary standards.
One of the most common is the so-called EM4100 or compatilble. Cards and readers are widely available,
although it was originally a product of EM Microelectronic, and subsequently superceded by
[EM4200](https://www.emmicroelectronic.com/product/lf-animal-access-ics/em4200)


Product identification tags (e.g. as used for products in staff-less shops) operate in UHF ISM bands and can operate at moderate range up to 12m.
Most
[Electronic Product Code](https://en.wikipedia.org/wiki/Electronic_Product_Code)
RFID tags comply with ISO/IEC 18000-6C for the RFID air interface standard.

At the higher end are solutions in the 2450-5800 MHz wireless band and even 3.1–10 GHz microwave.


### Security

It doesn't take much research to quickly discover that the security is one of the biggest issues with RFID.

Most if not all early security mechanisms have been compromised.
This includes the
[NXP Crypto-1](https://en.wikipedia.org/wiki/Crypto-1) encryption algorithm
that is used by MFRC522 and MIFARE cards.


### Getting Started

I think it was watching Julian Ilett's "First Look: RC522 RFID Reader/Writer ($4 on eBay)" video
that originally encouraged me to buy one to try...

[![clip](https://img.youtube.com/vi/nn-nuhAByRk/0.jpg)](https://www.youtube.com/watch?v=nn-nuhAByRk)

Bigclivedotcom's RFID reader technology and cloning tags video is also a good intro..

[![clip](https://img.youtube.com/vi/VsZLFqE_iLc/0.jpg)](https://www.youtube.com/watch?v=VsZLFqE_iLc)


## Construction

First step is to do some tag reading.
Here's a quick setup with an Arduino Uno, using Miguel Balboa's
[MFRC522 RFID Library](https://github.com/miguelbalboa/rfid).

Power: the MFRC522 is 3.3V device, and officially tolerant up to around 4V.
So, running it with the 5V Uno is not strictly legit. Power is supplied
correctly at 3.3V, but data lines will stray up to 5V.
But it does seem to work, as many have proven before, though I wouldn't do it this way
for anything other than short tests.

Pin connections:

| MFRC522  | Arduino |
|----------|---------|
| SDA      | 10      |
| SCK      | 13      |
| MOSI     | 11      |
| MISO     | 12      |
| IRQ      | -       |
| GND      | GND     |
| RST      | 9       |
| 3.3      | 3.3V    |


![Breadboard](./assets/DeviceDumper_bb.jpg?raw=true)

![Schematic](./assets/DeviceDumper_schematic.jpg?raw=true)

![Build](./assets/DeviceDumper_build.jpg?raw=true)


## Test Program

The [DeviceDumper.ino](./DeviceDumper.ino) combines a few diagnostic tests:

* runs a self-test on the MFRC522 PCD
* waits for a PICC to be presented, then:
    * tries common keys to find one that authenticates (it doesn't try a full crack of the card)
    * dumps and interprets the full contents of the card

It only does read operations.

The "common keys" come from the work in the [MiFare Classic Universal toolKit (MFCUK)](https://github.com/nfc-tools/mfcuk).

### Blank Card

Scanning the blank PICC that was supplied with the module..

![card_test](./assets/card_test.png?raw=true)

```
-----------------------------
MFRC522 Digital self test
Firmware Version: 0x92 = v2.0
Performing test... Result: OK
-----------------------------
Scan PICC to see UID, SAK, type, and data blocks...
Authenticating using key A =  FF FF FF FF FF FF
Success with key: FF FF FF FF FF FF
Card UID: EB CC 0C C5
Card SAK: 08
PICC type: MIFARE 1KB
Sector Block   0  1  2  3   4  5  6  7   8  9 10 11  12 13 14 15  AccessBits
  15     63   00 00 00 00  00 00 FF 07  80 69 FF FF  FF FF FF FF  [ 0 0 1 ]
         62   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
         61   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
         60   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
  14     59   00 00 00 00  00 00 FF 07  80 69 FF FF  FF FF FF FF  [ 0 0 1 ]
         58   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
         57   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
         56   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
  13     55   00 00 00 00  00 00 FF 07  80 69 FF FF  FF FF FF FF  [ 0 0 1 ]
         54   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
         53   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
         52   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
  12     51   00 00 00 00  00 00 FF 07  80 69 FF FF  FF FF FF FF  [ 0 0 1 ]
         50   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
         49   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
         48   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
  11     47   00 00 00 00  00 00 FF 07  80 69 FF FF  FF FF FF FF  [ 0 0 1 ]
         46   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
         45   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
         44   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
  10     43   00 00 00 00  00 00 FF 07  80 69 FF FF  FF FF FF FF  [ 0 0 1 ]
         42   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
         41   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
         40   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
   9     39   00 00 00 00  00 00 FF 07  80 69 FF FF  FF FF FF FF  [ 0 0 1 ]
         38   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
         37   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
         36   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
   8     35   00 00 00 00  00 00 FF 07  80 69 FF FF  FF FF FF FF  [ 0 0 1 ]
         34   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
         33   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
         32   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
   7     31   00 00 00 00  00 00 FF 07  80 69 FF FF  FF FF FF FF  [ 0 0 1 ]
         30   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
         29   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
         28   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
   6     27   00 00 00 00  00 00 FF 07  80 69 FF FF  FF FF FF FF  [ 0 0 1 ]
         26   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
         25   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
         24   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
   5     23   00 00 00 00  00 00 FF 07  80 69 FF FF  FF FF FF FF  [ 0 0 1 ]
         22   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
         21   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
         20   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
   4     19   00 00 00 00  00 00 FF 07  80 69 FF FF  FF FF FF FF  [ 0 0 1 ]
         18   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
         17   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
         16   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
   3     15   00 00 00 00  00 00 FF 07  80 69 FF FF  FF FF FF FF  [ 0 0 1 ]
         14   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
         13   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
         12   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
   2     11   00 00 00 00  00 00 FF 07  80 69 FF FF  FF FF FF FF  [ 0 0 1 ]
         10   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
          9   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
          8   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
   1      7   00 00 00 00  00 00 FF 07  80 69 FF FF  FF FF FF FF  [ 0 0 1 ]
          6   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
          5   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
          4   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
   0      3   00 00 00 00  00 00 FF 07  80 69 FF FF  FF FF FF FF  [ 0 0 1 ]
          2   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
          1   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
          0   EB CC 0C C5  EE 88 04 00  85 00 B4 2E  F0 BB 6A A8  [ 0 0 0 ]
```

Breaking this down:

```
-----------------------------
MFRC522 Digital self test
Firmware Version: 0x92 = v2.0
Performing test... Result: OK
-----------------------------
Scan PICC to see UID, SAK, type, and data blocks...
Authenticating using key A =  FF FF FF FF FF FF
Success with key: FF FF FF FF FF FF
Card UID: EB CC 0C C5
Card SAK: 08
PICC type: MIFARE 1KB
```

The factory default key worked for authentication.

The card UID shown is actually from the first 4 bytes of the EEPROM.

The SAK (Select Acknowledge) is the code that the card returned when selected.
The `08` is decoded to mean this is a MIFARE 1KB card.

The memory dump that follows lists the 16 sectors,
each a total 64 bytes organised as 4 blocks of 16 bytes (for a total of 1024).

Sector 0:

* first block (16 bytes) is for manufacturer data (usually read-only). This includes the card identification:
    * a 4-byte NUID (`EB CC 0C C5` in this case)
    * or 7-byte UID (`EB CC 0C C5  EE 88 04` in this case)
    * the 5th byte is a checksum of the first 4 bytes: `EB ^ CC ^ 0C ^ C5 = EE`
* The next 2 blocks (32 bytes) are empty data blocks
* The final block (16 bytes) is the sector trailer


The Sector Trailer comprises:

* Bytes 0-5: Key A
* Bytes 6-8: Access bits
* Bytes 9: User data
* Bytes 10-15: Key B (or user data)


```
Sector Block   0  1  2  3   4  5  6  7   8  9 10 11  12 13 14 15  AccessBits
   0      3   00 00 00 00  00 00 FF 07  80 69 FF FF  FF FF FF FF  [ 0 0 1 ]
          2   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
          1   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
          0   EB CC 0C C5  EE 88 04 00  85 00 B4 2E  F0 BB 6A A8  [ 0 0 0 ]
```

Note that Key A appears to be `00 00 00 00 00 00` - but we authenticated with `FF FF FF FF FF FF`. What gives?
The AccessBits `0 0 1` means Key A is write only, and Key B is read/write and may be used for data.
When keys are write-only, they return 0 when read.

Sectors 1 through 15 are identical in structure, and on this card are initialised with blank default data:

* 3 data blocks
* 1 sector trailer


```
Sector Block   0  1  2  3   4  5  6  7   8  9 10 11  12 13 14 15  AccessBits
  15     63   00 00 00 00  00 00 FF 07  80 69 FF FF  FF FF FF FF  [ 0 0 1 ]
         62   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
         61   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
         60   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
(etc)
``

### Blank Tag

The tag supplied with the modules reads just like the card and is cleanly initialised with no data.

```
Card UID: 46 B5 BC 93
Card SAK: 08
PICC type: MIFARE 1KB
Sector Block   0  1  2  3   4  5  6  7   8  9 10 11  12 13 14 15  AccessBits
  15     63   00 00 00 00  00 00 FF 07  80 69 FF FF  FF FF FF FF  [ 0 0 1 ]
         62   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
         61   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
         60   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
(etc)
   0      3   00 00 00 00  00 00 FF 07  80 69 FF FF  FF FF FF FF  [ 0 0 1 ]
          2   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
          1   00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00  [ 0 0 0 ]
          0   46 B5 BC 93  DC 08 04 00  62 63 64 65  66 67 68 69  [ 0 0 0 ]
```


## Conclusion

The MFRC522 readers and MIFARE cards/tags widely available in eBay/aliexpress are amazing bargains.
While good for games and hobby projects, security is non-existant when coupled with the common libraries.

When real seurity is required, would need to at least swith up to 3DES or AES encryption.
For example that could mean using the
[Mifare Desfire EV1](https://www.mifare.net/en/products/chip-card-ics/mifare-desfire/mifare-desfire-ev1/)
as described in projects
[like this](https://www.codeproject.com/Articles/1096861/DIY-electronic-RFID-Door-Lock-with-Battery-Backup?msg=5457794) -
also featured on the
[Adafruit blog](https://blog.adafruit.com/2016/07/18/diy-rfid-e-lock-upgraded-to-work-with-desfire-ev1-cards-library-compatible-for-teensyarduino/).


## Credits and References
* [RFID module RC522 Kits](https://www.aliexpress.com/item/Free-Shipping-RFID-module-RC522-Kits-S50-13-56-Mhz-6cm-With-Tags-SPI-Write-Read/32523771442.html) - examples from a seller on aliexpress
* [RFID](https://en.wikipedia.org/wiki/Radio-frequency_identification) - Wikipedia
* [MFRC522 product info](https://www.nxp.com/products/identification-and-security/nfc/nfc-reader-ics/standard-performance-mifare-and-ntag-frontend:MFRC52202HN1)
* [MFRC522 Datasheet](https://www.nxp.com/docs/en/data-sheet/MFRC522.pdf)
* [MIFARE Classic product info](https://www.nxp.com/products/identification-and-security/mifare-ics/mifare-classic:MC_41863)
* [MF1S50YYX_V1: MIFARE Classic product info](https://www.nxp.com/products/identification-and-security/mifare-ics/mifare-classic/mifare-classic-ev1-1k-mainstream-contactless-smart-card-ic-for-fast-and-easy-solution-development:MF1S50YYX_V1)
* [Mifare MFRC522 RFID Reader/Writer](https://playground.arduino.cc/Learning/MFRC522) - arduino playground
* [MFRC522 RFID Library](https://github.com/miguelbalboa/rfid)
