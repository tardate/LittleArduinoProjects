# #305 KeyboardMatrixModule/LedControl

Demo controlling the LEDs on a simple pushbutton/LED matrix module

![Build](./assets/LedControl_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

See [LEAP#303 KeyboardMatrixModule](../) for details of the module I am testing here.

It features 8 LEDs. I'll test these with a simple direct-control program running on an Arduino.

### 8 LEDs

The board features 8 red LEDs with 1kΩ (102) current-limiting resistors and corresponding pins D1-8.

With VCC connected to power, when any pin D1-8 is pulled to ground the corresponding LED will light.


### Test Program

The [LedControl.ino](./LedControl.ino) sketch does no more than switch the LEDs on in order.


## Construction

![Breadboard](./assets/LedControl_bb.jpg?raw=true)

![Schematic](./assets/LedControl_schematic.jpg?raw=true)

![Build](./assets/LedControl_build.jpg?raw=true)

## Credits and References
* [LEAP#303 KeyboardMatrixModule](../)
* [..as mentioned on my blog](http://blog.tardate.com/2017/05/leap303-keyboard-matrix-module.html)
