# #331 GettingBlinky

Getting up and running building a PIC assembler project on MacOSX with a PIC12F675 development board. Let's get Blinky!

Here's a quick demo of it working...

[![GettingBlinky_build](./assets/GettingBlinky_build.jpg?raw=true)](https://www.youtube.com/watch?v=pw0WdkqDNsM)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

PIC is not necessarily everyone's first choice for embedded development these days,
and perhaps it is now more like a right-of-passage.
I guess it was [Julian Ilett](https://www.youtube.com/watch?v=p2rZwR9oM_k) who finally gave me the nudge - I really need to try this for myself.
One thing that's held me back is the perception that you have to "downgrade" to Windows in order to get anything going.

So challenge accepted: I finally decided to see what it is like to develop with PIC assembler,
and ideally do it all on my development platform of choice - MacOSX - without resorting to containers or VMs.


### PIC12F675 Development Board

I got myself a board [like this one](https://www.aliexpress.com/item/5V-PIC12F675-Development-Board-Learning-Board-Test-Breadboard-USB-Cable/32803124346.html).
It appears to be a very common board - the same as used by Julian - and features the PIC12F675, one of the "Mid-Range 8-bit MCUs" in the PIC family.

![GettingBlinky_dev_board](./assets/GettingBlinky_dev_board.jpg?raw=true)

Male-to-female Dupont connectors are fine for connecting the programmer.
I also followed the suggestion and made up a cable using a 6-wire "5S1P balanced charger cable" with a 6-pin JST XH female connector on one end and a 6-pin header on the other.

#### PIC12F675 Specs

The [microchip](http://www.microchip.com/wwwproducts/en/PIC12F675) site has plenty of info and datasheets for the processor. The core specs:

* 1024 words flash memory
* 64 bytes SRAM
* 128 bytes EEPROM
* 6 I/O ports
* 4 channels ADC (10-bit)
* 1 comparator
* 1 timer (8-bit)
* 1 timer (16-bit)
* internal 4 MHz oscillator, up to 20 MHz oscillator / clock input

![PIC12F675_pinout](./assets/PIC12F675_pinout.png?raw=true)

#### Development Board Circuit and Mods

The development board includes a number peripherals to play with:
* 2 LEDs (configured active low)
* 2 push-buttons with pull-up resistors
* 1 potentiometer (between VDD and ground)
* reset button with pull-up and RC de-bounce

Power can be provided by the programmer or via the DC jack (with power switch and filter caps).

One curious thing about the board is how VPP is connected via the RESET switch and debounce circuit.
Although it appears to work just fine, there's a mod recommended by Julian to rewire VPP to connect on the other side of the RESET jumper so
it is possible to have VPP connected and isolated from the reset circuitry.

Having VPP connected via the reset circuit could conceivably cause havoc if the power supply to VDD didn't like seeing 12V on the
other end of the 10kΩ R5.

![Schematic](./assets/GettingBlinky_schematic.jpg?raw=true)


### Toolchain

I'm using [MPLAB X IDE v3.51](http://www.microchip.com/mplab/mplab-x-ide) which appears to be built on [NetBeans](https://netbeans.org/kb/index.html),
and offers great cross-platform support. I'm running it on MacOSX.

It's actually a great environment, although a little hard to find things at first.
A real boon is the built-in simulator, allowing code execution, breakpoints and step-by-step debugging all without a target device or programmer attached.

![mplab_ide](./assets/mplab_ide.png?raw=true)


### Programmer

Got myself a clone [PicKit 3 programmer](https://www.aliexpress.com/item/pickit-3-Programming-emulator-PIC-microcontroller-minimum-system-board-development-board-universal-programmer-seat/1734894366.html). It's been working for me like a charm.

One important configuration item is to enable the programmer to provide power to the target device, if it is not powered separately
I enabled 4.75 V, as I've seen reports of intermittent communication issues if the full 5V is selected.

![mplab_programmer_power](./assets/mplab_programmer_power.png?raw=true)

Of course, the board also works just fine with external 5V power connected after the chip has been programmed:

![GettingBlinky_external_power](./assets/GettingBlinky_external_power.jpg?raw=true)


### Finally, Some Code

Just a single source file - see [blinky.asm](./Blinky.X/blinky.asm).
It is just about the simplest thing you could do - blink an LED of course.
I've avoided any include files, preferring to need to figure it all out (with some serious cribbing from Julian Ilett).


#### Configuration Bits

The configuration word (address: 2007h) - documented in section 9.1 of the datasheet - is used to configure chip features.
The IDE includes a configuration bits editor that can help derive suitable values.

I'm running with 0x31F5 (0b11000111110101), which breaks down as follows:

| Bits  | Selected | Definition                                                                                                                              |
|-------|----------|-----------------------------------------------------------------------------------------------------------------------------------------|
| 13-12 |  11      | Bandgap Calibration bits for BOD and POR voltage. 11 = Highest bandgap voltage                                                          |
| 11-9  |  000     | Unimplemented, read as 0                                                                                                                |
| 8     |  1       | Data Code Protection bit. 1 = disabled                                                                                                  |
| 7     |  1       | Code Protection bit. 1 = disabled                                                                                                       |
| 6     |  1       | Brown-out Detect Enable bit. 1 = enabled                                                                                                |
| 5     |  1       | MCLRE Select bit. 1 = GP3/MCLR pin function is MCLR                                                                                     |
| 4     |  1       | PWRTE: Power-up Timer Enable bit. 1 = PWRT disabled                                                                                     |
| 3     |  0       | WDTE: Watchdog Timer Enable bit. 0 = WDT disabled                                                                                       |
| 2-0   |  101     | FOSC2:FOSC0: Oscillator Selection bits. 101 = INTOSC oscillator: CLKOUT function on GP4/OSC2/CLKOUT pin, I/O function on GP5/OSC1/CLKIN |

With that oscillator setting, can conveniently measure the clock (FOSC/4) on pin 3 (GP4/OSC2/CLKOUT),
around 1.063MHz according to my scope i.e. FOSC=4MHz:

![scope_clock](./assets/scope_clock.gif?raw=true)

#### Turning an LED on and off

GPIO ports default to input, so clearing the corresponding bit in the TRISIO register sets the port state to output:

```
bcf TRISIO, 0
```

Then clearing and setting the corresponding bit in the GPIO register sets the output state high or low:

```
bsf GPIO, 0
bcf GPIO, 0
```

But... TRISIO and GPIO registers are in different "banks", so it is necessary to set the correct bank in the STATUS register first
by setting or clearing the RP0 bit.


#### Adding Delay

It's been a long time since I did any assembler, and I'd forgotten that with great power comes ... the need to do everything for yourself.
None of this `sleep(500)` business!

I obviously want to slow my LED blinking down to something visible. Julian demonstrated how you can do this by just slowing down the clock.
But keeping the clock at full speed requires delay code, and there are many approaches (
[just google it](https://www.google.com.sg/search?q=pic+assembler+delay+example&oq=pic+assembler+delay+example)
).

I chose to use a trick based on an idea I [found here](http://www.piclist.com/techref/postbot.asp?by=time&id=piclist\2001\10\29\205252a).

It essentially does a 2's complement of the 1's complement to increment by one, with a few NOPs thrown in
to produce a loop of 8 clock cycles.

Surrounded by a few make-work loops, the result is an LED blinking at around 4Hz:

![scope_led_pulse](./assets/scope_led_pulse.gif?raw=true)


## Credits and References
* [PIC12F675 info and datasheet](http://www.microchip.com/wwwproducts/en/PIC12F675)
* [PIC Assembly Language Tutorials: #0 - Shopping List & Mods](https://www.youtube.com/watch?v=p2rZwR9oM_k) - Julian Ilett
* [PIC Assembly Language Tutorial: #1 - Config and Clock](https://www.youtube.com/watch?v=491StrMyqa4) - Julian Ilett
* [PIC Assembly Language Update: #1.1 - PCB schematic](https://www.youtube.com/watch?v=TneWtGyar6M) - Julian Ilett
* [pickit 3 Programming / emulator + PIC microcontroller / minimum system board / development board / universal programmer seat](https://www.aliexpress.com/item/pickit-3-Programming-emulator-PIC-microcontroller-minimum-system-board-development-board-universal-programmer-seat/1734894366.html) - example seller on aliexpress
* [5V PIC12F675 Development Board Learning Board Test Breadboard+USB Cable](https://www.aliexpress.com/item/5V-PIC12F675-Development-Board-Learning-Board-Test-Breadboard-USB-Cable/32803124346.html) - example seller on aliexpress
* [5S1P balanced charger cable with a 6-pin JST XH female connector](https://www.aliexpress.com/item/10Pcs-5S1P-Balance-Charger-Silicon-Cable-Wire-JST-XH-Connector-Male-Female-Plug-For-Rc-Airplane/32657806702.html) - example seller on aliexpress
* [MPLAB X IDE](http://www.microchip.com/mplab/mplab-x-ide)
* [..as mentioned on my blog](https://blog.tardate.com/2017/08/leap331-getting-blinky-with-pic-assembler.html)
