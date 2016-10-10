/*

  BasicBuckBoostAvrControl
  __subtitle__

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/BasicBuckBoostAvrControl

 */

#define F_CPU 8000000
const int pwm = 1;
const int potinput = A1;
const int feedbackinput = A3;
int potinputval;
int feedbackinputval;
int pwmval;

void setup() {
  TCCR0A = 2 << COM0A0 | 2 << COM0B0 | 3 << WGM00;
  TCCR0B = 0 << WGM02 | 1 << CS00;
  TCCR1 = 0 << PWM1A | 0 << COM1A0 | 1 << CS10;
  GTCCR = 1 << PWM1B | 2 << COM1B0;
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
    if (pwmval > 203){
      analogWrite(pwm, pwmval);
      potinputval = analogRead(potinput);
      feedbackinputval = analogRead(feedbackinput);
    }
    else {
    analogWrite(pwm, pwmval);
    pwmval = pwmval + 1;
    potinputval = analogRead(potinput);
    feedbackinputval = analogRead(feedbackinput);
  }}
  while (feedbackinputval > potinputval){
    if (pwmval == 0){
      analogWrite(pwm, pwmval);
      potinputval = analogRead(potinput);
      feedbackinputval = analogRead(feedbackinput);
    }
    else{
    analogWrite(pwm, pwmval);
    pwmval = pwmval - 1;
    potinputval = analogRead(potinput);
    feedbackinputval = analogRead(feedbackinput);
    }}
}
