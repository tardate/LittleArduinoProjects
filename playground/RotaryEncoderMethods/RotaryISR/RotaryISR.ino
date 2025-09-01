/*

  RotaryEncoderMethods/RotaryISR
  Test rotary-encoder input using change-triggered interrupt and the Rotary library

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/RotaryEncoderMethods

 */

#include <Rotary.h>

#define ENCODER_RIGHT_LED 5
#define ENCODER_LEFT_LED 6

#define ENCODER_INTERRUPT_A 0
#define ENCODER_INTERRUPT_B 1
#define ENCODER_PIN_A 2
#define ENCODER_PIN_B 3

volatile int encoder_position = 0;
volatile int encoder_delta = 0;
int current_encoder_position = 0;
int current_encoder_delta = 0;

Rotary encoder = Rotary(ENCODER_PIN_A, ENCODER_PIN_B);

void setup() {
  Serial.begin(115200);

  pinMode(ENCODER_LEFT_LED, OUTPUT);
  pinMode(ENCODER_RIGHT_LED, OUTPUT);

  attachInterrupt(ENCODER_INTERRUPT_A, loadEncoderPositionOnChange, CHANGE);
  attachInterrupt(ENCODER_INTERRUPT_B, loadEncoderPositionOnChange, CHANGE);
}

void loop() {
  if(encoderPositionUpdated()) printEncoderInfo();
}

void printEncoderInfo() {
  Serial.print("CURRENT encoder_position: ");
  Serial.print(current_encoder_position);
  Serial.print(", delta: ");
  Serial.print(current_encoder_delta);
  Serial.print(", direction: ");
  if(current_encoder_delta>0) Serial.println("right");
  else Serial.println("left");
}

bool encoderPositionUpdated() {
  static int last_position = -999;

  // disable interrupts while we copy the current encoder state
  uint8_t old_SREG = SREG;
  cli();
  current_encoder_position = encoder_position;
  current_encoder_delta = encoder_delta;
  SREG = old_SREG;

  bool updated = (current_encoder_position != last_position);
  last_position = current_encoder_position;

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
    digitalWrite(ENCODER_LEFT_LED, LOW);
    digitalWrite(ENCODER_RIGHT_LED, HIGH);
  }
  else if (result == DIR_CCW) {
    encoder_delta = -1;
    encoder_position--;
    digitalWrite(ENCODER_LEFT_LED, HIGH);
    digitalWrite(ENCODER_RIGHT_LED, LOW);
  }
}
