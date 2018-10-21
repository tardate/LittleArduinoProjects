# 427 Little Electronics and Arduino Projects
> Latest addition:sparkles: [ATtiny/SoftwarePWM](./playground/ATtiny/SoftwarePWM) - generating arbitrary PWM signals with an ATtiny85 and bit-banging techniques.





Just my collection of electronics projects, many involving an Arduino in one way or another.
Some are full builds (like [The FretBoard](./FretBoard)),
while many are trivial breadboard kata, intended to test or explore a single idea.

Many are variations of things found wild on the net, or inspired by ideas from the sources such as:

* [Boldport Club](http://www.boldport.club/)
* [Nuts & Volts magazine](http://www.nutsvolts.com/)
* [Silicon Chip magazine](http://www.siliconchip.com.au/)
* [Electrical Engineering StackExchange](http://electronics.stackexchange.com/)
* [Arduino StackExchange](http://arduino.stackexchange.com/)
* [Arduino Playground](http://playground.arduino.cc/)
* books from [my electronics bookshelf](https://www.goodreads.com/review/list/17475014-paul?shelf=electronics)
* the many great electronics YouTube channels e.g.
  - [Afrotechmods](https://www.youtube.com/channel/UCosnWgi3eorc1klEQ8pIgJQ)
  - [Ben Eater](https://www.youtube.com/channel/UCS0N5baNlQWJCUrhCEo8WlA)
  - [GreatScott!](https://www.youtube.com/channel/UC6mIxFTvXkWQVEHPsEdflzQ)
  - [Julian Ilett](https://www.youtube.com/channel/UCmHvGf00GDuPYG9DZqQKd9A)
  - [Scullcom Hobby Electronics](https://www.youtube.com/channel/UCDqryeq1kMDSEQwltWqASrA)
  - [w2aew](https://www.youtube.com/channel/UCiqd3GLTluk2s_IBt7p_LjA)

Feel free to borrow liberally, and if you spot any issues do let me know. See the individual projects for credits where due.
There are even now a few projects contributed by others - send your own over in a pull request
if you would also like to add to this collection.

## Project Index

LittleArduinoProjects has a new catalog/web site!
It's actually just simple GitHub pages sitting right on top of this repository. Try it out:

[![leap-splash](./catalog/assets/images/leap-splash.png?raw=true)](https://leap.tardate.com/)


## Getting Up and Running

Some projects require additional libraries including FastLED, FlexiTimer2, RadioHead.
A set of such libraries are included as submodules of this repository,
see the [libraries/](./libraries) page for more information on the included libraries and submodule management.

For Arduino projects, I have the Arduino IDE sketchbook location (in preferences) set to the root of this repository.
This makes all the projects available to me in the IDE, and automatically includes libraries
that are linked as git submodules in the [libraries/](./libraries) folder.

If you don't have the Arduino IDE setup this way, libraries can be retrieved with git,
or you can just install them separately as you would any other library.

If you clone this repo, also update the submodules to have them available for compilation:

    $ git submodule update --init

To pull submodule updates later on:

    $ git submodule foreach git pull


## Ye Olde Project Index

Still up to date, but try [the catalog site](https://leap.tardate.com/) instead...


| Project                                                                            | Category/Description                                              |
|------------------------------------------------------------------------------------|-------------------------------------------------------------------|
| [#426 3x7 RippleTester ](./BoldportClub/3x7/RippleTester)                          | **Boldport, 7-Segment, CMOS/TTL**  using some 4000 series counters (CD4017, CD4060) to exercise the digits and segments of the Boldport 3x7 |
| [#148 AD9833/BasicDemoCycle](./playground/AD9833/BasicDemoCycle)                   | **Arduino, Oscillators**        run a basic waveform demo with an AD9833 module |
| [#184 AdjustablePulseGenerator](./Electronics101/555Timer/AdjustablePulseGenerator)| **555 Timer, Oscillators**      widely-adjustable square wave generator using the 555 timer |
| [#131 AMFMRadioKit](./Radio/AMFMRadioKit)                                          | **Radio, AM, FM**               notes on an AM/FM radio kit build |
| [#143 AM/OpAmpTransmitter](./Electronics101/AM/OpAmpTransmitter)                   | **Radio, OpAmp**                simple AM transmitter with OpAmp carrier/mixer |
| [#132 AMTransmitter/555](./Electronics101/555Timer/AMTransmitter)                  | **Radio, 555 Timer**            a simple 555-based AM transmitter |
| [#139 AnalogComparator](./playground/AnalogComparator)                             | **Arduino, Sensor, OpAmp**      test the Atmega328 built-in analog comparator |
| [#020 Arduino Internals](./playground/Internals)                                   | **Arduino**                     report on Arduino Board internals |
| [#100 ArdWinVaders](./playground/OLED/ArdWinVaders)                                | **Arduino, OLED**               an Arduino & OLED version of a classic game |
| [#404 Arza-matron](./Kraft/arzamatron)                                             | **Arduino, LED, Sensors**       whipping together a simple sound-activated party decoration with the other half of the Fretboard guitar some LED strips |
| [#379 AS3935](./playground/AS3935)                                                 | **Arduino, AS3935, Sensors**    using the AMS AS3935 Franklin Lightning Sensor with an Arduino with the Wire library |
| [#186 AsyncJKCounter](./Electronics101/DigitalLogic/AsyncJKCounter)                | **CMOS/TTL, Digital Logic**     an asynchronous 4-bit counter built with JK Flip-Flops |
| [#014 AsyncLedStripEffects](./LEDArrayDemos/AsyncLedStripEffects)                  | **LED Array, Timing, Arduino**  demo effects on the LED strip driven using timer interrupt |
| [#394 AT89C2051/Programmer](./8051/AT89C2051/Programmer)                           | **8051**                        building a programmer for the Intel MCS-51/8051 compatible AT89C2051, with host software running on MacOSX |
| [#395 AT89C2051/Blinky](./8051/AT89C2051/Blinky)                                   | **8051, LED**                   Simplest LED blinky program in C for the AT89C2051(8051/MCS51) microprocessor, built with the SDCC open-source toolchain on MacOSX |
| [#399 AT89C2051/LedChaser](./8051/AT89C2051/LedChaser)                             | **8051, LED**                   run an LED chaser with an AT89C2051 using interrupts for timing; C source compiled with SDCC on MacOSX |
| [#069 ATmegaBreadboard](./playground/ATmegaBreadboard)                             | **Arduino, ATmel**              running an ATMEGA328P-PU on a breadboard  |
| [#099 ATmegaISPShield](./playground/ATmegaISPShield)                               | **Arduino, ATmel, ICSP**        a DIY ATmega programming shield for using an Arduino as ISP  |
| [#405 ATmegaSerialProgrammer](./playground/ATmegaSerialProgrammer)                 | **Arduino, ATmel, ICSP, UART**  all about bootloaders and how to program an ATMEGA328P chip over a serial connection with a CH340G USB-Serial adapter instead of ICSP |
| [#068 ATmegaViaArduinoISP](./playground/ATmegaViaArduinoISP)                       | **Arduino, ATmel, ICSP**        Programming an ATMEGA328P-PU on a breadboard with Arduino ISP |
| [#427 ATtiny/SoftwarePWM](./playground/ATtiny/SoftwarePWM)                         | **ATmel, PWM**                  generating arbitrary PWM signals with an ATtiny85 and bit-banging techniques |
| [#275 ATtiny8MHz](./playground/ATtiny8MHz)                                         | **Arduino, ATmel**              how to run an ATtiny85 microprocessor at 8MHz using the internal clock |
| [#126 ATtinyHardwareInterrupt](./playground/ATtinyHardwareInterrupt)               | **Arduino, ATmel**              test hardware interrupts with an ATtiny85 processor on a breadboard |
| [#070 ATtinyWithArduinoISP](./playground/ATtinyWithArduinoISP)                     | **Arduino, ATmel, ICSP**        Programming an ATTINY85-20PU on a breadboard with Arduino ISP |
| [#253 ATtinyProgrammingShield](./playground/ATtinyProgrammingShield)               | **Arduino, ATmel**              a custom ATtiny programming shield for Arduino ISP |
| [#127 ATtinySleep](./playground/ATtinySleep)                                       | **Arduino, ATmel**              test sleep mode with an ATtiny85 processor on a breadboard |
| [#128 ATtinyTotalSleep](./playground/ATtinyTotalSleep)                             | **Arduino, ATmel**              test a total power shutdown with an ATtiny85 processor on a breadboard |
| [#210 AudioAmps/TDA7297Kit](./Electronics101/AudioAmps/TDA7297Kit)                 | **Audio**                       testing a TDA7297 audio amplifier kit (pump up the jam) |
| [#309 AudioConnectors](./Electronics101/Connectors/Audio)                          | **Audio, Connectors**           notes on miscellaneous audio connectors |
| [#235 AudioDSP](./playground/AudioDSP)                                             | **Audio, Arduino, DSP, OpAmp**  build and test an arduino DSP circuit based on the pedalSHIELD by electrosmash |
| [#236 AudioDSP/Boost](./playground/AudioDSP/Boost)                                 | **Audio, Arduino, DSP, OpAmp**  arduino DSP boost effect based on the pedalSHIELD by electrosmash |
| [#238 AudioDSP/Crunch](./playground/AudioDSP/Crunch)                               | **Audio, Arduino, DSP, OpAmp**  arduino DSP crunchy distortion effect based on the pedalSHIELD by electrosmash |
| [#237 AudioDSP/Distortion](./playground/AudioDSP/Distortion)                       | **Audio, Arduino, DSP, OpAmp**  arduino DSP simple distortion effect based on the pedalSHIELD by electrosmash |
| [#239 AudioDSP/SuperCrunch](./playground/AudioDSP/SuperCrunch)                     | **Audio, Arduino, DSP, OpAmp**  arduino DSP crunchy symmetrical Schetzen distortion effect based on the pedalSHIELD by electrosmash |
| [#359 AudioEffectsChips/HS088](./Electronics101/AudioEffectsChips/HS088)           | **Audio, Music Chips**          figuring out the HS088 "Ding Dong" audio effects chip |
| [#292 AudioEffectsChips/H823](./Electronics101/AudioEffectsChips/H823)             | **Audio, Music Chips**          figuring out how to use the H823 "Happy Birthday" music chip |
| [#362 AudioEffectsChips/H83A](./Electronics101/AudioEffectsChips/H83A)             | **Audio, Music Chips**          figuring out how to use the H-83A "12 songs" music chip |
| [#356 AudioEffectsChips/PX088A](./Electronics101/AudioEffectsChips/PX088A)         | **Audio, Music Chips**          figuring out how to use the PX088A "Für Elise" music chip |
| [#373 AudioEffectsChips/PX835](./Electronics101/AudioEffectsChips/PX835)           | **Audio, Music Chips**          figuring out how to use the PX835 "16 Kind of Sound Doorbell Chip" music chip |
| [#202 AudioLevelIndicatorKit](./Electronics101/AudioLevelIndicatorKit)             | **LM3915, Audio**               an audio level indicator kit based on the LM3915 |
| [#254 AvrHardwarePWM](./playground/AvrHardwarePWM)                                 | **ATmega, ATmel, Arduino, PWM** all about hardware PWM and demonstrating the modes with the Arduino UNO/ATmega328 |
| [#255 AvrHardwarePWM/ATtiny](./playground/AvrHardwarePWM/ATtiny)                   | **ATtiny, ATmel, Arduino, PWM** all about hardware PWM and demonstrating the modes with the ATtiny85 |
| [#217 BasicBuckAvrControl](./Electronics101/SwitchModePowerSupplies/BasicBuckAvrControl) | **Power, Arduino**        a simple buck converter circuit from first principles |
| [#288 BasicInvertingBuckBoostAvrControl](./Electronics101/SwitchModePowerSupplies/BasicInvertingBuckBoostAvrControl) | **Power, ATtiny, Arduino**   build and test an inverting buck-boost converter controlled by an ATtiny85 |
| [#262 BazzFuss](./Electronics101/GuitarEffects/BazzFuss)                           | **Guitar Effects, Audio**       the Bazz Fuss "chocolate noisette" - a super-minimalist overdrive/distortion/fuzz effect circuit |
| [#408 BBBreakout](./Electronics101/Power/BBBreakout)                               | **Power**                       a little breadboard power adapter and breakout with 5.5x2.1mm barrel jack, terminal block and XH2.54 connectors |
| [#133 BidirectionalLevelShifter](./Electronics101/BidirectionalLevelShifter)       | **FET**                         test a basic bi-directional 5/3.3V level shifter circuit |
| [#134 BidirectionalLevelShifterModule](./Electronics101/BidirectionalLevelShifterModule) | **FET**                   test a bi-directional 5/3.3V level shifter module |
| [#318 Bistable](./Electronics101/555Timer/Bistable)                                | **555 Timer**                   using the 555 timer as a bistable latch and button debouncer |
| [#412 BJT Comparator](./Electronics101/BJT/Comparator)                             | **BJT, Comparator**             investigating and testing a comparator design with discrete components |
| [#093 BJT CurrentSink](./Electronics101/BJT/CurrentSink)                           | **BJT, Power**                  test a BJT constant current sink circuit |
| [#094 BJT LongTail Pair](./Electronics101/BJT/LongTailPair)                        | **BJT, OpAmp**                  test the basic BJT "long-tail" differential amplifier circuit |
| [#138 BJT Monostable](./Electronics101/BJT/Monostable)                             | **BJT, RC**                     test a 2-transistor monostable multivibrator |
| [#378 BJT Phase Splitter](./Electronics101/BJT/PhaseSplitter)                      | **BJT, Signals**                simple unity-gain phase splitter in a little breadboard-compatible package |
| [#105 BJT SawTooth](./Electronics101/BJT/SawTooth)                                 | **BJT, Oscillators**            testing a simple BJT saw-tooth oscillator |
| [#140 BJT ZenerMode Effects](./Electronics101/BJT/ZenerModeEffects)                | **BJT, Zener, Oscillators**     playing around with some zener-mode sound effects |
| [#009 Blink](./playground/Blink)                                                   | **LED, Arduino**                the simplest blinking LED, with some electrical measurements thrown in |
| [#030 BlinkPrecision](./playground/BlinkPrecision)                                 | **LED, Timing, Arduino**        use a timer to perform a function on a precise schedule |
| [#386 BluePill](./STM32/BluePill)                                                  | **STM32**                       programming an ARM Cortex-M3 STM32F103C8T6 Blue Pill board with the Arduino IDE |
| [#425 BoldportClub/3x7](./BoldportClub/3x7)                                        | **Boldport, 7-Segment**         building the Boldport 3x7, Project #29, with custom flip-top layout so you can see inside this discrete 3-digit, 7-segment display |
| [#369 BoldportClub/ananas](./BoldportClub/ananas)                                  | **Boldport, Oscillators**       building the tropical end-of-year present from Boldport Club, Project #20 - ananas! |
| [#363 BoldportClub/binco](./BoldportClub/binco)                                    | **Boldport, PCB Design, LED, CMOS/TTL** BINCO is a little up or down "fidget" counter, Project #19 of the Boldport Club |
| [#409 BoldportClub/conehead](./BoldportClub/conehead)                              | **Boldport, Oscillators, CMOS/TTL, Audio** the Conehead is the fourth in the Boldport Club series of beautiful electronic critters, Project #24 April 2018 |
| [#269 BoldportClub/cordwood](./BoldportClub/cordwood)                              | **Boldport, PCB Design, LED**  the Cordwood Puzzle evokes an era of stuffing massive components into small spaces without a clear idea of where this is all heading! Introducing the Boldport Club Project #3 |
| [#270 BoldportClub/cordwood/aanimate](./BoldportClub/cordwood/aanimate)            | **Boldport, Cordwood, Arduino** run a demo animation using aaronjasso's Cordwood library |
| [#271 BoldportClub/cordwood/tuner](./BoldportClub/cordwood/tuner)                  | **Boldport, Cordwood, Arduino, Audio** use the Boldport Cuttle & Cordwood as a guitar tuner, with a custom input preamp |
| [#411 BoldportClub/cordwood-three](./BoldportClub/cordwood-three)                  | **Boldport, LED**               custom build of the Boldport Club Cordwood Puzzle III, Project #25, May 2018, with an archway layout and a spring-loaded LED trigger machanism |
| [#321 BoldportClub/cordwood-too](./BoldportClub/cordwood-too)                      | **Boldport, PCB Design, LED**   the Cordwood Puzzle returns! Boldport Club Project #13, May 2017 |
| [#322 BoldportClub/cordwood-too/FidgetCube](./BoldportClub/cordwood-too/FidgetCube) | **Boldport, Sensors, LED**     making a Fidget Cube controller for the Boldport Cordwood Too |
| [#257 BoldportClub/Emergency](./BoldportClub/Emergency)                            | **Boldport, PCB Design, Oscillators** pimp the Boldport Club Emergency kit (Project #2) .. now a LED blinky with 3 passives and a transistor (Esaki Effect) |
| [#340 BoldportClub/IxpandO](./BoldportClub/IxpandO)                                | **Boldport, PCB Design, Port Expander**  an input/output expansion board based on Microchip's MCP23017, BoldportClub Project #16. Demo program covers digital output and interrupt-driven input |
| [#311 BoldportClub/Juice](./BoldportClub/Juice)                                    | **Boldport, PCB Design, Power** building the Boldport Juice battery replacement kit (Project #12) |
| [#263 BoldportClub/ligemdio](./BoldportClub/ligemdio)                              | **Boldport, PCB Design, LED, BJT** an LED tester kit featureing a classic BJT constant current source. From The Boldport Club (Project #8) |
| [#419 BoldportClub/lite2sound-bc](./BoldportClub/lite2sound-bc)                    | **Boldport, PCB Design, Audio** building Lite2Sound Boldport Club Project #26 |
| [#345 BoldportClub/mostap](./BoldportClub/mostap)                                  | **Boldport, CMOS**              upgrading the tap to modern CMOS and MOSFET technology, circa 1975 - another Boldport Club retro classic. The mostap is a touch sensor using NAND-gate flip-flops and FET output drivers. |
| [#256 BoldportClub/Pease](./BoldportClub/Pease)                                    | **Boldport, PCB Design, LM331** a Bob Pease tribute, LM331 voltage-to-frequency kit from The Boldport Club (Project #1) |
| [#402 BoldportClub/pips](./BoldportClub/pips)                                      | **Boldport, CD4060**            rolling the BoldportClub Pips (Project #23) - a classic Elektor die circuit using the CD4060 ripple counter |
| [#290 BoldportClub/PissOff](./BoldportClub/PissOff)                                | **Boldport, PCB Design, NXP**   an angry barking blue-in-the-face mad proximity sensor - Boldport Club Project #9, November 2016 |
| [#316 BoldportClub/QSOPBreakout](./BoldportClub/QSOPBreakout)                      | **Boldport, Soldering**         all about soldering and the Boldport Club QSOP breakout board |
| [#325 BoldportClub/spoolt](./BoldportClub/spoolt)                                  | **Boldport, Soldering**         pimp my spoolt - the Boldport Club solder dispenser (Project #15, July 2017) |
| [#323 BoldportClub/stringy](./BoldportClub/stringy)                                | **Boldport, PIC, Audio**        building and playing (mainly playing) the Boldport Club Stringy (Project #14) |
| [#285 BoldportClub/tap](./BoldportClub/tap)                                        | **Boldport, PCB Design, CMOS/TTL** Harking back to an old Boldport project, which harks back to a 1974 Elektor article .. and the main IC (7400 NAND gate) is still available! |
| [#266 BoldportClub/TheCuttle](./BoldportClub/TheCuttle)                            | **Boldport, PCB Design, ATmega, ATmel, Arduino** the most beautiful Arduino-compatible board you will ever see. Another soldering kit from The Boldport Club (Project #6) |
| [#284 BoldportClub/TheGent](./BoldportClub/TheGent)                                | **Boldport, PCB Design, Bugs**  The Gent is Boldport Club Project #10 - a simple circuit on a beautiful board |
| [#251 BoldportClub/TheLady](./BoldportClub/TheLady)                                | **Boldport, PCB Design, Bugs**  a ladybird soldering and display kit from The Boldport Club (Project #4) |
| [#299 BoldportClub/TheMatrix](./BoldportClub/TheMatrix)                            | **Boldport, PCB Design, LED, AS1130** building The Matrix (Boldport Club project #11) is an I²C-controlled 24x5 LED matrix display, powered by an AMS AS1130 LED driver |
| [#357 BoldportClub/TheMonarch](./BoldportClub/TheMonarch)                          | **Boldport, PCB Design, Bugs, LFSR** the third in a series of beautiful electronic "bug" boards from the Boldport Club, Project #18 October 2017 |
| [#277 BoldportClub/Touchy](./BoldportClub/Touchy)                                  | **Boldport, EFM8, Sensors**     Touchy is a capacitive touch input device with on-board Sleepy Bee microcontroller (Boldport Club Project #7) |
| [#392 BoldportClub/whiteboard](./BoldportClub/whiteboard)                          | **Boldport, LM317, CD4060**     building the Whiteboard (Boldport Club project #22), a breadboard enhancer featuring variable and coin-cell power supplies and prototyping areas. Demonstrated with a 4-stage CD4060 ripple counter |
| [#385 BoldportClub/widlar](./BoldportClub/widlar)                                  | **723, Power, Oscillator**      hacking the BoldportClub Widlar (Project #21) to get the classic μA723 to do something other than voltage regulation (LED blinky) |
| [#162 BoostBuckConverterModule](./Electronics101/BoostBuckConverterModule)         | **Power**                       quick test of an LM2577S/LM2596S Boost/Buck Converter Module |
| [#280 BreadboardTransmitter](./Electronics101/FM/BreadboardTransmitter)            | **FM**                          build a simple 3-stage FM transmitter on a breadboard from a design by dazaro3 |
| [#089 BreatheLamp](./Electronics101/BreatheLamp)                                   | **OpAmp, LED**                  build and test a common LED visual effect circuit |
| [#211 BuckConverterModules](./Electronics101/BuckConverterModules)                 | **Power**                       test a range of low-cost buck converter modules, often using LM2596 |
| [#057 CapacitanceTester](./Electronics101/CapacitanceTester)                       | **LCD, RC, Arduino**            capacitor tester with LCD output |
| [#396 CapacitiveTouchOrgan](./playground/CapacitiveTouchOrgan)                     | **Audio, Sensors, MPR121**      a simple chromatic scale organ, controlled with a Freescale/NXP MPR121 Proximity Capacitive Touch Sensor and an Arduino |
| [#012 Capacitorial](./Electronics101/Capacitorial)                                 | **RC**                          graphing capacitor discharge with Processing |
| [#382 CD4046 VCO](./Electronics101/CD4046/VCO)                                     | **RC, CD4046, Oscillators**     audio range voltage-controlled oscillator using the CD4046 PLL/VCO IC |
| [#206 CD4047/AstableOscillator](./Electronics101/CD4047/AstableOscillator)         | **CMOS/TTL, Oscillators**       test the astable operating mode of the CD4047 |
| [#294 CD4060/CrystalOscillator](./Electronics101/CD4060/CrystalOscillator)         | **CMOS/TTL, Oscillators**       exploring the behaviour of the CD4060 ripple counter driven by a crystal oscillator |
| [#291 CD4060/MusicLightKit](./Electronics101/CD4060/MusicLightKit)                 | **CMOS**                        learning how to use the CD4060 14-Stage Ripple Carry Binary Counter by building a music/LED-effects kit |
| [#293 CD4060/RCOscillator](./Electronics101/CD4060/RCOscillator)                   | **CMOS, Oscillators**           exploring the behaviour of the CD4060 ripple counter driven by an RC oscillator |
| [#297 CD4070/Oscillator](./Electronics101/CD4070/Oscillator)                       | **CMOS, Oscillators**           examine a classic CD4070 oscillator design and variations |
| [#268 ChainBlocks](./playground/ChainBlocks)                                       | **Arduino**                     testing some "Chain Blocks" and demonstrate an XY Plotter block (with an MCP42010 digital potentiometer) by drawing the PrexLab logo on an Oscilloscope |
| [#170 ClapSwitchKit](./Electronics101/ClapSwitchKit)                               | **Oscillators, BJT, Logic Gates** build and analyse a simple clap switch circuit available as a kit |
| [#258 ClapSwitchKit2](./Electronics101/ClapSwitchKit2)                             | **Oscillators, BJT, Logic Gates** practice some Boldport-style soldering on yet-another clap switch kit |
| [#364 ClassicNokia](./playground/ClassicNokia)                                     | **Audio, Arduino**              just a quick transcription of the classic Nokia 3310 ringtone for Arduino |
| [#234 CMOSInverterOscillator](./Electronics101/CMOSInverterOscillator)             | **CMOS, Oscillators**           use a CD4096 to generate an oscillating waveform and plot the results |
| [#246 CMOSOscillators](./Electronics101/CMOSOscillators)                           | **CMOS, Oscillators**           testing a 4-pin CMOS oscillator component |
| [#180 ColpittsOscillator](./Electronics101/Oscillators/Colpitts)                   | **LC, Oscillators**             testing a basic Colpitts Oscillator circuit |
| [#371 CommonEmitterAmplifier](./Electronics101/BJT/CommonEmitterAmplifier)         | **BJT**                         all about BJT common-emitter amplifier biasing and class of operation |
| [#418 CommonEmitterHartley](./Electronics101/Oscillators/CommonEmitterHartley)     | **BJT, Oscillators**            build and test a BJT common-emitter Hartley oscillator |
| [#052 Comparator741](./Electronics101/Comparator741)                               | **OpAmp**                       demo LM741 OpAmp comparator mode (with PWM-to-analog side-topic) |
| [#278 ComponentTesterKit](./Equipment/ComponentTesterKit)                          | **Tools, Test Equipment, ATmega**  build and evaluate a popular ATMEAG328-based component tester kit |
| [#136 CounterModule](./playground/CounterModule)                                   | **CMOS, Arduino**               a general-purpose CD4017 counter module |
| [#141 CrystalTester](./Electronics101/CrystalTester)                               | **Radio, Oscillators**          a Colpitts Oscillator circuit for testing crystal oscillators with a frequency counter |
| [#168 CurrentSensorModule](./playground/CurrentSensorModule)                       | **Sensors, Arduino**            test an ACS712 current sensor module with display on a 5110 LCD |
| [#420 CuttleTalk](./BoldportClub/lite2sound-bc/CuttleTalk)                         | **Boldport, Audio, LiFi**       playing audio from a Boldport Cuttle (Arduino) over LiFi with lite2sound |
| [#130 DarlingtonTouchSwitch](./Electronics101/DarlingtonTouchSwitch)               | **Sensors, BJT**                test a Darlington-pair touch switch |
| [#414 Decade Programmable Resistor](./Electronics101/DecadeProgrammableResistor)   | **Test Equipment**              building an old-fashioned 7-digit decade programmable resistor with push-button control |
| [#352 Decoding ACARS](./SDR/DecodingACARS)                                         | **SDR, Radio**                  decoding ACARS with rtl_acars_ng and a R820T2+RTL2832U dongle on MacOSX |
| [#339 DelayKit](./Electronics101/GuitarEffects/DelayKit)                           | **Guitar, Audio**               build and test a PT2399-based analogue delay pedal kit |
| [#353 DFlipFlop](./Electronics101/DigitalLogic/DFlipFlop)                          | **Logic Gates, CMOS/TTL**       building a clocked D Flip-flop with 74LS00 NAND gates |
| [#301 DHT11/Basics](./playground/DHT11/Basics)                                     | **Sensors, Arduino**            test basic temperature and humidity readings with the DHT11 sensor |
| [#229 Dice](./Electronics101/555Timer/Dice)                                        | **555 Timer, CMOS**             a 555/4017-based dice circuit with slow-down and auto power-off |
| [#393 DicksonChargePump](./playground/DicksonChargePump)                           | **Arduino, Power**              Zener-regulated 12V Dickson Charge Pump driven with Arduino PWM |
| [#240 DigitalInputWithAnalogPins](./playground/DigitalInputWithAnalogPins)         | **Arduino**                     demonstrate how analog pins can also be used as a digital GPIO |
| [#319 DigitalLogicClock](./Electronics101/555Timer/DigitalLogicClock)              | **555 Timer, CMOS/TTL**         build a flexible, low-frequency digital logic clock module |
| [#259 DigitalPots/M62429](./Electronics101/DigitalPots/M62429)                     | **Arduino, Digital Pot, M62429** control the M62429 dual channel volume control with an Arduino |
| [#261 DigitalPots/MCP4017](./Electronics101/DigitalPots/MCP4017)                   | **Arduino, Digital Pot, MCP4017** control the MCP4017 single 7-Bit I²C digital potentiometer with an Arduino |
| [#264 DigitalPots/MCP42010](./Electronics101/DigitalPots/MCP42010)                 | **Arduino, Digital Pot, MCP42010** control the MCP42010 dual 10kΩ digital potentiometer with an Arduino and hardware SPI |
| [#370 DigitaSwitch/TS3A5018](./Electronics101/DigitaSwitch/TS3A5018)               | **Arduino, Digital Switch, 555 Timer**  testing the TS3A5018 Quad SPDT Analog Switch with a simple 555 timer and Arduino demo |
| [#110 DiodeLogic/AND](./Electronics101/DiodeLogic/AND)                             | **Diode, Logic Gates**          test the basic diode-logic AND gate |
| [#109 DiodeLogic/OR](./Electronics101/DiodeLogic/OR)                               | **Diode, Logic Gates**          test the basic diode-logic OR gate |
| [#348 DLatch](./Electronics101/DigitalLogic/DLatch)                                | **Logic Gates, CMOS/TTL**       building a D Latch with 74LS00 NAND gates |
| [#201 DoorbellKit](./Electronics101/555Timer/DoorbellKit)                          | **555 Timer, Oscillators**      another two-tone doorbell using a 555 timer oscillator |
| [#407 DPS3005BenchPowerSupply](./Equipment/DPS3005BenchPowerSupply)                | **Power, Tools**                building an AC-powered 32V/5A variable bench power supply based on the DPS3005 DC power supply module and rectified step-down transformer |
| [#219 DS18S20/OneWireReading](./playground/DS18S20/OneWireReading)                 | **Sensors, Arduino**            basic interrogation of a DS18S20 using 1-wire protocol |
| [#166 DS3231RTC/TimeDemo](./playground/DS3231RTC/TimeDemo)                         | **RTC, Arduino**                prints the system time synced from the RTC to the serial output |
| [#188 EEPROM/AT24C02/BasicReadWrite](./playground/EEPROM/AT24C02/BasicReadWrite)   | **EEPROM, Arduino**             basic read/write operations to external EEPROM (AT24C02) with the Wire library |
| [#314 EEPROM/AT28C16/PEProgrammer](./playground/EEPROM/AT28C16/PEProgrammer)       | **EEPROM, Arduino**             programming an AT28C16 64k EEPROM with an Arduino and MCP23S17 16-bit port expander |
| [#051 El Jarabe Tapatío](./playground/JarabeTapatio)                               | **Audio, Arduino**              play The Mexican Hat Dance on a piezo buzzer with LM 386 amplification |
| [#038 ElectretADC](./playground/ElectretADC)                                       | **Audio, Arduino**              convert electret signal to a full range analog input with an LM324 preamp and plot the raw and aplified signals |
| [#037 ElectretTrigger](./playground/ElectretTrigger)                               | **Sensors, Audio, OpAmp, Arduino** uses an electret microphone and LM324 amplifier to trigger action when over audio threshold |
| [#088 ElectronicClockKit](./Electronics101/ElectronicClockKit)                     | **LCD, Kit**                    build and investigate a commercially available "electronic clock" kit |
| [#194 ESP8266/DIYDevBoard](./ESP8266/DIYDevBoard)                                  | **ESP8266**                     a DIY devboard for an ESP-01 ESP8266 |
| [#344 ESP8266/micropython/GettingStarted](./ESP8266/micropython/GettingStarted)    | **ESP8266, MicroPython**        getting MicroPython up and running with an ESP-01 ESP8266 |
| [#342 ESP8266/MorseBlinky](./ESP8266/MorseBlinky)                                  | **ESP8266**                     building code for an ESP-01 with the ESP8266 core for Arduino and demonstrate with a simple morse code blinker |
| [#343 ESP8266/Sensors/DHT11](./ESP8266/Sensors/DHT11)                              | **ESP8266, Sensors**            reading temperature and humidity with a DHT11 sensor and ESP-01, coding with ESP8266 core for Arduino |
| [#154 ESP8266/SerialTest](./ESP8266/SerialTest)                                    | **ESP8266**                     first test of an ESP8266 module - serial communication to the SoC |
| [#155 ESP8266/SerialTest/ruby](./ESP8266/SerialTest/ruby)                          | **ESP8266, ruby**               exercising ESP8266 serial communications with Ruby |
| [#274 FY3200S](./Equipment/FY3200S)                                                | **Tools, Test Equipment**       testing out the Feeltech FY3200S digital function generator |
| [#310 FM/TEA5767](./Electronics101/FM/TEA5767)                                     | **FM, Arduino**                 controlling the TEA5767 low-power FM stereo radio chip with an Arduino |
| [#225 FQ777-954/TearDown](./Kinetics/FQ777-954/TearDown)                           | **Drones, Radio**               teardown an FQ777-954 nano drone and figure out as much of the technical design as possible |
| [#223 Fritzing Parts](./FritzingParts)                                             | **EDA**                         my collection of custom Fritzing Parts |
| [#207 FrequencyCounter](./Electronics101/FrequencyCounter)                         | **CMOS, Oscillators**           test a CMOS frequency counter circuit with 100Hz - 5MHz range |
| [#295 FrequencyCounterKit](./Equipment/FrequencyCounterKit)                        | **PIC, Tools, Test Equipment, Oscillators** build and test a common PIC-based frequency counter kit |
| [#018 FretBoard](./FretBoard)                                                      | **LED Array, Arduino**          a multi-project build status indicator, that pulls software build status from the net and animates the status of up to 24 projects with an LED array |
| [#053 FunctionGenerator324](./Electronics101/FunctionGenerator324)                 | **OpAmp, Oscillators**          LM324 configured as a low-frequency square, triangle, sine, and cosine function generator |
| [#282 FunctionGeneratorKit](./Equipment/FunctionGeneratorKit)                      | **Oscillators, Tools, Test Equipment, XR2206**  build and test a function generator kit based on the XR-2206 monolithic function generator |
| [#220 GccToolchain](./playground/GccToolchain)                                     | **avr-lib, avrdude**            programming an Arduino with C and a command line |
| [#245 GeneralCurveTracer](./Electronics101/GeneralCurveTracer)                     | **BJT, Oscillators**            test a DC-powered general curve tracer circuit |
| [#241 GeneralPurpose358](./Electronics101/AudioAmps/GeneralPurpose358)             | **OpAmp, Audio**                test a general-purpose LM358 amplifier circuit |
| [#050 Girabot](./Girabot)                                                          | **Sensors, OpAmp, Arduino**     EE40LX Electronic Interfaces robot project |
| [#338 GlowBall](./Kraft/GlowBall)                                                  | **LED, Oscillators, Power**     building LED effects for a Glass Eye Studio Celestial Planet Weight |
| [#298 GoldenHind](./Kraft/GoldenHind)                                              | **Kraft**                       building a mini metal model of the Golden Hind |
| [#387 GpsBasics](./playground/GpsBasics)                                           | **GPS, Arduino**                using a NEMA-compatible GPS module for time and location with an Arduino |
| [#368 GranularSynth](./playground/GranularSynth)                                   | **Audio, Arduino**              building an ATmega328 granular synth module in an Altoids can ..  because granular synthesis is a basically how they make Altoids, right? |
| [#098 GuitarHeadphoneAmp](./Electronics101/AudioAmps/GuitarHeadphoneAmp)           | **OpAmp, Audio**                an LM386 fixed-gain guitar headphone amp |
| [#249 GuitarPracticeAmp](./Electronics101/AudioAmps/GuitarPracticeAmp)             | **OpAmp, Audio**                single-channel 10W guitar practice amplifier based on the TDA2050 |
| [#403 GY560](./Equipment/GY560)                                                    | **Radio, Tools, Test Equipment**       checking out the GY560 Frequency Counter |
| [#198 HallEffectSwitch](./Electronics101/HallEffectSwitch)                         | **Sensors**                     testing a Hall effect switch |
| [#005 HeartQuotes](./playground/HeartQuotes)                                       | **LCD, Ethernet, Arduino**      press a button to get a quote from the net and display on an LCD |
| [#142 HighFrequencyOpAmpOscillators](./Electronics101/HighFrequencyOpAmpOscillators) | **OpAmp, Oscillators**         how fast can you push an Op-Amp oscillator? |
| [#043 HitTheLights](./playground/HitTheLights)                                     | **LCD, Human Input, Arduino**   simple LED game with LCD output and interrupt-driven button input |
| [#410 HomopolarJouleThiefBlinky](./Kinetics/HomopolarJouleThiefBlinky)             | **Kinetics, LED, Oscillators**  a totally Rube-Goldberg contraption for blinking an LED with a AAA battery, homopolar motor and joule thief mechanisms |
| [#203 HomopolarMotor](./Kinetics/HomopolarMotor)                                   | **Kinetics**                    build a basic homopolar motor |
| [#397 I2CScanner](./playground/I2CScanner)                                         | **I2C, Arduino**                scanning for I²C devices with an Arduino |
| [#146 InvertingChargePump](./Electronics101/555Timer/InvertingChargePump)          | **555 Timer, Power**            test an inverting charge pump circuit based on a 555 timer |
| [#006 It's Better With Bacon](./playground/BetterWithBacon)                        | **LCD, Arduino**                simple LCD test |
| [#056 JoystickServoControl](./playground/JoystickServoControl)                     | **Human Input, Arduino**        controlling two servos with a joystick |
| [#303 KeyboardMatrixModule](./playground/KeyboardMatrixModule)                     | **Arduino, LED, Human Input**   demo a simple pushbutton/LED matrix module |
| [#304 KeyboardMatrixModule/KeyMatrixInput](./playground/KeyboardMatrixModule/KeyMatrixInput)     | **Arduino, Human Input** demo multiplexed key input on a simple pushbutton/LED matrix module and how to use INPUT_PULLUP |
| [#305 KeyboardMatrixModule/LedControl](./playground/KeyboardMatrixModule/LedControl)             | **Arduino, LED**         demo controlling the LEDs on a simple pushbutton/LED matrix module |
| [#306 KeyboardMatrixModule/SwitchInterrupts](./playground/KeyboardMatrixModule/SwitchInterrupts) | **Arduino, Human Input** demo interrupt-driven switch input on a simple pushbutton/LED matrix module and how to use the EnableInterrupt library |
| [#227 KnightRider](./Electronics101/555Timer/KnightRider)                          | **555 Timer, CMOS, LED**        the familiar "Knight-Rider" LED circuit using a 555 and 4017 |
| [#324 Labrador](./Equipment/Labrador)                                              | **Tools, Test Equipment**       first look at the EspoTek Labrador USB "lab-on-a-board" hardware and software |
| [#422 LaserTapeMeasure](./playground/VL53L0X/LaserTapeMeasure)                     | **Sensors, Arduino, LCD**       using a VL53L0X ranging sensor to make a short-range laser tape measure with an Arduino with Nokia 5110 display |
| [#365 Lcd5110/AdafruitHardwareSPI](./playground/Lcd5110/AdafruitHardwareSPI)       | **LCD, Arduino**                a quick Nokia 5110 LCD test using hardware SPI and the Adafruit PCD8544 library |
| [#366 Lcd5110/AdafruitSoftwareSPI](./playground/Lcd5110/AdafruitSoftwareSPI)       | **LCD, Arduino**                a quick Nokia 5110 LCD test using software SPI and the Adafruit PCD8544 library |
| [#085 Lcd5110/BareBack](./playground/Lcd5110/BareBack)                             | **LCD, Arduino**                driving a Nokia 5110 LCD Display with an Arduino and the raw command set |
| [#149 Lcd5110/JuliansU8glibDemo](./playground/Lcd5110/JuliansU8glibDemo)           | **LCD, Arduino**                quick test drive of Julian Ilett's 5110 LCD demo with the u8glib library |
| [#398 LCD I2C Adapter](./playground/LCD/I2CAdapter)                                | **LCD, I2C**                    using an I²C adapter to reduce the Arduino pins needed to drive an LCD |
| [#195 LCResonator](./Electronics101/LCResonator)                                   | **Oscillators, LC**             measure the resonant frequency of an LC circuit or inductance of an inductor  |
| [#034 LDRComparator](./Electronics101/LDRComparator)                               | **Sensors, OpAmp, Arduino**     low-light/proximity Trip Detector demonstration using LM324 and LDR/Wheatstone Bridge sensor |
| [#047 LDRStereoTripDetector](./Electronics101/LDRStereoTripDetector)               | **OpAmp**                       demo LM324 OpAmp as threshold trigger for stereo LDR/Wheatstone Bridge sensor |
| [#058 Led4Digit7Segment](./playground/Led4Digit7Segment)                           | **7-Segment, Arduino**          overview of driving a 4-digit 7-segment display |
| [#080 Led4Digit7Segment/DoubleShift](./playground/Led4Digit7Segment/DoubleShift)   | **7-Segment, CMOS/TTL, Arduino**    driving a 4-Digit 7-Segment display with only 3 pins, using two 74HC595 shift registers and some NPN BJTs |
| [#081 Led4Digit7Segment/DoubleShiftWithFETs](./playground/Led4Digit7Segment/DoubleShiftWithFETs) | **7-Segment, CMOS/TTL, Arduino** driving a 4-Digit 7-Segment display with only 3 pins, using two 74HC595 shift registers and some n-channel FETs |
| [#078 Led4Digit7Segment/SingleShift](./playground/Led4Digit7Segment/SingleShift)   | **7-Segment, CMOS/TTL, Arduino**    driving a 4-digit 7-segment display with a shift register and a few BJTs |
| [#199 LED7Segment/CD4026BucketBrigade](./playground/LED7Segment/CD4026BucketBrigade) | **7-Segment, CMOS, Arduino**  a CD4026 bucket-brigade for driving multiple 7-segment displays |
| [#196 LED7Segment/CD4026Drive](./playground/LED7Segment/CD4026Drive)               | **7-Segment, CMOS, Arduino**    driving a 7-segment display with CD4026 Counter |
| [#308 LED7Segment/CombinationalLogicDriver](./playground/LED7Segment/CombinationalLogicDriver) | **7-Segment, CMOS/TTL, Arduino** - dust off some combinational logic methods and build a 8421-BCD to 7-segment LED driver with 7400 series logic |
| [#001 LED7Segment/DirectDrive](./playground/LED7Segment/DirectDrive)               | **7-Segment, Arduino**          test a 7-segment common cathode display |
| [#177 LED7Segment/ShiftDrive](./playground/LED7Segment/ShiftDrive)                 | **7-Segment, CMOS/TTL, Arduino**    test control of a 7-segment display via a 74HC595 shift register |
| [#178 LED7Segment/ShiftDriveModule](./playground/LED7Segment/ShiftDriveModule)     | **7-Segment, CMOS/TTL, Arduino, PCB** a custom 7-segment display module PCB with 74HC595 shift register interface |
| [#189 LED7Segment/ShiftDriveSPI](./playground/LED7Segment/ShiftDriveSPI)           | **7-Segment, CMOS/TTL, Arduino, SPI** using SPI to control a 7-segment display via a 74HC595 shift register |
| [#007 LEDArrayDemos](./LEDArrayDemos)                                              | **LED Array, Arduino**          Intro and Setup.. I bought some [WS2811-based LED Strips](http://www.aliexpress.com/item/IP68-12mm-WS2811-as-WS2801-led-pixel-module-IP68-waterproof-DC5V-full-color-RGB-50pcs-a/1932649085.html) with a specific project in mind. But first, need to get them working... |
| [#003 LEDChaser](./playground/LedChaser)                                           | **LED, Arduino**                blinks a series of 12 LEDs in a coninuous loop |
| [#103 LedControlDemo](./playground/LED8x8/LedControlDemo)                          | **8x8 LED, Arduino**            test driving and LED matrix with the LedControl library |
| [#173 LEDCubes/Mini4](./playground/LEDCubes/Mini4)                                 | **LED, CMOS/TTL, Arduino**          a mini 64 LED cube with an Atmel328 and 3 x 74HC595 register interface |
| [#231 LEDDimmer/CurrentRegulator](./Electronics101/LEDDimmer/CurrentRegulator)     | **LED, Power**                  test a current-regulator style LED dimmer circuit |
| [#232 LEDDimmer/555PWM](./Electronics101/LEDDimmer/555PWM)                         | **LED, Power, 555 Timer**       test a PWM LED dimmer circuit using a 555 timer |
| [#067 LEDLamp](./Electronics101/LEDLampAC)                                         | **Power, LED**                  build and analyse a commercial LED lamp kit with capacitive power supply |
| [#209 LedPanelDisplay72R02](./playground/LedPanelDisplay72R02)                     | **LED, Arduino**                test a 7-digit & 7-status indicator LED display |
| [#224 LEDStrobeKit](./Electronics101/LEDStrobeKit)                                 | **LED, 555 Timer, CMOS**        build and analyse a common LED strobe kit |
| [#079 LedTemperatureDisplay](./playground/LedTemperatureDisplay)                   | **Sensors, LM35, 7-Segment, Arduino** measure ambient temperature using LM35 and display with a 4-digit 7-segment LED unit |
| [#179 LEDx16Module](./playground/LEDx16Module)                                     | **CMOS/TTL, SMD, Arduino**      a custom 16 LED SMD PCB with 74HC595 shift register interface |
| [#065 LevelIndicatorLM3915](./playground/LevelIndicatorLM3915)                     | **LM3915, Arduino**             Driving an LM3915 10-segment display with a single Arduino pin |
| [#010 LightOrNot](./playground/LightOrNot)                                         | **Sensors, Arduino**            uses an LDR to adjust the blink rate of an LED |
| [#421 LimeSDR/FirstLook](./SDR/LimeSDR/FirstLook)                                  | **SDR**                         unboxing and first test of the LimeSDR-USB software-defined radio with MacOSX host |
| [#416 LineFollowerKit](./Kinetics/LineFollowerKit)                                 | **Sensors, Kinetics, OpAmp**    building the D2-5 Intelligent Line Tracking Car Kit - a nice demonstration of a simple feedback control system with an LM358 op-amp |
| [#350 LiteWings](./Kraft/CircuitScribe/LiteWings)                                  | **Conductive Ink**              learning about conductive ink with the CircuitScribe LiteWings kit |
| [#095 LittleGem/A386](./Electronics101/AudioAmps/LittleGem)                        | **OpAmp, Audio**                a basic Smokey-inspired LM386 guitar power amp |
| [#160 LM324/SplitterBuffer](./Electronics101/LM324/SplitterBuffer)                 | **OpAmp**                       demonstrate load-independance of an LM324 buffer and signal splitter |
| [#384 LM723/HighVoltageRegulator](./Electronics101/LM723/HighVoltageRegulator)     | **Power, Regulator, LM723**     playing with the basic high voltage output circuit for the LM723 voltage regulator |
| [#383 LM723/LowVoltageRegulator](./Electronics101/LM723/LowVoltageRegulator)       | **Power, Regulator, LM723**     playing with the basic low voltage output circuit for the LM723 voltage regulator |
| [#191 LowVoltageGlowingLEDs](./Electronics101/LowVoltageGlowingLEDs)               | **BJT, LED, Oscillators, Power** a dual-LED "glowing" oscillator from a 1.5V supply |
| [#423 MakerUno](./playground/MakerUno)                                             | **Arduino**                     checking out the Maker UNO, a feature-packed Arduino-compatible board from Cytron in Penang, Malaysia |
| [#101 MaxRawDemo](./playground/LED8x8/MaxRawDemo)                                  | **8x8 LED, Arduino**            drive an 8x8 LED Matrix with a MAX7219 chip an raw SPI commands |
| [#358 MC34063/ModuleKit](./Electronics101/SwitchModePowerSupplies/MC34063/ModuleKit) | **Power**                     build and test an MC34063-based boost converter |
| [#335 MCP2200/Chaser](./Electronics101/MCP2200/Chaser)                             | **UART, USB, LED**              using the MCP2200 GPIO from MacOSX. With great power comes great responsibility to blink LEDs |
| [#334 MCP2200/DevKit](./Electronics101/MCP2200/DevKit)                             | **UART, USB**                   exploring the capabilities of the MCP2200 USB-to-UART and program it from a MacOSX host |
| [#313 MCP23S17](./Electronics101/MCP23S17)                                         | **Arduino, Port Expander**      investigate and test the MCP23S17 16-Bit I/O Expander with serial interface |
| [#040 MeLEDy](./Electronics101/MeLEDy)                                             | **Audio**                       use an electret microphone to light a series of LEDs in proportion to volume |
| [#252 MessageWaiting](./Electronics101/555Timer/MessageWaiting)                    | **LED, 555 Timer**              two-LED flasher with a 555 and minimal components - turned into a "message waiting" indicator with some free-wired SMD construction |
| [#372 MilliVoltmeterDIY](./Equipment/MilliVoltmeterDIY)                            | **ATmega, ADC, Tools, Test Equipment** an ATmega328-based millivolt meter based on a design by Scullcom Hobby Electronics. Uses an LTC2400 ADC and LT1019 voltage reference |
| [#391 MilliVoltmeterDIY PCB and Enclosure](./Equipment/MilliVoltmeterDIY/CustomBoardAndEnclosure) | **ATmega, ADC, Tools, Test Equipment**  custom PCB and enclosure for the ATmega328-based millivolt meter based on a design by Scullcom Hobby Electronics. Uses an LTC2400 ADC and LT1019 voltage reference |
| [#230 MinimalLCOscillator](./Electronics101/MinimalLCOscillator)                   | **LC, Oscillators**             test an LC oscillator of just 5 components |
| [#326 Mixers](./Electronics101/Mixers)                                             | **Radio, Mixers**                  all about frequency mixers |
| [#327 Mixers/RFDiodeRing](./Electronics101/Mixers/RFDiodeRing)                     | **Radio, Mixers**                  a diode ring double-balanced frequency mixer |
| [#150 ML741](./Electronics101/ML741)                                               | **OpAmp**                       an LM741-style OpAmp built with discrete components |
| [#151 ML741/Comparator](./Electronics101/ML741/Comparator)                         | **OpAmp**                       test a comparator circuit with the ML741 discrete component opamp |
| [#158 ML741/Inverter](./Electronics101/ML741/Inverter)                             | **OpAmp**                       test an inverter circuit using the ML741 discrete component opamp |
| [#159 ML741/InvertingAmplifier](./Electronics101/ML741/InvertingAmplifier)         | **OpAmp**                       test an inverting amplifier circuit using the ML741 discrete component opamp |
| [#161 ML741/NonInvertingAmplifier](./Electronics101/ML741/NonInvertingAmplifier)   | **OpAmp**                       test a non-inverting amplifier circuit using the ML741 discrete component opamp |
| [#157 ML741/VoltageFollower](./Electronics101/ML741/VoltageFollower)               | **OpAmp**                       test a voltage follower/buffer circuit with the ML741 discrete component opamp |
| [#082 MobileRFDetectorKit](./Electronics101/EMRDetection/MobileRFDetectorKit)      | **Radio**                          build and investigate a commercially available "mobile phone signal" detector kit |
| [#017 Monostable](./Electronics101/555Timer/Monostable)                            | **555 Timer**                   basic monostable mode using an Arduino and processing to plot the output |
| [#075 Monostable122](./Electronics101/Monostable122)                               | **CMOS/TTL**                    simple pulse trigger using 74LS122 monostable with external timing configuration |
| [#076 MonostablePulseExtender](./playground/MonostablePulseExtender)               | **CMOS/TTL, Arduino**           test the behaviour of a 74LS122 monostable with external timing configuration and plot the results with an Arduino |
| [#046 MotorControlPWM](./playground/MotorControlPWM)                               | **Motors, Arduino**             tests PWM speed control of a DC motor driven by an Arduino |
| [#218 MPU6050/AccelGyroTest](./playground/MPU6050/AccelGyroTest)                   | **Sensors, MPU-6050, Arduino**  first test of an Invensense MPU-6050 3-Axes Accelerometer Gyroscope Module |
| [#315 MT3608/VariableBoost](./Electronics101/SwitchModePowerSupplies/MT3608/VariableBoost) | **Power** testing the canonical variable boost circuit using the MT3608 High Efficiency 1.2MHz 2A Step Up Converter |
| [#190 MultiSlaveSPI](./playground/MultiSlaveSPI)                                   | **SPI, Arduino**                using SPI to control multiple devices that support an SPIish interface |
| [#226 MusicBoxKit](./Electronics101/MusicBoxKit)                                   | **Music, Arduino**              build and test a Music Box kit, and run a demonstration under Arduino control |
| [#156 MSO5074FG_unboxing](./Equipment/MSO5074FG_unboxing)                          | **Tools, Test Equipment, Oscilloscope** unboxing and first tests of a Hantek MSO5074FG oscilloscope |
| [#415 Nixie Power Supply - 555 Timer Version](./Electronics101/555Timer/NixiePowerSupply) | **Power, Nixie, 555 Timer**   using a 555 boost converter to test some Nixie IN3 and IN14 tubes |
| [#377 Nokia 5110 Shield](./playground/Lcd5110/DIYShield)                           | **LCD, Arduino**                putting a Nokia 5110 on an Arduino Uno shield for no-fuss prototyping |
| [#036 NonInverting324](./Electronics101/NonInverting324)                           | **OpAmp**                       demo LM324 OpAmp non-inverting DC gain mode |
| [#072 NOR7402](./Electronics101/NOR7402)                                           | **CMOS/TTL, Arduino**           demo the 74LS02 Quad 2-input NOR gate with an Arduino |
| [#114 NORGateOscillator](./Electronics101/NORGateOscillator)                       | **CMOS/TTL, Oscillators, Arduino** test a low-speed square wave oscillator using NOR gates |
| [#176 nRF24Breakout](./Electronics101/nRF24Breakout)                               | **nRF24, PCB**                  a simple PCB breadboard adapter for 8-pin nRF24 modules |
| [#187 nRF24/PingPong](./playground/nRF24/PingPong)                                 | **nRF24, Arduino**              two Arduino's entertaining themselves with a game of "ping pong" over nRF24L01+ 2.4GHz RF |
| [#367 nRF24/Scanner](./playground/nRF24/Scanner)                                   | **nRF24, Arduino**              a 2.4GHz channel scanner for the nRF24l01+ with Nokia 5110 LCD display |
| [#087 OLED/SSD1306BareBack](./playground/OLED/SSD1306BareBack)                     | **OLED, Arduino**               driving a monochrome 128x64 OLED Display with an Arduino and the raw command set |
| [#086 OLED/SSD1306WithAdaFruitLibraries](./playground/OLED/SSD1306WithAdaFruitLibraries) | **OLED, Arduino**         running the AdaFruit example program with a monochrome 128x64 OLED Display |
| [#122 OpAmpTimer](./Electronics101/OpAmpTimer)                                     | **OpAmp, Timer**                testing an OpAmp timer switch |
| [#336 Oscillators/ComparatorRelaxation](./Electronics101/Oscillators/ComparatorRelaxation) | **OpAmp, Oscillators**  test a classic comparator-based relaxation oscillator, modified for single-supply LM358 OpAmp |
| [#213 OSHChip/blinky](./OSHChip/blinky)                                            | **ARM, OSHChip**                first tests of the OSHChip nRF51822-CFAC-A0 in DIP16 packaging |
| [#214 OSHChip/GccToolchain](./OSHChip/GccToolchain)                                | **ARM, gcc, OSHChip**           can I build a program for the OSHChip using the gcc toolchain and Nordic Semi SDK on MacOSX? |
| [#216 OSHChip/LEDx16Module](./OSHChip/LEDx16Module)                                | **OSHChip, SPI**                driving an SPI LED module with the OSHChip |
| [#215 OSHChip/YottaToolchain](./OSHChip/YottaToolchain)                            | **ARM, gcc, yotta, OSHChip**    build a simple program using the Official Yotta target for OSHChip and gcc on MacOSX |
| [#121 PeakDetector](./Electronics101/PeakDetector)                                 | **OpAmp, RC**                   test an OpAmp-based peak detector circuit |
| [#247 pedalShieldUno](./playground/pedalShieldUno)                                 | **DSP, Guitar, Arduino**        build and test a genuine pedalSHIELD UNO Arduino-based guitar effects pedal |
| [#250 pedalShieldUno/AudioDSP](./playground/pedalShieldUno/AudioDSP)               | **DSP, Guitar, Arduino**        test and develop the AudioDSP library for programming the pedalSHIELD Uno |
| [#331 PIC/GettingBlinky](./PIC/GettingBlinky)                                      | **PIC, LED**                    getting up and running building a PIC assembler project on MacOSX with a PIC12F675 development board. Let's get Blinky! |
| [#390 PIC/GettingBlinky/UsingC](./PIC/GettingBlinky/UsingC)                        | **PIC, LED**                    getting up and running building XC8 C projects on MacOSX and a PIC12F675. Let's get Blinky again! |
| [#248 PierceGateOscillator](./Electronics101/PierceGateOscillator)                 | **Oscillators, Crystal**        build and test a 4.27 MHz Pierce Gate Oscillator circuit using a 74LS14 schmitt inverter |
| [#242 PierceOscillator](./Electronics101/PierceOscillator)                         | **Oscillators, Crystal**        test a Pierce Oscillator made with a minimum of components |
| [#376 PiezoVibrationDetector](./playground/PiezoVibrationDetector)                 | **Arduino, Piezo**              counting beats per minute with a piezo tap sensor and an Arduino/ATmega328 analog comparator |
| [#401 Pixie](./Radio/pixie)                                                        | **Radio**                          research the history and variants of the Pixie QRP transceiver, and build a basic Pixie 4.3 kit on 40m |
| [#090 PlotNValues](./playground/PlotNValues)                                       | **Arduino, Processing**         generic script to sample up to 6 analog inputs and stream the data to serial in ASCII format for plotting with Processing |
| [#183 PolarityTester](./Electronics101/PolarityTester)                             | **Inverter, CMOS**              demonstrate a polarity-testing circuit |
| [#193 PovShakeStickKit](./Electronics101/PovShakeStickKit)                         | **8051, LED**                   build and investigate an AT89S52-based "shake stick" kit |
| [#330 Power/Any2AnyPowerPack](./Electronics101/Power/Any2AnyPowerPack)             | **Power**                       a 2.1mm DC adapter pack with battery bypass and any-polarity to any-polarity connectors |
| [#165 Power2662Inverter](./Electronics101/Power2662Inverter)                       | **Power**                       test a negative 5V power supply using the LM2662 Switched Capacitor Voltage Converter |
| [#026 Power317](./Electronics101/Power317)                                         | **Power**                       test/graph an adjustable voltage supply built with the LM317 Adjustable Regulator |
| [#092 Power317CC](./Electronics101/Power317CC)                                     | **Power**                       test a constant current power supply built with the LM317 |
| [#027 Power7805](./Electronics101/Power7805)                                       | **Power**                       test and graph a voltage supply built with an LM7805 5V Regulated Supply |
| [#153 PowerAMS1117](./Electronics101/PowerAMS1117)                                 | **Power**                       test an AMS1117 3.3V linear regulator |
| [#060 PowerBreadboard5V](./Electronics101/PowerBreadboard5V)                       | **Power**                       custom regulated 5V power supply module for standard breadboard |
| [#329 PowerConnectors](./Electronics101/Connectors/Power)                          | **Power**                       obsessing over all manner of DC power connectors |
| [#152 PowerLD1117](./Electronics101/PowerLD1117)                                   | **Power**                       test an LD1117 3.3V linear regulator |
| [#028 PowerMB102](./Electronics101/PowerMB102)                                     | **Power**                       demo and test a commercial 3.3/5V MB102 breadboard power supply unit |
| [#182 PowerSupply317Kit](./Electronics101/PowerSupply317Kit)                       | **Power**                       build and test a mains-powered 1.25V-12V DC LM317 power supply kit |
| [#029 PowerZener](./Electronics101/PowerZener)                                     | **Power**                       test and graph a power supply regulated with a 1N4733 zener diode |
| [#019 Popcorn](./playground/Popcorn)                                               | **Audio, Arduino**              How to make a piezo buzzer even more annoying? Make it play popcorn! |
| [#004 Pushbutton LED switch](./playground/PushbuttonLED)                           | **LED, Arduino**                Momentary push button switch is used to toggle the LED on and off |
| [#233 PWM/GeneralPurposeHighSideController](./Electronics101/PWM/GeneralPurposeHighSideController) | **PWM, 555 Timer, Oscillators, Power**  build and test a general-purpose high-side PWM controller |
| [#025 Quad Latch](./Electronics101/QuadLatch)                                      | **CMOS/TTL**                    graph the basic operation of the 74LS75 4-bit bistable latch |
| [#073 QuadNOR](./Electronics101/QuadNOR)                                           | **CMOS/TTL, Arduino**           demo simple cascading NOR gate logic with the 74LS02 and an Arduino |
| [#115 R2RDAC](./playground/R2RDAC)                                                 | **Arduino**                     build and test a 16-bit R2R-ladder digital to analog converter with shift register interface |
| [#035 RangeFinder](./playground/RangeFinder)                                       | **Sensors, Arduino, HC-SR04**   proximity/distance measurement with an HC-SR04 untrasonic ranging module |
| [#049 RCOscillator](./Electronics101/RCOscillator)                                 | **BJT, RC, Oscillators**        simple RC/transistor multistable vibrator |
| [#332 RCPhaseShiftBJT](./Electronics101/Oscillators/RCPhaseShiftBJT)               | **BJT, RC, Oscillators**        testing an RC phase-shift oscillator using a BJT amplifier |
| [#129 RelaxationJouleThief](./Electronics101/RelaxationJouleThief)                 | **Power, RLC, Oscillators**     test a "joule thief" circuit based on a relaxation oscillator |
| [#055 RelayControlTest](./playground/RelayControlTest)                             | **Servo, Arduino**              quick test to drive a motor with a common relay using NPN switching circuit under Arduino control |
| [#054 RelayModuleTest](./playground/RelayModuleTest)                               | **Servo, Arduino**              quick test of a common relay board to switch a motor under Arduino control |
| [#024 ResistorTransistorLogic/AND](./Electronics101/ResistorTransistorLogic/AND)   | **BJT, RTL, Logic Gates**       test the basic resistor-transistor logic AND gate  |
| [#023 ResistorTransistorLogic/NAND](./Electronics101/ResistorTransistorLogic/NAND) | **BJT, RTL, Logic Gates**       test the basic resistor-transistor logic NAND gate  |
| [#111 ResistorTransistorLogic/NOR](./Electronics101/ResistorTransistorLogic/NOR)   | **BJT, RTL, Logic Gates**       test the basic resistor-transistor logic NOR gate  |
| [#013 ResistorTransistorLogic/NOT](./Electronics101/ResistorTransistorLogic/NOT)   | **BJT, RTL, Logic Gates**       test the basic resistor-transistor logic NOT gate (Inverter) |
| [#112 ResistorTransistorLogic/OR](./Electronics101/ResistorTransistorLogic/OR)     | **BJT, RTL, Logic Gates**       test the basic resistor-transistor logic OR gate |
| [#221 ResistorTransistorLogic/XOR](./Electronics101/ResistorTransistorLogic/XOR)   | **BJT, RTL, Logic Gates**       test the basic resistor-transistor logic XOR gate/XOR |
| [#124 RFDetectorProbe](./Electronics101/EMRDetection/RFDetectorProbe)              | **Radio**                          a simple RF detector mounted in a pen |
| [#337 RgbLedGlow](./Electronics101/RgbLedGlow)                                     | **LED, Oscillators**            rainbow glow effects with an RGB LED and OpAmp oscillators |
| [#169 RGBLedModule](./playground/RGBLedModule)                                     | **LED, Arduino**                demo an RGB LED module |
| [#107 RingCounter](./Electronics101/RingCounter)                                   | **CMOS, 555 Timer**             test the classic CD4017 walking-ring counter |
| [#108 RingCounterController](./playground/RingCounterController)                   | **CMOS, Arduino**               control the classic CD4017 walking-ring counter with an Arduino |
| [#144 RingOscillator](./Electronics101/RingOscillator)                             | **CMOS/TTL, Oscillators**       test an oscillator built with a 74LS14 Inverter chip |
| [#347 RF Connectors](./Electronics101/Connectors/RF)                               | **Radio, Connectors**           notes on miscellaneous RF connectors |
| [#063 RFSwitch](./Electronics101/RFSwitch)                                         | **Radio, OpAmp**                simple remote control switch with 433Mhz transmitter/receiver and some analog signal processing |
| [#064 RFSwitchASK](./playground/RFSwitchASK)                                       | **Radio, ASK, Arduino**         data communications using ASK protocol over 433Mhz RF transmitter and receiver set |
| [#008 RGBCalibrate](./LEDArrayDemos/RGBCalibrate)                                  | **LED Array, Arduino**          quick test to make sure LEDs are correctly addressable and their color can be set correctly |
| [#118 RotaryEncoderMethods](./playground/RotaryEncoderMethods)                     | **Sensor, Arduino**             finding the best method for reading a rotary-encoder |
| [#119 RotaryEncoderModule](./playground/RotaryEncoderModule)                       | **Sensor, 8x8 LED, Arduino**    testing a Rotary Encoder module controlling an LED 8x8 display |
| [#413 Rotary Encoder Tester](./Electronics101/RotaryEncoders/IncrementalTester)    | **Sensor, CMOS/TTL**            demonstrating a rotary encoder forward/reverse LED indicator using simple digital logic |
| [#084 RouletteKit](./Electronics101/555Timer/RouletteKit)                          | **555 Timer**                   build and examine the workings of a commercial 555 Roulette kit |
| [#351 RTL-SDR Dongle](./SDR/RtlSdrDongle)                                          | **SDR, Radio**                  getting started with an R820T2+RTL2832U dongle and open-source SDR software on MacOSX (gprx, CubicSDR) |
| [#104 Ruby](./Electronics101/AudioAmps/Ruby)                                       | **OpAmp, Audio**                a version of the runoffgroove Ruby LM386 guitar amp |
| [#192 Sagrada Família](./Kraft/SagradaFamilia)                                     | **LED, Kraft**                  a paper model with some LED effects |
| [#272 Saike909D](./Equipment/Saike909D)                                            | **Tools**                       unboxing and initial review of the Saike 909D 3-in-1 hot air rework station |
| [#260 SaleaeLogic](./Equipment/SaleaeLogic)                                        | **Tools, Test Equipment, Logic Analyzer**  checking out a second-hand Saleae Logic (24 MS/s, 8 channel USB logic analyzer - that works on a Mac!!) |
| [#021 Schmitt Inverter](./Electronics101/SchmittInverter)                          | **CMOS/TTL**                    graph the basic operation of the 74LS14 Hex Inverter with Schmitt Trigger Inputs |
| [#317 SchmittTrigger/BasicDiscrete](./Electronics101/SchmittTrigger/BasicDiscrete) | **Schmitt, BJT**                test the classic emitter-coupled Schmitt Trigger circuit design |
| [#172 SCRLatch](./Electronics101/SCRLatch)                                         | **SCR, Thyristor**              exploring the behaviour of low-power silicon controlled rectifiers (SCR) |
| [#406 SerialInterface/UsbUartCH340G](./Electronics101/SerialInterface/UsbUartCH340G) | **USB, Serial, CH340**        build a USB to TTL serial interface on a breadboard using the CH340G interface chip, and use it to program Arduino sketches on an ATmega328P |
| [#042 ServoTest](./playground/ServoTest)                                           | **Servo, Arduino**              test the positioning accuracy of a servo motor driven by an Arduino |
| [#041 Shifty](./playground/Shifty)                                                 | **LED, CMOS/TTL, Arduino**      drive 8 LEDs with 3 pins using a 74HC595 shift register |
| [#044 SimpleChime](./Electronics101/555Timer/SimpleChime)                          | **555 Timer**                   play a sound for a fixed duration when a button is pressed |
| [#120 SimplePeakDetector](./Electronics101/SimplePeakDetector)                     | **RC**                          test the basic diode-RC peak detector circuit |
| [#417 SimpleSamplePlayer](./playground/Audio/SimpleSamplePlayer)                   | **Audio, Arduino, PWM**         playing short audio samples on an Arduino using some PWM tricks from the PCM library |
| [#045 SimpleSiren](./Electronics101/555Timer/SimpleSiren)                          | **555 Timer**                   classic timer circuit producing a two-tone oscillation |
| [#388 SingaporeBands](./Radio/SingaporeBands)                                      | **Radio**                       notes on official band plans for Singapore and my and personal observations on where the activity is found |
| [#208 SingleStageTransmitterKit](./Electronics101/FM/SingleStageTransmitterKit)    | **FM**                          build a simple single-stage FK702 FM Transmitter Kit by Future Kit |
| [#279 SingleStageTransmitterKit2](./Electronics101/FM/SingleStageTransmitterKit2)  | **FM**                          build and tweak/tune another simple single-stage FM Transmitter Kit |
| [#171 SMDPracticeBoards](./Electronics101/SMDPracticeBoards)                       | **SMD, CMOS, 555 Timer**        a collection of notes, kits and resources for hand-soldering surface mount devices |
| [#096 Smokey](./Electronics101/AudioAmps/Smokey)                                   | **Amp, Audio**                  quick build of a Smokey-like LM386 guitar power amp |
| [#355 Snow Flake](./Kraft/snowflake)                                               | **Kraft, ARM, LED**             an Atmel SAM D ARM Cortex-M0-controlled LED ornament produced by @LuckResistor and shared with the Boldport Club community as a special project |
| [#296 SolarPendulum](./BoldportClub/QSOPBreakout/SolarPendulum)                    | **Boldport, Solar**             build a solar-powered pendulum similar to the popular "solar wobble/flip-flop toys" on the Boldport QSOP breakout board |
| [#102 SolenoidControl](./playground/SolenoidControl)                               | **Solenoid, Arduino**           controlling a mini solenoid with an Arduino |
| [#117 SolenoidDIY](./Electronics101/SolenoidDIY)                                   | **Solenoid, Arduino**           build and test a basic electromechanical solenoid |
| [#200 SolenoidMotor](./Kinetics/SolenoidMotor)                                     | **Solenoid**                    a single-cylinder mini-solenoid engine |
| [#354 SpiderBot](./Kinetics/SpiderBot)                                             | **Boldport, Kinetics**          Boldport Club PissOff mutant offspring .. with spider legs and scuttling drive system |
| [#016 Square Wave - 555](./Electronics101/555Timer/AstableOscillator)              | **555 Timer, Oscillators**      using a 555 timer as an astable oscillator to generate a square wave and an Arduino and processing to plot the output |
| [#039 Square Wave - LM324](./Electronics101/Oscillators/AstableOpamp)              | **OpAmp, Oscillators**          using an LM324 OpAmp to generate a square wave (astable opamp oscillator) |
| [#022 Square Wave - Schmitt](./Electronics101/SchmittOscillator)                   | **CMOS/TTL, Oscillators**       using an 74LS14 Hex Inverter with Schmitt Trigger Inputs to generate a square wave |
| [#061 SRLatch](./Electronics101/DigitalLogic/SRLatch)                              | **Logic Gates, BJT**            Set/Reset latch with BJTs |
| [#062 SRLatchFlipper](./Electronics101/DigitalLogic/SRLatchFlipper)                | **Logic Gates, BJT, Arduino**   Set/Reset latch with BJTs, controlled and monitored by an Arduino |
| [#346 SRLatchWithNandGates](./Electronics101/DigitalLogic/SRLatchWithNandGates)    | **Logic Gates, CMOS/TTL**       Set-Reset latch implemented with NAND gates |
| [#077 SRLatchWithNorGates](./Electronics101/DigitalLogic/SRLatchWithNorGates)      | **Logic Gates, CMOS/TTL**       Set-Reset latch implemented with NOR gates |
| [#222 StairStepGenerator](./Electronics101/StairStepGenerator)                     | **OpAmp, 555 Timer, Oscillators**  generate a stair-step waveform with analog components |
| [#212 StayCreative](./Electronics101/StayCreative)                                 | **Audio, LED**                  an audio level VU meter driving a custom LED sign |
| [#048 StereoLightTrigger](./playground/StereoLightTrigger)                         | **Sensors, Arduino**            demo an interrupt-driven method for responding to LDR light threshold triggers |
| [#185 StirlingEngineHB13](./Kinetics/StirlingEngineHB13)                           | **Kinetics**                    building the Böhm Stirling-Technik HB13 Small Bonsai engine |
| [#349 stringy/DemoBurner](./BoldportClub/stringy/DemoBurner)                       | **Boldport, PIC**               burning a new demo mode for the Boldport Club Stringy, with a Ruby gem for MusicXML conversion to PIC assembler |
| [#015 StripTease](./LEDArrayDemos/StripTease)                                      | **LED Array, Arduino**          demo a range of effects on the LED strip |
| [#123 SuperheterodyneReceiverKit](./Radio/SuperheterodyneReceiverKit)              | **Radio, AM**                   build and analyse a basic superheterodyne AM MW radio receiver kit |
| [#066 Switch - NFET](./Electronics101/SwitchNFET)                                  | **MOSFET**                      small-signal n-channel MOSFET switch with turn-off delay |
| [#116 Switch - NJFET](./Electronics101/SwitchNJFET)                                | **JFET, Arduino**               switch an independent power source using an Arduino and n-channel JFET |
| [#032 Switch - NPN](./Electronics101/SwitchNPN)                                    | **BJT**                         small-signal digital switch with NPN BJT |
| [#106 Switch - PFET](./Electronics101/SwitchPFET)                                  | **MOSFET**                      small-signal p-channel MOSFET switch with turn-on delay |
| [#091 Switch - PJFET](./Electronics101/SwitchPJFET)                                | **JFET, Arduino**               switch an independent power source using an Arduino and p-channel JFET |
| [#033 Switch - PNP](./Electronics101/SwitchPNP)                                    | **BJT**                         small-signal digital switch with PNP BJT |
| [#286 SwitchPowerNFET](./Electronics101/SwitchPowerNFET)                           | **MOSFET, Arduino**             low-side n-channel MOSFET switching of large loads with a microcontroller |
| [#243 Switches](./Electronics101/Switches)                                         | **Switches**                    Notes on miscellaneous mechanical switches used in electrical circuits |
| [#244 Switches/DPDT](./Electronics101/Switches/DPDT)                               | **Switches**                    all about double-pole, double-thow (DPDT) toggle switches |
| [#175 SwitchSoftLatch](./Electronics101/SwitchSoftLatch)                           | **MOSFET, BJT**                 test a soft-latching power switching circuit |
| [#320 SyncJKCounter](./Electronics101/DigitalLogic/SyncJKCounter)                  | **CMOS/TTL, Digital Logic**     a synchronous 8-bit counter built with JK Flip-Flops |
| [#204 TemperatureLoggerTypeK](./playground/TemperatureLoggerTypeK)                 | **Sensors, Thermocouple, Arduino**  simple high-temperature monitor using Type K (differential) and LM35 (cold-junction) sensors |
| [#074 TestIR](./playground/TestIR)                                                 | **IR, Arduino**                 test raw IR reception with a TSOP1838-type IR sensor and an Arduino |
| [#361 TFT/Color128x128](./playground/TFT/Color128x128)                             | **TFT LCD, Arduino**            testing a 128x128 colour TFT LCD with a couple of different Arduino libraries |
| [#267 TheCuttle/ScopeTag](./BoldportClub/TheCuttle/ScopeTag)                       | **Boldport, ATmega, ATmel, Arduino, Digital Pot, MCP42010, Oscilloscope** Get the Boldport Cuttle to write its name on a Digital Oscilloscope with an MCP42010 digital potentiometer |
| [#312 TheMatrix/Firecracker](./BoldportClub/TheMatrix/Firecracker)                 | **Boldport, LED, AS1130, Sensors**  a firecracker simulacrum running on the BoldportClub Matrix |
| [#302 TheMatrix/GameOfLife](./BoldportClub/TheMatrix/GameOfLife)                   | **Boldport, LED, AS1130**       a simple implementation of Conway's Game of Life on the BoldportClub Matrix |
| [#307 TheMatrix/KeypadControl](./BoldportClub/TheMatrix/KeypadControl)             | **Boldport, LED, AS1130**       use a 20-button keypad to write a scrolling message on the Boldport Matrix |
| [#300 TheMatrix/LedTest](./BoldportClub/TheMatrix/LedTest)                         | **Boldport, LED, AS1130**       testing The Matrix (Boldport Club project #11) with @luckyresistor's LRAS1130 library |
| [#424 TheToneRanger](./playground/VL53L0X/TheToneRanger)                           | **Arduino, Sensors, Audio**     a simple modification of the basic VL53L0X example to add audio indication of range |
| [#281 ThreeStageTransmitter](./Electronics101/FM/ThreeStageTransmitter)            | **Radio, FM**                   build an "ugly-style in a can" version of dazaro3's 3-stage FM transmitter circuit |
| [#375 ThreeTransistorShortWaveReceiver](./Radio/ThreeTransistorShortWaveReceiver)  | **Radio, HF**                   building a simple 3-transistor regenerative receiver for HF shortwave |
| [#380 Tin Counter](./playground/tin_counter)                                       | **Arduino, Sensors, HC-SR04**   a project by novaprimexex to count tins as they roll by and detect tins without paper labels |
| [#071 TinyBlink](./playground/TinyBlink)                                           | **Arduino, ATmel**              a simple blink sketch with an ATTINY85-20PU on a breadboard |
| [#360 TL431/ShuntRegulator](./Electronics101/VoltageReference/TL431/ShuntRegulator)| ** Power, Regulator, Reference** testing a TL431 voltage reference (regulator) circuit with manual course and fine trim |
| [#137 ToroidJouleThief](./Electronics101/ToroidJouleThief)                         | **Power, RL, Oscillators**      test a "joule thief" circuit based on a ferrite toroid |
| [#135 TouchSwitch/555](./Electronics101/555Timer/TouchSwitch)                      | **555 Timer**                   test a touch switch circuit based on a 555 timer |
| [#228 TransistorCurveTracer](./Electronics101/TransistorCurveTracer)               | **OpAmp, 555 Timer, Oscillators**  simple NPN transistor curve tracer using a Stairstep generator circuit |
| [#083 TransistorTester](./Electronics101/TransistorTester)                         | **Arduino, BJT**                use an Arduino to test NPN and PNP BJTs |
| [#205 TriacDimmer](./Electronics101/TriacDimmer)                                   | **Triac, Thyristor**            investigate the operation of triacs and build the basic dimmaer circuit |
| [#031 Triangle Wave - 555](./Electronics101/555Timer/TriangleWaveGen)              | **555 Timer, Oscillators**      generate a triangle wave with 555 timer astable oscillator and RC integrator |
| [#113 TTLBufferDriver](./Electronics101/TTLBufferDriver)                           | **OpAmp, TTL**                  using an OpAmp as a final buffer stage for TTL or similar circuits |
| [#389 TwoStageCommonEmitterAmplifier](./Electronics101/BJT/TwoStageCommonEmitterAmplifier) | **BJT, Amplifier**      designing a two-stage common-emitter BJT amplifier |
| [#059 TwoToneDoorbell](./Electronics101/555Timer/TwoToneDoorbell)                  | **555 Timer, Oscillators**      basic two-tone doorbell using a 555 timer oscillator, with n-channel FET for power conservation |
| [#287 UltrasonicAlarm](./Electronics101/UltrasonicAlarm)                           | **555 Timer, Sensors, CMOS/TTL, HC-SR04** build an ultrasonic motion alarm with the HC-SR04 module and discrete logic |
| [#174 UsbNotifier](./Electronics101/UsbNotifier)                                   | **LED, USB**                    tear-down and demo code for some oldUSB Webmail Notifier devices |
| [#341 UsbPowerSupplyKit](./Electronics101/Power/UsbPowerSupplyKit)                 | **Power, USB**                  building a USB Wall Wart and taking a look at how they work .. instead of taking them apart or having them blow up |
| [#400 USBProtector](./Equipment/USBProtector)                                      | **Power, USB, Tools, Test Equipment**  building the Silicon Chip USB Protector which demonstrates various methods of reverse-polarity, over-voltage and over-current protection |
| [#145 VariableDutyCycle](./Electronics101/555Timer/VariableDutyCycle)              | **555 Timer, Oscillators**      a 555 oscillator circuit that allows easy manual duty cycle adjustment while minimising the change to frequency |
| [#002 Variable LED brightness with PWM](./playground/VariableLED)                  | **LED, Arduino**                variable resistor is used to control the brightness of an LED with PWM |
| [#276 VariableFrequencyRunwayLEDs](./playground/VariableFrequencyRunwayLEDs)       | **LED, Arduino**                a PWM-controlled variable frequency LED "runway lights" effect using the LM331 and CD4017 |
| [#163 VariableSawtoothGenerator](./Electronics101/VariableSawtoothGenerator)       | **OpAmp, Oscillators**          test a variable-geometry, fixed-amplitude sawtooth wave generator circuit |
| [#125 VoiceLevelIndicatorKit](./Electronics101/VoiceLevelIndicatorKit)             | **LED, Kit**                    build and investigate a commercially available "3-band voice level indicator" kit |
| [#273 VoltageControlledOscillator](./Electronics101/VoltageControlledOscillator)   | **Oscillators, VCO, Varicap**   exploring varicap diodes (KV1471) and their use in frequency tuning of a Colpitts-style voltage-controlled oscillator |
| [#328 VoltageControlledOscillator/555](./Electronics101/555Timer/VoltageControlledOscillator) | **Oscillators, VCO, 555 Timer** a voltage-controlled oscillator (VCO) using the 555 timer |
| [#147 VoltageDoublerChargePump](./Electronics101/555Timer/VoltageDoublerChargePump)| **555 Timer, Power**            test a voltage-doubling charge pump circuit based on a 555 timer |
| [#374 VoltageReference/LT1019](./Electronics101/VoltageReference/LT1019)           | **Voltage Reference**           exploring the LT1019 precision reference, tested with an Arduino as an external voltage reference |
| [#333 VoltageSelfMeasurement](./playground/VoltageSelfMeasurement)                 | **Arduino, ADC**                self-measurement of an Arduino's supply voltage (Vcc) |
| [#167 VoltageSensorModule](./playground/VoltageSensorModule)                       | **Sensors, Arduino**            test a 25V voltage sensor module with display on a 5110 LCD |
| [#289 VoltmeterAmmeterModule](./Electronics101/VoltmeterAmmeterModule)             | **Sensors**                     test and calibrate a DC Voltmeter/Ammeter panel module |
| [#181 VoltmeterModule](./Electronics101/VoltmeterModule)                           | **Sensors**                     test a 3-wire voltmeter module |
| [#097 VolumeControlPowerAmp](./Electronics101/AudioAmps/VolumeControlPowerAmp)     | **OpAmp, Audio**                an LM386 fixed-gain audio power amp with volume control |
| [#381 WaterQualityMonitor](./playground/WaterQualityMonitor)                       | **Arduino, Sensors**            a project by oweibo to monitor water quality |
| [#164 WatsonLedRing](./Electronics101/WatsonLedRing)                               | **Oscillators**                 test a Watson 3-LED Ring oscillator |
| [#197 WienBridgeAudioToneGenerator](./Electronics101/WienBridgeAudioToneGenerator) | **OpAmp, Oscillators**          fixed-frequency tone generator based on a Wien Bridge Oscillator |
| [#011 X113647Stepper](./playground/X113647Stepper)                                 | **Stepper, Arduino**            using the 28BYJ-48 stepper motor and a X113647 Stepper Motor Driver Board with an Arduino |
| [#283 XorWithNandGates](./Electronics101/DigitalLogic/XorWithNandGates)            | **Logic Gates, CMOS/TTL**       construct an XOR gate with only an 74LS132 quad NAND gate, and demonstrate its behaviour with an Arduino and Processing |
| [#265 XYplotter](./playground/XYplotter)                                           | **Arduino, Digital Pot, MCP42010, Oscilloscope** draw pictures on a Digital Oscilloscope using an MCP42010 dual digital potentiometer and an Arduino. Of course, the first thing to try is the classic Christmas Tree |
