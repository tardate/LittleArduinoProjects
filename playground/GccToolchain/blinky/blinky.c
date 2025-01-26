/*
  yet another blink

  ATmega168/328-Arduino Pin Mapping:
  Digital pin 13 is mapped to PB5 (SCK/PCINT5)

 */

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB = (1<<DDB5); // set for output

    while(1)
    {
        // LED on: PB5 = High = Vcc
        PORTB = (1<<PB5);
        _delay_ms(200);

        //LED off: PB5 = Low = 0v
        PORTB &= ~ (1<<PB5);
        _delay_ms(1800);
    }
}
