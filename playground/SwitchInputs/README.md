# #728 Switch Inputs

Reviewing the main methods for reading switch inputs with an Arduino.

![Build](./assets/SwitchInputs_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/6nlSVAiZOdM/0.jpg)](https://www.youtube.com/watch?v=6nlSVAiZOdM)

## Notes

Reading the on/off state of a switch is perhaps the most basic Arduino GPIO input task.

It is very simple from a programming perspective. Two library functions are required:

* pinMode - used to set the appropriate mode for the selected GPIO pin
* digitalRead - used to read the binary switch state (LOW, HIGH) from the selected GPIO pin

From an electrical perspective, there are some choices to be made.

The project below is a simple demonstration of the main approaches.
The code is available in [SwitchInputs.ino](./SwitchInputs.ino).

### Push-button: Input goes LOW when pressed

This is covered in "5.1 Using a Switch" from the [Arduino Cookbook](../../books/arduino-cookbook/)

This approach uses an external resistor to pull the input pin HIGH by default. Pressing the button will pull the input LOW.

Basic approach:

* pin `pinA` is used to read the button state
    * pin `pinA` is set to `INPUT` mode
    * a resistor R1 is used to pull the pin `HIGH` by default
    * push-button S1 pulls the pin `LOW` when pressed
* pin `pinA_led` is used drive an LED to indicate the current button state read from pin `pinA`
    * pin `pinA_led` is set to `OUTPUT` mode
    * it drives and LED with current-limiting resistor
    * output is set `HIGH` or `LOW` to match the currently read state of pin `pinA`

### Push-button: Input goes HIGH when pressed

This approach alters the configuration of the external resistor to pull the input pin LOW by default. Pressing the button will pull the input HIGH.

Basic approach:

* pin `pinB` is used to read the button state
    * pin `pinB` is set to `INPUT` mode
    * a resistor R3 is used to pull the pin `LOW` by default
    * push-button S2 pulls the pin `HIGH` when pressed
* pin `pinB_led` is used drive an LED to indicate the current button state read from pin `pinB`
    * pin `pinB_led` is set to `OUTPUT` mode
    * it drives and LED with current-limiting resistor
    * output is set `HIGH` or `LOW` to match the currently read state of pin `pinB`

### Push-button: Input goes HIGH when pressed, Without External Resistors

This is covered in "5.2 Using a Switch Without External Resistors" from the [Arduino Cookbook](../../books/arduino-cookbook/)

The external pull-up resistor for the switch input can be dispensed with by using the internal pull-up resistors that are part of the GPIO port design.
Pull-ups are enabled by using the [`INPUT_PULLUP`](https://docs.arduino.cc/language-reference/en/variables/constants/inputOutputPullup/) pin mode.

Note: in earlier versions of the Arduino libraries, this mode was not available. Pull-ups were enabled by writing HIGH to the port after setting INPUT mode e.g. as follows:

    pinMode(inputPin, INPUT);
    digitalWrite(inputPin, HIGH);

Basic approach:

* pin `pinC` is used to read the button state
    * pin `pinC` is set to `INPUT_PULLUP` mode
    * push-button S3 pulls the pin `LOW` when pressed
* pin `pinC_led` is used drive an LED to indicate the current button state read from pin `pinC`
    * pin `pinC_led` is set to `OUTPUT` mode
    * it drives and LED with current-limiting resistor
    * output is set `HIGH` or `LOW` to match the currently read state of pin `pinC`

### Circuit Design

The design is available in [SwitchInputs.fzz](./SwitchInputs.fzz).

![bb](./assets/SwitchInputs_bb.jpg?raw=true)

![schematic](./assets/SwitchInputs_schematic.jpg?raw=true)

![bb_build](./assets/SwitchInputs_bb_build.jpg?raw=true)

## Credits and References

* [Arduino: Digital Pins](https://docs.arduino.cc/learn/microcontrollers/digital-pins/)
* [Arduino functions: digitalRead()](https://docs.arduino.cc/language-reference/en/functions/digital-io/digitalread/)
* [Arduino functions: digitalWrite()](https://docs.arduino.cc/language-reference/en/functions/digital-io/digitalwrite/)
* [Arduino functions: pinMode()](https://docs.arduino.cc/language-reference/en/functions/digital-io/pinMode/)
* [Arduino Cookbook](../../books/arduino-cookbook/)
