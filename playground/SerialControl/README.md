# #746 Serial Control

Using serial commands to control and query information from an Arduino.

![Build](./assets/SerialControl_build.jpg?raw=true)

## Notes

This is a simple Arduino sketch that responds to serial control.
As well as providing a simple demonstration of Arduino serial coding,
I made this sketch so that I could use the Uno as an intelligent responder for testing client-side serial code.

Form more information on serial communications, see
[Arduino Cookbook: 4. Serial Communications](../../books/arduino-cookbook/)

### Code

The [SerialControl.ino](./SerialControl.ino) sketch listens for commands on the serial port and then responds accordingly.

Currently, it supports the following commands:

* `d` : show system information
* `i` : generate a random 8-bit integer
* `s<length>` : generate a random string of specified length
* `t` : toggle the LED on pin 13
* `?` : show this message

A blank line will follow the output of all commands.
This indicator may be used for client-side flow control if required.

### Using the Arduino IDE

The script can be compiled and uploaded from the IDE, and used with the built-in serial monitor set for 115200 baud:

![ide-example](./assets/ide-example.png?raw=true)

### Using Screen

I'm using macOS, so (as with Linux) the most handy console utility is
[screen](https://codingkata.tardate.com/tools/screen/).

The Arduino is showing up as a character and TTY device with ID 2430:

```sh
$ ls -1 /dev/*serial*
/dev/cu.usbserial-2430
/dev/cu.wchusbserial2430
/dev/tty.usbserial-2430
/dev/tty.wchusbserial2430
```

For simple character interaction, any of these devices with work, but `cu` devices are preferred. For example:

```sh
screen /dev/cu.usbserial-2430 115200
```

![screen-example](./assets/screen-example.png)

## Credits and References

* [Arduino reference: Serial](https://docs.arduino.cc/language-reference/en/functions/communication/serial/)
* [Arduino Cookbook: 4. Serial Communications](../../books/arduino-cookbook/)
* [screen notes](https://codingkata.tardate.com/tools/screen/)
