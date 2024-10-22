# #304 KeyboardMatrixModule/KeyMatrixInput

Demo multiplexed key input on a simple pushbutton/LED matrix module and how to use INPUT_PULLUP.

![Build](./assets/KeyMatrixInput_build.jpg?raw=true)

## Notes

See [LEAP#303 KeyboardMatrixModule](../) for details of the module I am testing here.

It features a 4x4 matrix of Push Buttons.

### 4x4 Matrix Push Button Array

The module includes an array of 16 (black) pushbuttons K1-K16.

These are connected in a 4x4 matrix, with 8 pins: L1-4, R1-4. Looking at the module with the LEDs at the bottom:

* the "L" pins connect to all the pushbuttons in a row
* the "R" pins connect to all the pushbuttons in a column

So for example pressing the button on the second row, third from the left, will open a circuit between L2 and R3.

### Test Program

The [KeyMatrixInput.ino](./KeyMatrixInput.ino) sketch demonstrates reading the key matrix directly from an Arduino.

It scans the matrix and prints any pressed keys to the serial out.
Scanning the matrix involves by sequentially setting one of the L1-4 pins, and testing for a corresponding signal on R1-4.

NB: The role of L and R pins can be switched - but doing it this way means the corresponding pin label (K1-16) can be easily determined.

There's a basic decision to be made here: detect input swinging HIGH or LOW?

Since the key matrix does not include any pull-up/pull-down resistors, detecting HIGH is asking for trouble,
as when no keys are pressed, inputs L1-4 are effectively floating. To detect a normally LOW state swinging high requires
additional pull-down resistors (say 10kΩ).

That's possible, but things are easier if we use the INPUT_PULLUP feature of the ATmega:

* R1-4 are normally pulled high with INPUT_PULLUP
* L1-4 are HIGH by default - pressing a button would have no effect on the HIGH state of the R1-4 pin
* when an L pin is set LOW (say L2), then if any R1-4 also read LOW, then we know the corresponding button is pressed

#### Debouncing

Multiple key registrations (or missed button presses) are possible depending on the scanning frequency.
Since this is a polling approach, normal mechanical bouncing is not such a problem.
I've avoided the issue by setting the polling frequency at a relatively slow 1/150ms

#### Test Run

Here's an example of the console output, with me pressing all the buttons from K1 to K16 and then down the even numbers:

![example_console_output](./assets/example_console_output.png?raw=true)

## Construction

![Breadboard](./assets/KeyMatrixInput_bb.jpg?raw=true)

![Schematic](./assets/KeyMatrixInput_schematic.jpg?raw=true)

![Build](./assets/KeyMatrixInput_build.jpg?raw=true)

## Credits and References

* [LEAP#303 KeyboardMatrixModule](../)
* [Arduino DigitalPins](https://www.arduino.cc/en/Tutorial/DigitalPins)
* [..as mentioned on my blog](https://blog.tardate.com/2017/05/leap303-keyboard-matrix-module.html)
