# #386 BluePill

Programming an ARM Cortex-M3 STM32F103C8T6 Blue Pill board with the Arduino IDE.

![Build](./assets/BluePill_build.jpg?raw=true)


[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

Popularly known as the [Blue Pill](http://wiki.stm32duino.com/index.php?title=Blue_Pill),
the STM32F103C8T6 Minimum System Development Board seems like an excellent gateway drug for getting into ARM Cortex-M3 development.

This is particularly true as it is possible to program it with the familar Arduino IDE.

This is my first look at one of these boards, so I have simple expectations - follow along some of the tutorials
on the web/youtube and at least get a simple program running on the board. In the process I'll learn
a bit more about the board's capabilities and quirks.

## Board Specs

* ARM Cortex M3
* 72 MHz
* 64 KB
* 20 KB RAM
* Reset button
* LED on PIN PC13
* 32 kHz Real time clock crystal
* Jump links on Boot0 and Boot1
* Micro USB connector for power and data
* ST-Link header on the top of the board.

### Pinouts

[![Bluepillpinout](./assets/Bluepillpinout.gif?raw=true)](http://wiki.stm32duino.com/index.php?title=Blue_Pill)


### Power

The STM32F103C8 operates from 2.0 to 3.6V.
The development board includes a 3.3V LDO regulator, and since many pins are 5V-tolerant, this allows the board to be used
with 5V USB power.


## Programming with the Arduino IDE

I'm following the
[STM32 Arduino Tutorial - How to use the STM32F103C8T6 board with the Arduino IDE](http://www.youtube.com/watch?v=K-jYSysmw9w)
YouTube tutorial by educ8s.tv. This is one of many, but it is the most accurate and up-to-date that I found in a quick search.

[![clip](http://img.youtube.com/vi/K-jYSysmw9w/0.jpg)](http://www.youtube.com/watch?v=K-jYSysmw9w)

Here's how the process went for me....

### Adding Board Support to the IDE

NB: I'm running Arduino IDE 1.8.2 on MacOSX at the time of this test.

A Boards Manager package is created by Dan Drown, the instructions are on
[the stm32duino site](http://wiki.stm32duino.com/index.php?title=Boards_Manager_package)

Add custom boards package [package_STM32duino_index.json](http://dan.drown.org/stm32duino/package_STM32duino_index.json) in Preferences

![setup_board_manager](./assets/setup_board_manager.png?raw=true)

Install the `STM32F1xx/GD32F1xx boards` package by stm32duino in the Board Manager:

![setup_install_boards](./assets/setup_install_boards.png?raw=true)



### Connecting a Serial Programmer

I'm using a CH340G USB-serial adapter from MacOSX (similar but different to FTDI-based adapters).

Connections are as follows:

| USB-Serial | BluePill |
|------------|----------|
|  GND       |  GND     |
|  VCC       |  5V      |
|  RXD       |  A9      |
|  TXD       |  A10     |


![Breadboard](./assets/BluePill_bb.jpg?raw=true)

![Schematic](./assets/BluePill_schematic.jpg?raw=true)


![Build](./assets/BluePill_build.jpg?raw=true)


### Uploading Sketch

The [Blink.ino](./Blink/Blink.ino) sketch is just about the simplest thing possible - blinks the LED connected on port PC13.
This is not showing off the board capabilities at all - I'm just trying to verify the programming process.

For programming, the BluePill Boot0 jumper is set to 1 (pulled high).

From the Arduino IDE, the program compiled and uploaded over serial without any issue..

![serial_programming](./assets/serial_programming.png?raw=true)

After disconnecting the serial programmer and switching the BluePill Boot0 jumper to 0 (pulled low),
the board can be powered from USB with the program running:

![BluePill_usb_powered](./assets/BluePill_usb_powered.jpg?raw=true)


## Credits and References
* [ARM Cortex-M3 STM32F103C8T6 Minimum System Development Board STM32](https://www.aliexpress.com/item/STM32F103C8T6-ARM-STM32-Minimum-System-Development-Board-Module-For-Arduino/32667468626.html) - example from a seller on aliexpress
* [STM32F103C8 Product Info and Datasheet](http://www.st.com/en/microcontrollers/stm32f103c8.html)
* [Blue Pill](http://wiki.stm32duino.com/index.php?title=Blue_Pill) - stm32duino wiki
* [Blue Pill Fritzing Part source](http://blog.naver.com/PostView.nhn?blogId=chandong83&logNo=221026011343&categoryNo=0&parentCategoryNo=39&viewDate=&currentPage=1&postListTopCurrentPage=1&from=search)
* [..as mentioned on my blog](https://blog.tardate.com/2018/05/leap386-the-blue-pill.html)
