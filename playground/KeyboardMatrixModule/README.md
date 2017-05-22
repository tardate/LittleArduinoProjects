# #303 KeyboardMatrixModule

Demo a simple pushbutton/LED matrix module.

![Build](./assets/KeyboardMatrixModule_build.jpg?raw=true)

## Notes

I picked up one of these [4x4 Independent Keyboard Matrix modules](http://www.aliexpress.com/item/8-LED-4x4-Push-Buttons-Matrix-16-Key-Switch-Keyboard-for-Arduino-AVR-ARM-STM32/1526506146.html) to see how useful it might be for arbitrary input with a microcontroller.

It features:

* 4x4 matrix of Push Buttons
* 4 independent Push Buttons
* 8 LEDs

It doesn't contain any smarts, so using all the 20 possible inputs and outputs requires a bit of ingenuity (if you want to use them all)
on many microprocessors (such as the Arduino Uno or Nano). If you are using something like the Arduino Mega, then there should be plently of available I/O directly to the board.

In this project, I examine how it is constructed, and provide some examples of how to make it work:

* [LedControl](./LedControl) - LED control
* [KeyMatrixInput](./KeyMatrixInput) - multiplexed key input
* [SwitchInterrupts](./SwitchInterrupts) - interrupt-driven switch input


### 4x4 Matrix Push Button Array

The module includes an array of 16 (black) pushbuttons K1-K16.

These are connected in a 4x4 matrix, with 8 pins: L1-4, R1-4. Looking at the module with the LEDs at the bottom:

* the "L" pins connect to all the pushbuttons in a row
* the "R" pins connect to all the pushbuttons in a column

So for example pressing the button on the second row, third from the left, will open a circuit between L2 and R3.

### 4 Independent Push Buttons

There are 4 independant (red) pushbuttons S1-4.

With VCC connected to power and GND grounded, pins S1-4 are normally pulled high with a 10kΩ built-in resistor.
When pressed, the corresponding button pin will pull low.

### 8 LEDs

The board includes 8 red LEDs with 1kΩ (102) current-limiting resistors and corresponding pins D1-8.

With VCC connected to power, when any pin D1-8 is pulled to ground the corresponding LED will light.

## Construction

![Schematic](./assets/KeyboardMatrixModule_schematic.jpg?raw=true)

![Build](./assets/KeyboardMatrixModule_build.jpg?raw=true)

![KeyboardMatrixModule_build_reverse](./assets/KeyboardMatrixModule_build_reverse.jpg?raw=true)

## Credits and References
* [4x4 Independent Keyboard Matrix module](http://www.aliexpress.com/item/8-LED-4x4-Push-Buttons-Matrix-16-Key-Switch-Keyboard-for-Arduino-AVR-ARM-STM32/1526506146.html) - from a seller on aliexpress
* [..as mentioned on my blog](http://blog.tardate.com/2017/05/leap303-keyboard-matrix-module.html)
