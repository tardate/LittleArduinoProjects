# #640 CMOS Cookbook

Book notes: CMOS Cookbook, by Donald E. Lancaster, Howard M. Berlin. First published January 1, 1988.

[![Build](./assets/cmos-cookbook_build.jpg?raw=true)](https://amzn.to/4ioq5Vl)

## Notes

See also:

* [amazon](https://amzn.to/4ioq5Vl)
* [goodreads](https://www.goodreads.com/book/show/2384294.CMOS_Cookbook)
* <https://openlibrary.org/works/OL25163884W/CMOS_Cookbook>
* <https://archive.org/details/donlancaster_cmoscb>

## Contents

CHAPTER 1: SOME BASICS

The CMOS Process
CMOS Features
Logic and Transmission Gates
Sources
Pins and Packages
CMOS Families
Input Protection
Power Supplies
CMOS Usage Rules
Mounting and Breadboarding
TestIng and Monitoring States
Interface
Tools
"Bad" and "Burned-Out" ICs
Some ConventIons

CHAPTER 2: SOME CMOS INTEGRATED CIRCUITS

* Numeric Index
* Function Index

CHAPTER 3: LOGIC

* CMOS Logic Gates as Simple Switches
* State Definitions: What Is a Zero
* The One-Input Logic Gate
* The Two-Input Logic Gate
* Other Two-Input Gates
* More Inputs
* A Trick Called DeMorgan's Theorem
* Transmission-Gate Logic (TGL)
* Mickey-Mouse Logic (M2L)
* TRI-STATE Logic
* Advanced Logic Techniques
* Data-Selector Logic

CHAPTER 4: MULTIVIBRATORS

* Bistable Circuits
* Schmitt Triggers
* Astable Circuits
* Crystal Oscillators
* Voltage-Controlled Oscillators
* Monostable Circuits
* The CMOS 555 Timer
* The 4047 Multivibrator
* Duty-Cycle Integrators
* Some Guidelines

CHAPTER 5: CLOCKED LOGIc: JK AND D FLIP-FLOPS

* CMOS Clocked Logic
* A Clocked-Logic Block
* An Alternate-
* Action Push Button
* A Master-Slave Clocked Logic Block
* Direct Inputs
* The 4013 Dual Type-D Flip-Flop
* The 4027 Dual JK Flip-Flop
* An Applications Catalog

CHAPTER 6: COUNTERS AND SHIFT REGISTERS

* Counter Qualities
* Some CMOS Counters
* Some Counter Applications
* Shift Registers
* Digital Sine-Wave Generators
* Some Fine Print

CHAPTER 7: OP AMPS, ANALOG SWITCHES, AND PHASE-LOCKED LOOPS

* CMOS Operational Amplifiers
* CMOS Analog Switches
* *CMOS Phase-Locked Loops

CHAPTER 8: DIGITAL DISPLAYS

* Interfacing Lamps and LEDs
* 7-Segment LED Displays 429
* Display Drivers
* Obtaining BCD Information from 7-Segment Displays
* Liquid-Crystal Displays

CHAPTER 9: IC MEMORIES AND PROGRAMMABLE LOGIC ARRAYS

* What Is a Memory?
* Basic Memory Organizations
* The 1K Convention
* Input/Output Connections
* Read-Only Memories
* ROM Storage
* Random-Access Memories
* Programmable Logic Arrays
* Some Examples

CHAPTER 10: GETTING IT ALL TOGETHER

* Multiplexed Digital Displays
* A Digital Wristwatch
* A Multimode Stopwatch
* A Frequency Counter
* Four-In-One Video Game
* The CMOS Microlab
* Bit-Boffer Digital
* Cassette Recorder
* The CMOS Music Modules
* TVT-4 TV Typewriter
* 3.5-Digit A/D Converters
* Some Challenges

APPENDIX A TTL TO CMOS CONVERSION TABLE

APPENDIX B SOME PRODUCT SOURCES

## CMOS USAGE RULES

* All inputs must go somewhere. A solid connection to an input signal, to + V, or to ground must be provided for all inputs, particularly when breadboarding.
* Protect the protection. Avoid ever having the input-protection diodes conduct. If you must use diode current, limit the current to 10 milliamperes or less. Watch for the effects of diodes on time constants and other shaping circuits.
* Use high-impedance test inputs. If you remove supply power without removing "stiff" input signals, you can damage the input protection or latch up the package.
* Avoid static during handling. Store the ICs in conductive foam or metal carriers. Leave them on foil or on a cookie sheet during benchwork. Don't use a soldering gun. Make sure any inputs going off board have a load resistor (1 megohm) across them.
* Condition all mechanical inputs going to clocked logic. Push buttons, switches, and keyboard contacts must be debounced with contact conditioning (Chapter 4) to make them noise- and bounce-free.
* Use fast rise and fall clocks. The rise and fall times on the clock input of clocked logic blocks must be faster than 5 microseconds. Otherwise, erratic operation caused by clock skew can result.

## FUNCTION INDEX

| Analog Switches     | Chip ID |
|---------------------|---------|
| Quad                | 4016 |
| Quad, low-impedance | 4066,74HC4066 |
| 1-of-8              | 4051, 74C151, 74HC4051 |
| Dual 1-of-8         | 4097 |
| Dual 1-of-4         | 4052, 74C153, 74HC4052 |
| Triple 1-of-2       | 4053,74HC4053 |
| 1-of-16             | 4067,74C150 |

| Arithmetic Units            | Chip ID |
|-----------------------------|---------|
| Triple-adder, +logic        | 4032 |
| Triple-adder, -logic        | 4038 |
| Magnitude comparator        | 4063, 74C85 |
| Parity generator, 12-input  | 4531 |
| Full 4-bit adder            | 4008,74C83 |

| Buffers and Inverters       | Chip ID |
|-----------------------------|---------|
| Hex buffer (obsolete)       | 4010 |
| Hex buffer/translator       | 4050, 74HC4050 |
| Quad inverter/buffer        | 4041 |
| Hex inverter (obsolete)     | 4009 |
| Hex inverter/translator     | 4049,74HC4049 |
| Hex inverter                | 4069,74C04 |
| Hex tri-state inverter      | 4502, 74C125, 74C126 |
| Hex tri-state buffer        | 4503 |

| Counters: Octal             | Chip ID |
|-----------------------------|---------|
| Synchronous l-of-8 outputs  | 4022 |

| Counters: Decimal                  | Chip ID |
|------------------------------------|---------|
| Synchronous l-of-1O outputs        | 4017 |
| With 7-segment decoder/enable      | 4026 |
| With 7 -segment decoder/blanking   | 4033 |
| With 7-segment decoder/driver      | 4511 |
| Up with asynchronous clear         | 74C160 |
| Up-down                            | 4510, 74C90, 74C190 |
| Up-down synchronous                | 40192,74C192 |
| Dual synchronous                   | 4518 |

| Counters: Binary (Hexadecimal) | Chip ID |
|--------------------------------|---------|
| Dual Synchronous               | 4520, 74C93, 74HC4520 |
| Up with asynchronous clear     | 74C161 |
| Up-down synchronous            | 4019374C193 |
| Up-down                        | 4516 |
| Up-down, decade or binary      | 4029 |

| Counters: Ripple            | Chip ID |
|-----------------------------|---------|
| 7-stage                     | 4024,74HC4024 |
| 12-stage                    | 4040, 74HC4040 |
| 14-stage                    | 4020, 74HC4020 |
| 14-stage with oscillator    | 4060, 74HC4060 |

| Counters: Programmable divide-by-n | Chip ID |
|------------------------------------|---------|
| 2-through-1O walking ring          | 4018 |
| Decimal                            | 4522 |
| Binary                             | 4526 |

| Data Selectors                     | Chip ID |
|------------------------------------|---------|
| Quad 1-of-2                        | 4019,74C157 |
| Dual 1-of-4                        | 4539 |
| Quad 1-of-2, inverted              | 74C158 |
| 1-of-8                             | 4512 |

| Decoders                           | Chip ID |
|------------------------------------|---------|
| Dual 1-of-4, noninverting          | 4555,74C155 |
| Dual 1-of-4, inverting             | 4556, 74C156 |
| 1-of-lO                            | 4028,74C42 |
| 1-of-16 high                       | 4514, 74C154, 74HC4514 |
| 1-of-16 low                        | 4515 |
| BCD-to-7-segment driver            | 4543, 74HC4543 |
| BCD-to-7-segment driver with latch | 4511 |
| BCD-to-7-segment driver with latch | 74C48 |
| 7-segment-to-BCD with latch        | 74C915 |

| Encoders                           | Chip ID |
|------------------------------------|---------|
| Priority encoder, 8-to-3 line      | 4532,74C148 |

| Flip-Flops                         | Chip ID |
|------------------------------------|---------|
| Dual Type-D                        | 4013,40175, 74C74 |
| Dual JK with preclear              | 74C73,74C107 |
| Dual JK with preset and preclear   | 4027, 74C76 |
| Quad RIS, NOR logic                | 4043 |
| Quad RIS, NAND logic               | 4044 |

| Gates                              | Chip ID |
|------------------------------------|---------|
| Quad 2-input AND.                  | 4081,74C08 |
| Quad 2-input NAND                  | 4011,74COO |
| Quad 2-input OR                    | 4071,74C32 |
| Quad 2-input NOR                   | 4001,74C02 |
| Quad EXCLUSIVE OR (obsolete)       | 4030 |
| Quad EXCLUSIVE-OR                  | 4070, 74C86 |
| Quad EXCLUSIVE-NOR                 | 4077 |
| Dual3-input NOR plus inverter      | 4000 |
| Triple 3-input AND                 | 4073, 74C11 |
| Triple 3-input NAND                | 4023, 74C10 |
| Triple 3-input OR                  | 4075,74HC4075 |
| Triple 3-input NOR                 | 4025,74C27 |
| Dual 4-input AND                   | 4082 |
| Dual4-input NAND                   | 4012,74C20 |
| Dual 4-input OR                    | 4072 |
| Dual4-input NOR                    | 4002, 74C25, 74HC4002 |
| 8-input NAND                       | 4068,74C30 |
| 8-input NOR                        | 4078,74HC4078 |

| Linear Devices                                | Chip ID |
|-----------------------------------------------|---------|
| Transistor array, common-emitter (not CMOS)   | 3081 |
| Transistor array, common-collector (not CMOS) | 3082 |
| CMOS operational amplifier                    | 3130 |
| 5-volt positive regulator (not CMOS)          | 7805 |
| 12-volt positive regulator (not CMOS)         | 7812 |

| Multivibrators                     | Chip ID |
|------------------------------------|---------|
| Single, astable and monostable     | 4047 |
| Dual, retriggerable monostable     | 4528,74C123 |
| Single CMOS timer. . . . . . .     | L555 |
| Dual CMOS timer. . . . . . . .     | L556 |

| Programmable Read-Only Memories    | Chip ID |
|------------------------------------|---------|
| 32 8-bit words (not CMOS)          | 7603 |
| 256 4-bit words (not CMOS)         | 7611 |

| Random-Access Memories              | Chip ID |
|-------------------------------------|---------|
| 1024 I-bit words                    | 21O2 |
| 256 4-bit words                     | 2112 |
| 256 4-bit words                     | 5lO1 |

| Schmitt Triggers                   | Chip ID |
|------------------------------------|---------|
| Hex inverting                      | 4584,74C14 |
| Quad 2-input NAND                  | 4093 |

| Shift Registers                               | Chip ID |
|-----------------------------------------------|---------|
| 4-stage, parallel-in/parallel-out             | 4035, 40195 |
| Dual4-stage, serial-in/parallel-out           | 4015,4094, 74HC4015 |
| 8-stage, parallel-in/serial-out               | 4014 |
| 8-stage, parallel-in/serial-out, asynchronous | 4021,74C165 |
| 18-stage, serial-in/serial-out                | 4006 |
| 64-stage                                      | 4031 |

| Special Devices: MSI               | Chip ID |
|------------------------------------|---------|
| Binary rate multiplier             | 4089 |
| Decimal rate multiplier            | 4527 |
| Phase-locked loop                  | 4046 |
| Priority encoder, 8-input          | 4532 |

| Special Devices: LSI                    | Chip ID |
|-----------------------------------------|---------|
| AID converter, 3 1 /2-digit             | MC14433 |
| AID converter, 3 1 /2-digit, LCD        | 71O6 |
| AID converter, 31f2-digit, LED          | 71O7 |
| Baud-rate generator                     | MC14411 |
| Bit-rate generator                      | 4702 |
| Frequency counter                       | 7208 |
| Frequency synthesiser                   | 0320 |
| Modem                                   | MC14412 |
| Oscillator/ divider, 17 -stage          | 5369 |
| Stopwatch                               | 7045 |
| Television numeric display              | 5841 |
| Time base                               | 7207 |
| Top-octave music generator (not CMOS)   | 5024 |
| Touch-Tone dialer                       | MC14410 |
| TV game controller                      | 8500 |
| Wristwatch                              | 7200 |

| Storage Registers                  | Chip ID |
|------------------------------------|---------|
| Quad latch                         | 4042, 74C75 |
| Quad-D                             | 40175, 74C175 |
| Quad tri-state                     | 4076 |
| Dual quad latch                    | 4508 |
| Hex-D                              | 40174, 74C174 |
| 8-stage bidirectional              | 4034 |
