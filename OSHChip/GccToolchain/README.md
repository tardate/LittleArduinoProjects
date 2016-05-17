# #214 OSHChip/GccToolchain

Can I build a program for the OSHChip using the gcc toolchain and Nordic Semi SDK on MacOSX?

## Notes

This is still a work-in-progress. I have been able to compile and deploy a simple program, but there remain a few rough edges.

Notes below represent the best current state I've got to.

There are probably easier ways to do this ... like using the
[Official Yotta target for OSHChip using gcc](https://github.com/OSHChip/target-OSHChip-gcc) ...
but I was curious to see how far I could get with just gcc and the Nordic Semi SDK.

## The Example Program

Nothing special - [blinky.c](./blinky.c) is just an LED blinker (using the onboard LEDs).
It is C not C++ (learn how to crawl before I walk).


## The Moving Parts

I'm guided by the (now a little dated) post:
[Getting started with nRF51 development on Mac OS X](https://devzone.nordicsemi.com/blogs/22/getting-started-with-nrf51-development-on-mac-os-x/). I'll be doing something similar:

* installing [GCC ARM Embedded](https://launchpad.net/gcc-arm-embedded)
* using an SDK from [Nordic Semiconductor developer zone](http://developer.nordicsemi.com/)

I'm testing with two version of the SDK, as I'm not sure if there's a good reason for one over the other yet:

* 11.0.0 (latest version as of now)
* 6.0.0 (version as used by many examples on the net)

These are installed locally, in this folder. If I find a solid configuration, I'll then think about a shared installation.
Having a particioned development environment is always nice anyway.


## Installation

The [setup.sh](./setup.sh) script automates some steps that could be done manually if desired:

* download and unzip the GCC ARM kit to `./gcc-arm-none-eabi-5_3-2016q1`
* download and unzip two versions of the NordicSemi SDK to `./sdk.6` and `./sdk.6`
* patch the Markfile.posix in each SDK to reference the GCC ARM Embedded installed in the first step

## Make with SDK 11.0.0

Use the `make.11` folder to build with the 11.0.0 SDK.

```
$ cd make.11
$ make
rm -rf _build
echo  Makefile
Makefile
mkdir _build
Compiling file: blinky.c
Compiling file: system_nrf51.c
Compiling file: nrf_delay.c
Assembly file: gcc_startup_nrf51.s
Linking target: nrf51422_xxac.out
Preparing: nrf51422_xxac.bin
Preparing: nrf51422_xxac.hex

   text    data     bss     dec     hex filename
   1020     108      28    1156     484 _build/nrf51422_xxac.out

```

The build results are generated in `make.11/_build`.

The hex file to install in the OSHChip is `make.11/_build/nrf51422_xxac.hex`

If the OSHChip programmer shows up as the only `Untitled` device, there's a make target to copy & install:

```
$ make cpinstall
Linking target: nrf51422_xxac.out
Preparing: nrf51422_xxac.bin
Preparing: nrf51422_xxac.hex

   text    data     bss     dec     hex filename
   1028     108      28    1164     48c _build/nrf51422_xxac.out

Copying: _build/nrf51422_xxac.hex
cp _build/nrf51422_xxac.hex /Volumes/Untitled/
```

## Make with SDK 6.0.0

Use the `make.6` folder to build with the 6.0.0 SDK.

```
$ cd make.6
$ make
mkdir _build
[..blah blah..]

```

The build results are generated in `make.6/_build`.

The hex file to install in the OSHChip is `make.6/_build/blinky_xxaa.hex`

If the OSHChip programmer shows up as the only `Untitled` device, there's a make target to copy & install:

```
$ make cpinstall
Copying: _build/blinky_xxaa.hex:
cp _build/blinky_xxaa.hex /Volumes/Untitled/

```

## So Far So Good, But...

Copy the hex files to the OSHChip Programmer USB device ... and they won't install.

After a bit of digging around and comparing "good" .hex files with those that refuse to install via the programmer,
it seems that the OSHChip programmer is only recognising those encoded with an Extended Linear Address record.

These hex files are generated with `gcc-arm-none-eabi-5_3-2016q1/bin/arm-none-eabi-objcopy` and are in the
[Intel HEX](https://en.wikipedia.org/wiki/Intel_HEX) format.

Here's the start of a "good" hex file, from the [blinky](../blinky) project I compiled with the mbed online tools:

```
:020000040000FA
:10000000C0070000D1060000D1000000B1060000CA
:1000100000000000000000000000000000000000E0
:100020000000000000000000000000005107000078
...
```

And here's the start of the file compiled with SDK 11.0.0:

```
:10000000008000208D030000CD030000CF0300001E
:1000100000000000000000000000000000000000E0
:10002000000000000000000000000000D1030000FC
...
```

The first and most obvious difference is that `:020000040000FA` record at the beginning. It's an Extended Linear Address record:

* `:` - Start code, one character, an ASCII colon ':'
* `02` - Byte count, two hex digits, indicating the number of bytes (hex digit pairs) in the data field.
* `0000` - Address, four hex digits, representing the 16-bit beginning memory address offset of the data. The physical address of the data is computed by adding this offset to a previously established base address, thus allowing memory addressing beyond the 64 kilobyte limit of 16-bit addresses. The base address, which defaults to zero, can be changed by various types of records. Base addresses and address offsets are always expressed as big endian values.
* `04` - Record type, two hex digits, 00 to 05, defining the meaning of the data field. `04` = Extended Linear Address
* `0000` - Data, a sequence of n bytes of data, represented by 2n hex digits. Some records omit this field (n equals zero). The meaning and interpretation of data bytes depends on the application.
* `FA` - Checksum, two hex digits, a computed value that can be used to verify the record has no errors.

Extended Linear Address:

> Allows for 32 bit addressing (up to 4GiB). The address field is ignored (typically 0000) and the byte count is always 02. The two encoded, big endian data bytes specify the upper 16 bits of the 32 bit absolute address for all subsequent type 00 records; these upper address bits apply until the next 04 record. If no type 04 record precedes a 00 record, the upper 16 address bits default to 0000. The absolute address for a type 00 record is formed by combining the upper 16 address bits of the most recent 04 record with the low 16 address bits of the 00 record.

Now this seemed a whole bunch of nothing: set extended linear addressing at offset 0?

Time for a quick experiment: manually adding `:020000040000FA` to the top of one of the failing hex files. Now it copies and installs correctly!

I've hunted high and low for objcopy or linker options to `force` extended linear addressing but can't find anything.

So for now (and a real hack) is that I've updated `make cpinstall` to patch the hex file if necessary to add the extended linear addressing directive. The hex patch is applied using the [ensure_ela.sh](./ensure_ela.sh) script.

I'll need to follow-up on this situation - it's a bit hairy.
I since found this [arm-gcc hex file header question](http://www.oshchip.com/forum/viewtopic.php?f=7&p=395#p395)
on the OSChip forum which points to the same issue.. a good place to start..

## Construction

![The Build](./assets/GccToolchain_build.jpg?raw=true)

## Credits and References
* [Getting started with nRF51 development on Mac OS X](https://devzone.nordicsemi.com/blogs/22/getting-started-with-nrf51-development-on-mac-os-x/)
* [GCC ARM Embedded](https://launchpad.net/gcc-arm-embedded)
* [nordicsemi SDK](http://developer.nordicsemi.com/)
* [Moving from nRF51822 to nRF51422?](https://devzone.nordicsemi.com/question/30569/moving-from-nrf51822-to-nrf51422/) - devzone question
* [arm-gcc hex file header question](http://www.oshchip.com/forum/viewtopic.php?f=7&p=395#p395)
* [Intel HEX](https://en.wikipedia.org/wiki/Intel_HEX) - wikipedia
* [objcopy](https://sourceware.org/binutils/docs/binutils/objcopy.html)
