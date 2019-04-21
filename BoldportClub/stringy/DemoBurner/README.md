# #349 stringy/DemoBurner

Burning a new demo mode for the Boldport Club Stringy, with a Ruby gem for MusicXML conversion to PIC assembler.

A quick video of the the new demo...

[![Build](https://img.youtube.com/vi/Jn1iYxQHtXs/0.jpg)](https://youtu.be/Jn1iYxQHtXs)

## Notes

So, a long time after building the Boldport Club String, I decided to read the source ..
and discovered I totally missed the fact that [it has a demo mode](https://github.com/boldport/stringy/blob/master/software/stringy.asm#L34);-)

I was reading the source to learn more about what tricks James Hutchby used to implement the Karplus-Strong algorithm,
but now I am distracted and decided first to make some new demo tracks.


### First Step - Building the Original Source

It's great to see source code being released, thank you Boldport and MadLabs!

I'm using [MPLAB X IDE v3.51](http://www.microchip.com/mplab/mplab-x-ide) on MacOSX.

After loading the source files in a [new project CustomDemo.X](./CustomDemo.X),
my first build failed with two errors:
```
Error[151]   LittleArduinoProjects/BoldportClub/stringy/DemoBurner/CustomDemo.X/stringy.asm 1426 : Operand contains unresolvable labels or is too complex
Error[151]   LittleArduinoProjects/BoldportClub/stringy/DemoBurner/CustomDemo.X/stringy.asm 469 : Operand contains unresolvable labels or is too complex
```
It seems this is to do with addressing, so I switch to absolute mode:

![build_mode](./assets/build_mode.png?raw=true)

.. and now it builds

```
make -f nbproject/Makefile-default.mk SUBPROJECTS= .build-conf
make[1]: Entering directory 'LittleArduinoProjects/BoldportClub/stringy/DemoBurner/CustomDemo.X'
make  -f nbproject/Makefile-default.mk dist/default/production/CustomDemo.X.production.hex
make[2]: Entering directory 'LittleArduinoProjects/BoldportClub/stringy/DemoBurner/CustomDemo.X'
"/Applications/microchip/mplabx/v3.51/mpasmx/mpasmx" -q -p12f1840 -u \"LittleArduinoProjects/BoldportClub/stringy/DemoBurner/CustomDemo.X/stringy.asm\"
"/Applications/microchip/mplabx/v3.51/mpasmx/mplink"    -p12f1840  -w  -m"dist/default/production/CustomDemo.X.production.map"   -z__MPLAB_BUILD=1  -odist/default/production/CustomDemo.X.production.cof  build/default/production/stringy.o
MPLINK 5.08, LINKER
Device Database Version 1.34
Copyright (c) 1998-2011 Microchip Technology Inc.
Errors    : 0

MP2HEX 5.08, COFF to HEX File Converter
Copyright (c) 1998-2011 Microchip Technology Inc.
Errors    : 0

make[2]: Leaving directory 'LittleArduinoProjects/BoldportClub/stringy/DemoBurner/CustomDemo.X'
make[1]: Leaving directory 'LittleArduinoProjects/BoldportClub/stringy/DemoBurner/CustomDemo.X'

BUILD SUCCESSFUL (total time: 880ms)
Loading code from LittleArduinoProjects/BoldportClub/stringy/DemoBurner/CustomDemo.X/dist/default/production/CustomDemo.X.production.hex...
Loading completed
```

### Step Two - Reprogramming the Stringy

The stringy board has pin sockets for all the PIC pins (even in the same order as exposed from a programmer),
so I'm guessing I can program this in-circuit?

| Programmer Port | PIC Pin       | Encumberances?                                                                                          |
|-----------------|---------------|---------------------------------------------------------------------------------------------------------|
| 1: VPP          | 4 MCLR        | Normally-open S1. OK                                                                                    |
| 2: VDD          | 1 VDD         | Battery and regulator, OK if battery not attached                                                       |
| 3: GND          | 8 GND         | Battery OK if battery not attached                                                                      |
| 4: PGD          | 7 RA0/ICSPDAT | 1kΩ pull-down resistor. Hmm, should be OK?                                                              |
| 5: PGC          | 6 RA1/ICSPCLK | 1MΩ pull-down resistor and "plectrum" leads. Make sure plectrums are safely isolated during programming |


Here's a PICkit 3 connected to the stringy, with some blu tack assist:

![Build](./assets/DemoBurner_build.jpg?raw=true)

Connecting up the programmer, and I'm seeing the device OK..

![programmer_connected](./assets/programmer_connected.png?raw=true)

And it programs without error..
```
*****************************************************

Connecting to MPLAB PICkit 3...

Currently loaded firmware on PICkit 3
Firmware Suite Version.....01.46.14
Firmware type..............Enhanced Midrange

Programmer to target power is enabled - VDD = 4.750000 volts.
Target device PIC12F1840 found.
Device ID Revision = 5

Device Erased...

Programming...

The following memory area(s) will be programmed:
program memory: start address = 0x0, end address = 0x49f
configuration memory
User Id Memory
Programming/Verify complete
```

Note that I've enabled powering the device, so I can test it without having to install a battery.
Out of habit, I set the voltage at 4.75V instead of 5V, as the PICkit 3 is prone to errors otherwise.

Power up the stringy, and it works just fine. So far so good!


### Burning a new Demo

So the final thing I want to do for now is burn new demo track.

.. but I don't want to be transcribing/composing in assembler, so instead I "assembled" this workflow:

* score in [Guitar Pro](https://www.guitar-pro.com/en/index.php)
* export to MusicXML
* convert to assembler for the stringy with a Ruby gem [StringyFi](https://github.com/tardate/stringyfi)
* compile with [MPLAB X IDE](http://www.microchip.com/mplab/mplab-x-ide)
* program the stringy using a PICkit 3

Olé!

See the music sources in [examples](./examples) - `*.gp` is the Guitar Pro file, `*.xml` is the MusicXML export.

My first attempts were with some quite complex scores and I immediately ran into the major problem:
the current stringy code only allows for 2-bits worth of note duration, which doesn't cut it
for anything ranging from half notes to 32nd's, with dotted notes and ties!

So I limited myself and found a nice (appropriately named) candidate - the main riff from Deep Purple's Burn.
I still had to simplify the transcription somewhat to encourage the stringy to play it decently,
and I think the result is "OK" .. see it on [YouTube](https://youtu.be/Jn1iYxQHtXs).

Here's the simplified score:

![BurnIntro](./examples/BurnIntro.png?raw=true)

### MusicXML Conversion

I clobbered together some routines I'd used before into a simple converter packaged as the Ruby gem `stringyfi`.
It has to make a whole lot of assumptions like: only covert 1 part, 1 voice, and choose the closest duration.
It currently pays no attemption to original tempo, and doesn't support many notation features (such as tied notes).

### Installing the Coverter

There's a Gemfile waiting to install in this directory. Assuming you have a working Ruby environment:

```
$ gem install bundler  # if not already installed
$ bundle install
```

### Running a Conversion

Choose the XML to convert, and pipe the output into the `demo.tun` file

```
$ stringyfi ./examples/BurnIntro.xml > ./CustomDemo.X/demo.tun
converting ./examples/BurnIntro.xml..
  shortest_fractional_duration: 0.125
  octave_range: [3, 5]
.. done.
```

### Recompiling

Now just recompile the [CustomDemo.X](./CustomDemo.X) project with MPLAB and program.
Here's BURN getting burned:

```
*****************************************************

Connecting to MPLAB PICkit 3...

Currently loaded firmware on PICkit 3
Firmware Suite Version.....01.46.14
Firmware type..............Enhanced Midrange

Programmer to target power is enabled - VDD = 4.750000 volts.
Target device PIC12F1840 found.
Device ID Revision = 5

Device Erased...

Programming...

The following memory area(s) will be programmed:
program memory: start address = 0x0, end address = 0x49f
configuration memory
User Id Memory
Programming/Verify complete
```

### Reverting the Source

The [freshen_source.sh](./freshen_source.sh) script grabs the original sources files (including the original demo)
and replaces the sources in [CustomDemo.X](./CustomDemo.X) project.

Useful to:

* put the original demo tune back in place
* undo any modifications to the firmware and revert to "factory" mode

### Next Steps

After investigating the original source, I've seen a few areas that might be worth working on:

* finer-grained duration control. 2 bits isn't enough for more complex scores
* running longer tracks. When I tried longer pieces, I suspect I ran into memory addressing limits or possibly timing bugs  - not sure which yet, but 20 odd measures in, the stringy would go haywire.


## Credits and References
* [LEAP#323 stringy](../) - my original stringy build and project info
* [StringyFi](https://github.com/tardate/stringyfi) - source for the MusicXML conversion gem
* [Original String Source](https://github.com/boldport/stringy/blob/master/software)
* [MPLAB X IDE](http://www.microchip.com/mplab/mplab-x-ide)
* [Guitar Pro](https://www.guitar-pro.com/en/index.php)
* [..as mentioned on my blog](https://blog.tardate.com/2017/10/leap349-burn-a-new-demo-for-the-stringy.html)
