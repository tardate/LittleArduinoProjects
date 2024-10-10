# #596 SYN6288 Module

Investigating the SYN6288 Chinese text to speech module with simple Arduino demonstration.

![Build](./assets/SYN6288Module_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/0qK9wVQqV3A/0.jpg)](https://www.youtube.com/watch?v=0qK9wVQqV3A)

## Notes

I picked up a
[SYN6288 speech synthesis module](https://www.aliexpress.com/item/4001100326898.html)
during the 11-11 sales last year. Finally got around to giving it a run.

Bottom line:

* the chip is for Chinese (Mandarin) speech synthesis. It can read english characters, but if you are looking for speech synthesis in other languages, this is not the chip you need.
* it does a phenomenal job. Pronunciation is good, and the ability to mix background sounds is pretty amazing in such a small chip.
* Volume without additional amplification is also very good.
* the command set is pretty straight-forward and easy to code for.

The code I'm using for the demo is very basic and takes a few short-cuts.
But from this little test I can tell that it would be quite easy to code up a full-featured library.

The current product is [SYN6288E](http://www.tts168.com.cn/productinfo.aspx?ProductsId=41&CateId=8&code=SYN6288E)

## SYN6288 Module

The SYN6288 speech synthesis module is manufactured by [Beijing Yu Tone World Technology Co. Ltd 北京宇音天下科技有限公司](http://www.tts168.com.cn/)

The OSYNO 6188 28pin small volume speech synthesis chip was introduced in 2003. While quite revolutionary, its features were limited:

* only GB_2312 and ASCII code
* max 9600bps

The SYN6288 new gen product was launched in 2010, with improved features:

* GB2312, GBK, BIG5 and Unicode
* max 38400bps
* new control commands incl synthesis, stop synthesis, pause synthesis, continue synthesis, change baud rate

### General Specifications

Description:

1. the module has the standard 3.5mm standard audio interface, can be plugged into the audio, amplifier equipment, set aside speaker interface directly to drive 8Ω 0.5W speakers.
2. module input voltage can choose 3-5V arbitrary power input, serial communication operation is simple. The baud rate can be selected 3 communication level: 9600,19200,38400bit/s.
3. Input Chinese characters can be prepared from the corresponding audio, sound is output by the audio output interface, use the sound of a human voice, add background music, a variety of sound system, only need to send instruction format.
4. supporting the official test software, can realize the voice synthesis demonstration operation

Feature:

* Support Text, GBK, BIG5 and GB2312  and UNICODE code format;
* clear, natural, accurate Chinese speech synthesis effect; can  arbitrary Chinese text synthesis, support synthesis English letters;
* have  intelligent text analysis and processing algorithm,can correctly identify the numerical number, date, time and the common measurement symbols;
* strong conversion and Chinese surname processing ability;
* support multiple text control mark, improve the correct rate of text processing;
* text volume of each synthesis up to 200 bytes;
* support a variety of control commands, including: synthesis, stop, pause synthesis, continue synthesis,alter baudrate etc.;
* support for hibernation, in sleep mode power consumption can be reduced;  support a variety of ways to query chip working state;
* support for serial data communication interface, support the three kind of communication baud rate: 9600bps, 19200bps, 38400bps;
* support 16 grade volume adjustment;  the playback volume of text prospects and background music in the background can be separated from the control volume;
* can send control markup adjustment speed ,support  6 grade  words speed adjustment;
* chip solidified with the multi polyphonic music, sound effects And a common voice prompt tone for certain industries;
* the internal integration of 19 sound tone, 23 Chord tone, 15 background music;
* the final products of SSOP SMD package form;
* the indicators of chip meet outdoor harsh environment application

### Basic Mode of Operation

Covered in the datasheet [
[ZH](./assets/SYN6288_Manual.pdf),
[EN](./assets/SYN6288_Manual_en.pdf)
]

The module:

* operates on 5V
* receives commands over UART connection. Default 9600bps, 8 data bit, 1 stop bit, no parity.
* provides mono audio output on the BP0 and BN0 pins.
* a BUSY output pin goes high when still processing the commands sent to it via UART.

Commands are sent in a common frame structure:

| frame part          | length        | values | description|
|---------------------|---------------|--------|------------|
| header              | 1 byte        | 0xFD   | |
| data area length    | 2 bytes       |        | |
| data area: command  | 1 byte        |        | |
| data area: params   | 1 byte        |        | |
| data area: text     |               |        | 200 bytes max |
| data area: checksum | 1 byte        |        | XOR checksum |

#### Command 0x01: Play

params[bits: 7,6,5,4] - encode background music (0 - 15)

params[bits: 3,1,0] - specify encoding format:

* 0x00 - GB2312
* 0x01 - GBK
* 0x02 - BIG5
* 0x03 - UNICODE

eg:

| command | params | description |
|---------|--------|-------------|
| 0x01    | 0x00   | Play text GB2312 encoding |
| 0x01    | 0x01   | Play text GBK encoding    |
| 0x01    | 0x02   | Play text BIG5 encoding    |
| 0x01    | 0x03   | Play text Unicode encoding    |
| 0x01    | 0x09   | Play text GBK encoding with background music 1   |
| 0x01    | 0x79   | Play text GBK encoding with background music 15   |

#### Command 0x02: Stop synthesis

#### Command 0x03: Synthetic pause

#### Command 0x04: Recovery synthesis

#### Command 0x21: Chip Status

#### Command 0x31: Set Baud Rate

#### Command 0x88: Power Down


## Arduino Libraries

There don't appear to be any well supported Arduino libraries at this time. The best examples I found to work with include:

* [SYN6288 Chinese Speech Synthesis Module](http://www.toughdev.com/content/2014/07/syn6288-chinese-speech-synthesis-module/) - good overview with PIC/MPLAB examples
* [Syn6288 library](https://github.com/brucetsao/LIB_for_MCU/tree/master/Arduino_Lib/libraries/Syn6288) - unknown origin, not full featured but for Arduino


## Example Code

I'm using a local cleaned up / butchered version of the [Syn6288 library](https://github.com/brucetsao/LIB_for_MCU/tree/master/Arduino_Lib/libraries/Syn6288)
with a simple demonstration of three text blocks:

* Chinese synthesis, reading: "希望大家心想事成健健康康"
* reading English characters: "leap.tardate.com"
* counting numbers (in Chinese): "1,2,3,4,5,6,7,8,9"

NB: [r12a.github.io/app-encodings/](https://r12a.github.io/app-encodings/) is a fantastic resource for cross-encoding text to bytes

The code takes quite a few shortcuts:

* drives the SYN6288 through the hardware serial (using `Serial` class and pins 0, 1).
  * This is easy, but with an Uno it does mean disconnecting the SYN6288 while programming
* code does not check chip status or monitor the busy indicator
  * this means it needs to "guess" how long the chip will teak to synthesise the text
  * interesting: reading english characters seems to take more time than readin Chinese

## Construction

Here are the details of the interconnection of the module with an Arduino Uno and speaker - all that I needed for a test.

![bb](./assets/SYN6288Module_bb.jpg?raw=true)

![schematic](./assets/SYN6288Module_schematic.jpg?raw=true)

![Build](./assets/SYN6288Module_build.jpg?raw=true)

## Credits and References

* [SYN6288 speech synthesis module, text to speech, TTS pronunciation Live](https://www.aliexpress.com/item/4001100326898.html)
* [SYN6288 Chinese Speech Synthesis Module](http://www.toughdev.com/content/2014/07/syn6288-chinese-speech-synthesis-module/) - good overview with PIC/MPLAB example
* [Syn6288 library](https://github.com/brucetsao/LIB_for_MCU/tree/master/Arduino_Lib/libraries/Syn6288)
* [Beijing Yu Tone World Technology Co. Ltd 北京宇音天下科技有限公司](http://www.tts168.com.cn/)
* [Demystifying SYN6288](http://www.tts168.com.cn/newsinfo.aspx?NewsId=129&CateId=4)
* [Encoding converter](https://r12a.github.io/app-encodings/) - very useful coverter
* [SYN6288E](http://www.tts168.com.cn/productinfo.aspx?ProductsId=41&CateId=8&code=SYN6288E) - current product line
