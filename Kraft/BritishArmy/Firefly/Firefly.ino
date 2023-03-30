/*

  Firefly
  Testing some mini/micro linear servo motors with an ATtiny85

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Kraft/BritishArmy/Firefly

 */


#include <SoftwareServo.h>

static const int FIRING_PIN = PB3; // pin 2 on the DIP8 ATTiny85
static const int SERVO_PIN = PB4; // pin 3 on the DIP8 ATTiny85

static const int TIME_TO_GET_BOOTS_ON = 800;
static const int TIME_TO_FIRE = 300;
static const int TIME_TO_RELOAD = 1000;
static const int CRANK_IT = 20;

static const int STARTING_ANGLE = 10;

static const int STEPS_PER_SEQUENCE = 4;
static const int SEQUENCE_SIZE = STEPS_PER_SEQUENCE * 2;

static const int ACTION_SEQUENCE[][SEQUENCE_SIZE] =
{
 // each step is a pair of values: (target angle, degrees per update). Ignore step if target angle < 0
 { 55,   3, 100,   2,  80,   2,  85,   1}
,{ 65,   1,  30,   5,  20,   1,  60,   1}
,{170,   1,  90,   4,  70,   2,  80,   1}
,{ 75,   1,  65,   2,  55,   3,  45,   1}
};

const int NUM_ACTION_SEQUENCES = sizeof(ACTION_SEQUENCE) / (sizeof(int) * SEQUENCE_SIZE);

volatile boolean triggered;
volatile boolean rising;
volatile byte acsr_value;
SoftwareServo myServo;


ISR (ANA_COMP_vect) {
  if (triggered) return;

  cli();
  acsr_value = ACSR;
  rising = (acsr_value & bit(ACO)) > 0;
  triggered = true;
  sei();
}


void setup() {
  pinMode(FIRING_PIN, OUTPUT);
  digitalWrite(FIRING_PIN, LOW);

  myServo.attach(SERVO_PIN);
  myServo.setMinimumPulse(832);
  stepTo(STARTING_ANGLE);

  ADCSRB = ADCSRB & ! bit(ACME);   // disable Analog Comparator Multiplexer Enable
  ACSR =  bit(ACI)                 // clear Analog Comparator Interrupt Flag
        | bit(ACIE)                // set Analog Comparator Interrupt Enable
        | bit(ACIS1) | bit(ACIS0)  // select rising edge: ACIS1/ACIS0 Analog Comparator Interrupt Mode Select
        ;
}


void loop() {
  if (triggered) {
    take_action_chaps();
    triggered = false;
  }
}


void take_action_chaps() {
  delay(TIME_TO_GET_BOOTS_ON);
  traverse_turret();
  fire();
  delay(TIME_TO_RELOAD);
}


void traverse_turret() {
  static int current_sequence = 0;
  static int current_angle = 0;

  for(int step = 0; step < SEQUENCE_SIZE; step += 2) {

    int end_angle = ACTION_SEQUENCE[current_sequence][step];
    int delta = ACTION_SEQUENCE[current_sequence][step + 1];

    if (end_angle > current_angle) {
      do {
        current_angle += delta;
        if (current_angle > end_angle) current_angle = end_angle;
        stepTo(current_angle);
      } while(current_angle < end_angle);

    } else {
      do {
        current_angle -= delta;
        if (current_angle < end_angle) current_angle = end_angle;
        stepTo(current_angle);
      } while(current_angle > end_angle);
    }
  }

  if (++current_sequence >= NUM_ACTION_SEQUENCES) current_sequence = 0;
}


void fire() {
  // TODO: find a good sound effect
  digitalWrite(FIRING_PIN, HIGH);
  delay(TIME_TO_FIRE);
  digitalWrite(FIRING_PIN, LOW);
}


void stepTo(int pos) {
  myServo.write(pos);
  delay(CRANK_IT);
  SoftwareServo::refresh();
}
