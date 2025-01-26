#include <ServoManager.h>

// The number of microseconds of ON per 20ms to get the servo to go to 180
#define MICROSECONDS_FOR_180 2000

// The number of microseconds of ON per 20ms to get the servo to go to 0
#define MICROSECONDS_FOR_0 400

int8_t sign(int16_t num) {
	if(num < 0) {
		return -1;
	}else if(num == 0) {
		return 0;
	}else {
		return 1;
	}
}

/**
 * Stores how many microseconds before we should send information
 * to the servos
 */
static uint32_t microsecondsUntilNextCycle = 0;
static bool currentlyUpdatingServos = false;
static PrecisionServo* servos = NULL;
static uint8_t numServos = 0;
static uint8_t totalServos = 0;

void ServoManager::setup(uint8_t totServos) {
	// TIMSK - Timer/Counter Interrupt Mask Register
	// OCIE0A - Timer/Counter0 Output Compare Match A Interrupt Enable
	// TOIE0 - Timer/Counter0 Overflow Interrupt Enable 
	TIMSK |= _BV(TOIE1);
	
	// TCCR1 - Timer/Counter1 Control Register 
	// Bits CS1[3:0] -> control prescaling
	TCCR1 = _BV(CS12) | _BV(CS11) | _BV(CS10) | _BV(CTC1); // 1/64 prescaling with reset on match with OCR1C 
	
	// 159 is the desired overflow time; this comes from the 
	// table on page 88 for a 50kHz clock. That's not what 
	// we have but somehow it works
	OCR1C = 159;
	
	PLLCSR |= _BV(PCKE); // use the fast peripheral clock (64Mhz)
	
	if(totServos <= 0) {
		// ideally we'd raise an error 
		totalServos = -1;
		return;
	}
	
	servos = (PrecisionServo*)malloc(sizeof(PrecisionServo) * totServos);
	numServos = 0;
	totalServos = totServos;
	
	// enable global interrupts
	sei();
}

PrecisionServo* ServoManager::createServo(uint8_t pin) {
	if(numServos >= totalServos)
		return NULL; // ideally we'd raise an error 
	
	PrecisionServo* newServo = (servos + sizeof(PrecisionServo) * numServos);
	numServos++;
	
	pinMode(pin, OUTPUT);
	newServo->pin = pin;
	newServo->angleDegrees = 0;
	newServo->targetAngleDegrees = 0;
	newServo->iterationsLeftOnCurrentIncrement = 10;
	newServo->lastDirection = 0;
	newServo->setSetting(SERVO_SLOW_PRECISE);
	return newServo;
}

void ServoManager::waitUntilFinished() {
	bool finished = false;
	while(!finished) {
		finished = true;
		PrecisionServo* servo = servos;
		for(uint8_t index = 0; index < numServos; index++) {
			if(index != 0) {
				servo += sizeof(PrecisionServo);
			}
			
			if(servo->iterationsLeftOnCurrentIncrement != 0 || servo->angleDegrees != servo->targetAngleDegrees) {
				finished = false;
				break;
			}
		}
	}
}

int32_t calculateOntimeFor(uint8_t degrees) {
	return (int32_t)(MICROSECONDS_FOR_0 + (MICROSECONDS_FOR_180 - MICROSECONDS_FOR_0) * (degrees / 180.0));
}

int32_t sendServoSignal(PrecisionServo* servo) {
	int32_t ontime = calculateOntimeFor(servo->angleDegrees);

	digitalWrite(servo->pin, HIGH);
	delayMicroseconds(ontime);
	digitalWrite(servo->pin, LOW);

	
	return ontime;
}

void interpolateServo(PrecisionServo* servo) {
	if(servo->iterationsLeftOnCurrentIncrement > 0) {
		servo->iterationsLeftOnCurrentIncrement--;
	}else if(servo->targetChanged && servo->newTarAddIters != 0) {
		servo->iterationsLeftOnCurrentIncrement = servo->newTarAddIters;
		servo->targetChanged = false;
	}else if(servo->angleDegrees != servo->targetAngleDegrees) {
		int32_t towardAmt = servo->targetAngleDegrees - servo->angleDegrees;
		int8_t towardSign = sign(towardAmt);
		
		if(towardSign != servo->lastDirection && servo->newDirAddIters != 0) {
			servo->iterationsLeftOnCurrentIncrement = servo->newDirAddIters;
		}else {		
			if(towardAmt >= -servo->maxMovement && towardAmt <= servo->maxMovement) {
				servo->angleDegrees = servo->targetAngleDegrees;
			}else {
				servo->angleDegrees += sign(towardAmt) * servo->maxMovement;
			}
			
			servo->iterationsLeftOnCurrentIncrement = servo->movementIters;
		}
		servo->lastDirection = towardSign;
	}
}

void updateServos() {
	PrecisionServo* servo = servos;
	
	int32_t lastSleep = 0;
	for(int i = 0; i < numServos; i++) {
		if(i != 0) {
			servo += sizeof(PrecisionServo);
			delayMicroseconds(MICROSECONDS_FOR_180 - lastSleep);
		}
		
		lastSleep = sendServoSignal(servo);
		interpolateServo(servo);
	}
}

ISR(TIM1_OVF_vect) {
	updateServos();
}
