/*

  TestIR
  Use raw pin reading methods to read and decode IR sensor input.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/TestIR
  This code is based on original source from https://learn.adafruit.com/ir-sensor/using-an-ir-sensor

*/

// when defined, sends data stream for plotting, else sends data dump
// #define ENABLE_PLOT_OUTPUT

#define IRpin_PIN PIND
#define IRpin 2
#define IRpin_MASK _BV(IRpin)

#define MAXPULSE 65000
#define PULSE_RESOLUTION 20

uint16_t pulses[100][2];
uint8_t pulse_index = 0;

void setup(void) {
  Serial.begin(9600);
#ifndef ENABLE_PLOT_OUTPUT
  Serial.println("Ready to receive IR data..");
#endif
}

void loop(void) {
  uint16_t highpulse = 0;
  uint16_t lowpulse = 0;

  while (IRpin_PIN & IRpin_MASK) {
    highpulse++;
    delayMicroseconds(PULSE_RESOLUTION);

    if ((highpulse >= MAXPULSE) && (pulse_index != 0)) {
      printPulses();
      pulse_index=0;
      return;
    }
  }
  pulses[pulse_index][0] = highpulse;

  while (! (IRpin_PIN & IRpin_MASK)) {
    lowpulse++;
    delayMicroseconds(PULSE_RESOLUTION);

    if ((lowpulse >= MAXPULSE) && (pulse_index != 0)) {
      printPulses();
      pulse_index=0;
      return;
    }
  }
  pulses[pulse_index][1] = lowpulse;

  pulse_index++;
}

#ifdef ENABLE_PLOT_OUTPUT

void printPulses(void) {
  for (uint8_t i = 0; i < pulse_index; i++) {
    for (int high_pulse_count = 0; high_pulse_count < pulses[i][0] /10 && high_pulse_count < 100; high_pulse_count++) {
      Serial.println("1024");
    }
    for (int low_pulse_count = 0; low_pulse_count < pulses[i][1] / 10 && low_pulse_count < 100; low_pulse_count++) {
      Serial.println("0");
    }
  }
}

#else

void printPulses(void) {
  Serial.println("\n\r\n\rReceived: \n\rOFF \tON");
  for (uint8_t i = 0; i < pulse_index; i++) {
    Serial.print(pulses[i][0] * PULSE_RESOLUTION, DEC);
    Serial.print(" usec, ");
    Serial.print(pulses[i][1] * PULSE_RESOLUTION, DEC);
    Serial.println(" usec");
  }

  // print it in a 'array' format
  Serial.println("int IRsignal[] = {");
  Serial.println("// ON, OFF (in 10's of microseconds)");
  for (uint8_t i = 0; i < pulse_index-1; i++) {
    Serial.print("\t"); // tab
    Serial.print(pulses[i][1] * PULSE_RESOLUTION / 10, DEC);
    Serial.print(", ");
    Serial.print(pulses[i+1][0] * PULSE_RESOLUTION / 10, DEC);
    Serial.println(",");
  }
  Serial.print("\t"); // tab
  Serial.print(pulses[pulse_index-1][1] * PULSE_RESOLUTION / 10, DEC);
  Serial.print(", 0};");
}

#endif

