/*

  RotaryEncoderMethods/Polling
  Test rotary-encoder input using simple polling

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/RotaryEncoderMethods

 */

#define ENCODER_RIGHT_LED 5
#define ENCODER_LEFT_LED 6

#define ENCODER_PIN_A 2
#define ENCODER_PIN_B 3

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
  static int last_pin_a_value = LOW;
  int current_pin_a_value = digitalRead(ENCODER_PIN_A);

  if ((last_pin_a_value == LOW) && (current_pin_a_value == HIGH)) {
    if (digitalRead(ENCODER_PIN_B) == HIGH) {
      current_encoder_delta = 1;
      current_encoder_position++;
      digitalWrite(ENCODER_LEFT_LED, LOW);
      digitalWrite(ENCODER_RIGHT_LED, HIGH);
    } else {
      current_encoder_delta = -1;
      current_encoder_position--;
      digitalWrite(ENCODER_LEFT_LED, HIGH);
      digitalWrite(ENCODER_RIGHT_LED, LOW);
    }
  }
  last_pin_a_value = current_pin_a_value;

  bool updated = (current_encoder_position != last_position);
  last_position = current_encoder_position;

  return updated;
}
