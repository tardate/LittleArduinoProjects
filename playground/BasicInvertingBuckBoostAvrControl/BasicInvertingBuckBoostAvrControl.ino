/*

  BasicInvertingBuckBoostAvrControl
  Based on original script from http://www.instructables.com/id/DIY-BuckBoost-Converter-Flyback/?ALLSTEPS

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/BasicInvertingBuckBoostAvrControl

 */

const int pwm = PB1;
const int potinput = A1;
const int feedbackinput = A3;

int potinputval;
int feedbackinputval;
int pwmval;

void setup() {
  // 8-bit Timer/Counter0 with PWM
  // WGM=b011: Fast PWM, TOP=0xFF, Update OCRx at BOTTOM
  // COM0A=0b11: Clear OC0A on Compare Match, set OC0A at BOTTOM
  // COM0B=0b11: Clear OC0B on Compare Match, set OC0B at BOTTOM
  // CS=0b001: clkI/O/(No prescaling)
  TCCR0A = 2 << COM0A0 | 2 << COM0B0 | 3 << WGM00;
  TCCR0B = 0 << WGM02 | 1 << CS00;

  // 8-bit Timer/Counter1
  // Timer/Counter Comparator A disconnected from output pin OC1A
  // PWM1B: Pulse Width Modulator B Enable
  // COM1B=0b10: Clear the OC1B output line.
  TCCR1 = 0 << PWM1A | 0 << COM1A0 | 1 << CS10;
  GTCCR = 1 << PWM1B | 2 << COM1B0;

  // note: analogWrite resets the COM settings!

  pinMode(pwm, OUTPUT);
  pinMode(potinput, INPUT);
  pinMode(feedbackinput, INPUT);

  digitalWrite(pwm, LOW);
  pwmval = 0;
}

void loop() {
  potinputval = analogRead(potinput);
  feedbackinputval = analogRead(feedbackinput);

  while (feedbackinputval < potinputval){
    // output is less than desired:
    // ramp up to 203 max, ~80% duty cycle (value seems arbitrary??))
    analogWrite(pwm, pwmval);
    if (pwmval < 204) pwmval = pwmval + 1;
    potinputval = analogRead(potinput);
    feedbackinputval = analogRead(feedbackinput);
  }

  while (feedbackinputval > potinputval){
    // output is higher than desired:
    // ramp down to 0 min
    analogWrite(pwm, pwmval);
    if (pwmval > 0) pwmval = pwmval - 1;
    potinputval = analogRead(potinput);
    feedbackinputval = analogRead(feedbackinput);
  }

}
