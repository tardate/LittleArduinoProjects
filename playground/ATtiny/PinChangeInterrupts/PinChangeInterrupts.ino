/*

  ATtiny/PinChangeInterrupts
  How to use pin change interrupts with the ATtiny85

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/ATtiny/PinChangeInterrupts

 */

const int LED_PIN = 0;  // D0: pin 5, PB0
const int INTERRUPT_PIN = 3;  // D3: pin 2, PB3

const int DEBOUNCE_DELAY = 750;

volatile bool interrupt_flag = false;
bool led_level = HIGH;

/*
 * Command: one-time setup
 */
void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, led_level);
  enablePinChangeInterrupt();
}

/*
 * Command: main loop - toggle the LED if interrupt flag is set
 */
void loop() {
  if (interrupt_flag) {
    led_level = !led_level;
    digitalWrite(LED_PIN, led_level);
    delay(DEBOUNCE_DELAY);
    interrupt_flag = false;
  }
}

/*
 * Command: enable pin change interrupts
 */
void enablePinChangeInterrupt() {
  pinMode(INTERRUPT_PIN, INPUT_PULLUP);
  cli();
  PCMSK |= (1 << digitalPinToPCMSKbit(INTERRUPT_PIN)); // Pin Change Enable
  // equivalent to: PCMSK |= (1 <<PCINT3);
  GIMSK |= (1 << digitalPinToPCICRbit(INTERRUPT_PIN)); // PCIE Pin Change Interrupt Enable
  // equivalent to: GIMSK |= (1 << PCIE);
  sei();
}

/*
 * Command: interrupt handler
 */
ISR(PCINT0_vect) {
  interrupt_flag = true;
}
