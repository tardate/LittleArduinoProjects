/*

  RotaryEncoderMethods/FallingEdgeDirectPortAccessISR
  Test rotary-encoder input using falling-edge interrupt and direct port access methods

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/RotaryEncoderMethods

 */

#define ENCODER_RIGHT_LED 5
#define ENCODER_LEFT_LED 6

#define ENCODER_PIN_A 2
#define ENCODER_PIN_B 3
#define ENCODER_INTERRUPT_A 0

volatile int encoder_position = 0;
volatile int encoder_delta = 0;
int current_encoder_position = 0;
int current_encoder_delta = 0;

void setup() {
  Serial.begin(115200);

  pinMode(ENCODER_LEFT_LED, OUTPUT);
  pinMode(ENCODER_RIGHT_LED, OUTPUT);

  pinMode(ENCODER_PIN_A, INPUT);
  pinMode(ENCODER_PIN_B, INPUT);
  digitalWrite(ENCODER_PIN_A, HIGH);
  digitalWrite(ENCODER_PIN_B, HIGH);

  attachInterrupt(ENCODER_INTERRUPT_A, loadEncoderPositionOnFallingPinA, FALLING);
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
  Read the encoder on falling edge interrupt on pin A using direct port access
  Since this is the falling edge of pin A:
  * if pin B is low we are going CW
  * if pin B is high we are going CCW
 */
void loadEncoderPositionOnFallingPinA() {
  int port_a_value = digitalRead(ENCODER_PIN_A);
  int port_b_value = digitalRead(ENCODER_PIN_B);

  if (port_a_value) {
    // NOP - still transitioning - should not get to this state on a falling interrupt
  } else {
    if (port_b_value) {
      encoder_delta = -1;
      encoder_position--;
      digitalWrite(ENCODER_LEFT_LED, HIGH);
      digitalWrite(ENCODER_RIGHT_LED, LOW);
    } else {
      encoder_delta = 1;
      encoder_position++;
      digitalWrite(ENCODER_LEFT_LED, LOW);
      digitalWrite(ENCODER_RIGHT_LED, HIGH);
    }
  }
}
