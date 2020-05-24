#include "delay.h"

#define DELAY_COUNT_1MS      568U

// Command: a simple do-nothing delay for approximately `ms` milliseconds
void delay(uint32_t ms) {
  for(uint32_t i = 0 ; i < ms * DELAY_COUNT_1MS ; i++);
}
