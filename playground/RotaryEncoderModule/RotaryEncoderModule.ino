/*

  RotaryEncoderModule
  Testing a Rotary Encoder module controlling an LED 8x8 display

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/RotaryEncoderModule

 */
#include <stdlib.h>
#include <LedControl.h>
#include <Rotary.h>

const int DIN_PIN = 10;
const int CS_PIN = 11;
const int CLK_PIN = 12;

const int DEMO_DELAY_LONG = 600;
const int DEMO_DELAY_SHORT = 50;

LedControl lc = LedControl(DIN_PIN, CLK_PIN, CS_PIN, 1);

const int ENCODER_INTERRUPT_A = 0;
const int ENCODER_INTERRUPT_B = 1;
const int ENCODER_PIN_A = 2;
const int ENCODER_PIN_B = 3;
const int ENCODER_PIN_SW = 4;

volatile bool encoder_has_changed = false;
int encoder_position = 0;
int encoder_delta = 0;

const int min_position = 0;
const int max_position = 63;
int current_position = 0;

Rotary encoder = Rotary(ENCODER_PIN_A, ENCODER_PIN_B);

void setup() {
  pinMode(ENCODER_PIN_SW, INPUT);
  digitalWrite(ENCODER_PIN_SW, HIGH);

  lc.shutdown(0, false);
  lc.setIntensity(0, 15);
  updateDisplay();

  attachInterrupt(ENCODER_INTERRUPT_A, flagEncoderChanged, CHANGE);
  attachInterrupt(ENCODER_INTERRUPT_B, flagEncoderChanged, CHANGE);
}

void loop() {
  if(encoderPositionUpdated()) updateDisplay();
}

void updateDisplay() {
  lc.clearDisplay(0);
  div_t posXY = div(current_position, 8);
  lc.setRow(0, posXY.quot, 0x01 << (7 - posXY.rem));
}

bool encoderPositionUpdated() {
  static int last_position = -999;

  int button_state = digitalRead(ENCODER_PIN_SW);
  if (button_state == LOW) {
    encoder_position = min_position;
  }
  else if (encoder_has_changed) {
    loadEncoderPosition();
    encoder_has_changed = false;
  }
  current_position = encoder_position;

  bool updated = (current_position != last_position);
  last_position = current_position;

  return updated;
}

void loadEncoderPosition() {
  unsigned char result = encoder.process();
  if (result == DIR_NONE) {
    // do nothing
  }
  else if (result == DIR_CW) {
    encoder_delta = 1;
    encoder_position++;
  }
  else if (result == DIR_CCW) {
    encoder_delta = -1;
    encoder_position--;
  }
  if(encoder_position<min_position) encoder_position = min_position;
  if(encoder_position>max_position) encoder_position = max_position;
}

/*
  Interrupt Service Routine:
  flags if encoder pin A or B has changed
 */
void flagEncoderChanged() {
  encoder_has_changed = true;
}
