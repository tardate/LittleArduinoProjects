# #553 1bitsy Bare Metal C

Bare metal programming the 1bitsy STM32F415RGT6by hand with gcc and the Black Magic Probe.

![Build](./assets/BareMetalBlinky_build.jpg?raw=true)

## Notes

[1bitsy](https://1bitsy.org/) is a fantastic little STM32F415 ARM Cortex-M4F development board that I got from the
[1Bitsy & Black Magic Probe](https://www.kickstarter.com/projects/esden/1bitsy-and-black-magic-probe-demystifying-arm-prog) kickstarter.

In project is an examination of the hardware, culminating in a small bare metal C example blinky program,
flashed to the device with the [Black Magic Probe](https://github.com/blacksphere/blackmagic/wiki).

### 1bitsy Hardware Overview

The 1bitsy itself was designed to be small, framework agnostic and with great debug tool support:

* small size (38.1mm x 17.8mm)
* STM32F415RGT6 MCU
* 41 exposed GPIO with multiple hardware functions
* Standard ARM Cortex 10Pin JTAG / SWD program, debug and trace connector
* 3.3V 500mA Low Dropout Voltage regulator
* Full Speed (12MBit) OTG (Client & Host) Micro-USB connector
* Exposed USB pads allowing soldered USB cable extension
* User controllable LED
* User controllable push button
* 25MHz external high speed crystal oscillator
* 32.768kHz RTC crystal footprint

Pinouts:

[![1bitsy_v1_0d_legend](./assets/1bitsy_v1_0d_legend.png?raw=true)](https://github.com/1Bitsy/1bitsy-hardware)
[![1bitsy_v1_0d_legend2](./assets/1bitsy_v1_0d_legend2.png?raw=true)](https://github.com/1Bitsy/1bitsy-hardware)

### STM32F415RGT6 Overview

The [STM32F415RGT6](https://www.st.com/en/microcontrollers-microprocessors/stm32f415rg.html)

Highlights:

* 32-bit ARM Cortex-M4 core
* 168MHz CPU core frequency
* 192KB RAM
* 1MB Flash
* FPU (Floating Point Unit) single precision floating point arithmetic hardware instructions
* DSP (Digital Signal Processor) Instructions
* USB Full Speed interface (12MBit)
* USB High Speed interface (12MBit with the built in FS PHY, 480MBit requires external PHY)
* 4bit SDIO interface (used for high speed SD Card)
* 10 x Timers (up to 32Bit resolution, up to 168MHz, up and down counting, synchronized 3 phase with complementary outputs and much more)
* 3 x 12-bit, 2.4 MSPS ADCs with 14 mux channels. Up to 7.2 MSPS in triple interleaved mode
* 2 x 12-bit, DACs
* General-purpose DMA: 16-stream DMA controller with FIFOs and burst support
* 2 x I2C (SMBus/PMBus)
* 6 x UART up to 10.5Mbit/s with modem, IrDA and LIN support
* 3 x SPI up to 42Mbit/s with I2S support for high fidelity audio output
* 2 x CAN 2.0B Active (requires external PHY)
* Cryptographic acceleration: hardware acceleration for AES 128, 192, 256, Triple DES, HASH (MD5, SHA-1), and HMAC
* True random number generator (RNG)
* CRC calculation unit
* RTC: subsecond accuracy, hardware calendar

[![en.bd_stm32f415_1mb.jpg](./assets/en.bd_stm32f415_1mb.jpg?raw=true)](https://www.st.com/en/microcontrollers-microprocessors/stm32f415rg.html)

STM32F415RGT6 (numbering scheme from datasheet section 7):

* STM32 = ARM-based 32-bit microcontroller
* F = Product type: general-purpose
* 415 = Device subfamily: STM32F41xxx, connectivity, cryptographic acceleration
* R = Pin count: 64 pins
* G = Flash memory size: 1024 Kbytes of Flash memory
* T = Package: LQFP
* 6 = Industrial temperature range, –40 to 85 °C.

### 1bitsy Examples

The [1bitsy-examples](https://github.com/1Bitsy/1bitsy-examples) repository provides some great examples
that just need the [GNU Arm Embedded Toolchain](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain)
installed.

Setting up and compiling the examples:

    $ git clone https://github.com/1Bitsy/1bitsy-examples.git
    $ cd 1bitsy-examples
    $ git submodule init
    $ git submodule update
    $ make

These work great - see [LEAP#550 Black Magic Probe](../../../Equipment/BlackMagicProbe) for an example of running the fancyblink example on the 1bitsy.

### 1bitsy Bare Metal

I'm going to attempt the most basic blinky program in bare-metal C.

To program bare metal, it's necessary to know the precise hardware details, in particular the memory map and register definitions.
The two critical resources I've used for this can be obtained from the
[STM32F415RG](https://www.st.com/en/microcontrollers-microprocessors/stm32f415rg.html) page:

* DS8597: STM32F415xx/STM32F417xx datasheet
* RM0090: STM32F405/415, STM32F407/417, STM32F427/437 and STM32F429/439 reference manual

### Memory Map

Memory map from datasheet section 4:

![memory_map](./assets/memory_map.png?raw=true)

### Interrupt Vectors

Interrupt and exception vectors are detailed in RM0090 12.2, Table 61 Vector table for STM32F405xx/07xx and STM32F415xx/17xx.

The details were used to create the isr vector table in [stm32_startup.c](./blinky/stm32_startup.c)

### Linker Script

The linker script [stm32_ls.ld](./blinky/stm32_ls.ld) is used to define three critical details for the linker:

* `ENTRY` - the function used as the program entry point
* `MEMORY` - the device-specific memory regions. We care about two: FLASH and SRAM.
* `SECTIONS` - how program code is collected into memory regions

### GPIO

The LED on the 1bitsy is connected to port PA8 (GPIO8 in GPIO port A).
Per the schematic, the LED and current-limiting resistor are wired as active-low.
The STM32F415xx has very generous currently handling capability on each pin: 25mA max (source or sink).

During and just after reset, the alternate functions are not active and the I/O ports are configured in Input Floating mode (CNFx[1:0]=01b, MODEx[1:0]=00b).
When configured as output, the value written to the Output Data register (GPIOx_ODR) is output on the I/O pin.

It is possible to use the output driver in Push-Pull mode or Open-Drain mode.
I'm going to use Push-Pull mode, so that it actually doesn't matter whether the LED is wired to source or sink from the pin.

#### GPIO Register Configuration

For PA8 - GPIO port A, bit 8 - these are the specifics, found in the RM0090 STM32F415xx (etc) reference manual.

There are five steps required to drive a GPIO pin output:

* The GPIO port clock must be enabled for anything to work (RCC_AHB1ENR)
* the GPIO pin mode must be set correctly (GPIOA_MODER)
* the GPIO pin output type must be set correctly (GPIOA_OTYPER)
* the GPIO pin pull-up/pull-down mode must be set correctly (GPIOA_PUPDR)
* finally, the output value can be set in the GPIOA_ODR register

##### RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)

* RCC Memory region: 0x4002 3800 - 0x4002 3BFF
* RCC_AHB1ENR is at offset 0x30: 0x4002 3830
* GPIOAEN is bit 0 of RCC_AHB1ENR

Bit0 GPIOAEN: IOportA clock enable

* 0: IO port A clock disabled
* 1: IO port A clock enabled

![RCC_AHB1ENR.png](./assets/RCC_AHB1ENR.png?raw=true)

##### GPIO port mode register (GPIOx_MODER)

* GPIOA Memory region: 0x4002 0000 - 0x4002 03FF
* GPIOA_MODER is at offset 0x0: 0x4002 0000
* MODER8[1:0] is bits 17, 16

MODERy[1:0]: Portx configuration bits

* 00: Input (reset state)
* 01: General purpose output mode
* 10: Alternate function mode
* 11: Analog mode

![GPIOx_MODER.png](./assets/GPIOx_MODER.png?raw=true)

##### GPIO port output type register (GPIOx_OTYPER)

* GPIOA Memory region: 0x4002 0000 - 0x4002 03FF
* GPIOA_OTYPER is at offset 0x04: 0x4002 0004
* OT8 is bit 8

OTy: Portx configuration bit

* 0: Output push-pull (reset state)
* 1: Output open-drain

![GPIOx_OTYPER.png](./assets/GPIOx_OTYPER.png?raw=true)

##### GPIO port pull-up/pull-down register (GPIOx_PUPDR)

* GPIOA Memory region: 0x4002 0000 - 0x4002 03FF
* GPIOA_PUPDR is at offset 0x0C: 0x4002 000C
* PUPDR8[1:0] is bits 17, 16

PUPDRy[1:0]: Portx configuration bits

* 00: No pull-up, pull-down (reset state for PA8)
* 01: Pull-up
* 10: Pull-down
* 11: Reserved

![GPIOx_PUPDR.png](./assets/GPIOx_PUPDR.png?raw=true)

##### GPIO port output data register (GPIOx_ODR)

* GPIOA Memory region: 0x4002 0000 - 0x4002 03FF
* GPIOA_ODR is at offset 0x14: 0x4002 0014
* ODR8 is bit 8

![GPIOx_ODR.png](./assets/GPIOx_ODR.png?raw=true)

### Project Overview

The example program is completely described by the following files. No other libraries required.

| Source File          | Notes/purpose |
|----------------------|---------------|
| `Makefile`           | makefile knows how to build the project with ARM gcc toochain, and flash the device using the Black Magic Probe |
| `blinky.c`           | main program - setup and run the main loop |
| `delay.c` & `delay.h`| simple NOP-based delay delay function |
| `flash.scr`          | GDB script for flashing the program. Used by the makefile |
| `led.c` & `led.h`    | a most basic GPIO implementation - knows how to enable and drive the LED PA8 port |
| `stm32_ls.ld`        | linker script, hand crafted for the STM32F415x |
| `stm32_startup.c`    | bootstrap code, hand crafted for the STM32F415x |

### Building the project

Default `make` or `make all` will compile:

```
$ cd blinky
$ make
arm-none-eabi-gcc -c -mcpu=cortex-m4 -mthumb -std=gnu11 -Wall -g -O0   -c -o blinky.o blinky.c
arm-none-eabi-gcc -c -mcpu=cortex-m4 -mthumb -std=gnu11 -Wall -g -O0   -c -o delay.o delay.c
arm-none-eabi-gcc -c -mcpu=cortex-m4 -mthumb -std=gnu11 -Wall -g -O0   -c -o led.o led.c
arm-none-eabi-gcc -c -mcpu=cortex-m4 -mthumb -std=gnu11 -Wall -g -O0   -c -o stm32_startup.o stm32_startup.c
arm-none-eabi-gcc -T stm32_ls.ld -nostdlib -Wl,-Map=blinky.map -o blinky.elf blinky.o delay.o led.o stm32_startup.o
arm-none-eabi-objcopy -O binary blinky.elf blinky.bin
```

I'm programming with the Black Magic Probe. When connected it will be represented by a two character devices, the first is the gdb host:

```
$ ls -1 /dev/cu.usb*
/dev/cu.usbmodem7BB19AA1
/dev/cu.usbmodem7BB19AA3
```

The makefile has a `flash` target that knows how to automate flashing the project to the 1bitsy using the Black Magic Probe:

```
$ make flash BMP_PORT=$(ls -1 /dev/cu.usb* | head -n1)
arm-none-eabi-gdb -nx --batch -ex 'target extended-remote /dev/cu.usbmodem7BB19AA1' -x flash.scr blinky.elf
Black Magic Probe (Firmware v1.6.1) (Hardware Version 3)
Copyright (C) 2015  Black Sphere Technologies Ltd.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>

Target voltage: 3.3V
Available Targets:
No. Att Driver
 1      STM32F4xx
0x08000200 in delay (ms=500) at delay.c:7
7   for(uint32_t i = 0 ; i < ms * DELAY_COUNT_1MS ; i++);
Loading section .text, size 0x360 lma 0x8000000
Start address 0x80002da, load size 864
Transfer rate: 2 KB/sec, 864 bytes/write.
Section .text, range 0x8000000 -- 0x8000360: matched.
[Inferior 1 (Remote target) killed]
```

### Calibrating the Delay

The delay function used in the program is not timer based - it just does a NOP loop for an appropriate number of cycles.

I changed the program to use a 10ms delay between on and off transitions, used a scope to measure the resulting waveform,
and then calcualted what the correct number of loops per millisecond should be.
An alternative approach would be to disassemble the code and count the operations and operation timing, but this was quicker!

At 10ms per transition (20ms full cycle), we should see a [50Hz](https://www.wolframalpha.com/input/?i=1%2F%282+*+10ms%29) square wave.
Hooking up to an oscilloscope, that's exactly what I'm recording:

![scope_calibration.gif](./assets/scope_calibration.gif?raw=true)

## Credits and References

* [1bitsy](https://1bitsquared.com/products/1bitsy) - in the 1bitsquared store
* [1Bitsy & Black Magic Probe - Demystifying ARM Programming](https://www.kickstarter.com/projects/esden/1bitsy-and-black-magic-probe-demystifying-arm-prog) - kickstarter
* [1bitsy](https://1bitsy.org/)
* [1bitsy-examples](https://github.com/1Bitsy/1bitsy-examples)
* [STM32F415RG product info](https://www.st.com/en/microcontrollers-microprocessors/stm32f415rg.html)
* [GNU Arm Embedded Toolchain](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain)
* [Black Magic Probe](https://github.com/blacksphere/blackmagic/wiki) - official wiki
