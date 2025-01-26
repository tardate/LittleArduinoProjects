/*

  CapacitiveTouchOrgan
  Simple 12-tone organ activated by touch

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/CapacitiveTouchOrgan

 */

#include <Wire.h>
#include "Adafruit_MPR121.h"

Adafruit_MPR121 cap = Adafruit_MPR121();

int tones[] = {
  523.25,  // C5
  554.37,  // C#5/Db5
  587.33,  // D5
  622.25,  // D#5/Eb5
  659.25,  // E5
  698.46,  // F5
  739.99,  // F#5/Gb5
  783.99,  // G5
  830.61,  // G#5/Ab5
  880.00,  // A5
  932.33,  // A#5/Bb5
  987.77   // B5
};

const uint8_t TOUCH_INTERRUPT_PIN = 2;
volatile boolean touch_flag = false;

/*
 * Command: enable hardware interrupt from MPR121
 */
void enableTouchInterrupt() {
  pinMode(TOUCH_INTERRUPT_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(TOUCH_INTERRUPT_PIN), handleTouchInterrupt, FALLING);
}

/*
 * Command: interrupt handler
 */
void handleTouchInterrupt() {
  touch_flag = true;
}

void setup() {
  cap.begin(0x5A);
  enableTouchInterrupt();
}

void loop() {
  if(touch_flag) {
    uint16_t touched = cap.touched();

    for (uint8_t i=0; i<12; ++i) {
      if (touched & _BV(i)) {
        tone(8, tones[i], 300);
      }
    }

    touch_flag = false;
  }
}