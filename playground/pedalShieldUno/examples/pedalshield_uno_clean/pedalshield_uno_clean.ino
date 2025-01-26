// CC-by-www.Electrosmash.com
// Based on OpenMusicLabs previous works.
// clean_pedalshield_uno.ino reads the ADC and plays it back into the PWM output

//defining hardware resources.
#define LED 13
#define FOOTSWITCH 12
#define TOGGLE 2
#define PUSHBUTTON_1 A5
#define PUSHBUTTON_2 A4

//defining the output PWM parameters
#define PWM_FREQ 0x00FF // pwm frequency - 31.3KHz
#define PWM_MODE 0 // Fast (1) or Phase Correct (0)
#define PWM_QTY 2 // 2 PWMs in parallel

//other variables
int input, vol_variable=512;
int counter=0;
byte ADC_low, ADC_high;

void setup() {
  //setup IO
  pinMode(FOOTSWITCH, INPUT_PULLUP);
  pinMode(PUSHBUTTON_1, INPUT_PULLUP);
  pinMode(PUSHBUTTON_2, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  
  // setup ADC
  ADMUX = 0x60; // left adjust, adc0, internal vcc
  ADCSRA = 0xe5; // turn on adc, ck/32, auto trigger
  ADCSRB = 0x07; // t1 capture for trigger
  DIDR0 = 0x01; // turn off digital inputs for adc0

  // setup PWM
  TCCR1A = (((PWM_QTY - 1) << 5) | 0x80 | (PWM_MODE << 1)); //
  TCCR1B = ((PWM_MODE << 3) | 0x11); // ck/1
  TIMSK1 = 0x20; // interrupt on capture interrupt
  ICR1H = (PWM_FREQ >> 8);
  ICR1L = (PWM_FREQ & 0xff);
  DDRB |= ((PWM_QTY << 1) | 0x02); // turn on outputs
  sei(); // turn on interrupts - not really necessary with arduino
  }

void loop() 
{
  //Turn on the LED if the effect is ON.
  if (digitalRead(FOOTSWITCH)) digitalWrite(LED, HIGH); 
    else  digitalWrite(LED, LOW);
  
  //nothing else here, all happens in the Timer 1 interruption.
}

ISR(TIMER1_CAPT_vect) 
{
  // get ADC data
  ADC_low = ADCL; // you need to fetch the low byte first
  ADC_high = ADCH;
  //construct the input sumple summing the ADC low and high byte.
  input = ((ADC_high << 8) | ADC_low) + 0x8000; // make a signed 16b value

  
  //write the PWM signal
  OCR1AL = ((input + 0x8000) >> 8); // convert to unsigned, send out high byte
  OCR1BL = input; // send out low byte

}
