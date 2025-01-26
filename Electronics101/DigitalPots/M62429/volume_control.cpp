#include "volume_control.h"


VolumeControl::VolumeControl(uint8_t data_pin, uint8_t clock_pin) {
  this->data_pin = data_pin;
  this->clock_pin = clock_pin;
}


void VolumeControl::begin() {
  pinMode(data_pin, OUTPUT);
  pinMode(clock_pin, OUTPUT);
  delay(100);
}


void VolumeControl::set_db(uint8_t db, uint8_t channel) {
  if (db > MAX_VOLUME) db = 0;
  else db = MAX_VOLUME - db;

  // data packet is constructed such that
  // the LSB is the first on the wire
  uint16_t data;

  data = channel;           // channel (2 bits)
  data |= (db & 0b1111100); // ATT1 (5 bits)
  data |= (db & 0b11) << 7; // ATT2 (2 bits)
  data |= (0b11 << 9);      // packet end

  for (uint8_t bit = 0; bit < 11; bit++) {
    delayMicroseconds(2);
    digitalWrite(data_pin, LOW);
    delayMicroseconds(2);
    digitalWrite(clock_pin, LOW);
    delayMicroseconds(2);
    digitalWrite(data_pin, (data >> bit) & 0x01);
    delayMicroseconds(2);
    digitalWrite(clock_pin, HIGH);
  }
  latch_data();
}

void VolumeControl::set_level(uint8_t level, uint8_t channel) {
  uint8_t db = map(level, 0, 100, MAX_VOLUME, 0);
  set_db(db, channel);
}


void VolumeControl::latch_data() {
  delayMicroseconds(2);
  digitalWrite(data_pin, HIGH);
  delayMicroseconds(2);
  digitalWrite(clock_pin, LOW);
}
