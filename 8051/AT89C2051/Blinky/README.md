# #395 AT89C2051 Blinky

Simplest LED blinky program in C for the AT89C2051(8051/MCS51) microprocessor, built with the SDCC open-source toolchain on MacOSX.

![Build](./assets/Blinky_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/HSkF3Fejx3c/0.jpg)](https://www.youtube.com/watch?v=HSkF3Fejx3c)

## Notes

The main purpose of this program is simply to have something for testing the [LEAP#394 AT89C2051 Programmer](../Programmer),
and also my first trial of [SDCC - Small Device C Compiler](http://sdcc.sourceforge.net).

It is almost but not quite the simplest LED blinky program possible.
It blinks an LED on P1_0, using a do-nothing loop to approximate 1Hz cycle time.

## Installing SDCC

SDCC can be compiled from source or installed with a range of pre-compiled distributions available for Linux, Mac and Windows.

I am [using a distribution for MacOSX](http://sdcc.sourceforge.net/snap.php#MacOSX).

Here's a command line replay of what I installed:

```
wget https://excellmedia.dl.sourceforge.net/project/sdcc/snapshot_builds/i386_universal-apple-macosx/sdcc-snapshot-i386_universal-apple-macosx-20150214-9180.tar.bz2
tar -zxvf sdcc-snapshot-i386_universal-apple-macosx-20150214-9180.tar.bz2
rm sdcc-snapshot-i386_universal-apple-macosx-20150214-9180.tar.bz2
# optionally move the sdcc folder to a nice place now
export SDCC_HOME=./sdcc
export PATH=$PATH:${SDCC_HOME}/bin
```

If the sdcc folder is installed anywhere other than the current folder, it is necessary to set the `SDCC_HOME` environment variable so the compiler can find all its bits and pieces (like library header files).

## Compiling

See the `Makefile` for the couple of simple instructions that are used. It builds simply like this:

```
$ make
sdcc -mmcs51 --code-size 2048 Blinky.c -o Blinky.ihx
packihx Blinky.ihx > Blinky.hex
packihx: read 13 lines, wrote 17: OK.
```

I've checked-in all the products of the compilation for study purposes:

| File       | Description |
|------------|-------------|
| Blinky.asm | Assembler source file created by the compiler  |
| Blinky.c   | C source file |
| Blinky.hex | Optional packed hex file created by packihx |
| Blinky.ihx | The load module in Intel hex format |
| Blinky.lk  | linker options (I think) |
| Blinky.lst | Assembler listing file created by the Assembler |
| Blinky.map | The memory map for the load module, created by the Linker |
| Blinky.mem | A file with a summary of the memory usage |
| Blinky.rel | Object file created by the assembler, input to Linkage editor |
| Blinky.rst | Assembler listing file updated with linkedit information, created by linkage editor  |
| Blinky.sym | Symbol listing for the sourcefile, created by the assembler |

## Controlling the RST line

I haven't found the definitive specification for this yet - but I quickly learned that you can't just ground the RST pin
and have the chip run!

The AT89C2051 data sheet actually specifies a RST pull-down of 50kΩ-300kΩ, but it seems to be important to also
couple to VCC with a capacitor of say 2.2µF or more.
Googling for 8051 circuit schematics, I see a common combination is 8.2kΩ pull-down and 2.2µF or 10µF to VCC.

## Construction

![Breadboard](./assets/Blinky_bb.jpg?raw=true)

![Schematic](./assets/Blinky_schematic.jpg?raw=true)

![Build](./assets/Blinky_build.jpg?raw=true)

## Credits and References

* [AT89C2051 product info and datasheet](https://www.microchip.com/wwwproducts/en/AT89c2051)
* [SDCC](http://sdcc.sourceforge.net) - Small Device C Compiler
* [LEAP#394 AT89C2051 Programmer](../Programmer)
* [..as mentioned on my blog](https://blog.tardate.com/2018/07/leap395-8051-programming-with-sdcc.html)
