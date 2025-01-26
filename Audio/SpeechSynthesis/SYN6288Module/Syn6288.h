#ifndef Syn6288_h
#define Syn6288_h
#include <inttypes.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <stddef.h>

#define HEADLEN      5
//#define LEN_OFFSET    2

class Syn6288
{
  public:
    void play(uint8_t *text, uint8_t text_length, uint8_t music);
    void setBaud(uint16_t boudr);

    // NYI:
    // void stop();
    // void restore();
    // void inquire();
    // void Pause();
    // void sleep();

    //private:
    uint8_t music;
    uint8_t pi;
};

#endif
