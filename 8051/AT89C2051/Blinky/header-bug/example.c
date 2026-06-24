#define MICROCONTROLLER_AT89CX051
#include <mcs51/at89x51.h>

void canary(void)
{
  TR1 = 0;
}
