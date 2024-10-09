# #637 Digital Clock Kit

Build a CMOS digital logic clock kit and understand the operating principles of the circuit.

![Build](./assets/DigitalClockKit_build.jpg?raw=true)

## Notes

It has been a while since I've pulled out one of the many DIY electronic kits to practice some soldering and brush up on digital circuits.

This is a common kit, easily found on aliexpress, ebay etc, generally called something like "6-bit digital circuit clock kit".
It is a simple clock circuit built solely with CMOS digital logic.

The basic operating principle:

* CD4060 is configured as a crystal-locked oscillator, buffered by a CD4013 Flip-Flop.
    * This generates a 1Hz square wave that provides the 1-second pulse that drives the clock
    * The signal can be disconnected by switch S1, effectively pausing the clock.
* Three CD4518 BCD counters are cascaded to count for the seconds, minutes, and hours of the clock
    * a CD4081 AND gate is used to decode the required output lines to trigger a carry and reset
    * for the seconds (U9) and minutes (U8):
        * Q2B (pin 12) & Q3B (pin 13)
        * i.e. when QB = 0110b, and QA = 0000b
        * i.e. 60 in BCD (60 seconds/minutes, 60 minutes/hour)
    * for the hours (U7):
        * Q2B (pin 12) & Q3A (pin 5)
        * i.e. when QB = 0010b, and QA = 0100b
        * i.e. 24 in BCD (24 hours/day)
    * pushbutton switches S2 and S3 may be used to input a manual carry/reset on the hour and minute CD4518s to allow the clock to be set
    * the clock can be temporarily stopped with S1 to calibrate the seconds
* Six CD4511 BCD-to-7 Segment drivers are then used to take the CD4518 outputs and drive the corresponding 7-segment LED units
* the four 3mm red LEDs are configured to provide the colon separator. They are connected to the 1Hz signal so they flash every second

### Circuit Design

I haven't drawn up the circuit in an EDA package (yet).
I did find a similar schematic from one of the kit vendors.
Here is the revised and verified version of the schematic.
NB: red marks are my revision to match the kit and PCB I received.

![schematic](./assets/DigitalClockKit_schematic.jpg?raw=true)

### Vendor Description

This product is a 24-hour digital circuit clock, using CD4518, CD4511, CD4081, CD4013, CD4060 and other chips, the circuit does not contain a microcontroller, so there is no program. Hours, minutes and seconds can be calibrated, without alarm function.
This kit mainly consists of a second signal generator, counter, decoding display and time calibration circuit. The second pulse is a 1HZ square wave signal obtained by precise frequency division of a high frequency signal generator, which is more accurate in timekeeping.
The second signal generator consists of CD4060 and CD4013, which generates a square wave signal with a frequency of 1HZ. CD4060 is a 14-level binary frequency divider/oscillator. It consists of a 32768HZ oscillator with external resistors R44, R43, C1, C2 and Y1. After 14 levels of binary frequency divider, the frequency of 2HZ square wave signal is obtained at pin 3. CD4013 contains two independent D flip-flops, take one of the flip-flops through the line configured as a binary counter, binary counting of the input 2HZ square wave signal can be obtained from the second signal. CD4518 is a double-decimal addition counter. With 3 CD4518 for hours, minutes, seconds, hours configured for the 24-binary, minutes and seconds configured for 60-binary. CD4518 counting results in the form of BCD code from pin Q0-Q3 output to the BCD decoder CD4511, CD4511 will be converted to the BCD code corresponding to the display of the corresponding digital tube light segment code, the digital tube to form a digital can be recognized to visually display the current results. Timing results.

Minutes and seconds are counted in 60 decimal, the seconds signal is introduced to the EN terminal of CD4518 through switch S1, and 1 is added to the falling edge of each seconds signal (if the seconds signal is connected to the CLK terminal of CD4518, 1 is added to the rising edge of each seconds signal), and when the counter counts up to 9, Q0-Q3 outputs 1001, i.e., Q3 is 1. As it is a decimal counter, when the next seconds signal arrives, the counter changes from 9 to 0, Q0-Q3 outputs 0000, thus forming a falling edge signal on Q3, this signal is introduced to the ten-digit counter of the second counter, and the ten-digit counter adds 1 to the ten-digit counter after each full count of 10 in the individual counter.When the ten-digit counter value reaches 6, Q0-Q3 outputs 0110, i.e., Q1 and Q2 are both 1 at the same time, and Q1 and Q2 are connected to the counter through an and gate after outputting 1 to the Q1 and Q2 are connected to the reset terminal of the counter through an and gate and output 1, so that the counter counts from 6 to 0 in advance, completing the cycle of 1 hexadecimal counting. The reset signal is also used as the counting signal of the sub-counter, and the sub-counter will be increased by 1 for every full 60 seconds. The sub-counter is also 60-bit, when the sub-counter is full 60, the ten bits of the sub-counter will be reset by a gate, so that the value of the time counter will be increased by 1. When the counter is full 24, the Q0-Q3 of the ten bits will be 0010 and that of the individual bits will be 0100, which will be connected to the counter after Q2 is done with the algorithm, so that the counter can be reset from 6 to 0 in advance. By connecting the Q1 of the tenth bit and the Q2 of the first bit to the reset terminals of the two counters, the hourly counter will return to 0 when the counter reaches the full 24, thus realizing the 24-bit counting.

Features

1. This is a 24-hour digital circuit clock kit, using CD4518, CD4511, CD4081, CD4013, CD4060 and other chips.
2. The product is made of high quality material, quality is guaranteed.
3. Can be used for teaching practical training welding, very suitable for DIY enthusiasts
4. Stable product performance, long service life
5. The use of red digital tube, digital clear at a glance

### Kit Parts

| Ref       | Item                                                 | Qty | Delivered OK? |
|-----------|------------------------------------------------------|-----|---------------|
|           | PCB board                                            | x1  | √             |
| DS1-6     | 0.56 LED 8-segment common cathode 5161AS             | x6  | √             |
| R48,49    | 470Ω resistor                                        | x2  | √             |
| R1-42     | 1kΩ resistor                                         | x42 | √ x50         |
| R45,46,47 | 2.2kΩ resistor                                       | x3  | √             |
| R43       | 100kΩ Resistor                                       | x1  | √             |
| R44       | 10MΩ resistor                                        | x1  | √             |
| D1,2?,3,4 | 1N4148 Diode                                         | x4  | √             |
| C3,4,5    | 10nF 103 Monolithic Capacitor                        | x3  | √             |
| Y1        | 32.768KHZ crystal                                    | x1  | √             |
| C1,2      | 30pF Porcelain Chip Capacitor                        | x2  | √             |
| C6        | 25V 100µF Capacitor                                  | x1  | √             |
| J1        | KF301-2P terminal block.                             | x1  | √             |
| U1-10     | 16P IC Block                                         | x10 | √             |
| U11,12    | 14P IC Block                                         | x2  | √             |
| U1-6      | CD4511 DIP16 BCD-to-7 Segment Latch/Decoder/Driver   | x6  | √             |
| U7-9.     | CD4518 DIP16 Dual BCD Up Counter                     | x3  | √             |
| U12       | CD4081 DIP14 Quad 2-Input AND Buffered B Series Gate | x1  | √             |
| U10       | CD4060 DIP16 14-Stage Ripple Carry Binary Counters   | x1  | √             |
| U11       | CD4013 DIP14 Dual D-Type Flip-Flop.                  | x1  | √             |
| D5,6,7,8  | 3mm Red LED                                          | x4  | √ x5          |
| S1        | 12D07 Toggle Switch                                  | x1  | √             |
| S2,S3     | pushbutton switch                                    | x2  | √             |

![kit_parts](./assets/kit_parts.jpg?raw=true)
![pcb_front](./assets/pcb_front.jpg?raw=true)
![pcb_rear](./assets/pcb_rear.jpg?raw=true)

### Build Log

After a pleasant soldering session - all ready for the insertion of the ICs after a few continuity checks.

![build01](./assets/build01.jpg?raw=true)

Running from a current-limited power supply with scope attached to CD4013 pin1. All good, no issues...

![build02](./assets/build02.jpg?raw=true)

The CD4013 pin1 a measures a 1000ms square wave - the 1Hz signal driving the clock.

![scope](./assets/scope.gif?raw=true)

## Credits and References

* [DC 4.5V-5.5V 6-bit digital circuit clock kit, electronic clock teaching and practical training, welding and DIY parts production](https://www.aliexpress.com/item/1005006053545226.html)
* [CD4511 datasheet](https://www.futurlec.com/4000Series/CD4511.shtml)
* [CD4518 datasheet](https://www.futurlec.com/4000Series/CD4518.shtml)
* [CD4081 datasheet](https://www.futurlec.com/4000Series/CD4081.shtml)
* [CD4060 datasheet](https://www.futurlec.com/4000Series/CD4060.shtml)
* [CD4013 datasheet](https://www.futurlec.com/4000Series/CD4013.shtml)
