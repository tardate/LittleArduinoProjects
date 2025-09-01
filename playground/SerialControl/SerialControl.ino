/*

  SerialControl

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/SerialControl

 */

const int LED_PIN = 13;

/*
 * Command: one-time setup
 */
void setup() {
  Serial.begin(115200);
  Serial.println(F("SerialControl ready"));

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}


/*
 * Command: main loop
 */
void loop() {
  char ch;

  while (Serial.available() > 0) {
    ch = Serial.read();
    switch(ch) {
    case 'd':
      printSystemInformation();
      break;
    case 'i':
      printRandomInt();
      break;
    case 's':
      printRandomString(readInteger());
      break;
    case 't':
      toggleLed();
      break;
    case '?':
      printUsage();
      break;
    }
    Serial.println();
  }
}


/*
 * Command: reads integer value from serial input
 */
int readInteger() {
  int value = 0;
  int shift_multiplier = 10;
  bool accumulating = true;

  while (accumulating) {
    if (Serial.available()) {
      char ch = Serial.read();
      if (ch >= '0' && ch <= '9') {
        value = (value * shift_multiplier) + (ch - '0');
      } else {
        accumulating = false;
      }
    }
  }
  return value;
}


/*
 * Command: print usage information
 */
void printUsage() {
  Serial.println(F("SerialControl commands:"));
  Serial.println(F("d : show system information"));
  Serial.println(F("i : generate a random 8-bit integer"));
  Serial.println(F("s<length> : generate a random string of specified length"));
  Serial.println(F("t : toggle the LED on pin 13"));
  Serial.println(F("? : show this message"));
}


/*
 * Command: print system information
 */
void printSystemInformation() {
  Serial.println(F("System Information:"));
  Serial.print(F("CPU Frequency: "));
  Serial.print(F_CPU / 1000000);
  Serial.println(F(" MHz"));

  Serial.print(F("Number of digital pins: "));
  Serial.println(NUM_DIGITAL_PINS);
  for(int p = 0; p < NUM_DIGITAL_PINS; p++) {
    Serial.print(p);
    Serial.print(F(":"));
    if(digitalPinToInterrupt(p) != NOT_AN_INTERRUPT) {
      Serial.print(F(" (interrupt:"));
      Serial.print(digitalPinToInterrupt(p));
      Serial.print(F(")"));
    }
    if(p == LED_BUILTIN) Serial.print(F(" (internal LED)"));
    if(digitalPinHasPWM(p)) Serial.print(F(" (PWM)"));
    Serial.println();

  }
  Serial.print(F("Number of analog inputs: "));
  Serial.println(NUM_ANALOG_INPUTS);
  for(int p = 0; p < NUM_ANALOG_INPUTS; p++) {
    Serial.print(F("A"));
    Serial.print(p);
    Serial.print(F(":"));
    Serial.print(F(" (pin:"));
    Serial.print(analogInputToDigitalPin(p));
    Serial.print(F(")"));
    Serial.println();
  }
}


/*
 * Command: generate a random integer between 0 and INT8_MAX
 */
void printRandomInt() {
  int randomValue = random(0, INT8_MAX);
  Serial.println(F("Random Integer:"));
  Serial.println(randomValue);
}

/*
 * Command: generate a random string of specified length
 */
void printRandomString(int length) {
  const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

  Serial.print(F("Random String with length="));
  Serial.print(length);
  Serial.println(F(":"));

  for (int i = 0; i < length; i++) {
    int index = random(0, sizeof(charset) - 1);
    Serial.print( charset[index]);
  }
  Serial.println();
}


/*
 * Command: toggle LED on pin 13
 */
void toggleLed() {
  static boolean output = HIGH;

  Serial.print(F("LED on pin 13: turning LED "));
  Serial.println(output ? F("ON") : F("OFF"));

  digitalWrite(LED_PIN, output);

  output = !output;
}
