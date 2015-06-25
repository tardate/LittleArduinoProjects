/*

  RotaryEncoderISR
  Demo interrupt-driven rotary-encoder input

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/RotaryEncoderISR

 */

#define SERIAL_DEBUG

#define ENCODER_PIN_A 2
#define ENCODER_PIN_B 4
#define ENCODER_INTERRUPT_A 0

volatile int encoder_position = 0;
volatile int encoder_delta = 0;
int current_encoder_position = 0;
int current_encoder_delta = 0;

void setup() {
  Serial.begin(115200);

  pinMode(ENCODER_PIN_A, INPUT);
  pinMode(ENCODER_PIN_B, INPUT);
  digitalWrite(ENCODER_PIN_A, HIGH);
  digitalWrite(ENCODER_PIN_B, HIGH);

  attachInterrupt(ENCODER_INTERRUPT_A, loadEncoderPositionOnFallingPinA, FALLING);
}

void loop() {
  if(encoderPositionUpdated()) {
    Serial.print("position: ");
    Serial.print(current_encoder_position);
    Serial.print(", delta: ");
    Serial.println(encoder_delta);
  }
  delay(1000);
}

bool encoderPositionUpdated() {
  static int last_position = -999;

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
  read the encode on falling edge interrupt on pin A
  Since this is the falling edge of pin A:
  * if pin B is low we are going CW
  * if pin B is high we are going CCW
 */
void loadEncoderPositionOnFallingPinA() {
  if ( digitalRead(ENCODER_PIN_B) ) {
    encoder_delta = -1;
    encoder_position--;
  } else {
    encoder_delta = 1;
    encoder_position++;
  }
  #ifdef SERIAL_DEBUG
  Serial.println(encoder_position);
  #endif
}
