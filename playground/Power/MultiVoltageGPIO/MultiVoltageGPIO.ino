/*

  Power/MultiVoltageGPIO
  A PWM charge-pump approach for driving low-current 0V, 5V, 12V output levels from an Arduino GPIO pin.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/Power/MultiVoltageGPIO

 */

const int PUMP_A        = 3;
const int PUMP_B        = 11;
const int VHIGH_IO_PIN  = 4;
const int VLOW_IO_PIN   = 5;
const int DEMO_DELAY_MS = 2000;

// Supported output levels
enum class OutputLevel : uint8_t {
  Level0V,
  Level5V,
  Level12V
};

/*
 * Enable Timer2 Fast PWM on pin 3, 11
 *   NB: pins must be set to OUTPUT for PWM to appear on the pins
 *   Fast PWM  : WGM21 WGM20
 *   Clear OC2A on Compare Match (COM2A1)
 *   Set   OC2B on Compare Match (COM2B1 + COM2B0)
 *   Frequency : 16MHz/1/256 = 62.5kHz (CS20)
 *   Pin 11    : (127+1)/256 = 50% duty cycle (OCR2A)
 *   Pin 3     : (127+1)/256 = 50% duty cycle (OCR2B)
 */
void setPwmMode() {
  PwmOff(); // just to be sure
  TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(COM2B0) | _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(CS20);
  OCR2A = 127;
  OCR2B = 127;
}

void PwmOff() {
  pinMode(PUMP_A, INPUT);
  pinMode(PUMP_B, INPUT);
}

void PwmOn() {
  pinMode(PUMP_A, OUTPUT);
  pinMode(PUMP_B, OUTPUT);
}

void SetIOLevel(OutputLevel level) {
  switch (level) {
    case OutputLevel::Level0V:
      digitalWrite(VLOW_IO_PIN, LOW);
      digitalWrite(VHIGH_IO_PIN, LOW);
      break;
    case OutputLevel::Level5V:
      digitalWrite(VLOW_IO_PIN, HIGH);
      digitalWrite(VHIGH_IO_PIN, LOW);
      break;
    case OutputLevel::Level12V:
      digitalWrite(VLOW_IO_PIN, HIGH);
      digitalWrite(VHIGH_IO_PIN, HIGH);
      break;
  }
}

void setup() {
  setPwmMode();
  pinMode(VLOW_IO_PIN, OUTPUT);
  pinMode(VHIGH_IO_PIN, OUTPUT);
  digitalWrite(VLOW_IO_PIN, LOW);
  digitalWrite(VHIGH_IO_PIN, LOW);
  PwmOn();
}

void loop() {
  SetIOLevel(OutputLevel::Level0V);
  delay(DEMO_DELAY_MS);
  SetIOLevel(OutputLevel::Level5V);
  delay(DEMO_DELAY_MS);
  SetIOLevel(OutputLevel::Level12V);
  delay(DEMO_DELAY_MS);
}
