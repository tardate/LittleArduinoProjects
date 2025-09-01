/*

  RotaryEncoderModule
  Testing a Rotary Encoder module controlling an LED 8x8 display

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/RotaryEncoderModule

 */
#include <stdlib.h>
#include <LedControl.h>
#include <Rotary.h>

#define DIN_PIN 10
#define CS_PIN 11
#define CLK_PIN 12

#define DEMO_DELAY_LONG 600
#define DEMO_DELAY_SHORT 50

LedControl lc=LedControl(DIN_PIN,CLK_PIN,CS_PIN,1);

#define ENCODER_INTERRUPT_A 0
#define ENCODER_INTERRUPT_B 1
#define ENCODER_PIN_A 2
#define ENCODER_PIN_B 3
#define ENCODER_PIN_SW 4

volatile int encoder_position = 0;
volatile int encoder_delta = 0;

#define min_position 0
#define max_position 63
int current_position = 0;

Rotary encoder = Rotary(ENCODER_PIN_A, ENCODER_PIN_B);

void setup() {
  pinMode(ENCODER_PIN_SW, INPUT);
  digitalWrite(ENCODER_PIN_SW, HIGH);

  lc.shutdown(0,false);
  lc.setIntensity(0,15);
  updateDisplay();

  attachInterrupt(ENCODER_INTERRUPT_A, loadEncoderPositionOnChange, CHANGE);
  attachInterrupt(ENCODER_INTERRUPT_B, loadEncoderPositionOnChange, CHANGE);
}

void loop() {
  if(encoderPositionUpdated()) updateDisplay();
}

void updateDisplay() {
  lc.clearDisplay(0);
  div_t posXY = div (current_position, 8);
  lc.setRow(0, posXY.quot, 0x01 << (7 - posXY.rem));
}

bool encoderPositionUpdated() {
  static int last_position = -999;

  int button_state = digitalRead(ENCODER_PIN_SW);

  // disable interrupts while we copy the current encoder state
  uint8_t old_SREG = SREG;
  cli();
  if(button_state == LOW) {
    encoder_position = min_position;
  } else {
    if(encoder_position<min_position) encoder_position = min_position;
    if(encoder_position>max_position) encoder_position = max_position;
  }
  current_position = encoder_position;
  SREG = old_SREG;

  bool updated = (current_position != last_position);
  last_position = current_position;

  return updated;
}

/*
  Interrupt Service Routine:
  reads the encoder on pin A or B change
 */
void loadEncoderPositionOnChange() {
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
}
