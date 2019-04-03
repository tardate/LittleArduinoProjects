# #088 ElectronicClockKit

Build and investigate a commercially available "electronic clock" kit


[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

I picked up a [AT89C2051 Electronic Clock](https://www.aliexpress.com/item/1Pcs-New-DIY-Kits-AT89C2051-Electronic-Clock-Suite-Electronic-Parts-Components/2045978940.html) for USD3.28, primarily to investigate how it works. There seems to be a flood of similar kits available from many sellers on aliexpress, ebay etc.

TL/DR - it's an interesting parts kit, and relies on the programming of the AT89C2051 for all the clock functions.
The device works fine, provided sufficient power is attached (a 9V battery is fine).

The microcontroller is supplied pre-flashed without source code -
[however this may be original design and source code](https://www.instructables.com/id/How-to-make-a-digital-clock-kit-based-on-Atmel/).

### How it works

The smarts of the clock are programmed in the Atmel AT89C2051 microcontroller.
The speed of the processor is governed by the 12MHz external crystal that is stabilised by the two 30pF capacitors.

The code is not provided, but seems it would be relatively easy to re-engineer.
The [How to Make a Digital Clock Kit Based on Atmel](https://www.instructables.com/id/How-to-make-a-digital-clock-kit-based-on-Atmel/) instructable
is possibly the original design and source code, although I haven't tested the code yet.

Power is provided through the 78L05 5V regulator, with a standard set of high/low frequency filter capacitors.

The three pushbuttons are direct digital inputs to the microcontroller. When pressed, they pull each of the digital inputs low.

The LED segments displays are common anode, with multiplexed control:
* digital pins are used to select the digit to display by turning on the associated S8550 transistor
* 7 digital pins are used to enable/disable the associated segment with a 220Ω current-limiting resistor in series (the decimal point segments are unused)

The "colons" between digits are provided with 4 LEDs. These are enabled/disabled as a block with a single digital pin.

The LED components are configured to sink current through the microcontroller's Port 1 pins.
Port 1 is an 8-bit bi-directional I/O port that can sink 20 mA and drive LED displays directly.
The direct driving of the LED displays appear within spec, but it is getting close. Maximum total current for all output pins is 80mA
In practice the circuit is drawing 60-70mA, most of which passes through the LEDs.

The "alarm" is provided by a simple piezo. Two connectors are provided to bypass/enhance the alarm:
* J2 can bypass the buzzer. It could be used to disable the onboard buzzer, or run an external alarm function in parallel (depending on how the bypass affected the current to the base of Q7). The external function could not draw much power, as the only current would come from the microcontroller pin
* J3 can also bypass the buzzer in a similar fashion, except this acts acorss the piezo, so has the full Vcc power supply available.

The J2/J3 configuration appears a bit strange. Neither positively bypass or provide parallel operation of external circuits.
And if they are used to directly "short" the buzzer to disable it, they will likely damage the circuit if sufficient current is available from the power supply.
A J2 short will overload an AT89C2051 pin. A J3 short could burn out Q7.

### Directions for Use
This is how it is meant to work... translated;-)

Function keys:
* S1 - function selection button
* S2 - function extension button
* S3 - value increment button.

Functions and operation instructions:

Short press of S1 (less than 1 second) cycles through the selection of six functions in a continuous loop.
A long press of S1 (more than 2 seconds) immediately returns to the clock function state.

Functions:

(1) clock function: after power-up, the clock is reset to 10:10:00

(2) Time adjustment:
* Short press S1 sets the current time
* Press S2 increments the hours count
* Press S3 increments the minutes count
* Note that seconds are not adjustment

(3) Alarm clock function:
* After selection, defaults to 22:10:00
* Press S2 increments the hours count
* Press S3 increments the minutes count
* Note that seconds are not adjustment
* When hours incremented past 23 it will display `-- : -- : --` prior to cycling back to 0. This represents `alarm off`.
* Short press S1 to set the alarm time
* When the alarm goes off, the buzzer will ring for 3 seconds

(4) Countdown function:
* After selection, defaults to 0
* Press S2 increments the countown scale
* Press S3 increments the countdown value
* After S2 has been pressed 7 times, the countdown starts.

(5) Stopwatch function:
* After selection, defaults to 00:00:00
* Press S2 to start stop-watch
* Press S2 to stop stop-watch
* Press S3 to reset timing

(6) counter function:
* After selection, defaults to 00:00:00
* Press S2 to increment counter
* Press S2 to reset


## Construction

![The Build](./assets/ElectronicClockKit_build.jpg?raw=true)

![The Schematic](./assets/ElectronicClockKit_schematic.jpg?raw=true)

![Parts](./assets/ElectronicClockKit_parts.jpg?raw=true)

![PCB front](./assets/ElectronicClockKit_pcb_front.jpg?raw=true)

![PCB rear](./assets/ElectronicClockKit_pcb_back.jpg?raw=true)

### Parts

| Qty | ID         | Description                     |
|-----|------------|---------------------------------|
|   9 | R1,2,11-17 | 1kΩ resistor                    |
|   7 | R4-10      | 220Ω resistor                   |
|   1 | R3         | 10kΩ resistor                   |
|   1 | R18        | 5.1kΩ resistor                  |
|   1 |            | 5Ω resistor                     |
|   2 | C5,6       | 30pF ceramic capacitor          |
|   2 | C1,4       | 100nF 104 ceramic capacitor     |
|   2 | C2,3       | 10μF electrolytic capacitor     |
|   1 | T1         | 12MHz crystal                   |
|   3 | S1-3       | pushbutton switch               |
|   1 | U2         | AT89C2051 microcontroller       |
|   1 | U1         | 78L05 5V regulator              |
|   7 | Q1-7       | S8550 PNP transistor            |
|   1 | U3         | piezo speaker                   |
|   4 | D1-4       | 3mm red LED                     |
|   3 | DS1-3      | CAI3261BS 2-digit/7-segment LED |
|   1 | J1         | 2-connector terminal block      |
|   2 | J2,3       | 2-pin connector                 |
|   1 |            | PCB                             |

## Credits and references
* [AT89C2051 Electronic Clock](https://www.aliexpress.com/item/1Pcs-New-DIY-Kits-AT89C2051-Electronic-Clock-Suite-Electronic-Parts-Components/2045978940.html)
* [78L05 Datasheet](https://www.futurlec.com/Linear/78L05.shtml)
* [S8550 Datasheet](http://www.unisonic.com.tw/datasheet/S8550.pdf)
* [AT89C2051 Datasheet](https://www.futurlec.com/Atmel/AT89C2051.shtml)
* [CAI3261BS Datasheet](http://datasheet.sparkgo.com.br/LD3361BS.pdf)
* [How to Make a Digital Clock Kit Based on Atmel](https://www.instructables.com/id/How-to-make-a-digital-clock-kit-based-on-Atmel/) - possibly the original design and source code (thanks to @zoomx for the reference)
