# #306 KeyboardMatrixModule/SwitchInterrupts

Demo interrupt-driven switch input on a simple pushbutton/LED matrix module and how to use the EnableInterrupt library.

![Build](./assets/SwitchInterrupts_build.jpg?raw=true)

## Notes

See [LEAP#303 KeyboardMatrixModule](../) for details of the module I am testing here.

It features 4 independent Push Buttons (S1-4).

### 4 Independent Push Buttons

There are 4 independant (red) pushbuttons S1-4.

With VCC connected to power and GND grounded, pins S1-4 are normally pulled HIGH with a 10kΩ built-in resistor.
When pressed, the corresponding button pin will pull LOW.

### Test Program

The [SwitchInterrupts.ino](./SwitchInterrupts.ino) sketch demonstrates handling key presses with interrupts.

With four switches, that means we need at least 4 interrupts.
There are only two external interrupt pins on the ATmega168/328 (ie, in the Arduino Uno/Nano/Duemilanove), INT0 and INT1, and they are mapped to Arduino pins 2 and 3.

To get more external interrupts, you could instead use a Mega2560 for example, which supports external interrupts on digital GPIO pins 2, 3, 18, 19, 20, 21.

Another approach (the one I'll use here) is to use pin change interrupts that be enabled
on any or all 20 of the pins of an ATmega168/328-based Arduinos.
The [EnableInterrupt library](https://github.com/GreyGnome/EnableInterrupt) is a very easy way to do this.

The test script simply:

* sets up falling-edge interrupts on the four switch pins (normally pulled high)
* the interrupt routine records which switch was pressed
* the main loop looks for a switch press, prints to the serial console and clears the switch press flag

#### Test Run

Here's an example of the console output, with me pressing all the switches from S1 to S4:

![example_console_output](./assets/example_console_output.png?raw=true)



## Construction

![Breadboard](./assets/SwitchInterrupts_bb.jpg?raw=true)

![Schematic](./assets/SwitchInterrupts_schematic.jpg?raw=true)

![Build](./assets/SwitchInterrupts_build.jpg?raw=true)

## Credits and References
* [LEAP#303 KeyboardMatrixModule](../)
* [arduinoBoardMega2560](https://www.arduino.cc/en/Main/arduinoBoardMega2560)
* [Arduino Interrupts](http://playground.arduino.cc/Code/Interrupts)
* [Arduino attachInterrupt](https://www.arduino.cc/en/Reference/attachInterrupt)
* [EnableInterrupt library](https://github.com/GreyGnome/EnableInterrupt)
* [..as mentioned on my blog](https://blog.tardate.com/2017/05/leap303-keyboard-matrix-module.html)
