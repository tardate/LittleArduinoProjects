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
  acsr_value = ACSR;
  triggered = true;
  rising = (acsr_value & bit (ACO)) > 0;
}

void setup () {
  Serial.begin (115200);
  Serial.println ("Started.");

  pinMode(INDICATOR_PIN, OUTPUT);
  digitalWrite(INDICATOR_PIN, LOW);

  ADCSRB = ADCSRB & ! bit (ACME); // disable Analog Comparator Multiplexer Enable
  ACSR =  bit (ACI)               // clear Analog Comparator Interrupt Flag
        | bit (ACIE)              // set Analog Comparator Interrupt Enable
        | bit (ACIS1)             // select falling edge: ACIS1/ACIS0 Analog Comparator Interrupt Mode Select
        ;
}

void loop () {

  if (triggered) {

    cli();

    // just give an indication via Serial and LED that we handled an interrupt...
    digitalWrite(INDICATOR_PIN, HIGH);
    triggered = false;

    Serial.print ("Triggered! ACSR=");
    Serial.print (acsr_value, BIN);
    if (rising)
      Serial.println (" RISING EDGE .. wtf, didn't ask for these");
    else
      Serial.println (" FALLING EDGE (as requested)");

    sei();

    delay(200);
    digitalWrite(INDICATOR_PIN, LOW);


  }

}