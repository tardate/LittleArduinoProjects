# #213 OSHChip/blinky

First test of the OSHChip V1.0

## Notes

I heard about the OSHChip on the [embedded.fm podcast](http://embedded.fm/episodes/146) and immediately wanted one!

An ARM Cortex-M0 32 bit micro processor (nRF51822) with 2.4 GHz Radio and other goodies all in a breadboard-compatible DIP16 package ..
how could you say no?!

So far, so good. Literally 5 minutes to the first blinking LED, and hours of fun followed .. this is an awesome little package.

### Building with the mbed Online Compiler

The [Getting Started guide](https://github.com/OSHChip/OSHChip_Related_Files/tree/master/Getting_Started_Files/Getting_Started_With_mbed)
describes the easiest way to get up and running using the mbed online compiler.

Basically...

* sign up/ open the [mbed compiler](https://developer.mbed.org/)
* import the [OSHChip_Blinky](https://developer.mbed.org/users/OSHChip/code/OSHChip_Blinky/) sample
* compile and download the .hex file
* connect the [OSHChip CMSIS-DAP](https://www.tindie.com/products/OSHChip/oshchip-cmsis-dap-v10-swd-programmer-and-more/) to the OSHChip, plug into USB
* copy the hex file to the USB device
* it reboots and starts running the program

... 5 minutes later, I'm blinking the on-board red, green and blue LEDs. Impressive!

And I'm doing this on MacOSX. The only quirk I've noticed is
that when the chip reboots after successfully loading the program,
there an alert in the Finder about "Disk Not Ejected Properly" (as the USB drive disappears and returns). Seems completely innocuous..

Programming in action...

![programming_in_action](./assets/programming_in_action.jpg?raw=true)

### CMSIS-DAP Connection

The programming connector is a mini 4 pin header thingy.
[Connecting OSHChip to the programmer/debugger](http://oshchip.org/docs/OSHChip_Connections.html) requires some care to get the orientation correct.

* Basically, the programmer should hang off the side of the chip, with red/line 1 of the ribbon cable on the high side of the chip (pins 9-16).
* There are pin numbers on the top of the programmer's SWD 2x5 to 2x2 Adapter which also align with the pin numbers on the OSHChip.

![programmer_orientation](./assets/programmer_orientation.jpg?raw=true)

For my first test I had both jumpers on the programmer installed:

* with J1 installed, the OSHChip is powered from the programmer (and must not be plugged into the target system)
* with J5 installed, it provides a loopback TX Out to RX In, I think mainly for testing communciations from the computer side.


### Onboard LED Addressing

| Port | Device |
|------|--------|
| P0_5 | Green LED (onboard) |
| P0_3 | Blue LED (onboard)  |
| P0_8 | Red LED (onboard)   |

### Pin Functions

The 16 pins of the OSHChip are assigned as follows:

| Pin | Port       |
|-----|------------|
| 1   | P0_20      |
| 2   | P0_18      |
| 3   | P0_16      |
| 4   | P0_15      |
| 5   | P0_12      |
| 6   | P0_11      |
| 7   | P0_9       |
| 8   | GND        |
| 9   | P0_1 AIN2  |
| 10  | P0_2 AIN3  |
| 11  | P0_0 AREF0 |
| 12  | P0_27 AIN1 |
| 13  | P0_26 AIN0 |
| 14  | P0_24      |
| 15  | P0_21      |
| 16  | VDD/VCC    |


### Running Free

The OSHChip runs from 1.8V to 3.6V

To power it independently I used this
[Buck Converter Module](https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/BuckConverterModules#module-2)
dialed into 3.3V.

### Connecting Some Peripherals

Of course, an LED first.

How much current can I draw from a GPIO pin?
I ended up scouring the nRF51822 Product Specification v3.1, and closest I can find a "maximum rating" specification is the statement that *maximum number of pins with 5 mA high drive is 3.*

GPIO high is VDD-0.3V, so 3V, so I should easily be good with a
[600Ω](http://www.wolframalpha.com/input/?i=3V%2F5mA)
current-limiting resistor.

But to be super-kiasi I'll connect an LED to P0_9 (pin 7) with 1kΩ (actually draws about 1.5mA).

I modified [OSHChip_Blinky.cpp](./src/OSHChip_Blinky.cpp) to include the extra LED.
One thing I need to check further - it appears the ports are operating as "active low" by default (so logic appears inverted).


## Construction

![Breadboard](./assets/blinky_bb.jpg?raw=true)

![The Schematic](./assets/blinky_schematic.jpg?raw=true)

![The Build](./assets/blinky_build.jpg?raw=true)

## Credits and References
* [OSHChip](http://oshchip.org/) - main site
* [OSHChip](https://github.com/oshchip) - on GitHub
* [OSHChip](https://www.tindie.com/products/OSHChip/oshchip-v10/) - on tindie
* [OSHChip CMSIS-DAP](https://www.tindie.com/products/OSHChip/oshchip-cmsis-dap-v10-swd-programmer-and-more/) - on tindie
* [OSHChip_V1.0 Schematic](https://github.com/OSHChip/OSHChip_V1.0_Docs/blob/master/Other_Files/OSHChip_V1.0___Schematic.PDF)
* [nRF51822](https://www.nordicsemi.com/eng/Products/Bluetooth-Smart-Bluetooth-low-energy/nRF51822)
* [ARM Cortex-M0 Processor](http://www.arm.com/products/processors/cortex-m/cortex-m0.php) - main information centre
