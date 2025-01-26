#ifndef LdrSubsystem_h
#define LdrSubsystem_h

// quad-state indicator
// 00 - left/right off
// 01 - left off/right on
// 10 - left on/right off
// 11 - left on/right on

int ldr_state = 0;

void clearLdrState() {
  ldr_state = 0;
}

#ifdef ENABLE_LDR_SUBSYSTEM

void setupLdrSystem() {
  pinMode(LDR_ENABLE_PIN, INPUT);
  pinMode(LDR1OUT_PIN, INPUT);
  pinMode(LDR2OUT_PIN, INPUT);
  digitalWrite(LDR_ENABLE_PIN, HIGH);
}

int sampleLdrState() {
  ldr_state = digitalRead(LDR1OUT_PIN) << 1 | digitalRead(LDR2OUT_PIN);
  return ldr_state;
}


#else
// NOP functions for when LDRs disabled

void setupLdrSystem() {
}

int sampleLdrState() {
  return 0;
}

#endif

#endif
