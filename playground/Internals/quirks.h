

// When digitalPinToInterrupt was back-ported to 1.0.6 it seems NOT_AN_INTERRUPT define was forgotten
// See https://github.com/arduino/Arduino/issues/2379
#ifndef NOT_AN_INTERRUPT
#define NOT_AN_INTERRUPT -1
#endif
