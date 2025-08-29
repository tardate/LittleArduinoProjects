/*

  cordwood/tuner
  Derived from & inspired by code by Nicole Grimwood and Amanda Ghassaei - see http://www.instructables.com/id/Arduino-Guitar-Tuner/

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/BoldportClub/cordwood/tuner

 */

#define fDELTA 10 // +/- 10 Hz wiggle room
#define f_E    82 // E 82.4 Hz
#define f_A   110 // A 110 Hz
#define f_D   147 // D 146.8 Hz
#define f_G   196 // G 196 Hz
#define f_B   247 // B 246.9 Hz
#define f_e   330 // e 329.6 Hz

// settings for the 6 strings:
#define PIN_INDEX 0 // GPIO pin index
#define F_INDEX   1 // target frequency index
#define LL_INDEX  2 // lower frequency limit index
#define UL_INDEX  3 // upper frequency limit index
const static int NOTES[][4]  = {
  { 2, f_E, (f_E - fDELTA), (f_E + fDELTA) },
  { 3, f_A, (f_A - fDELTA), (f_A + fDELTA) },
  { 4, f_D, (f_D - fDELTA), (f_D + fDELTA) },
  { 5, f_G, (f_G - fDELTA), (f_G + fDELTA) },
  { 6, f_B, (f_B - fDELTA), (f_B + fDELTA) },
  { 7, f_e, (f_e - fDELTA), (f_e + fDELTA) }
};

const int NUM_NOTES = sizeof(NOTES) / (sizeof(int) * 4);


volatile unsigned int period; // storage for period of wave
volatile byte checkMaxAmp;

int current_frequency;

const static byte SLOPE_TOLERANCE = 3;      // slope tolerance - adjust this if you need
const static int TIMER_TOLERANCE = 10;      // timer tolerance - adjust this if you need
const static byte SAMPLING_THRESHOLD = 100; // crossing-point for sampling
const static byte AMPLITUDE_THRESHOLD = 30; // raise if you have a very noisy signal


void setup() {
  enableLedOutput();
  setLeds(HIGH);
  enableAnalogSampling();
}


void loop() {
  setLeds(LOW);
  setFrequency();
  stringCheck();
  delay(100);
}


/*
 * enable all the LED pins
 */
void enableLedOutput() {
  for(byte note = 0; note < NUM_NOTES; note++) {
    pinMode(NOTES[note][PIN_INDEX], OUTPUT);
  }
}

/*
 * toggle all the LEDs
 */
void setLeds(byte level) {
  for(byte note = 0; note < NUM_NOTES; note++) {
    digitalWrite(NOTES[note][PIN_INDEX], level);
  }
}

/*
 * recalculate the current input frequency
 */
void setFrequency() {
  if (checkMaxAmp > AMPLITUDE_THRESHOLD) {
    current_frequency = 38462/float(period);
  }
}

/*
 * turn on the LED for the detected string (if any)
 */
void stringCheck() {
  for(byte note = 0; note < NUM_NOTES; note++) {
    if (current_frequency > NOTES[note][LL_INDEX] & current_frequency < NOTES[note][UL_INDEX]) {
      setLeds(LOW);
      digitalWrite(NOTES[note][PIN_INDEX], HIGH);
      break;
    }
  }
}


/*
 * set up continuous sampling of analog pin 0 at 38.5kHz
 */
void enableAnalogSampling() {
  cli(); // disable interrupts
  ADCSRA = 0; ADCSRB = 0;                // clear ADCSRA and ADCSRB registers
  ADMUX |= (1 << REFS0);                 // set reference voltage
  ADMUX |= (1 << ADLAR);                 // left align the ADC value - so we can read highest 8 bits from ADCH register only
  ADCSRA |= (1 << ADPS2) | (1 << ADPS0); // set ADC clock with 32 prescaler- 16mHz/32=500kHz
  ADCSRA |= (1 << ADATE);                // enabble auto trigger
  ADCSRA |= (1 << ADIE);                 // enable interrupts when measurement complete
  ADCSRA |= (1 << ADEN);                 // enable ADC
  ADCSRA |= (1 << ADSC);                 // start ADC measurements
  sei(); // enable interrupts
}

/*
 * globals that are basically "private" to the ADC ISR...
 */

byte newData = 0;
byte prevData = 0;

unsigned int time = 0;//keeps time and sends vales to store in timer[] occasionally

#define ADC_SAMPLES 10 // number of samples to store
int timer[ADC_SAMPLES];  // storage for timing of events
int slope[ADC_SAMPLES];  // storage for slope of events
byte sample_index = 0; // current storage index

unsigned int totalTimer;//used to calculate period

int maxSlope = 0;//used to calculate max slope as trigger point
int newSlope;//storage for incoming slope data

byte noMatch = 0; // counts how many non-matches you've received to reset variables if it's been too long

//variables for amp detection
unsigned int ampTimer = 0;
byte maxAmp = 0;

/*
 * interrupt handler for when new ADC value ready
 */
ISR(ADC_vect) {

  // store previous value and read new
  // Since the result is left adjusted and no more than 8-bit precision is required, it is sufficient to read ADCH.
  prevData = newData;
  newData = ADCH;

  if (prevData < SAMPLING_THRESHOLD && newData >= SAMPLING_THRESHOLD){
    //if increasing and crossing sampling threshold

    newSlope = newData - prevData; //calculate slope

    if (abs(newSlope-maxSlope)<SLOPE_TOLERANCE){//if slopes are ==

      //record new data and reset time
      slope[sample_index] = newSlope;
      timer[sample_index] = time;
      time = 0;
      if (sample_index == 0){//new max slope just reset
        noMatch = 0;
        sample_index++;
      }
      else if (abs(timer[0]-timer[sample_index])<TIMER_TOLERANCE && abs(slope[0]-newSlope)<SLOPE_TOLERANCE) {//if timer duration and slopes match
        //sum timer values
        totalTimer = 0;
        for (byte i=0;i<sample_index;i++){
          totalTimer+=timer[i];
        }
        period = totalTimer;//set period
        //reset new zero index values to compare with
        timer[0] = timer[sample_index];
        slope[0] = slope[sample_index];
        sample_index = 1;//set index to 1
        noMatch = 0;
      }
      else{//crossing midpoint but not match
        sample_index++;//increment index
        if (sample_index >= ADC_SAMPLES){
          reset();
        }
      }
    }
    else if (newSlope>maxSlope){//if new slope is much larger than max slope
      maxSlope = newSlope;
      time = 0;//reset clock
      noMatch = 0;
      sample_index = 0;//reset index
    }
    else{//slope not steep enough
      noMatch++;//increment no match counter
      if (noMatch >= ADC_SAMPLES){
        reset();
      }
    }
  }

  time++; //increment timer at rate of 38.5kHz

  ampTimer++; //increment amplitude timer
  if (abs(127-ADCH)>maxAmp){
    maxAmp = abs(127-ADCH);
  }
  if (ampTimer==1000){
    ampTimer = 0;
    checkMaxAmp = maxAmp;
    maxAmp = 0;
  }

}

inline void reset(){
  sample_index = 0;//reset index
  noMatch = 0;//reset match couner
  maxSlope = 0;//reset slope
}
