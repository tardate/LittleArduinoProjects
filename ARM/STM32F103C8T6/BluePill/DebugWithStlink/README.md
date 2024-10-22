# #548 Debug Arduino STM32 with stlink

Using gdb and the stlink open source STM32 MCU programming toolset to debug code built and uploaded using the Arduino IDE on MacOSX.

![Build](./assets/DebugWithStlink_build.jpg?raw=true)

## Notes

Using the Arduino IDE with STM32 extensions is quite a convenient way to make simple programs for an ARM Cortex devices like the
ARM Cortex-M3 STM32F103C8T6 Blue Pill.

However, it does mean you miss out on the debugging features that are usually expected in "proper embedded IDEs".

If one is using an [ST-Link/V2 programmer](https://www.aliexpress.com/item/32867333890.html) instead of a USB-Serial adapter for programming the device,
then it should be possible to easily get in there with gdb for debugging.

I'm experimenting here with the [stlink](https://github.com/stlink-org/stlink) open source STM32 MCU programming toolset,
using it in conjuction with the Arduino IDE as the main compiler/programmer.

This actually works quite well!

### Building the Example Code

I'm using a simple blinky sketch [DebugWithStlink.ino](./DebugWithStlink.ino), compiled and uploaded using the Arduino IDE and ST-Link/V2 programmer.

Here's a transcript from the IDE console:

```
/Applications/Arduino.app/Contents/Java/arduino-builder -dump-prefs -logger=machine -hardware /Applications/Arduino.app/Contents/Java/hardware -hardware /Users/paulgallagher/Library/Arduino15/packages -hardware /Users/paulgallagher/MyGithub/LittleArduinoProjects/hardware -tools /Applications/Arduino.app/Contents/Java/tools-builder -tools /Applications/Arduino.app/Contents/Java/hardware/tools/avr -tools /Users/paulgallagher/Library/Arduino15/packages -built-in-libraries /Applications/Arduino.app/Contents/Java/libraries -libraries /Users/paulgallagher/MyGithub/LittleArduinoProjects/libraries -fqbn=stm32duino:STM32F1:genericSTM32F103C:device_variant=STM32F103C8,upload_method=STLinkMethod,cpu_speed=speed_72mhz,opt=osstd -ide-version=10810 -build-path /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_279421 -warnings=all -build-cache /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_cache_261188 -prefs=build.warn_data_percentage=75 -prefs=runtime.tools.arm-none-eabi-gcc.path=/Users/paulgallagher/Library/Arduino15/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1 -prefs=runtime.tools.arm-none-eabi-gcc-4.8.3-2014q1.path=/Users/paulgallagher/Library/Arduino15/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1 -prefs=runtime.tools.stm32tools.path=/Users/paulgallagher/Library/Arduino15/packages/stm32duino/tools/stm32tools/2018.4.29 -prefs=runtime.tools.stm32tools-2018.4.29.path=/Users/paulgallagher/Library/Arduino15/packages/stm32duino/tools/stm32tools/2018.4.29 -verbose /Users/paulgallagher/MyGithub/LittleArduinoProjects/ARM/STM32F103C8T6/BluePill/DebugWithStlink/DebugWithStlink.ino
/Applications/Arduino.app/Contents/Java/arduino-builder -compile -logger=machine -hardware /Applications/Arduino.app/Contents/Java/hardware -hardware /Users/paulgallagher/Library/Arduino15/packages -hardware /Users/paulgallagher/MyGithub/LittleArduinoProjects/hardware -tools /Applications/Arduino.app/Contents/Java/tools-builder -tools /Applications/Arduino.app/Contents/Java/hardware/tools/avr -tools /Users/paulgallagher/Library/Arduino15/packages -built-in-libraries /Applications/Arduino.app/Contents/Java/libraries -libraries /Users/paulgallagher/MyGithub/LittleArduinoProjects/libraries -fqbn=stm32duino:STM32F1:genericSTM32F103C:device_variant=STM32F103C8,upload_method=STLinkMethod,cpu_speed=speed_72mhz,opt=osstd -ide-version=10810 -build-path /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_279421 -warnings=all -build-cache /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_cache_261188 -prefs=build.warn_data_percentage=75 -prefs=runtime.tools.arm-none-eabi-gcc.path=/Users/paulgallagher/Library/Arduino15/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1 -prefs=runtime.tools.arm-none-eabi-gcc-4.8.3-2014q1.path=/Users/paulgallagher/Library/Arduino15/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1 -prefs=runtime.tools.stm32tools.path=/Users/paulgallagher/Library/Arduino15/packages/stm32duino/tools/stm32tools/2018.4.29 -prefs=runtime.tools.stm32tools-2018.4.29.path=/Users/paulgallagher/Library/Arduino15/packages/stm32duino/tools/stm32tools/2018.4.29 -verbose /Users/paulgallagher/MyGithub/LittleArduinoProjects/ARM/STM32F103C8T6/BluePill/DebugWithStlink/DebugWithStlink.ino
Using board 'genericSTM32F103C' from platform in folder: /Users/paulgallagher/Library/Arduino15/packages/stm32duino/hardware/STM32F1/2018.4.29
Using core 'maple' from platform in folder: /Users/paulgallagher/Library/Arduino15/packages/stm32duino/hardware/STM32F1/2018.4.29
Detecting libraries used...
/Users/paulgallagher/Library/Arduino15/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++ -c -g -Os -w -DDEBUG_LEVEL=DEBUG_NONE -std=gnu++11 -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -DBOARD_generic_stm32f103c -DVECT_TAB_ADDR=0x8000000 -DERROR_LED_PORT=GPIOC -DERROR_LED_PIN=13 -w -x c++ -E -CC -mcpu=cortex-m3 -DF_CPU=72000000L -DARDUINO=10810 -DARDUINO_GENERIC_STM32F103C -DARDUINO_ARCH_STM32F1 -DCONFIG_MAPLE_MINI_NO_DISABLE_DEBUG=1 -DSERIAL_USB -DGENERIC_BOOTLOADER -DMCU_STM32F103C8 -mthumb -march=armv7-m -D__STM32F1__ -DMCU_STM32F103C8 -mthumb -march=armv7-m -D__STM32F1__ -I/Users/paulgallagher/Library/Arduino15/packages/stm32duino/hardware/STM32F1/2018.4.29/system/libmaple -I/Users/paulgallagher/Library/Arduino15/packages/stm32duino/hardware/STM32F1/2018.4.29/system/libmaple/include -I/Users/paulgallagher/Library/Arduino15/packages/stm32duino/hardware/STM32F1/2018.4.29/system/libmaple/stm32f1/include -I/Users/paulgallagher/Library/Arduino15/packages/stm32duino/hardware/STM32F1/2018.4.29/system/libmaple/usb/stm32f1 -I/Users/paulgallagher/Library/Arduino15/packages/stm32duino/hardware/STM32F1/2018.4.29/system/libmaple/usb/usb_lib -I/Users/paulgallagher/Library/Arduino15/packages/stm32duino/hardware/STM32F1/2018.4.29/cores/maple -I/Users/paulgallagher/Library/Arduino15/packages/stm32duino/hardware/STM32F1/2018.4.29/variants/generic_stm32f103c /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_279421/sketch/DebugWithStlink.ino.cpp -o /dev/null
Generating function prototypes...
/Users/paulgallagher/Library/Arduino15/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++ -c -g -Os -w -DDEBUG_LEVEL=DEBUG_NONE -std=gnu++11 -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -DBOARD_generic_stm32f103c -DVECT_TAB_ADDR=0x8000000 -DERROR_LED_PORT=GPIOC -DERROR_LED_PIN=13 -w -x c++ -E -CC -mcpu=cortex-m3 -DF_CPU=72000000L -DARDUINO=10810 -DARDUINO_GENERIC_STM32F103C -DARDUINO_ARCH_STM32F1 -DCONFIG_MAPLE_MINI_NO_DISABLE_DEBUG=1 -DSERIAL_USB -DGENERIC_BOOTLOADER -DMCU_STM32F103C8 -mthumb -march=armv7-m -D__STM32F1__ -DMCU_STM32F103C8 -mthumb -march=armv7-m -D__STM32F1__ -I/Users/paulgallagher/Library/Arduino15/packages/stm32duino/hardware/STM32F1/2018.4.29/system/libmaple -I/Users/paulgallagher/Library/Arduino15/packages/stm32duino/hardware/STM32F1/2018.4.29/system/libmaple/include -I/Users/paulgallagher/Library/Arduino15/packages/stm32duino/hardware/STM32F1/2018.4.29/system/libmaple/stm32f1/include -I/Users/paulgallagher/Library/Arduino15/packages/stm32duino/hardware/STM32F1/2018.4.29/system/libmaple/usb/stm32f1 -I/Users/paulgallagher/Library/Arduino15/packages/stm32duino/hardware/STM32F1/2018.4.29/system/libmaple/usb/usb_lib -I/Users/paulgallagher/Library/Arduino15/packages/stm32duino/hardware/STM32F1/2018.4.29/cores/maple -I/Users/paulgallagher/Library/Arduino15/packages/stm32duino/hardware/STM32F1/2018.4.29/variants/generic_stm32f103c /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_279421/sketch/DebugWithStlink.ino.cpp -o /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_279421/preproc/ctags_target_for_gcc_minus_e.cpp
/Applications/Arduino.app/Contents/Java/tools-builder/ctags/5.8-arduino11/ctags -u --language-force=c++ -f - --c++-kinds=svpf --fields=KSTtzns --line-directives /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_279421/preproc/ctags_target_for_gcc_minus_e.cpp
Compiling sketch...
/Users/paulgallagher/Library/Arduino15/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++ -c -g -Os -Wall -Wextra -DDEBUG_LEVEL=DEBUG_ALL -std=gnu++11 -MMD -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -DBOARD_generic_stm32f103c -DVECT_TAB_ADDR=0x8000000 -DERROR_LED_PORT=GPIOC -DERROR_LED_PIN=13 -mcpu=cortex-m3 -DF_CPU=72000000L -DARDUINO=10810 -DARDUINO_GENERIC_STM32F103C -DARDUINO_ARCH_STM32F1 -DCONFIG_MAPLE_MINI_NO_DISABLE_DEBUG=1 -DSERIAL_USB -DGENERIC_BOOTLOADER -DMCU_STM32F103C8 -mthumb -march=armv7-m -D__STM32F1__ -DMCU_STM32F103C8 -mthumb -march=armv7-m -D__STM32F1__ -I/Users/paulgallagher/Library/Arduino15/packages/stm32duino/hardware/STM32F1/2018.4.29/system/libmaple -I/Users/paulgallagher/Library/Arduino15/packages/stm32duino/hardware/STM32F1/2018.4.29/system/libmaple/include -I/Users/paulgallagher/Library/Arduino15/packages/stm32duino/hardware/STM32F1/2018.4.29/system/libmaple/stm32f1/include -I/Users/paulgallagher/Library/Arduino15/packages/stm32duino/hardware/STM32F1/2018.4.29/system/libmaple/usb/stm32f1 -I/Users/paulgallagher/Library/Arduino15/packages/stm32duino/hardware/STM32F1/2018.4.29/system/libmaple/usb/usb_lib -I/Users/paulgallagher/Library/Arduino15/packages/stm32duino/hardware/STM32F1/2018.4.29/cores/maple -I/Users/paulgallagher/Library/Arduino15/packages/stm32duino/hardware/STM32F1/2018.4.29/variants/generic_stm32f103c /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_279421/sketch/DebugWithStlink.ino.cpp -o /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_279421/sketch/DebugWithStlink.ino.cpp.o
Compiling libraries...
Compiling core...
Using previously compiled file: /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_279421/core/wirish/start.S.o
Using previously compiled file: /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_279421/core/wirish/start_c.c.o
Using previously compiled file: /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_279421/core/wirish/syscalls.c.o
Using previously compiled file: /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_279421/core/board.cpp.o
Using previously compiled file: /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_279421/core/wirish/boards.cpp.o
Using previously compiled file: /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_279421/core/wirish/boards_setup.cpp.o
Using precompiled core: /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_cache_261188/core/core_33a28a35d5be94a4487e04df0719a759.a
Linking everything together...
/Users/paulgallagher/Library/Arduino15/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-g++ -Os -Wl,--gc-sections -mcpu=cortex-m3 -T/Users/paulgallagher/Library/Arduino15/packages/stm32duino/hardware/STM32F1/2018.4.29/variants/generic_stm32f103c/ld/jtag_c8.ld -Wl,-Map,/var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_279421/DebugWithStlink.ino.map -L/Users/paulgallagher/Library/Arduino15/packages/stm32duino/hardware/STM32F1/2018.4.29/variants/generic_stm32f103c/ld -o /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_279421/DebugWithStlink.ino.elf -L/var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_279421 -lm -lgcc -mthumb -Wl,--cref -Wl,--check-sections -Wl,--gc-sections -Wl,--unresolved-symbols=report-all -Wl,--warn-common -Wl,--warn-section-align -Wl,--warn-unresolved-symbols -Wl,--start-group /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_279421/sketch/DebugWithStlink.ino.cpp.o /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_279421/core/wirish/start.S.o /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_279421/core/wirish/start_c.c.o /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_279421/core/wirish/syscalls.c.o /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_279421/core/board.cpp.o /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_279421/core/wirish/boards.cpp.o /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_279421/core/wirish/boards_setup.cpp.o /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_cache_261188/core/core_33a28a35d5be94a4487e04df0719a759.a -Wl,--end-group
/Users/paulgallagher/Library/Arduino15/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-objcopy -O binary /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_279421/DebugWithStlink.ino.elf /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_279421/DebugWithStlink.ino.bin
/Users/paulgallagher/Library/Arduino15/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/arm-none-eabi-size -A /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_279421/DebugWithStlink.ino.elf
Sketch uses 16024 bytes (24%) of program storage space. Maximum is 65536 bytes.
Global variables use 3096 bytes (15%) of dynamic memory, leaving 17384 bytes for local variables. Maximum is 20480 bytes.
/Users/paulgallagher/Library/Arduino15/packages/stm32duino/tools/stm32tools/2018.4.29/macosx/stlink_upload cu.wchusbserial1420 {upload.altID} {upload.usbID} /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_279421/DebugWithStlink.ino.bin
2020-05-02T12:32:25 INFO /Users/kuwatay/src/stlink-master/src/common.c: Loading device parameters....
2020-05-02T12:32:25 INFO /Users/kuwatay/src/stlink-master/src/common.c: Device connected is: F1 Medium-density device, id 0x20036410
2020-05-02T12:32:25 INFO /Users/kuwatay/src/stlink-master/src/common.c: SRAM size: 0x5000 bytes (20 KiB), Flash: 0x10000 bytes (64 KiB) in pages of 1024 bytes
2020-05-02T12:32:25 INFO /Users/kuwatay/src/stlink-master/src/common.c: Attempting to write 16024 (0x3e98) bytes to stm32 address: 134217728 (0x8000000)

Flash page at addr: 0x08000000 erased
Flash page at addr: 0x08000400 erased
Flash page at addr: 0x08000800 erased
Flash page at addr: 0x08000c00 erased
Flash page at addr: 0x08001000 erased
Flash page at addr: 0x08001400 erased
Flash page at addr: 0x08001800 erased
Flash page at addr: 0x08001c00 erased
Flash page at addr: 0x08002000 erased
Flash page at addr: 0x08002400 erased
Flash page at addr: 0x08002800 erased
Flash page at addr: 0x08002c00 erased2020-05-02T12:32:26 INFO /Users/kuwatay/src/stlink-master/src/common.c: Finished erasing 16 pages of 1024 (0x400) bytes
2020-05-02T12:32:26 INFO /Users/kuwatay/src/stlink-master/src/common.c: Starting Flash write for VL/F0/F3 core id
2020-05-02T12:32:26 INFO /Users/kuwatay/src/stlink-master/src/flash_loader.c: Successfully loaded flash loader in sram

Flash page at addr: 0x08003000 erased
Flash page at addr: 0x08003400 erased
Flash page at addr: 0x08003800 erased
Flash page at addr: 0x08003c00 erased

  0/15 pages written
  1/15 pages written
  2/15 pages written
  3/15 pages written
  4/15 pages written
  5/15 pages written
  6/15 pages written
  7/15 pages written
  8/15 pages written
  9/15 pages written
 10/15 pages written
 11/15 pages written
 12/15 pages written
 13/15 pages written2020-05-02T12:32:26 INFO /Users/kuwatay/src/stlink-master/src/common.c: Starting verification of write complete

 14/15 pages written
 15/15 pages written2020-05-02T12:32:27 INFO /Users/kuwatay/src/stlink-master/src/common.c: Flash written and verified! jolly good!
```

Grabbing a copy of the compiled assets for examples below.
The Arudino IDE builds these in a temp filder and they'll be automatically cleaned up when we exit the Arduino IDE if we don't take a copy.
This step is actually optional if I remember not to quit the IDE.

```
$ cp /var/folders/28/_tsmhg4172s_wy7vswfkzq9h0000gn/T/arduino_build_279421/DebugWithStlink* build
$ ls -1 build/
DebugWithStlink.ino.bin
DebugWithStlink.ino.elf
DebugWithStlink.ino.map
```

### Installing stlink

For Mac users, [stlink](https://github.com/stlink-org/stlink) is perhaps most conveniently installed with homebrew:

```
$ brew install stlink
...(etc)...
$ brew info stlink
stlink: stable 1.6.0 (bottled), HEAD
STM32 discovery line Linux programmer
https://github.com/texane/stlink
/usr/local/Cellar/stlink/1.6.0 (27 files, 774.9KB) *
  Poured from bottle on 2020-05-01 at 23:35:11
From: https://github.com/Homebrew/homebrew-core/blob/master/Formula/stlink.rb
==> Dependencies
Build: cmake ✘, pkg-config ✘
Required: libusb ✔
==> Options
--HEAD
  Install HEAD version
==> Analytics
install: 704 (30 days), 2,241 (90 days), 6,412 (365 days)
install-on-request: 692 (30 days), 2,197 (90 days), 6,323 (365 days)
build-error: 0 (30 days)
$ ls  /usr/local/Cellar/stlink/1.6.0/bin
st-flash  st-info   st-util
```

### Getting Programmer Information

The `st-info` utility provides a few options to interrogate the programmer.

```
$ st-info --probe
Found 1 stlink programmers
 serial: 543f7606503f49534614013f
openocd: "\x54\x3f\x76\x06\x50\x3f\x49\x53\x46\x14\x01\x3f"
  flash: 65536 (pagesize: 1024)
   sram: 20480
 chipid: 0x0410
  descr: F1 Medium-density device
```

Note that this interrupts the program running on the device and it will need a reset.
e.g. this gets the device running again:

```
$ st-flash reset
st-flash 1.6.0
2020-05-02T15:25:41 INFO common.c: Loading device parameters....
2020-05-02T15:25:41 INFO common.c: Device connected is: F1 Medium-density device, id 0x20036410
2020-05-02T15:25:41 INFO common.c: SRAM size: 0x5000 bytes (20 KiB), Flash: 0x10000 bytes (64 KiB) in pages of 1024 bytes
```

### Flashing the Device

Although the Arduino IDE has the built-in upload capability,
it is possible to flash a new image directly:

```
$ st-flash write build/DebugWithStlink.ino.bin 0x08000000
st-flash 1.6.0
2020-05-02T12:42:36 INFO usb.c: -- exit_dfu_mode
2020-05-02T12:42:36 INFO common.c: Loading device parameters....
2020-05-02T12:42:36 INFO common.c: Device connected is: F1 Medium-density device, id 0x20036410
2020-05-02T12:42:36 INFO common.c: SRAM size: 0x5000 bytes (20 KiB), Flash: 0x10000 bytes (64 KiB) in pages of 1024 bytes
2020-05-02T12:42:36 INFO common.c: Attempting to write 16024 (0x3e98) bytes to stm32 address: 134217728 (0x8000000)
Flash page at addr: 0x08003c00 erased
2020-05-02T12:42:36 INFO common.c: Finished erasing 16 pages of 1024 (0x400) bytes
2020-05-02T12:42:36 INFO common.c: Starting Flash write for VL/F0/F3/F1_XL core id
2020-05-02T12:42:36 INFO flash_loader.c: Successfully loaded flash loader in sram
 16/16 pages written
2020-05-02T12:42:37 INFO common.c: Starting verification of write complete
2020-05-02T12:42:37 INFO common.c: Flash written and verified! jolly good!
```


### Starting Debug Host

`st-util` will start a debug host with the first stlink device it can find by default:

```
$ st-util -v
st-util 1.6.0
2020-05-02T12:43:41 DEBUG common.c: stlink current mode: mass
2020-05-02T12:43:41 DEBUG common.c: stlink current mode: mass
2020-05-02T12:43:41 DEBUG common.c: *** stlink_enter_swd_mode ***
2020-05-02T12:43:41 DEBUG common.c: *** looking up stlink version
2020-05-02T12:43:41 DEBUG common.c: st vid         = 0x0483 (expect 0x0483)
2020-05-02T12:43:41 DEBUG common.c: stlink pid     = 0x3748
2020-05-02T12:43:41 DEBUG common.c: stlink version = 0x2
2020-05-02T12:43:41 DEBUG common.c: jtag version   = 0x11
2020-05-02T12:43:41 DEBUG common.c: swim version   = 0x4
2020-05-02T12:43:41 DEBUG common.c: *** set_swdclk ***
2020-05-02T12:43:41 DEBUG common.c: *** stlink_jtag_reset ***
2020-05-02T12:43:41 DEBUG common.c: *** stlink_reset ***
2020-05-02T12:43:41 DEBUG common.c: *** stlink_write_debug32 5fa0004 to 0xe000ed0c
2020-05-02T12:43:41 INFO common.c: Loading device parameters....
2020-05-02T12:43:41 DEBUG common.c: *** stlink_core_id ***
2020-05-02T12:43:41 DEBUG common.c: core_id = 0x1ba01477
2020-05-02T12:43:41 DEBUG common.c: *** stlink_read_debug32 20036410 is 0xe0042000
2020-05-02T12:43:41 DEBUG common.c: *** stlink_read_debug32 ffff0040 is 0x1ffff7e0
2020-05-02T12:43:41 INFO common.c: Device connected is: F1 Medium-density device, id 0x20036410
2020-05-02T12:43:41 INFO common.c: SRAM size: 0x5000 bytes (20 KiB), Flash: 0x10000 bytes (64 KiB) in pages of 1024 bytes
2020-05-02T12:43:41 DEBUG common.c: *** stlink_reset ***
2020-05-02T12:43:41 DEBUG common.c: *** stlink_write_debug32 5fa0004 to 0xe000ed0c
2020-05-02T12:43:41 INFO gdb-server.c: Chip ID is 00000410, Core ID is  1ba01477.
2020-05-02T12:43:41 INFO gdb-server.c: Listening at *:4242...
```

### Setting up to Run GDB

We could use gdb from a separately installed [ARM toolchain](https://developer.arm.com), however the Arduino IDE
already has one installed. We just need to find it!

The console log provides the exact path. In my case, it is in `/Users/paulgallagher/Library/Arduino15/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin`

```
$ ls -1 /Users/paulgallagher/Library/Arduino15/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin
arm-none-eabi-addr2line
arm-none-eabi-ar
arm-none-eabi-as
arm-none-eabi-c++
arm-none-eabi-c++filt
arm-none-eabi-cpp
arm-none-eabi-elfedit
arm-none-eabi-g++
arm-none-eabi-gcc
arm-none-eabi-gcc-4.8.3
arm-none-eabi-gcc-ar
arm-none-eabi-gcc-nm
arm-none-eabi-gcc-ranlib
arm-none-eabi-gcov
arm-none-eabi-gdb
arm-none-eabi-gprof
arm-none-eabi-ld
arm-none-eabi-ld.bfd
arm-none-eabi-nm
arm-none-eabi-objcopy
arm-none-eabi-objdump
arm-none-eabi-ranlib
arm-none-eabi-readelf
arm-none-eabi-size
arm-none-eabi-strings
arm-none-eabi-strip
```

To make these tools easily available, I can temporarily update the PATH:

```
$ export PATH="/Users/paulgallagher/Library/Arduino15/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin:$PATH"
$ arm-none-eabi-gdb -v
GNU gdb (GNU Tools for ARM Embedded Processors) 7.6.0.20140228-cvs
Copyright (C) 2013 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "--host=x86_64-apple-darwin10 --target=arm-none-eabi".
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
```

### Examining the Program to Orient Debugging

The map file [DebugWithStlink.ino.map](./build/DebugWithStlink.ino.map) provides the full layout of the file,
including functions and variables.
For example, I can find:

* the main loop function at address 0x0000000008000148 (.text._Z4loopv)
* the global_counter variable is at 0x0000000020000008 (.data.global_counter)

We can also use objdump to inspect the elf file:

```
$ arm-none-eabi-objdump -h build/DebugWithStlink.ino.elf

build/DebugWithStlink.ino.elf:     file format elf32-littlearm

Sections:
Idx Name          Size      VMA       LMA       File off  Algn
  0 .text         00002e24  08000000  08000000  00008000  2**4
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
  1 .text.align   00000004  08002e24  08002e24  0000ae24  2**0
                  ALLOC, CODE
  2 .ARM.exidx    00000008  08002e28  08002e28  0000ae28  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  3 .data         00000868  20000000  08002e30  00010000  2**3
                  CONTENTS, ALLOC, LOAD, DATA
  4 .rodata       00000800  08003698  08003698  00013698  2**3
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  5 .bss          000003b0  20000868  20000868  00018868  2**2
                  ALLOC
  6 .debug_aranges 00000f80  00000000  00000000  00013e98  2**3
                  CONTENTS, READONLY, DEBUGGING
  7 .debug_info   000204f2  00000000  00000000  00014e18  2**0
                  CONTENTS, READONLY, DEBUGGING
  8 .debug_abbrev 00006165  00000000  00000000  0003530a  2**0
                  CONTENTS, READONLY, DEBUGGING
  9 .debug_line   0000ab97  00000000  00000000  0003b46f  2**0
                  CONTENTS, READONLY, DEBUGGING
 10 .debug_frame  000023a4  00000000  00000000  00046008  2**2
                  CONTENTS, READONLY, DEBUGGING
 11 .debug_str    00007bfa  00000000  00000000  000483ac  2**0
                  CONTENTS, READONLY, DEBUGGING
 12 .debug_loc    00008d02  00000000  00000000  0004ffa6  2**0
                  CONTENTS, READONLY, DEBUGGING
 13 .ARM.attributes 00000029  00000000  00000000  00058ca8  2**0
                  CONTENTS, READONLY
 14 .debug_ranges 00001ac0  00000000  00000000  00058cd1  2**0
                  CONTENTS, READONLY, DEBUGGING
 15 .comment      00000070  00000000  00000000  0005a791  2**0
                  CONTENTS, READONLY
```

### Running a Debug Session with GDB

First, initialise gdb with the elf file:

```
$ arm-none-eabi-gdb $(pwd)/build/DebugWithStlink.ino.elf
GNU gdb (GNU Tools for ARM Embedded Processors) 7.6.0.20140228-cvs
Copyright (C) 2013 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "--host=x86_64-apple-darwin10 --target=arm-none-eabi".
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>...
Reading symbols from /Users/paulgallagher/MyGithub/LittleArduinoProjects/ARM/STM32F103C8T6/BluePill/DebugWithStlink/build/DebugWithStlink.ino.elf...done.
```

Connecting to the stlink debug host on port 4242 (making sure I have `st-util` running in a separate console):

```
(gdb) target extended localhost:4242
Remote debugging using localhost:4242
__start__ () at /Users/paulgallagher/Library/Arduino15/packages/stm32duino/hardware/STM32F1/2018.4.29/variants/generic_stm32f103c/wirish/start.S:51
51          ldr r1,=__msp_init
```

Setting a breakpoint on the `loop` function and letting the program run to the breakpoint:

```
(gdb) break loop
Breakpoint 1 at 0x8000148: file /Users/paulgallagher/MyGithub/LittleArduinoProjects/ARM/STM32F103C8T6/BluePill/DebugWithStlink/DebugWithStlink.ino, line 20.
(gdb) cont
Continuing.
Note: automatically using hardware breakpoints for read-only addresses.

Breakpoint 1, loop () at /Users/paulgallagher/MyGithub/LittleArduinoProjects/ARM/STM32F103C8T6/BluePill/DebugWithStlink/DebugWithStlink.ino:20
20    output = !output;
```

Listing the code around this line:

```
(gdb) list 18,34
18  void loop() {
19    static boolean output = LOW;
20    output = !output;
21
22    if (global_counter > 10) {
23      global_counter = 1;
24    } else {
25      ++global_counter;
26    }
27
28    digitalWrite(LED_PIN, output);
29    if (output) {
30      delay(BASE_FREQ * global_counter);
31    } else {
32      delay(BASE_FREQ * global_counter);
33    }
34  }
```

Checking the local and global variables:

```
(gdb) info locals
output = false
(gdb) x/x &global_counter
0x20000008 <global_counter>:  0x00000001
```

Continue to next breakpoint and examine the change in variables:

```
(gdb) cont
Continuing.

Breakpoint 1, loop () at /Users/paulgallagher/MyGithub/LittleArduinoProjects/ARM/STM32F103C8T6/BluePill/DebugWithStlink/DebugWithStlink.ino:20
20    output = !output;
(gdb) info locals
output = true
(gdb) x/x &global_counter
0x20000008 <global_counter>:  0x00000002
```

Stepping over lines

```
(gdb) next
18  void loop() {
(gdb) next
20    output = !output;
(gdb) next
22    if (global_counter > 10) {
(gdb) next
20    output = !output;
(gdb) next
22    if (global_counter > 10) {
(gdb) next
28    digitalWrite(LED_PIN, output);
(gdb) next
22    if (global_counter > 10) {
(gdb) next
23      global_counter = 1;
(gdb) next
25      ++global_counter;
(gdb) next
28    digitalWrite(LED_PIN, output);
(gdb) next
30      delay(BASE_FREQ * global_counter);
(gdb) x/x &global_counter
0x20000008 <global_counter>:  0x00000003
```

Checking `global_counter`, and setting it to a new value that will cause a different branch in the next cycle:

```
(gdb) whatis global_counter
type = int
(gdb) p global_counter
$1 = 3
(gdb) set var global_counter=11
(gdb) cont
Continuing.

Breakpoint 1, loop () at /Users/paulgallagher/MyGithub/LittleArduinoProjects/ARM/STM32F103C8T6/BluePill/DebugWithStlink/DebugWithStlink.ino:20
20    output = !output;
(gdb) p global_counter
$2 = 11
(gdb) next
18  void loop() {
(gdb) next
20    output = !output;
(gdb) next
22    if (global_counter > 10) {
(gdb) next
20    output = !output;
(gdb) next
22    if (global_counter > 10) {
(gdb) next
28    digitalWrite(LED_PIN, output);
(gdb) next
22    if (global_counter > 10) {
(gdb) next
23      global_counter = 1;
(gdb) next
25      ++global_counter;
(gdb) next
28    digitalWrite(LED_PIN, output);
(gdb) p global_counter
$3 = 1
```

Checking and clearing breakpoints:

```
(gdb) info breakpoints
Num     Type           Disp Enb Address    What
1       breakpoint     keep y   0x08000148 in loop()
                                           at /Users/paulgallagher/MyGithub/LittleArduinoProjects/ARM/STM32F103C8T6/BluePill/DebugWithStlink/DebugWithStlink.ino:20
  breakpoint already hit 3 times
(gdb) delete 1
(gdb) cont
Continuing.
```

Example stlink console, from startup to when gdb connects:

![console_stlink](./assets/console_stlink.png?raw=true)

GDB connected via stlink:

![console_gdb](./assets/console_gdb.png?raw=true)


## Construction

ST-Link V2 connections to the "Blue Pill":

![Breadboard](./assets/DebugWithStlink_bb.jpg?raw=true)

![Schematic](./assets/DebugWithStlink_schematic.jpg?raw=true)

## Credits and References

* [stlink](https://github.com/stlink-org/stlink)
* [gdb](https://www.gnu.org/software/gdb/)
* [gdb cheat sheet](https://gist.github.com/rkubik/b96c23bd8ed58333de37f2b8cd052c30)
* [ST-Link/V2 programmer](https://www.aliexpress.com/item/32867333890.html)
