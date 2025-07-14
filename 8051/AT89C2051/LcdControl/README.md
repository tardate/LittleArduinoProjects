# #778 AT89C2051 LCD Control

Demonstrates HD44780-based LCD control using the AT89C2051 (8051) microprocessor, compiled with SDCC on macOS.

![Build](./assets/LcdControl_build.jpg?raw=true)

## Notes

This is a demonstration of how to control an HD44780-based LCD such as the QC1602A.
See [LEAP#749 HD44780-based LCD Modules](../../../Electronics101/HD44780/) for more information about such displays.

In this example, we will be controlling the 16-pin interface directly. No libraries are used.

### Circuit Design

![bb](./assets/LcdControl_bb.jpg?raw=true)

![schematic](./assets/LcdControl_schematic.jpg?raw=true)

![bb_build](./assets/LcdControl_bb_build.jpg?raw=true)

### Code

All the code is in a single file: [LcdControl.c](./LcdControl.c).

The `main` function:

* calls `init_lcd` to initialise the display
* calls `write_welcome` to send a message to the display ("MAKE MORE PROJECTS")
* goes into an endless do-nothing loop

All LCD interaction is accomplished with the `send_command` and `send_data` functions.
These simply:

* load the command/data into the P1 8-bit register
* set the appropriate Register Select (RS) - command or data
* toggle the enable line high then low, with a suitable delay

```c
/*
 * Command: send LCD command. Assumes RW=0 (write mode) is hard-wired.
 */
void send_command(unsigned int command_value ) {
  P1=command_value;
  RS=0;
  E=1;
  ms_delay(10);
  E=0;
}

/*
 * Command: send LCD data. Assumes RW=0 (write mode) is hard-wired.
 */
void send_data(unsigned int data_value) {
  P1=data_value;
  RS=1;
  E=1;
  ms_delay(10);
  E=0;
}
```

### Programming

The [Makefile](./Makefile) is setup to compile the code using the SDCC compiler .. running on macOS in this instance:

```sh
$ make
sdcc -mmcs51 --code-size 2048 LcdControl.c -o LcdControl.ihx
packihx LcdControl.ihx > LcdControl.hex
packihx: read 21 lines, wrote 31: OK.
```

And program the chip using `at89overlord` and
the [LEAP#394 AT89C2051 Programmer](../Programmer/):

```sh
$ at89overlord -p /dev/tty.usbserial-2420 -f ./LcdControl.hex
# Initializing the programmer...
# Initialized!
# Confirming chip ID...
# Confirmed!
# Erasing flash...
# Done!
# Writing flash...
# Done!
# Verifying...
# Done!
```

## Credits and References

* [LEAP#394 AT89C2051 Programmer](../Programmer/)
* [SDCC - Small Device C Compiler](https://sdcc.sourceforge.net/)
* [LEAP#749 HD44780-based LCD Modules (e.g. QC1602A)](../../../Electronics101/HD44780/)
