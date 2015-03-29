#ifndef MicSubsystem_h
#define MicSubsystem_h


volatile int mic_reading;
volatile boolean mic_state;

void clearMicState() {
  mic_reading = 512;
  mic_state = false;
}

#ifdef ENABLE_MIC_SUBSYSTEM

#define TRIGGER_THRESHOLD 100

void setupMicSystem() {
  clearMicState();
  pinMode(MIC_AMP_OUT_PIN, INPUT);
}

boolean sampleMicState() {
  if(!mic_state) {
    int new_mic_reading = analogRead(MIC_AMP_OUT_PIN);
    if(new_mic_reading<mic_reading) {
      mic_reading = new_mic_reading;
      mic_state = (mic_reading < TRIGGER_THRESHOLD);
    }
  }
  return mic_state;
}

#else
// NOP functions for when LDRs disabled

void setupMicSystem() {
}

boolean sampleMicState() {
  return false;
}

#endif

#endif
