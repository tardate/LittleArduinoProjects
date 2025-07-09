# #399 AT89C2051 LED Chaser

Run an LED chaser with an AT89C2051 using interrupts for timing; C source compiled with SDCC on macOS (Intel and now Apple Silicon).

![Build](./assets/LedChaser_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/OgvEktRaQ-w/0.jpg)](https://www.youtube.com/watch?v=OgvEktRaQ-w)

## Notes

This project is a simple extension of blinking LEDs with the 8051 to explore the use of timers and interrupts.

The AT89C2051 has two 16-bit timer/counters.
The timers are highly configurable. I'm using Timer0 mode 3, which splits it into two 8 bit counters,
and conigure to fire interrupt 1 on overflow.

Register usage:

* `TMOD` sets the mode and gating for Timer0 and Timer1. In this case, Timer1 is ignored, and Timer0 set for:
    * Mode 3: uses TL0 as an 8-bit timer/counter.
    * Timer0 counts based on the divided-down system clock (clock / 12)
    * Timer0 is enabled when the TR0 bit is set
* `TL0` is the low 8 bits of the Timer0 register
* `ET0=1` enables Timer0 interrupt.
* `EA=1`  enables global interrupt.
* `TR0=1` sets Timer0 running.
* `TF0` is the Timer0 flag set every time an overflow occurs. Flags are cleared before calling the timer interrupt routine.

## Interrupt Service Routine

The interrupt service routine is declared with the non-standard `__interrupt` keyword,
allowing the compiler/linker to correctly vector this function for interrupt 1:

```c
void timer0_isr(void) __interrupt (1) {
  ...
}
```

The interrupt routine is setup in this program to count interrupts and trigger an LED state change at a frequency of 2Hz.

## Driving LEDs with Port 1

Eight LEDs are used by this program in a simple "chase" sequence, which maps nicely to the 8 bits or Port 1.
All the Port 1 output buffers can sink 20 mA, more than enough for the LEDs I'm using.

Only pins P1.2 to P1.7 provide internal pull-ups and can source current. P1.0 and P1.1 require external pull-ups for this,
so the most convenient arrangement for this design is low-side control of the LEDs i.e. active-low logic.

## Code and Compilation

This is a single-file program: [LedChaser.c](./LedChaser.c) - with a Makefile to build with
[SDCC](https://sdcc.sourceforge.net). I'm compiling this on macOS.

```sh
$ make
sdcc -mmcs51 --code-size 2048 LedChaser.c -o LedChaser.ihx
packihx LedChaser.ihx > LedChaser.hex
packihx: read 18 lines, wrote 25: OK.
```

## Programming

[LEAP#394 AT89C2051 Programmer](../Programmer) and `at89overlord`

```sh
$ source ../Programmer/venv/bin/activate
$ at89overlord -p /dev/tty.usbmodem14531 -f LedChaser.hex
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

## Construction

![Breadboard](./assets/LedChaser_bb.jpg?raw=true)

![Schematic](./assets/LedChaser_schematic.jpg?raw=true)

![Build](./assets/LedChaser_build.jpg?raw=true)

## Credits and References

* [AT89C2051 product info and datasheet](https://www.microchip.com/wwwproducts/en/AT89c2051)
