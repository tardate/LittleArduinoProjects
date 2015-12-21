#include "cube_driver.h"

CubeDriver::CubeDriver(int latch_pin, int clock_pin, int data_pin) {
  this->latch_pin = latch_pin;
  this->clock_pin = clock_pin;
  this->data_pin = data_pin;
  this->layer_buffer = (uint16_t*)malloc( CUBE_LAYERS );
  reset();

}

void CubeDriver::init() {
  pinMode(latch_pin, OUTPUT);
  pinMode(clock_pin, OUTPUT);
  pinMode(data_pin, OUTPUT);
}

void CubeDriver::reset() {
  this->current_layer = 0;
  this->utility_settings = 0;
}

void CubeDriver::updateUtilitySettings(byte new_settings) {
  this->utility_settings = new_settings;
}

void CubeDriver::setLayer(byte layer, uint16_t data) {
  layer_buffer[layer] = data;
}

void CubeDriver::clearAll() {
  for(int l=0; l < CUBE_LAYERS; l++) this->layer_buffer[l] = 0x0;
}

void CubeDriver::clearAllWithAnimation() {
  for(int l=0; l < CUBE_LAYERS; l++) this->layer_buffer[l] = 0x0;
  for(int u=1; u <= 0xF; u++) {
    this->utility_settings = u;
    delay(30);
  }
  this->utility_settings = 0;
}

void CubeDriver::setAll() {
  for(int l=0; l < CUBE_LAYERS; l++) this->layer_buffer[l] = 0xFFFF;
}

// Command: draws the next "step" in the cube display.
// This should be called on a regular schedule
void CubeDriver::redraw() {
  // step to the next layer
  if(this->current_layer++ >= CUBE_LAYERS) this->current_layer = 0;

  digitalWrite(latch_pin, LOW);
  shiftOut(data_pin, clock_pin, LSBFIRST, (utility_settings << 4) | (0x1 <<  current_layer));
  shiftOut(data_pin, clock_pin, LSBFIRST, layer_buffer[current_layer]);
  shiftOut(data_pin, clock_pin, LSBFIRST, layer_buffer[current_layer] >> 8);

  // uint16_t data = 0xFF00;
  // shiftOut(data_pin, clock_pin, LSBFIRST, (utility_settings << 4) | (0x1 <<  current_layer));
  // shiftOut(data_pin, clock_pin, LSBFIRST, data);
  // shiftOut(data_pin, clock_pin, LSBFIRST, data >> 8);
  digitalWrite(latch_pin, HIGH);

}
