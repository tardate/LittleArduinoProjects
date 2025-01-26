#ifndef MicSubsystem_h
#define MicSubsystem_h

int mic_reading;
int mic_reading_max;
int mic_reading_min;
boolean mic_state;

void clearMicState() {
  mic_reading = 512;
  mic_reading_max = 512;
  mic_reading_min = 512;
  mic_state = false;
}

#ifdef ENABLE_MIC_SUBSYSTEM

#define TRIGGER_TRIES 400
#define TRIGGER_BAND 120
#define TRIGGER_BAND_LOW 512 - TRIGGER_BAND
#define TRIGGER_BAND_HI 512 + TRIGGER_BAND

void setupMicSystem() {
  clearMicState();
  pinMode(MIC_AMP_OUT_PIN, INPUT);
}

boolean sampleMicState() {
  for(int tries = 0 ; tries < TRIGGER_TRIES; tries++) {
    if(!mic_state) {
      mic_reading = analogRead(MIC_AMP_OUT_PIN);
      if(mic_reading<mic_reading_min) mic_reading_min = mic_reading;
      if(mic_reading>mic_reading_max) mic_reading_max = mic_reading;
      //mic_state = (mic_reading > 100) && ( (mic_reading < TRIGGER_BAND_LOW) || (mic_reading > TRIGGER_BAND_HI));
      mic_state = mic_reading > TRIGGER_BAND_HI;
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
