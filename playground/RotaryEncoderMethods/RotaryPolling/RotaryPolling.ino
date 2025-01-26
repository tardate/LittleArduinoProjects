/*

  RotaryEncoderMethods/RotaryPolling
  Test rotary-encoder input using polling and the Rotary library

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/RotaryEncoderMethods

 */

#include <Rotary.h>

#define ENCODER_RIGHT_LED 5
#define ENCODER_LEFT_LED 6

#define ENCODER_PIN_A 2
#define ENCODER_PIN_B 3

int current_encoder_position = 0;
int current_encoder_delta = 0;

Rotary encoder = Rotary(ENCODER_PIN_A, ENCODER_PIN_B);

void setup() {
  Serial.begin(115200);
  pinMode(ENCODER_LEFT_LED, OUTPUT);
  pinMode(ENCODER_RIGHT_LED, OUTPUT);
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
  unsigned char result = encoder.process();

  if (result == DIR_NONE) {
    // do nothing
  }
  else if (result == DIR_CW) {
    current_encoder_delta = 1;
    current_encoder_position++;
    digitalWrite(ENCODER_LEFT_LED, LOW);
    digitalWrite(ENCODER_RIGHT_LED, HIGH);
  }
  else if (result == DIR_CCW) {
    current_encoder_delta = -1;
    current_encoder_position--;
    digitalWrite(ENCODER_LEFT_LED, HIGH);
    digitalWrite(ENCODER_RIGHT_LED, LOW);
  }

  bool updated = (current_encoder_position != last_position);
  last_position = current_encoder_position;

  return updated;
}
