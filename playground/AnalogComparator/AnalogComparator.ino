/*

  AnalogComparator
  Testing the Atmega328 built-in analog comparator

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/AnalogComparator

 */

#define INDICATOR_PIN 8

volatile boolean triggered;
volatile boolean rising;
volatile byte acsr_value;

ISR (ANALOG_COMP_vect) {
  if (triggered) return;           // For testing purposes, ignore the interrupt if we haven't reported the last one yet.
                                   // This also effects some crude debouncing.
  cli();
  acsr_value = ACSR;
  rising = (acsr_value & bit(ACO)) > 0;
  triggered = true;
  sei();
}

void setup() {
  Serial.begin (115200);
  Serial.println ("Started.");

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

// just give an indication via Serial and LED that we handled an interrupt...
void show_what_happened() {
  digitalWrite(INDICATOR_PIN, HIGH);

  Serial.print ("Triggered! ACSR=");
  Serial.print (acsr_value, BIN);
  if (rising)
    Serial.println (" RISING EDGE (as expected)");
  else
    Serial.println (" FALLING EDGE .. wtf, didn't ask for this, but every so often one slips thru. Maybe a sync issue reading ACSR.");

  triggered = false;

  delay(100);
  digitalWrite(INDICATOR_PIN, LOW);
}