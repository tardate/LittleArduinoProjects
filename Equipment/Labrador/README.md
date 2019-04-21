# #324 Labrador

First look at the EspoTek Labrador USB "lab-on-a-board" hardware and software.

![Build](./assets/Labrador_build.jpg?raw=true)

## Notes

The [EspoTek Labrador](https://www.crowdsupply.com/espotek/labrador) is a crowd-funded
lab-on-a-board that includes an oscilloscope, waveform generator, power supply, logic analyzer, and multimeter.
I was drawn to the project specifically because it promised open hardware, and multi-platform open source software.

I just received a Labrador board, and this project is an initial test and review.

## Board Inspection

I have the "backer edition batch 1" version of the board, which has the same layout as shown in this pinout diagram:

![pinout](./assets/pinout.png?raw=true)

With a few liberties (slight bend in the underside PSU pins), I was able to mount the board pretty conveniently on a breadboard.
The PSU pins connect to the breadboard rail (see below: the default 4.5V output reading as 4.69V on my multimeter).

With a few minor modifications, the board could probably be made much more breadboard compatible.

![Labrador_dut](./assets/Labrador_dut.jpg?raw=true)


## Software Install and Power Up

After connecting the USB cable, the board was detected without any issue by the MacOSX USB subsystem. This is how it appers in System Information:

![usb_info](./assets/usb_info.png?raw=true)

First a first test, I'm using a precompiled MacOSX 64 bit binary provided in the pre-release software and documentation kit.

On initial startup, it appeared to "freeze" but I gather it was probably just taking some time to update the firmware on the board.
Now the device is detected immediately by the software, and I was able to test all the major functions of the software without any problem.

A ran the calibration routine (Menu: Oscilloscope > Calibrate) before running the tests.

## Testing the Features

### Oscilloscope

Showing an external 1kHz 4V peak-to-peak signal connected to channel 1 in the software.
I even figured out how to place horizontal and vertical cursors to make convenient readings.

![test_scope](./assets/test_scope.png?raw=true)

### Signal Generator

Configuring the signal generator:

* CH1: 1kHz Sine 1V peak-to-peak
* CH2: 2kHz Sawtooth 1V peak-to-peak

Here's the capture on an external scope:

![test_fg](./assets/test_fg.gif?raw=true)

Some slight adjustments:

* CH1: 1kHz Sine 2V peak-to-peak
* CH2: 4kHz Sawtooth 2V peak-to-peak

Here's the capture as fed back to the board's own scope:

![test_fg_to_scope](./assets/test_fg_to_scope.png?raw=true)

### Power Supply

I could control the power supply in software from 4.5 to 12V.
My multimeter doesn't quite agree with the output levels; I will need to make some more measurements with properly calibrated equipment.
I also haven't put the power supply under any load. According to specs it should be able to provide up to ~1.5W.

### Multimeter

The oscilloscope channels are used to support multimeter functions.

#### Measuring Voltage

The load is connected between Oscilloscope CH1 pin 1 and Oscilloscope CH2 pin 1. Few things to note:

* positive voltage is measured as CH2 with respect to CH1.
* Must disable both oscilloscope channels in the software before the multimeter mode can be enabled

For a quick test, I'm measuring the PSU output with the voltmeter:

![test_voltmeter_setup](./assets/test_voltmeter_setup.jpg?raw=true)

With the PSU dialed into 6V, the voltmeter measures 6.4V. This actually agrees with my standalone voltmeter,
and seems to indicate the PSU output regulation is pretty poor (at least when unloaded).

![test_voltmeter](./assets/test_voltmeter.png?raw=true)

### Logic Analyxer

Not tested this yet..

## Quick Look: Software

The software for both the AVR and the desktop application are open source and available on [GitHub](https://github.com/espotek/Labrador).

The desktop application is developed with Qt Creator. I haven't tried to build the software yet.

Here are my notes from a quick scan of the source:

* libusb and Linux/Windows/Mac/Android specifics are wrapped in a generic USB model as the main bridge for communicating with the board
* an isoBuffer class that enables O(1) performance for read/write operations, while maintaining a huge buffer size
* most of the rest of the code is UI related


## Quick Look: Schematic

The design files are open source and available on [GitHub](https://github.com/espotek/Labrador).
There is a KiCAD project that I was able to open with only a single warning (a missing custom component library, I haven't determined what this impacts yet).

The design appears to breakdown into these main subsystems:

* ATXMEGA32A4U-AU Low power, high performance 8/16-bit AVR microcontroller
* analog scope front end, with signals buffered with LM324 opamps
* 78L05 3.3V regulated power from USB
* boost converter directly controlled by PWM from the AVR processor
* heavily filtered/smoothed AVCC from the regulated 3.3 supply
* logic analyzer input via n-channel MOSFETs (DMN63D8LDW)
* DAC ouput direct from AVR buffered with LM324 opamps

![Labrador_schematic](./assets/Labrador_schematic.jpg?raw=true)

## Quick Look: PCB

The batch 1 backer edition of the board is a nice compact board. With a slight bend on the PSU pins, it can even fit quite nicely on a standard MB105 breadboard.

Here's a 3D render of the board in kicad:

![Labrador_pcb_3d](./assets/Labrador_pcb_3d.png?raw=true)

### Digital Out

The board includes pinouts for 4 GPIO ports (PE0-3). However it appears these are not given any specific fucntion in the current AVR code.

## Credits and References
* [EspoTek Labrador](https://www.crowdsupply.com/espotek/labrador) - crowdsupply
* [Pre-release Software and Documentation](https://drive.google.com/open?id=0B7U0ulRLHf8cRVBkeFc2SHpUOGs)
* [Labrador on GitHub](https://github.com/espotek/Labrador)
* [ATXMEGA32A4U-AU product info and datasheet](http://www.microchip.com/wwwproducts/en/ATxmega32A4U)
* [DMN63D8LDW datahseet](https://www.diodes.com/assets/Datasheets/DMN63D8LDW.pdf) - dual n-channel MOSFET
* [Qt Creator](https://www.qt.io/ide/)
* [KiCad](http://kicad-pcb.org/)
* [..as mentioned on my blog](https://blog.tardate.com/2017/07/leap324-espotek-labrador.html)
