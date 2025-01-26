/*

  ATtiny/AnalogComparator
  Testing the ATtiny85 built-in analog comparator

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/ATtiny/AnalogComparator

 */

static const int INDICATOR_PIN = PB4;

volatile boolean triggered;
volatile boolean rising;
volatile byte acsr_value;

ISR (ANA_COMP_vect) {
  if (triggered) {
    // For testing purposes, ignore the interrupt if we haven't reported the last one yet.
    // This also effects some crude debouncing.
    return;
  }

  cli();
  acsr_value = ACSR;
  rising = (acsr_value & bit(ACO)) > 0;
  triggered = true;
  sei();
}

void setup() {
  pinMode(INDICATOR_PIN, OUTPUT);
  digitalWrite(INDICATOR_PIN, LOW);

  ADCSRB = ADCSRB & ! bit(ACME);   // disable Analog Comparator Multiplexer Enable
  ACSR =  bit(ACI)                 // clear Analog Comparator Interrupt Flag
        | bit(ACIE)                // set Analog Comparator Interrupt Enable
        | bit(ACIS1) | bit(ACIS0)  // select rising edge: ACIS1/ACIS0 Analog Comparator Interrupt Mode Select
        ;
}

void loop() {
  if (triggered) show_what_happened();
}

// just give an indication on the LED that we handled an interrupt...
void show_what_happened() {
  digitalWrite(INDICATOR_PIN, HIGH);
  delay(100);
  digitalWrite(INDICATOR_PIN, LOW);
  triggered = false;
}
