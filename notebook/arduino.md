# Arduino Notes

## Prime Links

* [Arduino](https://www.arduino.cc/) - official home page
* [Arduino Playground](http://playground.arduino.cc/)
* [Arduino Source](https://github.com/arduino/Arduino/) - GitHub

## Timers and Pins

* Timer0 - Used for millis and delay; also analogWrite/PWM on pins 5 and 6
* Timer1 - analogWrite/PWM functions on pins 9 and 10; Servo library; Tone library (second tone)
* Timer2 - analogWrite/PWM functions on pins 3 and 11; Tone library (first tone)

### Tone library

* On a standard Arduino board, the first tone will use timer 2 (so PWM on pins 9 and 10 will not be available);
* the second tone uses timer 1 (preventing the Servo library and PWM on pins 11 and 12 from working).
* On a Mega board, each simultaneous tone will use timers in the following order: 2, 3, 4, 5, 1, 0.”

### Servo Library

* The Servo library uses the same timer as analogWrite on pins 9 and 10, so you can’t use analogWrite with these pins when using the Servo library.


## Arduino Pro Mini

* [Official Arduino Pro Mini site](http://www.arduino.cc/en/Main/ArduinoBoardProMini)
* [Arduino USB-to-Serial Tutorial - Programming the Pro Mini](https://youtu.be/Vawhrr4COjI) - great in-depth tests with various USB to serial devices by Julian Ilett.


### USB-to-Serial Programming

Pin Connections as described on
[weworkweplay](http://weworkweplay.com/play/connect-jy-mcu-usb-serial-port-adapter-to-arduino-mini-pro-3.3v-atmega328/):

* Connect USB DTR to Arduino GRN, aka DAW on some boards
* Connect USB RXD to Arduino TXD
* Connect USB TXD to Arduino RXI
* Connect USB 3.3V to Arduino VCC
* Connect USB Ground to Arduino BLK, aka GND on some boards

![The pro_mini_usb_serial_connection](./assets/pro_mini_usb_serial_connection.jpg?raw=true)


## Arduino Nano

See the [Official Arduino Nano](http://arduino.cc/en/Main/arduinoBoardNano) site for board details.


### Power

Specs:

* Operating Voltage (logic level) 5 V
* Input Voltage (recommended) 7-12 V
* Input Voltage (limits)  6-20 V

The power source is automatically selected to the highest voltage source from one of:

* the Mini-B USB connection
* 6-20V unregulated external power supply (pin 30)
* 5V regulated external power supply (pin 27)

See also:

* [Arduino Uno R3: Directly supply regulated 5V to 5V pin?](https://electronics.stackexchange.com/questions/65576/arduino-uno-r3-directly-supply-regulated-5v-to-5v-pin)

### Pins

![The nano_pins](./assets/nano_pins.png?raw=true)

[![attiny_generic_pinout_and_ISP_pins.png](./assets/attiny_generic_pinout_and_ISP_pins.png?raw=true)](https://arduino.pinout.guide/attiny_generic_pinout_and_ISP_pins.png)
