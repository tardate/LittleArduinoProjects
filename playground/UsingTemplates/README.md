# #485 UsingTemplates

Learning how to use C++ template functions in embedded projects with an Arduino.

![Build](./assets/UsingTemplates_build.jpg?raw=true)

## Notes

LuckyResistor has just published
[C++ Templates For Embedded Code](https://luckyresistor.me/2019/07/20/c-templates-for-embedded-code/),
the first in a series on the subject of C++ templates.

This is great! Although I've dabbled in C++ for years, I've never fully taken templates on board.
Proving that they can be beneficial for embedded development is a bonus.

### The First Example - circularShift

I've taken the circularShift example from the article, and extended the code a little to
toggle the LED on pin 13 everytime `circularShift` wraps a `1` around.

One important point to note if you are copying code from the article:

> The declaration and implementation of a function template have to be in a header file

With Arduino IDE 1.8.2, I get a compiler error like this if I try and put templates in the main sketch file:

    UsingTemplates:12: error: variable or field 'circularShift' declared void
     void circularShift(Value &value) {
                        ^
    UsingTemplates:12: error: 'Value' was not declared in this scope
    UsingTemplates:12: error: 'value' was not declared in this scope
     void circularShift(Value &value) {
                               ^
    exit status 1
    variable or field 'circularShift' declared void

Putting the template in a header file fixes this.
Also, Arduino IDE 1.8.9 does not have this issue - it can compile templates in the sketch file.

### Test Run

From the console, the first iterations checkout - correct right shift on both values (should improve this to include leading 0s in the output)


    10101011110011010000000100100011
    100010101000101
    11010101111001101000000010010001
    1010001010100010
    11101010111100110100000001001000
    101000101010001
    1110101011110011010000000100100
    1010100010101000

![console](./assets/console.png?raw=true)

## Construction

![Breadboard](./assets/UsingTemplates_bb.jpg?raw=true)

![Schematic](./assets/UsingTemplates_schematic.jpg?raw=true)

![Build](./assets/UsingTemplates_build.jpg?raw=true)

## Credits and References

* [C++ Templates For Embedded Code](https://luckyresistor.me/2019/07/20/c-templates-for-embedded-code/)
