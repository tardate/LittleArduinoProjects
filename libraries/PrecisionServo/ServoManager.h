#ifndef ServoManager_h
#define ServoManager_h

#include <Arduino.h>
#include <PrecisionServo.h>

class ServoManager {
	public:
		/**
		 * Initial setup required for all servo related 
		 * calls. Must be called prior to any other servo 
		 * manager functions.
		 * @param numServos how many servos are going to be set up
		 */
		static void setup(uint8_t numServos);
		
		/**
		 * Create a new servo at the specified pin 
		 * @param pin the pin which the servo will function on 
		 * @return a new servo attached to that pin 
		 */
		static PrecisionServo* createServo(uint8_t pin);
		
		/**
		 * Wait until the servos are at the target locations
		 */
		static void waitUntilFinished();
};

#endif