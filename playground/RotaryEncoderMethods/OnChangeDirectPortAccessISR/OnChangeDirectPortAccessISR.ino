/*

  RotaryEncoderMethods/OnChangeDirectPortAccessISR
  Test rotary-encoder input using on-change interrupt and direct port access methods

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/RotaryEncoderMethods

 */

// NB: expects all pins to be on port register D (digital pins 0 to 7)

#define ENCODER_RIGHT_LED 5
#define ENCODER_LEFT_LED 6

#define ENCODER_INTERRUPT_A 0
#define ENCODER_PIN_A 2
#define ENCODER_PIN_B 3

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

  attachInterrupt(ENCODER_INTERRUPT_A, loadEncoderPositionOnChangePinA, CHANGE);
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

#define ENCODER_PIN_A_PORT_MASK     (1 << ENCODER_PIN_A)
#define ENCODER_PIN_B_PORT_MASK     (1 << ENCODER_PIN_B)
#define ENCODER_RIGHT_LED_PORT_MASK (1 << ENCODER_RIGHT_LED)
#define ENCODER_LEFT_LED_PORT_MASK  (1 << ENCODER_LEFT_LED)

/*
  Read the encoder on pin A change interrupt using direct port access.
  * if both pins are the same, assume it is spinning forward.
  * if they're different, assume it's going backward.
  Note: this expects all pins to be on port register D (digital pins 0 to 7)
 */
void loadEncoderPositionOnChangePinA() {
  byte port_values = PIND; // gobble the port values in one go

  if ((port_values & ENCODER_PIN_A_PORT_MASK) && (port_values & ENCODER_PIN_B_PORT_MASK)) {
    encoder_delta = 1;
    encoder_position++;

    // turn left LED off, right LED on
    PORTD = PORTD & ~ENCODER_LEFT_LED_PORT_MASK | ENCODER_RIGHT_LED_PORT_MASK;
  } else {
    encoder_delta = -1;
    encoder_position--;

    // turn right LED off, left LED on
    PORTD = PORTD & ~ENCODER_RIGHT_LED_PORT_MASK | ENCODER_LEFT_LED_PORT_MASK;
  }
}
