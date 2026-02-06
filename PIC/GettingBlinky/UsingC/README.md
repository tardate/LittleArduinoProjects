# #390 Getting Blinky with PIC C

Getting up and running building XC8 C projects on macOS and a PIC12F675. Let's get Blinky again! Updated 2026 with latest IDE tools while still using the old PICkit 3.

![Build](./assets/UsingC_build.jpg?raw=true)

## Notes

The [LEAP#331 Getting Blinky with PIC Assembler](../) project was a simple test of the PIC12F675 with PIC assembler.
See that project for details of the PIC12F675 Development Board I'm using.

As the PIC12F675 is one of the lower-end 8-bit chips in the PIC family, I wasn't sure at first how
well it might be supported by C compilers. Well, I shouldn't have been concerned. In addition
to support from independent compiler makers, Microchip offer their own XC Compilers

This project is a quick test of the MPLAB XC8 compiler, which supports all 8-bit PICs,
is cross platform and has a free version available.

I originally ran this exercise in 2018 with MPLAB X IDE v5.30,
but now updated in Feb-2026:

* Compiled with MPLAB X IDE v6.20 on macOS
* Programmed using the PICkit 3 on Ubuntu with MPLAB X IPE v6.20 (the last version to support PICkit 3)

See [LEAP#331 Getting Blinky with PIC Assembler](../) for more details on the trials and tribulations of trying to continue to use the PICkit 3 on macOS.

### The New Project Wizard

A quick summary. Many of these settings can be changed later in project properties.

First create a new stand-alone project

![create_project_01](./assets/create_project_01.png?raw=true)

Select the device:

![create_project_02](./assets/create_project_02.png?raw=true)

Select a debugger (if any):

![create_project_03](./assets/create_project_03.png?raw=true)

Select a programmer (or do this later):

![create_project_04](./assets/create_project_04.png?raw=true)

Select the XC8 compiler:

![create_project_05](./assets/create_project_05.png?raw=true)

Select name and folder for the project:

![create_project_06](./assets/create_project_06.png?raw=true)

### Chip Configuration

The configuration word (address: 2007h) - documented in section 9.1 of the datasheet - is used to configure chip features.
The IDE includes a configuration bits editor that can help derive suitable values.

In XC8, these are conveniently defined with `pragma`.
I'm using a basic configuration, with a 4MHz internal clock and all other features disabled:

* INTOSC oscillator: CLKOUT function on GP4/OSC2/CLKOUT pin, I/O function on GP5/OSC1/CLKIN
* Watchdog Timer Enable bit (WDT disabled)
* Power-Up Timer Enable bit (PWRT disabled)
* GP3/MCLR pin function select (GP3/MCLR pin function is digital I/O, MCLR internally tied to VDD)
* Brown-out Detect Enable bit (BOD disabled)
* Code Protection bit (Program Memory code protection is disabled)
* Data Code Protection bit (Data memory code protection is disabled)

With MPLAB XC8, it is not necessary to specify the device in code.
Instead, the IDE records this in the NetBeans `nbproject/configurations.xml` file.
That makes the code more portable to other devices, but not to other toolchains.

## Code

See [Clinky.X/main.c](./Clinky.X/main.c).

One of the main benefits of coding in C instead of assembler is that bank switching is handled automatically.

This is a trivial demonstration of GPIO port manipulations, toggling active-low LEDs on GP0 and GP1.
There are a number of ways to toggle multiple bits in a port (and at least one way to do it wrong!).

One can write directly to the `GPIO` port, use the `GPIObits` struct,
or even use the [MPLAB Code Configurator (MCC) tool](http://microchipdeveloper.com/mcc:mccgpio) to generate boiler-plate
pin functions.

I'm using `GPIObits` in combination with a shadow register. This makes bit manipulation very explicit and understandable,
while ensuring no undesirable flipping of neighbouring bits.

What I discovered you **can't** do safely is this:

    GPIObits.GP0 = 1;
    GPIObits.GP1 = 0;

.. because bit changes may not be fast enough to be read reliably for the next bit-flip, meaning that changes get "lost".

## Programming

I am still using an old PICkit 3 programmer:
["pickit 3 Programming / emulator + PIC microcontroller / minimum system board / development board / universal programmer seat" (aliexpress seller listing)](https://www.aliexpress.com/item/1734894366.html) purchased for US $18.85 (Feb-2017).

On Windows or Ubuntu, the PIC16F8X can be easily programmed using the MPLAB X IDE v6.20 or MPLAB IPE v6.20 support for the PICkit 3.

Since I am no longer able to get the PICkit 3 working with macOS,
I am driving it remotely connected to an Ubuntu machine running MPLAB IPE v6.20, using the
[ipe-remote.sh](../ipe-remote.sh) script from
[LEAP#331 Getting Blinky with PIC Assembler](../).

```sh
$ ../ipe-remote.sh ronda-u1 12F675 Clinky.X/dist/default/production/Clinky.X.production.hex
Clinky.X.production.hex                                                                                                                                                                          100%  336    55.5KB/s   00:00
DFP Version Used : PIC10-12Fxxx_DFP,1.7.178,Microchip
*****************************************************
Connecting to MPLAB PICkit 3...
Currently loaded firmware on PICkit 3
Firmware Suite Version.....01.56.09
Firmware type..............Midrange
Programmer to target power is enabled - VDD = 4.750000 volts.
Target device PIC12F675 found.
Device Revision ID = b
Erasing...
Erase successful
Device Erased...
Programming...
The following memory area(s) will be programmed:
program memory: start address = 0x0, end address = 0x3fe
configuration memory
Programming/Verify complete
PICKIT3 Program Report
2026-02-06, 20:21:09
Device Type:PIC12F675
Program Succeeded.
PK3 Verify Report
2026-02-06, 20:21:09
Device Type:PIC12F675
The following memory areas(s) will be verified:
program memory: start address = 0x0, end address = 0x3ff
configuration memory
EEData memory
User Id Memory
Verification successful.
Verify Succeeded.
Operation Succeeded
```

I initially tested the code using a PIC12F675 Development Board as detailed in
[LEAP#331 Getting Blinky with PIC Assembler](../). Works like a charm!

![UsingC_devboard_build](./assets/UsingC_devboard_build.jpg?raw=true)

## Programming a Stand-alone Chip

Next I wired up a stand-alone PIC12F675 on a breadboard

![Breadboard](./assets/UsingC_bb.jpg?raw=true)

![Schematic](./assets/UsingC_schematic.jpg?raw=true)

Programming and running when powered by the programmer:

![Build](./assets/UsingC_build.jpg?raw=true)

And running independently with a 5V power supply.

![UsingC_running_standalone](./assets/UsingC_running_standalone.jpg?raw=true)

## Credits and References

* [mikroC](https://www.mikroe.com/mikroc-pic)
* [MPLAB X IDE](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide)
* [MPLAB XC8](https://www.microchip.com/en-us/tools-resources/develop/mplab-xc-compilers)
* [LEAP#331 Getting Blinky with PIC Assembler](../)
* ["pickit 3 Programming / emulator + PIC microcontroller / minimum system board / development board / universal programmer seat" (aliexpress seller listing)](https://www.aliexpress.com/item/1734894366.html)
    * Purchased for US $18.85 (Feb-2017)
* [PIC Microcontroller Projects in C](../../../books/pic-microcontroller-projects-in-c/) - I started working with this book, but found some of the code examples to be demonstrating incorrect techniques

## Video Tutorials

### PIC Microcontroller Tutorial 2 - Your first program, switching on an output

I started with a useful tutorial by Luke Briner explaining the differences between assembler and C code for a PIC.

[![clip](https://img.youtube.com/vi/myLBDtfnyRM/0.jpg)](https://www.youtube.com/watch?v=myLBDtfnyRM)
