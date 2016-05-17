# #215 OSHChip/YottaToolchain

Build a simple program using the Official Yotta target for OSHChip and gcc on MacOSX

## Notes

After bruising myself on the raw [GccToolchain](../GccToolchain) - and although I got a program running - I'm think I want my toolchain to do more of the hardwork for me!

So let's try [yotta](https://github.com/ARMmbed/yotta), the software module system used by mbed OS.

### First - Don't Do This

The OSX Installer from [mbed yotta](https://www.mbed.com/en/development/software/mbed-yotta/#Installing_yotta)
looked like the easy path. But after installing, I started seeing `certificate verify failed` errors when yotta
tried to contact the yotta registry.

Turns out this is a very old build (despite just downloading minutes ago)..

```
$ yotta --version
0.8.3
```

### Try The Real Way

Use [brew](https://github.com/Homebrew/homebrew) and [pip](https://pypi.python.org/pypi/pip)!

This procedure is outlined on [yottadocs](http://yottadocs.mbed.com/#installing).

```
$ brew tap ARMmbed/homebrew-formulae
$ brew install cmake ninja arm-none-eabi-gcc
```

NB: I already have python installed, so I skipped the `brew install python`.

Before installing yotta, I used [virtualenv](https://virtualenv.pypa.io/en/latest/)
to create and activate an isolated python environment for yotta development:

```
$ virtualenv venv
$ source venv/bin/activate
```

Next install yotta:

```
$ pip install yotta
# or use the requirements.txt file I have here:
$ pip install -r requirements.txt
```

How are we doing?

```
$ yotta --version
0.16.4
```
.. that's looking a bit more healthy.


### Initialise the Project

```
$ yotta init
Enter the module name: <yottatoolchain>
Enter the initial version: <0.0.0>
Is this an executable (instead of a re-usable library module)? <no> yes
Short description:
Author:
What is the license for this project (Apache-2.0, ISC, MIT etc.)?  <Apache-2.0>
$ yotta target oshchip-gcc
info: get versions for oshchip-gcc
info: download oshchip-gcc@1.1.4 from the public module registry
info: get versions for nordic-nrf51822-gcc
info: download nordic-nrf51822-gcc@1.0.0 from the public module registry
info: get versions for mbed-gcc
info: download mbed-gcc@1.2.2 from the public module registry
$ yotta install mbed-drivers
info: mbed-drivers, *
info: get versions for mbed-drivers
info: download mbed-drivers@1.5.0 from the public module registry
info: dependency mbed-drivers: ^1.5.0 written to module.json
info: get versions for mbed-hal
info: download mbed-hal@1.3.0 from the public module registry
info: get versions for cmsis-core
info: download cmsis-core@1.2.0 from the public module registry
info: get versions for ualloc
info: download ualloc@1.3.0 from the public module registry
info: get versions for minar
info: download minar@1.3.0 from the public module registry
info: get versions for core-util
info: download core-util@1.8.0 from the public module registry
info: get versions for compiler-polyfill
info: download compiler-polyfill@1.3.0 from the public module registry
info: get versions for greentea-client
info: download greentea-client@1.1.0 from the public module registry
info: get versions for mbed-hal-nordic
info: download mbed-hal-nordic@2.1.0 from the public module registry
info: get versions for mbed-hal-nrf51822-mcu
info: download mbed-hal-nrf51822-mcu@2.2.0 from the public module registry
info: get versions for nrf51-sdk
info: download nrf51-sdk@2.4.0 from the public module registry
info: get versions for mbed-hal-mkit
info: download mbed-hal-mkit@1.1.0 from the public module registry
info: get versions for cmsis-core-nordic
info: download cmsis-core-nordic@1.1.0 from the public module registry
info: get versions for cmsis-core-nrf51822
info: download cmsis-core-nrf51822@1.4.0 from the public module registry
info: get versions for dlmalloc
info: download dlmalloc@1.1.0 from the public module registry
info: get versions for minar-platform
info: download minar-platform@1.1.0 from the public module registry
info: get versions for minar-platform-mbed
info: download minar-platform-mbed@1.3.0 from the public module registry
```

NB: the transcript above wasn't the first time I ran those commands.
The first time I did the `yotta install mbed-drivers` it punched me out to the mbed site for authentication.

### Write a Program!

Or in this case, "borrow" it from [target-OSHChip-gcc/*/examples/blinky.cpp](https://github.com/OSHChip/target-OSHChip-gcc/blob/master/examples/blinky.cpp)!

```
$ curl -Lo source/blinky.cpp https://github.com/OSHChip/target-OSHChip-gcc/blob/master/examples/blinky.cpp?raw=true
```

### Build It

```
$ yotta build
info: generate for target: oshchip-gcc 1.1.4 at /Users/paulgallagher/MyGithub/LittleArduinoProjects/OSHChip/YottaToolchain/yotta_targets/oshchip-gcc
warning: subdirectory "test" of yottatoolchain 0.0.0 at /Users/paulgallagher/MyGithub/LittleArduinoProjects/OSHChip/YottaToolchain was ignored because it doesn't appear to contain any source files
GCC version is: 5.3.1
omit frame pointer for bootloader startup asm
suppressing warnings from nrf51-sdk
-- The ASM compiler identification is GNU
-- Found assembler: /usr/local/bin/arm-none-eabi-gcc
-- Configuring done
-- Generating done
-- Build files have been written to:
[ .. etc etc etc .. and a worrying large number of compiler warnings later ... ]
[126/126] Linking CXX executable source/yottatoolchain
Memory usage for 'yottatoolchain'
section             size
.data                184
.bss                 768
.heap              19528
.stack              2048

```

It's done. Now where's my program? Found it, `yottatoolchain-combined.hex` weighing in at a handsome 404kb!

```
$ ls -sk1 build/oshchip-gcc/source/
total 1308
  0 CMakeFiles
  4 CMakeLists.txt
  4 CTestTestfile.cmake
  4 cmake_install.cmake
428 yottatoolchain
404 yottatoolchain-combined.hex
 40 yottatoolchain.bin
112 yottatoolchain.hex
312 yottatoolchain.map

```

Looking at the the first few lines of `yottatoolchain-combined.hex` I can see it setting:
* Start Linear Address: 0x0001CBF1
* Extended Linear Address: 0x0000 upper 16 bits

```
:040000050001CBF13A
:020000040000FA
:10000000C0070000D1060000D1000000B1060000CA
:1000100000000000000000000000000000000000E0
:100020000000000000000000000000005107000078
...
```
### Send it to the OSHChip

I have the OSHchip & programmer plugged into my USB and appearing as `/Volumes/Untitled/`.

So copying it over...

```
$ cp build/oshchip-gcc/source/yottatoolchain-combined.hex /Volumes/Untitled/
```

Presto, the OSHChip rebooted and is now blinking the Red onboard LED every half a second.

## Construction

![The Build](./assets/YottaToolchain_build.jpg?raw=true)

## Credits and References
* [yottadocs](http://yottadocs.mbed.com/)
* [yotta](https://github.com/ARMmbed/yotta) - GitHub
* [Official Yotta target for OSHChip using gcc](https://github.com/OSHChip/target-OSHChip-gcc)
* [virtualenv](https://virtualenv.pypa.io/en/latest/)
* [brew](https://github.com/Homebrew/homebrew)
* [pip](https://pypi.python.org/pypi/pip)
