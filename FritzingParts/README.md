# #223 Fritzing Parts

Most projects in the LittleArduinoProjects collection a circuit schematic drawn with [Fritzing](http://fritzing.org/home/).
But often I needed a non-standard part for the diagram. Here they are!

NB: if I'm making a PCB, I'll probably be using [KiCad](http://kicad-pcb.org/) instead.
More recently, I've been using [EasyEDA](https://easyeda.com) as a great tool for drawing up schematics.

## New Parts

These are new parts I've created because I wasn't able to find an existing alternative:

* [AS712 Current Sensor Module](./AS712CurrentSensorModule)
* [AMS1117 SOT-223 Voltage Regulator on a PCB module](./AMS1117)
* [74LS02 Quad 2-input NOR Gate](./74LS02)
* [74LS122 Retriggerable Monostable Multivibrator](./74LS122)
* [74LS75 Quad Latch](./74LS75)
* [AD9833 Programmable Waveform Module](./AD9833_Module)
* [The Cuttle](./TheCuttle) - a Fritzing part for the Boldport Cuttle module
* [LM2662 Switched Capacitor Voltage Converter](./LM2662) - DIP8 module
* [LM324 Quad OpAmp](./LM324)
* [LM386 Low Voltage Audio Power Amplifier](./LM386)
* [LM3915 Dot/Bar Display Driver](./LM3915)
* [LM741 General Purpose Operational Amplifier](./LM741)
* [SCR generic TO-92 silicon controlled rectifier/thyristor](./SCR)
* [SMA420564 4-Digit 7-Segment LED Display](./SMA420564)
* [Stepper Motor 28BYJ-48](./28BYJ-48)
* [Stepper Driver Board X113647](./X113647)
* [Voltage Sensor Module](./VoltageSensorModule)


## Locally Cached Parts

If the part source is not in a reliable repository (e.g. GitHub), I may copy the part here with a note on its providence.

* [CD4017 (local copy)](./cached/CD4017.fzpz) - [original source](https://code.google.com/p/fritzing/issues/detail?id=875#c526)
* [HC-SR04 (local copy)](./cached/HC-SR04.fzpz) - [original source](http://fritzing.org/projects/hc-sr04-project)
* [Song Le Relay (local copy)](./cached/Song Le Relay.fzpz) - [original source](https://code.google.com/p/fritzing/issues/detail?id=2389)
* [2N7000 FET N-Channel (local copy)](./cached/2N7000 FET N-Channel.fzpz) - [original source](https://github.com/kylegordon/Fritzing-Parts)
* [STM32F103C8T6 Blue Pill (local copy)](./cached/BluePill) - [original source](http://blog.naver.com/PostView.nhn?blogId=chandong83&logNo=221026011343&categoryNo=0&parentCategoryNo=39&viewDate=&currentPage=1&postListTopCurrentPage=1&from=search)
* [ESP32 DevKit (local copy)](./cached/ESP32S_HiLetgo.fzpz) - [original source](https://forum.fritzing.org/t/esp32s-hiletgo-dev-boad-with-pinout-template/5357?u=steelgoose)
* [ESP12E (local copy)](./cached/ESP12E.fzpz) - [original source](https://github.com/mathijswesterhof/Fritzing-parts/blob/master/ESP%2012E.fzpz)

## Useful Parts Collections on GitHub

* [AdaFruit Fritzing Library](https://github.com/adafruit/Fritzing-Library)
* [Fritzing for the Spark Core](https://github.com/technobly/SparkCore-Fritzing)
* [kylegordon/Fritzing-Parts](https://github.com/kylegordon/Fritzing-Parts)
* [rwaldron/fritzing-components](https://github.com/rwaldron/fritzing-components)
* [SFE Fritzing parts](https://github.com/sparkfun/Fritzing_Parts)
* [una1veritas/EagleDocs](https://github.com/una1veritas/EagleDocs) - Eagle and Fritzing sources
* [ESP8266 parts](https://github.com/ydonnelly/ESP8266_fritzing)


## Creating Fritzing Parts

Fritzing seems caught in a perpetual 0.9 beta, and the parts editor is yet to be fully revised and documented. Some guides that are useful..

* [FritzingReference](http://fritzing.org/learning/full_reference)
* [New Parts Editor released](http://blog.fritzing.org/2012/10/09/new-parts-editor-released/) - October 9, 2012
* [Creating custom parts](http://fritzing.org/learning/tutorials/creating-custom-parts/)
* [Make Your Own Fritzing Parts](https://learn.sparkfun.com/tutorials/make-your-own-fritzing-parts) - Sparkfun

### Tips/tricks/heuristics

Hmm, there's not much guidance, but here ar ea few things that seem to apply (in the current versions at least)..

* breadboard views expect connector elements named with an ID indexed from 0 i.e. pin 0 should be named `connector0pin`
* schematic views expect(?) pins and terminals with an ID indexed from 0 i.e. pin 0 should be named `connector0pin` and have a terminal named `connector0terminal`
* render all non-standard fonts as objects


## Credits and References
* [Fritzing](http://fritzing.org/home/)
* [KiCad](http://kicad-pcb.org/)
* [..as mentioned on my blog](https://blog.tardate.com/2017/01/littlearduinoprojects223-fritzing-the-boldport-cuttle.html)
