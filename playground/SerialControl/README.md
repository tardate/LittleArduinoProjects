# #xxx Serial Control

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

### Using the Arduino IDE

The script can be compiled and uploaded from the IDE, and used with the built-in serial monitor set for 115200 baud:

![ide-example](./assets/ide-example.png?raw=true)

### Using Screen

I'm using macOS, so (as with Linux) the most handy console utility is
[screen](https://web.archive.org/web/20200220232553/http://www.noah.org/wiki/Screen_notes#using_screen_as_an_RS-232_.2F_general_serial_terminal).

The Arduino is showing up as a character and TTY device with ID 2420:

```sh
$ ls /dev/tty.*serial*
/dev/tty.usbserial-2420  /dev/tty.wchusbserial2420
$ ls /dev/cu.*serial*
/dev/cu.usbserial-2420  /dev/cu.wchusbserial2420
```

For simple character interaction, any of these devices with work. For example:

```sh
screen /dev/cu.usbmodem14511 115200
```

![screen-example](./assets/screen-example.png)

## Credits and References

* [Arduino reference: Serial](https://docs.arduino.cc/language-reference/en/functions/communication/serial/)
* [Arduino Cookbook: 4. Serial Communications](../../books/arduino-cookbook/)
* [screen notes](https://web.archive.org/web/20200220232553/http://www.noah.org/wiki/Screen_notes)
