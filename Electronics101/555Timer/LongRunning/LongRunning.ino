/*

  555Timer/LongRunning
  Measuring a very low frequency 555 timer circuit

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/Electronics101/555Timer/LongRunning

 */

const int INPUT_PIN = 2;
volatile bool input_changed = false;
static unsigned long trigger_on = 0;
static unsigned long trigger_off = 0;

/*
 * Command: one-time setup
 */
void setup() {
  Serial.begin(115200);
  pinMode(INPUT_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(INPUT_PIN), inputChanged, RISING);
}

void inputChanged() {
  input_changed = true;
}

/*
 * Command: main loop
 */
void loop() {
  if (input_changed) {
    input_changed = false;
    unsigned long last_trigger_on = trigger_on;
    trigger_on = millis();
    if (last_trigger_on > 0) {
      Serial.print("Triggered ON after : ");
      Serial.print(trigger_on - last_trigger_on);
      Serial.println(" ms");
    } else {
      Serial.println("Triggered ON (1st time)");
    }
  }
}
