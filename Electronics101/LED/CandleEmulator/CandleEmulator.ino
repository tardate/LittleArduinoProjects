/*

  LED/CandleEmulator
  An Arduino LED candle emulation

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/LED/CandleEmulator

 */

const int LED_PIN = 11;

uint8_t pwmDutyThreshold = 0;
uint8_t nextPwmDutyThreshold = 0;


/*
 * Command: one-time setup
 */
void setup() {
  pinMode(LED_PIN, OUTPUT);
}


/*
 * Command: main loop
 */
void loop() {
  if (pwmCycleStarted()) {
    if (animationFrameStarted()) {
      // update PWM duty cycle at the beginning of the frame
      pwmDutyThreshold = nextPwmDutyThreshold;
    }
  }
}


/*
 * Command: bit-banging PWM - increments PWM counter
 * Returns True if new PWM cycle started
 */
bool pwmCycleStarted() {
  static uint8_t pwmCounter = 0;

  delayMicroseconds(1000000/440/16); // Main clock=440*16 Hz

  // go high at start of PWM cycle
  if (pwmCounter == 0) digitalWrite(LED_PIN, HIGH);

  // increment the 4-bit PWM counter
  pwmCounter++;
  pwmCounter &= 0xf;

  // go low when duty cycle target reached
  if (pwmCounter == pwmDutyThreshold) digitalWrite(LED_PIN, LOW);

  return (pwmCounter == 0);
}


/*
 * Command: increments animation frame
 * Returns True if a new animation frame has started
 */
bool animationFrameStarted() {
  static uint8_t frameCounter = 0;  // 5 bit-Counter

  // increment the 5-bit frame counter
  frameCounter++;
  frameCounter &= 0x1f;

  if ((frameCounter & 0x07) == 0) {
    // generate a new random number every 8 cycles.
    uint8_t newValue = Rand() & 0x1f;
    if ((newValue & 0x0c) != 0) {
      // set new PWM duty cycle after rejecting values are identified by bit 2 and 3=0
      // and map upper half of values to maximum brightness
      nextPwmDutyThreshold = newValue > 0xf ? 0xf : newValue;
    }
  }

  return (frameCounter == 0);
}


/*
  32 Bit maximum length LFSR
  see http://www.ece.cmu.edu/~koopman/lfsr/index.html

  Using inverted values so the LFSR also works with zero initialisiation.
*/
uint8_t Rand(void) {
  static uint32_t Z = 0;

  if (Z & 1) {
    Z = (Z >> 1);
  } else {
    Z = (Z >> 1) ^ 0x7FFFF159;
  }

  return (uint8_t)Z;
}
