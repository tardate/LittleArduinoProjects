# #493 Fomu - Getting Started

A first look at the Fomu FPGA and some tests running MicroPython on the RISC-V CPU core, and peeking/poking memory over the wishbone bus.

![Build](./assets/GettingStarted_build.jpg?raw=true)

## Notes

I recently received a couple of [Fomu FPGA boards from crowdsupply](https://www.crowdsupply.com/sutajio-kosagi/fomu).
Time to figure out exactly what I bought and how to use it!

The bottom line:

* Fomu is really easy to get started with! Easiest toolchain installation ever
* the wishbone bus and bridge that is enabled by default allow direct access to memory from the host PC

### Introduction to Fomu

It turned out to be a good time to jump in, with a couple of resources just being released:

* The ["Fomu - an FPGA inside your USB port!"](https://www.youtube.com/watch?v=rBfC-oxvaqM) presentation by [Tim 'mithro' Ansell](https://twitter.com/mithro) and [Sean 'xobs' Cross](https://twitter.com/xobs)
at CCC 2019 is really worth watching as a first start. It's more of a project overview,
but helps to sort out the mess of jargon (tomu v TinyFPGA v fomu etc).
* Followed by an appearance on The Amp Hour [#456.3 – Discussing Fomu with Tim Ansell and Sean Cross](https://theamphour.com/456-3-discussing-fomu-with-tim-ansell-and-sean-cross/)

[![clip](https://img.youtube.com/vi/rBfC-oxvaqM/0.jpg)](https://www.youtube.com/watch?v=rBfC-oxvaqM)


### Fomu Production (PVT1) Board

The kit contains the Fomu board and a plastic shell that makes it easy to insert into a USB socket.

![fomu_kit](./assets/fomu_kit.jpg?raw=true)

![fomu_board](./assets/fomu_board.jpg?raw=true)

A brief overview of the specifications:

* FPGA: Lattice ICE40UP5K
* Speed: 48 MHz external oscillator
* RAM: 128 kB RAM for a soft CPU
* Storage: 2 MB SPI flash
* Connectivity: USB 2.0 FS (12 Mbps)
* Buttons: four capacitive touch pads
* LEDs: One RGB

The default Fomu firmware exposes a USB bootloader (`foboot`) running a RISC-V softcore.
The bootloader presents itself as a DFU image, in future may show up as a USB drive.

Fomu's USB support is implemented in the softcore of the FPGA rather than in support components.

* Downside: uses up alot of storage.
* Upside:
  * saves on external components for USB support, so smaller form-factor, cheaper to produce
  * allows some neat features (like the wishbone bus?)


## Construction

Packed on the little PCB are the components covering 4 main requirements:

* the FPGA itself
* user I/O: RGB LED and touch pads
* power regulators
* power filtering and ESB protection

![Schematic](./assets/GettingStarted_schematic.jpg?raw=true)

### Toolchain Support

The [Fomu Toolchain](https://github.com/im-tomu/fomu-toolchain) is a pre-configured set of tools comprising:

* yosys: Verilog synthesis
* nextpnr-ice40: FPGA place-and-route
* icestorm: FPGA bitstream packing
* riscv toolchain: Compile code for a RISC-V softcore
* dfu-util: Load a bitstream or code onto Fomu
* python: Convert Migen/Litex code to Verilog
* wishbone-tool: Interact with Fomu over USB
* serial console: Interact with Python over a virtual console

There appears to be a range of other tools that can be used with Fomu, though I not sure the status of each:

* Bare Metal
  * [LLVM](https://llvm.org/)
  * [GCC](https://gcc.gnu.org/)
  * [Embedded Rust](https://rust-embedded.github.io/book/)
* Software Support
  * [zephyr](https://www.zephyrproject.org/) - open-source RTOS
  * [NuttX](https://nuttx.org/) - open-source RTOS
  * [MicroPython](https://micropython.org/) - embedded Python
  * [CircuitPython](https://circuitpython.org/) - MicroPython derivative supported by Adafruit
* Design/development tools
  * [QEMU](https://www.qemu.org/) - processor emulator
  * [Renode](https://renode.io/) - open source software development framework for multi-node device systems
  * [Verilator](https://www.veripool.org/wiki/verilator) - free Verilog HDL simulator


## The Fomu Workshop

The [fomu-workshop](https://github.com/im-tomu/fomu-workshop) repository is a set of resources and examples that
have been used for introductory Fomu workshops (conducted by Tim and Sean).

The associated [web site](https://workshop.fomu.im) (GitHub Pages rendering of the repo) seems like the best place to start.
My notes below follow my progress, running on MacOSX 10.13.6.

### Installation

I'm building/running within this 'GettingStarted' folder.

Getting a local copy of the workshop files:

    $ git clone --recurse-submodules https://github.com/im-tomu/fomu-workshop.git

Grabbing the [appropriate build](https://github.com/im-tomu/fomu-toolchain/releases) of the pre-configured toolchain:

    $ wget https://github.com/im-tomu/fomu-toolchain/releases/download/v1.3/fomu-toolchain-macos-v1.3.zip
    $ unzip fomu-toolchain-macos-v1.3.zip

Finally setting the path to the toolchain bin folder and running `yosys` to verify things are on track:

    $ export PATH=$(pwd)/fomu-toolchain-macos-v1.3/bin:$PATH
    $ yosys

     /----------------------------------------------------------------------------\
     |                                                                            |
     |  yosys -- Yosys Open SYnthesis Suite                                       |
     |                                                                            |
     |  Copyright (C) 2012 - 2018  Clifford Wolf <clifford@clifford.at>           |
     |                                                                            |
     |  Permission to use, copy, modify, and/or distribute this software for any  |
     |  purpose with or without fee is hereby granted, provided that the above    |
     |  copyright notice and this permission notice appear in all copies.         |
     |                                                                            |
     |  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  |
     |  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF          |
     |  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR   |
     |  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES    |
     |  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN     |
     |  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF   |
     |  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.            |
     |                                                                            |
     \----------------------------------------------------------------------------/

     Yosys 78b30bbb1102047585d1a2eac89b1c7f5ca7344e (Fomu build) (git sha1 41d9173, clang 9.1.0 -fPIC -Os)

    yosys>

All good!

### The DFU

[dfu-util](https://sourceforge.net/projects/dfu-util/) is a host side implementation of the DFU 1.0 and DFU 1.1 specifications of the USB forum. DFU is intended to download and upload firmware to/from devices connected over USB.

Fomu is compatible with dfu-util and it makes for an amazingly simple process of reconfiguring the Fomu.

With a Fomu in a USB socket, `dfu-util` can interrogate the device and report it's status ("Fomu DFU Bootloader v1.8.7")

    $ dfu-util -l
    dfu-util 0.9

    Copyright 2005-2009 Weston Schmidt, Harald Welte and OpenMoko Inc.
    Copyright 2010-2019 Tormod Volden and Stefan Schmidt
    This program is Free Software and has ABSOLUTELY NO WARRANTY
    Please report bugs to http://sourceforge.net/p/dfu-util/tickets/

    Deducing device DFU version from functional descriptor length
    Found Runtime: [05ac:8289] ver=0150, devnum=6, cfg=1, intf=3, path="20-8.3", alt=0, name="UNKNOWN", serial="UNKNOWN"
    Found DFU: [1209:5bf0] ver=0101, devnum=10, cfg=1, intf=0, path="20-5", alt=0, name="Fomu DFU Bootloader v1.8.7", serial="UNKNOWN"


### Running MicroPython

The workshop files include `micropython-fomu.dfu` - pre-built RISC-V binary with a Fomu port of MicroPython.
Loaded with `dfu-util`:

    $ dfu-util -D fomu-workshop/micropython-fomu.dfu
    dfu-util 0.9

    Copyright 2005-2009 Weston Schmidt, Harald Welte and OpenMoko Inc.
    Copyright 2010-2019 Tormod Volden and Stefan Schmidt
    This program is Free Software and has ABSOLUTELY NO WARRANTY
    Please report bugs to http://sourceforge.net/p/dfu-util/tickets/

    Match vendor ID from file: 1209
    Match product ID from file: 5bf0
    Deducing device DFU version from functional descriptor length
    Opening DFU capable USB device...
    ID 1209:5bf0
    Run-time device DFU version 0101
    Claiming USB DFU Interface...
    Setting Alternate Setting #0 ...
    Determining device status: state = dfuIDLE, status = 0
    dfuIDLE, continuing
    DFU mode device DFU version 0101
    Device returned transfer size 1024
    Copying data from PC to DFU device
    Download  [=========================] 100%       133044 bytes
    Download done.
    state(7) = dfuMANIFEST, status(0) = No error condition is present
    state(8) = dfuMANIFEST-WAIT-RESET, status(0) = No error condition is present
    Done!

Console device will then be available to connect to the Python REPL e.g. using `screen`:

    $ screen /dev/cu.usb*
    MicroPython v1.4.1-6392-g573979203-dirty on 2019-08-23; fomu with vexriscv
    >>> hex(1024 + 48 + 2)
    '0x432'

#### Fomu Python Extensions

The [Fomu port of MicroPython](https://github.com/im-tomu/micropython/tree/fomu/ports/fomu)
appears to be quite limited at the moment (at least the build included in the workshop files).
Most MicroPython libraries are not available, but there is a `fomu` module
that provides access to specific features of the Fomu board including SPI and the RGB LED.

    >>> import fomu
    >>> spi = fomu.spi()
    >>> hex(spi.id())
    '0xc2152815'
    >>> rgb = fomu.rgb()
    >>> rgb.mode("error")

There is no sleep function, so a little do-nothing loop can be used to animate through
the defined RGB modes:

    >>> import fomu
    >>> rgb = fomu.rgb()
    >>> for status in ['idle', 'writing', 'error', 'done']:
    ...   rgb.mode(status)
    ...   for x in range(1000):
    ...     pass
    ...

Interesting: gives an idea of how fast (read: slow) python on RISC-V on an ICE40 FPGA is!
I first tried looping around 10000 times and that took about 30 seconds!

Interrogating the machine details from memory-mapped registers:

    >>> import machine
    >>> chr(machine.mem32[0xe0007028])
    'P'
    >>> machine.mem32[0xe0007000]
    1
    >>> machine.mem32[0xe0007004]
    8
    >>> machine.mem32[0xe0007008]
    7

i.e. this is a production 1.8.7 board

### Wishbone

The CPU in Fomu is built on [LiteX](https://github.com/enjoy-digital/litex),
which places every device on a [Wishbone bus](https://en.wikipedia.org/wiki/Wishbone_(computer_bus).
This is a 32-bit internal bus that maps peripherals into memory

Fomu also enabled a bridge on the bus by default that makes the it available over USB.

The `wishbone-tool` can then interact with the Fomu by basically peeking and poking memory!
See [fomu/include/generated/csr.h](https://github.com/im-tomu/micropython/blob/fomu/ports/fomu/include/generated/csr.h)
for memory addresses.

e.g. reboot the Fomu:

    $ wishbone-tool 0xe0006000 0xac
    INFO [wishbone_tool::usb_bridge] opened USB device device 011 on bus 020
    ERROR [wishbone_tool] server error: BridgeError(USBError(Io))
    INFO [wishbone_tool::usb_bridge] waiting for target device

Read and write memory:

    $ wishbone-tool 0x10000000
    INFO [wishbone_tool::usb_bridge] opened USB device device 019 on bus 020
    Value at 10000000: 00000005
    $ wishbone-tool 0x10000000 0x12345678
    INFO [wishbone_tool::usb_bridge] opened USB device device 019 on bus 020
    $ wishbone-tool 0x10000000
    INFO [wishbone_tool::usb_bridge] opened USB device device 019 on bus 020
    Value at 10000000: 12345678

Control the RGB LED (flash red)

    $ wishbone-tool 0xe0006804 1
    $ wishbone-tool 0xe0006800 200


### Next Steps

So far so good! Next steps:

* Blink an LED with C for the RISC-V CPU
* Blink an LED with verilog
* Blink an LED with Migen and LiteX

## Credits and References

* [Fomu, I’m](http://tomu.im/fomu.html) - Fomu home
* [Fomu](https://www.crowdsupply.com/sutajio-kosagi/fomu) - on crowdsupply
* [Fomu Toolchain](https://github.com/im-tomu/fomu-toolchain)
* [Fomu workshop](https://github.com/im-tomu/fomu-workshop)
* [dfu-util](https://sourceforge.net/projects/dfu-util/)
* [MicroPython docs](https://docs.micropython.org/en/latest/library/index.html)
* [The Amp Hour #456.3 – Discussing Fomu with Tim Ansell and Sean Cross](https://theamphour.com/456-3-discussing-fomu-with-tim-ansell-and-sean-cross/)
* [Fomu - an FPGA inside your USB port!](https://www.youtube.com/watch?v=rBfC-oxvaqM)
* Other tutorials/field reports:
  * [Fomu: a begineer's guide](https://www.taricorp.net/2019/fomu-beginners-guide/)
  * [Getting started with Fomu](https://www.hacklab.nl/fomu/)
  * [LiteX vs. Vivado: First Impressions](https://www.bunniestudios.com/blog/?p=5018) - bunnie
