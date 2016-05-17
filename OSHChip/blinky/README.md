# #213 OSHChip/blinky

First test of the OSHChip V1.0

## Notes

I heard about the OSHChip on the [embedded.fm podcast #146](http://embedded.fm/episodes/146) and immediately wanted one!

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
* with J5 installed, it loops back the RX and TX on the USB-side

Here are the device details of the programmer as they appear in **System Information**

    MBED CMSIS-DAP:

      Product ID: 0x0204
      Vendor ID:  0x0d28
      Version:  1.00
      Serial Number:  900902211A9CA51FE742CAEE
      Speed:  Up to 12 Mb/sec
      Manufacturer: MBED
      Location ID:  0x14500000 / 27
      Current Available (mA): 500
      Current Required (mA):  500
      Capacity: 8.5 MB (8,454,144 bytes)
      Removable Media:  Yes
      Detachable Drive: Yes
      BSD Name: disk2
      Partition Map Type: Unknown
      S.M.A.R.T. status:  Not Supported


#### Enabling Serial Output

The OSHChip_Blinky.cpp sample uses printf to log to the onboard UART at 9600 baud 8N1:

    printf("Loop Count:  %8d\r\n", loop_count++);

By default TX is on pin 1 of the OSHChip. To read the output via the CMSIS-DAP programmer,
connect pin 1 of the OSHChip to the RX (top corner) pin of J5 on the programmer.

Similarly for serial input, connect TX (lower) pin of J5 on the programmer to pin 2 on the OSHChip.

![programmer_with_serial](./assets/programmer_with_serial.jpg?raw=true)

On MacOSX, the programmer shows up as a character device:

    $ ls -1 /dev/cu*
    /dev/cu.Bluetooth-Incoming-Port
    /dev/cu.Bluetooth-Modem
    /dev/cu.usbmodem1452  # <- this one (it appeared after connecting the programmer)

The simplest way of getting connected on MacOSX is to use screen at 9600 baud:

    $ screen /dev/cu.usbmodem1452 9600
    Loop Count:         0
    Loop Count:         1
    Loop Count:         2

A screen session in action:

![screen_session](./assets/screen_session.png?raw=true)


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
| 1   | P0_20 TX   |
| 2   | P0_18 RX   |
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
I modified [OSHChip_Blinky.cpp](./src/OSHChip_Blinky.cpp) to include an extra LED, connected on P0_9 (pin 7).

The default configuration of the nRF51822 GPIO pins is standard drive strength (0.5mA) for both logic high and logic low,
and operate as active low.

The onboard LEDs are setup for active low drive, so I'll stick with that to keep the logic consistent. In other works the LEDs sink to the port when enabled.

The onboard LEDs are specially selected low current components, but my external LED could do with a little more juice
than the 0.5mA available in standard drive.

The nRF51 Series Reference Manual V3.0 specifies the GPIO configuration options (section 14, p56 on).
The following parameters can be configured through the PIN_CNF[n] registers:

* Direction
* Drive strength
* Enabling of pull-up and pull-down resistors
* Pin sensing
* Input buffer disconnect
* Analog input (for selected pins)

Using the constants defined in `nrf51_bitfields.h`, I'm configuring P0_9 (pin 7) as follows:

    /* configure OSHChip_Pin_7 for high drive active low */
    NRF_GPIO->PIN_CNF[OSHChip_Pin_7] =
          (GPIO_PIN_CNF_SENSE_Disabled << GPIO_PIN_CNF_SENSE_Pos)   // turn off pin sensing
        | (GPIO_PIN_CNF_DRIVE_H0S1 << GPIO_PIN_CNF_DRIVE_Pos)       // high drive 0, standard 1
        | (GPIO_PIN_CNF_PULL_Disabled << GPIO_PIN_CNF_PULL_Pos)     // disable pullups
        | (GPIO_PIN_CNF_INPUT_Disconnect << GPIO_PIN_CNF_INPUT_Pos) // input buffer disconnect
        | (GPIO_PIN_CNF_DIR_Output << GPIO_PIN_CNF_DIR_Pos);        // for output

That provides for sinking up to 5mA i.e. when the LED is on.
Conservatively ignoring the voltage drop across the LED and internal driver FETs,
that means I should be good with a [660Ω](http://www.wolframalpha.com/input/?i=3.3V%2F5mA)
current-limiting resistor for the LED. Using 1kΩ, the actual LED current when on is ~1.5mA.


#### An Explanation from Philip

Philip (the OSHChip creator) graciously provided the following information to explain what's going on:

The nRF51822 I/O pins are specified for 0.5 mA for both logic low and high when configured for standard drive strength. If a pin is configured for high strength, then the current can be as high as 5 mA , but no more than 3 GPIO pins should be configured this way. (Actually, the constraint is more likely: no more than 3 GPIO pins should be supplying 5 mA concurrently). The default configuration for GPIO pins is normal drive strength.
This is documented in the nRF51822 Product Specification V3.1 on page 65.

An output with high drive strength for logic low (H0) and standard drive strength for logic high (S1) is setup like this:
From the nRF51822 Series Reference Manual V3.0 on page 68.

For physical pin 7 (port bit P0_9)

    NRF_GPIO->PIN_CNF[9] = (GPIO_PIN_CNF_SENSE_Disabled << GPIO_PIN_CNF_SENSE_Pos)
    | (GPIO_PIN_CNF_DRIVE_H0S1 << GPIO_PIN_CNF_DRIVE_Pos)
    | (GPIO_PIN_CNF_PULL_Disabled << GPIO_PIN_CNF_PULL_Pos)
    | (GPIO_PIN_CNF_INPUT_Disconnect << GPIO_PIN_CNF_INPUT_Pos)
    | (GPIO_PIN_CNF_DIR_Output << GPIO_PIN_CNF_DIR_Pos);

This would configure OSHChip_Pin_7 for active low drive, with the other end of the LED/Resistor series pair connected to the 3.3 Volt supply. As a general rule of thumb, in CMOS chips, the output low driver (implemented with an N-Channel FET, is about twice as good (speed, drive strength) than the logic high driver (implemented with a P-Channel FET).

So what resistor do we choose? The above all assumes we want to maintain valid logic levels that are within 0.3V of their respective rails, but we are just driving a LED, and just want it to turn on. So here are 2 real examples:

The built in LEDs on OSHChip are specially selected low current LEDs, designed for 5 mA test current. The resistors are 4.7K Ohms (at about 1.7 V drop across the LED, 340 uA actual LED current). There are some OSHChips that were built with 20 mA test current LEDs for the green LED, and they had the appropriate resistor changed to 1K Ohms (at about 1.9 V drop across the LED, 1.4 mA actual LED current). All of these are quite bright with these values, and the outputs configured for standard drive for both low and high, with the LEDs illuminated when the output is low.

Nordic Semiconductor has the nRF51-DK board that has 4 LEDs, that have only a 220 resistor, and none of their examples put the outputs into high drive mode. So a clear violation of all the rules by the chip supplier. It works just fine.

Philip's recommendation: use active low drive the same as the on-board LEDs and how the nRF51-DK board do it. Pick LEDs that are designed for low current, and see if it works with 4.7K, then 2.7 K, then 1.0 K. Look at the OSHChip schematic to see how it is done.


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
* [OSHChip_CMSIS-DAP_V1.0 Schematic](https://github.com/OSHChip/OSHChip_CMSIS_DAP_V1.0_Docs/blob/master/Other%20Files/OSHChip_CMSIS-DAP_V1.0___Schematic_Prints.PDF)
* [nRF51822](https://www.nordicsemi.com/eng/Products/Bluetooth-Smart-Bluetooth-low-energy/nRF51822) - main information centre
* [ARM Cortex-M0 Processor](http://www.arm.com/products/processors/cortex-m/cortex-m0.php) - main information centre
