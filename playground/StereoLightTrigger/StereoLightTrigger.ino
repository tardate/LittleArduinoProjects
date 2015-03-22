/*

  StereoLightTrigger
  Demonstrates an interrupt-driven method for an Arduino to respond to LDR light threshold triggers.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/lpayground/StereoLightTrigger

 */

// #define WITH_SERIAL_DEBUG

#define LDR_LEFT_PIN 2
#define LDR_LEFT_INTERRUPT 0
volatile int ldr_left_flag = 0;

#define LDR_RIGHT_PIN 3
#define LDR_RIGHT_INTERRUPT 1
volatile int ldr_right_flag = 0;

#define LDR_LEFT_INDICATOR_PIN 7
#define LDR_RIGHT_INDICATOR_PIN 8

void setup() {
  #ifdef WITH_SERIAL_DEBUG
  Serial.begin(9600);
  #endif

  // enable the input pins
  pinMode(LDR_LEFT_PIN, INPUT);
  attachInterrupt(LDR_LEFT_INTERRUPT, ldrLeftActivate, RISING);

  pinMode(LDR_RIGHT_PIN, INPUT);
  attachInterrupt(LDR_RIGHT_INTERRUPT, ldrRightActivate, RISING);

}

void loop() {
 checkAndReportStatus();
 delay(100);
}


void checkAndReportStatus() {
  int current_ldr_left = ldr_left_flag;
  int current_ldr_right = ldr_right_flag;

  #ifdef WITH_SERIAL_DEBUG
  String result = "";
  Serial.println(result + current_ldr_left + "," + current_ldr_right);
  #endif

  digitalWrite(LDR_LEFT_INDICATOR_PIN,current_ldr_left);
  digitalWrite(LDR_RIGHT_INDICATOR_PIN,current_ldr_right);
  ldr_left_flag = 0;
  ldr_right_flag = 0;
}

void ldrLeftActivate() {
  ldr_left_flag = 1;
}
void ldrRightActivate() {
  ldr_right_flag = 1;
}

