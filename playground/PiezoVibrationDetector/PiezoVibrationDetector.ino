/*

  PiezoVibrationDetector
  Counting the beat with a piezo tap sensor and the Arduino/ATmega328 analog comparator.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/PiezoVibrationDetector

 */

const int MIN_MILLIS_PER_BEAT = 240;   // 250 bpm, "too fast to be useful"
const int MAX_MILLIS_PER_BEAT = 1800;  // 33 bpm, "threshold of the perceptual present"
const float BPM_FACTOR = 60.0 * 1000.0;
const float BPM_SMOOTHING_FACTOR = 0.4;

volatile unsigned long current_sample_time = 0;
volatile unsigned long previous_sample_time = 0;
volatile unsigned long instant_millis_per_beat = 0;
volatile int current_bpm = 0;
volatile boolean bpm_changed;


void setup() {
  displaySetup();
  enableComparatorInterrupt();
}


void loop () {
  if (bpm_changed) {
    displayBPM();
    bpm_changed = false;
  }

}


void enableComparatorInterrupt() {
  ADCSRB = 0;                   // Disable ACME: Analog Comparator Multiplexer Enable
  ACSR =
    _BV(ACI)                    // Clear Analog Comparator Interrupt Flag
    | _BV(ACIE)                 // Analog Comparator Interrupt Enable
    | _BV(ACIS1) | _BV(ACIS0);  // ACIS1, ACIS0: Analog Comparator Interrupt on Rising edge
}


/*
 Analog Comparator Interrupt, triggered on rising edge
 */
ISR (ANALOG_COMP_vect) {
  previous_sample_time = current_sample_time;
  current_sample_time = millis();

  instant_millis_per_beat = current_sample_time - previous_sample_time;
  if(instant_millis_per_beat > MAX_MILLIS_PER_BEAT) {
    // reset
    current_bpm = 0;
  } else if (instant_millis_per_beat < MIN_MILLIS_PER_BEAT)  {
    // discard
  } else {
    // counting the beat with simple exponential averaging
    if(current_bpm == 0) current_bpm = BPM_FACTOR / instant_millis_per_beat;
    else current_bpm =
      BPM_SMOOTHING_FACTOR * BPM_FACTOR / instant_millis_per_beat
      + (1.0 - BPM_SMOOTHING_FACTOR) * current_bpm;
    bpm_changed = true;
  }
}


void  displaySetup() {
  Serial.begin (115200);
  Serial.println ("Started.");
}


void displayBPM() {
  Serial.print("Current BPM: ");
  Serial.print(current_bpm);
  Serial.print(", ms per beat: ");
  Serial.println(instant_millis_per_beat);
}
