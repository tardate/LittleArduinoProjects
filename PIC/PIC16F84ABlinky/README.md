# #532 PIC16F84A Blinky

A quick test of programming a PIC16F84A on a breadboard and 3rd party dev board with MPLabX (assembler)

![Build](./assets/PIC16F84ABlinky_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/vAowaVov7Bk/0.jpg)](https://www.youtube.com/watch?v=vAowaVov7Bk)

## Notes

I'm planning to play around a bit more with low-end (8 bit) PICs. To start I'd like to get my toolchain setup and testing.
So for this project I'm programming a PIC16F84A-04 with a simple assembler "LED blinky" routine in order to test
my setup and the following tools:

* MPLABX v5.30 running on MacOSX
    * mplab_ide - the main IDE
    * mplab_ipe - the stand-alone programmer
    * mpasm 5.86
* PICKit 3 (clone)
* PIC16F84A-04 on a breadboard
* PIC16F84A-04 on a 3rd party development/programming board

### PIC16F84A Specs

The [microchip](https://www.microchip.com/wwwproducts/en/PIC16F84A) site has plenty of info and datasheets for the processor. The core specs:

* 1024 words flash memory
* 68 bytes SRAM
* 64 bytes EEPROM
* 13 I/O ports
* 1 8-bit timer/counter
* voltage range: 2.0-5.5
* up to 4 MHz oscillator (PIC16F84A-04 variant) or 20 MHz (PIC16F84A-20 variant)

![PIC16F84A_pinout](./assets/PIC16F84A_pinout.png?raw=true)

## Programmer

I got my PICKit 3 in a [programmer / minimum system board bundle](https://www.aliexpress.com/item/1734894366.html) from a seller on aliexpress.
Only 5 of the pins are relevant for programming the PIC16F84A:

| PIC16F84A Pin | Programmer Pin | Function   | Description         |
|---------------|----------------|------------|---------------------|
| MCLR  (4)     | VPP (1)        | VTEST MODE | Program Mode Select |
| VDD   (14)    | VDD (2)        | VDD        | Power Supply        |
| VSS   (5)     | GND (3)        | VSS        | Ground              |
| RB7   (13)    | PGD (4)        | DATA       | Data Input/Output   |
| RB6   (12)    | PGC (5)        | CLOCK      | Clock Input         |

Notes:

* MCLR is the Master Clear (Reset) input/programming voltage input. This pin is an active low RESET to the device
* In the PIC16F8X, the programming high voltage is internally generated. To activate the Programming mode, high voltage needs to be applied to MCLR input. Since the MCLR is used for a level source, this means that MCLR does not draw any significant current.

### Compiling the Project with the the MPLABX IDE

The [PIC16F84ABlinky.X](./PIC16F84ABlinky.X) project is a simple single-file program in assembler that blinks an LED on pin RA3 (2) at about 4Hz.
The code was compiled with the [MPLABX IDE](https://www.microchip.com/mplab/mplab-x-ide) and device programmed with a PICKit 3.

Project settings selected as follows:

* Family: Mid-Range 8-bit MCUs (PIC10/12/16/MCP)
* Device: PIC16F84A
* Compiler: mpasm 5.86

The [configuration bits](https://microchipdeveloper.com/mplabx:view-and-set-configuration-bits) are set:

* `_FOSC_HS` HS oscillator selected (I'm going to use a 4MHz crystal)
* `_WDTE_OFF` watchdog timer disabled
* `_PWRTE_OFF` power-up timer disabled
* `_CP_OFF` code protection disabled

### Using the MPLAB Integrated Programming Environment

The [MPLAB Integrated Programming Environment (mplab_ipe)](https://www.microchip.com/mplab/mplab-integrated-programming-environment)
is a standalone tool that can be used to erase, program or verify a chip.

Once the code was compiled, I tested erasing and programming. All good:

![ipe_erase_and_program](./assets/ipe_erase_and_program.png?raw=true)

Using the IPE to configure powering the device, I ran into what is apparently a common problem with the PICKit 3 clones - it complained
when I selected 5V (hence 4.75V being selected in this example). Strangely, I didn't have this problem when using the PICKit 3 from MPLABX IDE.

![ipe_set_power](./assets/ipe_set_power.png?raw=true)

## Construction

This is a minimal circuit - the application is basically a single LED on RA3.
More interesting details in the schematic are the in-circuit programming connections.

Diodes D1 and D2 prevent interference between programming power (VPP) and the pull-up to VDD required to enable the chip for normal operation.
Note:

* the PIC ICSP Guide does not include D2, but I found that without it I could not get the PIC to run with the programmer connected. This may be due to a difference between the clone PICKit 3 I have and the real thing.

![Breadboard](./assets/PIC16F84ABlinky_bb.jpg?raw=true)

![Schematic](./assets/PIC16F84ABlinky_schematic.jpg?raw=true)

Running on a breadboard:

![Build](./assets/PIC16F84ABlinky_build.jpg?raw=true)

Scope trace of the generated LED control signal - bang on 4 Hz:

![scope_ra3](./assets/scope_ra3.gif?raw=true)

## Using the Dev Board

After successfully programming on a breadboard, I tried the dev board that I received with the PICKit 3.
It turns out to be marginally more convenient, mainly because:

* the zif socket reduces the chance of damaging the PIC
* it has a pull-up resistor, and an LED with current-limiting resistor that can be used if needed

However, two limitations:

* because it is designed to generically handle any PIC up to 40 pin DIP package, it needs the correct connects to be wired up with jumpers
* it doesn't include diodes for diode-steering the VPP and VDD-pullup MCLR connections. I added these in the zif socket and wired up accordingly.

![devboard_build](./assets/devboard_build.jpg?raw=true)

![devboard_ext_power](./assets/devboard_ext_power.jpg?raw=true)

## Bad Chips

The first PIC16F84A chips I tried to program came from an aliexpress supplier and were clearly salvaged parts.
The programmer was unable to identify them or perform any programming actions.

```sh
Connecting to MPLAB PICkit 3...

Currently loaded firmware on PICkit 3
Firmware Suite Version.....01.56.02
Firmware type..............Midrange
Programmer to target power is enabled - VDD = 4.750000 volts.
Target Device ID (0x3fe0) is an Invalid Device ID. Please check your connections to the Target Device.
```

If I still tried to proceed with programming it would fail:

```sh
Programming...

The following memory area(s) will be programmed:
program memory: start address = 0x0, end address = 0x21
configuration memory
program memory
Address: 1 Expected Value: 3400 Received Value: 800
Failed to program device
```

I put this down to faulty chips. When I switch to some PIC16F84A chips from a reputable source [element14](https://sg.element14.com/microchip/pic16f84a-04-p/mcu-8bit-pic16-4mhz-dip-18/dp/9760865?st=PIC16F84A).

## Credits and References

* [PIC16F84A datasheet and info](https://www.microchip.com/wwwproducts/en/PIC16F84A)
* [PICkit™ 3 In-Circuit Debugger](https://www.microchip.com/developmenttools/ProductDetails/PG164130)
* [Pickit 3 Programmer/Debugger](https://components101.com/misc/pickit3-programmer-debugger-pinout-connections-datasheet)
* [Pickit 3 Programming / emulator + PIC microcontroller / minimum system board](https://www.aliexpress.com/item/1734894366.html) - clone? from an aliexpress seller
* [MPLABX IDE](https://www.microchip.com/mplab/mplab-x-ide)
* [MPLAB Integrated Programming Environment (mplab_ipe)](https://www.microchip.com/mplab/mplab-integrated-programming-environment)
