#include "MicroTimer2.h"


MicroTimer2 microTimer2;


// Handle Timer2 overflow. this will occur every 128us
ISR(TIMER2_OVF_vect) {
  microTimer2.increment_overflow_count();
}


MicroTimer2::MicroTimer2() {
  _overflow_count = 0;
  _total_count = 0;
  _started = false;
}


void MicroTimer2::enable() {
  if (_started) return;

  _initial_tccr2a = TCCR2A;
  _initial_tccr2b = TCCR2B;

  // set normal Waveform Generation Mode, OC0A and OC0B disconnected
  TCCR2A = 0;
  TCCR2B = _BV(CS21);

  enable_overflow_interrupt();
  reset();

  _started = true;
}


void MicroTimer2::disable(){
  if (!_started) return;

  disable_overflow_interrupt();
  TCCR2A = _initial_tccr2a;
  TCCR2B = _initial_tccr2b;

  _started = false;
}


unsigned long MicroTimer2::get_count() {
  enable();
  pause();
  _total_count = _overflow_count * 0x100 + TCNT2;
  resume();
  return _total_count;
}


float MicroTimer2::micros() {
  return get_count()/2.0;
}


void MicroTimer2::reset() {
  pause();
  _overflow_count = 0;
  _total_count = 0;
  TCNT2 = 0;
  reset_overflow_flag();
  resume();
}


inline void MicroTimer2::pause() {
  _paused_SREG = SREG;
  noInterrupts();
}


inline void MicroTimer2::resume() {
  SREG = _paused_SREG;
}


inline void MicroTimer2::increment_overflow_count() {
  ++_overflow_count;
}


inline void MicroTimer2::reset_overflow_flag() {
  TIFR2 |= _BV(TOV2);
}


inline void MicroTimer2::enable_overflow_interrupt() {
  TIMSK2 |= _BV(TOIE2);
}


inline void MicroTimer2::disable_overflow_interrupt() {
  TIMSK2 &= ~(_BV(TOIE2));
}
