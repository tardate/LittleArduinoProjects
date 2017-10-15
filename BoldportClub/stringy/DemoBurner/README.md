# #349 stringy/DemoBurner

Burning a new demo mode for the Boldport Club Stringy, with a Ruby script for MusicXML conversion.

![Build](./assets/DemoBurner_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

So, a long time after building the Boldport Club String, I decided to read the source ..
and discovered I totally missed the fact that [it has a demo mode](https://github.com/boldport/stringy/blob/master/software/stringy.asm#L34);-)



### First Step - Building the Original Source

It's great to see source code being released

I'm using [MPLAB X IDE v3.51](http://www.microchip.com/mplab/mplab-x-ide) on MacOSX.

After loading the source files in a new project, my first build failed with two errors:
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


Connecting up the pgrammer, and I'm seeing the device OK..

![programmer_connected](./assets/programmer_connected.png?raw=true)

And it programms without error..
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

Powering up the stringy, and it works just fine. So far so good!


## Credits and References
* [LEAP#323 stringy](../) - my original stringy build and project info
* [Original String Source](https://github.com/boldport/stringy/blob/master/software)
* [MPLAB X IDE](http://www.microchip.com/mplab/mplab-x-ide)
