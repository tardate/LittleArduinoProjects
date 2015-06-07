/*

  BJTLongTailPair
  Test a BJT differential amplifier circuit

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/BJTLongTailPair

 */

#define VREF      4920

#define AO1_PIN   A0
#define AO2_PIN   A1
#define AB1_PIN   A2
#define AB2_PIN   A3

void setup() {
  Serial.begin(9600);
  pinMode(AO1_PIN, INPUT);
  pinMode(AO2_PIN, INPUT);
  pinMode(AB1_PIN, INPUT);
  pinMode(AB2_PIN, INPUT);
}

void loop() {
  sample();
  delay(3000);
}

void sample() {
  int ao1 = map( analogRead(AO1_PIN), 0, 1023, 0, VREF);
  int ao2 = map( analogRead(AO2_PIN), 0, 1023, 0, VREF);
  int ab1 = map( analogRead(AB1_PIN), 0, 1023, 0, VREF);
  int ab2 = map( analogRead(AB2_PIN), 0, 1023, 0, VREF);

  int input_differential = 2 * ab2 - 2 * ab1;
  int output_differential = 2 * ao2 - 2 * ao1;
  float gain = 1.0 * output_differential/input_differential;

  Serial.println("\nSample:");
  Serial.print("                ao1: "); Serial.print(ao1);                   Serial.println(" mV");
  Serial.print("                ao2: "); Serial.print(ao2);                   Serial.println(" mV");
  Serial.print("                ab1: "); Serial.print(ab1);                   Serial.println(" mV");
  Serial.print("                ab2: "); Serial.print(ab2);                   Serial.println(" mV");
  Serial.print(" input_differential: "); Serial.print(input_differential);    Serial.println(" mV");
  Serial.print("output_differential: "); Serial.print(output_differential);   Serial.println(" mV");
  Serial.print("               gain: "); Serial.println(gain);
}

