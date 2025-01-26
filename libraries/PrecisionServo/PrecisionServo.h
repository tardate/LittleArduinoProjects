#ifndef PrecisionServo_h
#define PrecisionServo_h

#define SERVO_SLOW_SMOOTH 0 
#define SERVO_SLOW_PRECISE 1
#define SERVO_SLOW_ENDPOINT 2

#define SERVO_MEDIUM_SMOOTH 3
#define SERVO_MEDIUM_PRECISE 4
#define SERVO_MEDIUM_ENDPOINT 5 

#define SERVO_FAST_SMOOTH 6
#define SERVO_FAST_PRECISE 7
#define SERVO_FAST_ENDPOINT 8 

// The maximum number of degrees that we ask the servo to move at once
// higher values -> faster, less accurate movement
#define SLOW_SMOOTH_MAX_MOVEMENT 3
#define SLOW_PRECISE_MAX_MOVEMENT 10
#define SLOW_ENDPOINT_MAX_MOVEMENT 10

#define MEDIUM_SMOOTH_MAX_MOVEMENT 5
#define MEDIUM_PRECISE_MAX_MOVEMENT 12
#define MEDIUM_ENDPOINT_MAX_MOVEMENT 12

#define FAST_SMOOTH_MAX_MOVEMENT 8
#define FAST_PRECISE_MAX_MOVEMENT 15
#define FAST_ENDPOINT_MAX_MOVEMENT 15

// The number of times we send our orders to the servo when we change its 
// angle by max movement. Each iteration is roughly 20ms
#define SLOW_SMOOTH_MOVEMENT_ITERATIONS 3
#define SLOW_PRECISE_MOVEMENT_ITERATIONS 2
#define SLOW_ENDPOINT_MOVEMENT_ITERATIONS 2

#define MEDIUM_SMOOTH_MOVEMENT_ITERATIONS 2
#define MEDIUM_PRECISE_MOVEMENT_ITERATIONS 1
#define MEDIUM_ENDPOINT_MOVEMENT_ITERATIONS 1

#define FAST_SMOOTH_MOVEMENT_ITERATIONS 1
#define FAST_PRECISE_MOVEMENT_ITERATIONS 1
#define FAST_ENDPOINT_MOVEMENT_ITERATIONS 1

// The extra iterations we do when changing directions (each is roughly 20ms)
// These are at our old position; by sending extra it prepares the servo
// If the new direction additional iterations and max movement is high while 
// movement iterations is low, you get full-speed movement to endpoints followed 
// by a pause.
#define SLOW_SMOOTH_NEW_DIR_ADD_ITERS 0
#define SLOW_PRECISE_NEW_DIR_ADD_ITERS 3
#define SLOW_ENDPOINT_NEW_DIR_ADD_ITERS 25

#define MEDIUM_SMOOTH_NEW_DIR_ADD_ITERS 0
#define MEDIUM_PRECISE_NEW_DIR_ADD_ITERS 2
#define MEDIUM_ENDPOINT_NEW_DIR_ADD_ITERS 35

#define FAST_SMOOTH_NEW_DIR_ADD_ITERS 0
#define FAST_PRECISE_NEW_DIR_ADD_ITERS 1
#define FAST_ENDPOINT_NEW_DIR_ADD_ITERS 45

// The extra iterations we do when we've been given a new target, regardless 
// of if it's in a new direction.
#define SLOW_SMOOTH_NEW_TAR_ADD_ITERS 0
#define SLOW_PRECISE_NEW_TAR_ADD_ITERS 25
#define SLOW_ENDPOINT_NEW_TAR_ADD_ITERS 0

#define MEDIUM_SMOOTH_NEW_TAR_ADD_ITERS 0
#define MEDIUM_PRECISE_NEW_TAR_ADD_ITERS 35
#define MEDIUM_ENDPOINT_NEW_TAR_ADD_ITERS 0

#define FAST_SMOOTH_NEW_TAR_ADD_ITERS 0
#define FAST_PRECISE_NEW_TAR_ADD_ITERS 45
#define FAST_ENDPOINT_NEW_TAR_ADD_ITERS 0

#include <Arduino.h>
#include <inttypes.h>

/**
 * Contains information about a servo that can be sent 
 * to the servo manager 
 *
 * @author Timothy Moore
 * @author Elizabeth Moore
 */
struct PrecisionServo 
{
	/** 
	 * Which pin this servo is operating on. The pin 
	 * can be assumed to have been set to output mode 
	 * (done manually or via servo manager setup)
	 */
	uint8_t pin;
	
	/**
	 * The last angle that we told the servo to go to 
	 * in degrees. Starts at 0
	 */
	uint8_t angleDegrees;
	
	/**
	 * How many more times we should ask the servo to go to angleDegrees 
	 * before moving on.
	 */
	int8_t iterationsLeftOnCurrentIncrement;
	
	/**
	 * Which angle we are trying to get to on this servo.
	 */
	uint8_t targetAngleDegrees;
	
	/**
	 * If the target has recently changed.
	 */
	bool targetChanged;
	
	/**
	 * The sign (-1, 0, +1) for the last direction we tried to move 
	 * the servo in. The servo often loses accuracy when changing 
	 * direction, so if we try to change direction we add extra 
	 * delay.
	 */
	int8_t lastDirection;
	
	/**
	 * Set the target for the servo to the given degrees.
	 * @param angle the direction to go to, in degrees 
	 */
	void setTarget(uint8_t angle) {
		if(angle != targetAngleDegrees) {
			targetAngleDegrees = angle;
			targetChanged = true;
		}
	}
	
	/** Configure this servo to the given settings. 
	 * 
	 * @details This switch might be taking a lot of memory space. It could 
	 * perhaps be avoided using a compiler macro instead of a setSetting 
	 * function?
	 *
	 * @param setting The setting that this servo is using. 
	 * 
	 
	 * Valid Options:
	 *        SERVO_SLOW_SMOOTH
	 *       SERVO_SLOW_PRECISE
	 *      SERVO_SLOW_ENDPOINT
	 *      SERVO_MEDIUM_SMOOTH  
	 *     SERVO_MEDIUM_PRECISE
	 *    SERVO_MEDIUM_ENDPOINT
	 *        SERVO_FAST_SMOOTH
	 *       SERVO_FAST_PRECISE
	 *      SERVO_FAST_ENDPOINT
	 *
	 * SLOW/MEDIUM/FAST controls how rapidly the servo is going to the target 
	 * 
	 * SMOOTH - No additional pauses are used; the servo chases the target but 
	 *          often won't quite reach it. This is great for if you are trying 
	 *          to follow a sensor and the angles your asking for are inherently
	 *          inprecise.
	 *
	 * PRECISE - The servo pauses at the *old* target whenever the target changes.
	 *           This helps ensure it makes it exactly to the requested angles,
	 *           assuming that you are using waitUntilFinished or sufficient delays
	 *           between changing targets. This is ideal if you are hardcoding a 
	 *           sequence of movements and want the most consistent behavior possible.
	 *
	 * ENDPOINT - Acts very similiarly to PRECISE, except skips the pause when given
	 *            orders that continue in the same direction (the servo is often 
	 *            less accurate when changing directions)
	 */
	void setSetting(uint8_t setting) {
		switch(setting) {
		case SERVO_SLOW_SMOOTH:
			this->maxMovement = SLOW_SMOOTH_MAX_MOVEMENT;
			this->movementIters = SLOW_SMOOTH_MOVEMENT_ITERATIONS;
			this->newDirAddIters = SLOW_SMOOTH_NEW_DIR_ADD_ITERS;
			this->newTarAddIters = SLOW_SMOOTH_NEW_TAR_ADD_ITERS;
			break;
		case SERVO_SLOW_PRECISE:
			this->maxMovement = SLOW_PRECISE_MAX_MOVEMENT;
			this->movementIters = SLOW_PRECISE_MOVEMENT_ITERATIONS;
			this->newDirAddIters = SLOW_PRECISE_NEW_DIR_ADD_ITERS;
			this->newTarAddIters = SLOW_PRECISE_NEW_TAR_ADD_ITERS;
			break;
		case SERVO_SLOW_ENDPOINT:
			this->maxMovement = SLOW_ENDPOINT_MAX_MOVEMENT;
			this->movementIters = SLOW_ENDPOINT_MOVEMENT_ITERATIONS;
			this->newDirAddIters = SLOW_ENDPOINT_NEW_DIR_ADD_ITERS;
			this->newTarAddIters = SLOW_ENDPOINT_NEW_TAR_ADD_ITERS;
			break;
		case SERVO_MEDIUM_SMOOTH:
			this->maxMovement = MEDIUM_SMOOTH_MAX_MOVEMENT;
			this->movementIters = MEDIUM_SMOOTH_MOVEMENT_ITERATIONS;
			this->newDirAddIters = MEDIUM_SMOOTH_NEW_DIR_ADD_ITERS;
			this->newTarAddIters = MEDIUM_SMOOTH_NEW_TAR_ADD_ITERS;
			break;
		case SERVO_MEDIUM_PRECISE:
			this->maxMovement = MEDIUM_PRECISE_MAX_MOVEMENT;
			this->movementIters = MEDIUM_PRECISE_MOVEMENT_ITERATIONS;
			this->newDirAddIters = MEDIUM_PRECISE_NEW_DIR_ADD_ITERS;
			this->newTarAddIters = MEDIUM_PRECISE_NEW_TAR_ADD_ITERS;
			break;
		case SERVO_MEDIUM_ENDPOINT:
			this->maxMovement = MEDIUM_ENDPOINT_MAX_MOVEMENT;
			this->movementIters = MEDIUM_ENDPOINT_MOVEMENT_ITERATIONS;
			this->newDirAddIters = MEDIUM_ENDPOINT_NEW_DIR_ADD_ITERS;
			this->newTarAddIters = MEDIUM_ENDPOINT_NEW_TAR_ADD_ITERS;
			break;
		case SERVO_FAST_SMOOTH:
			this->maxMovement = FAST_SMOOTH_MAX_MOVEMENT;
			this->movementIters = FAST_SMOOTH_MOVEMENT_ITERATIONS;
			this->newDirAddIters = FAST_SMOOTH_NEW_DIR_ADD_ITERS;
			this->newTarAddIters = FAST_SMOOTH_NEW_TAR_ADD_ITERS;
			break;
		case SERVO_FAST_PRECISE:
			this->maxMovement = FAST_PRECISE_MAX_MOVEMENT;
			this->movementIters = FAST_PRECISE_MOVEMENT_ITERATIONS;
			this->newDirAddIters = FAST_PRECISE_NEW_DIR_ADD_ITERS;
			this->newTarAddIters = FAST_PRECISE_NEW_TAR_ADD_ITERS;
			break;
		case SERVO_FAST_ENDPOINT:
			this->maxMovement = FAST_ENDPOINT_MAX_MOVEMENT;
			this->movementIters = FAST_ENDPOINT_MOVEMENT_ITERATIONS;
			this->newDirAddIters = FAST_ENDPOINT_NEW_DIR_ADD_ITERS;
			this->newTarAddIters = FAST_ENDPOINT_NEW_TAR_ADD_ITERS;
			break;
		}
	}
	
	// servo settings; see defines at the top. Only change 
	// these directly if none of the presets are satisfactory.
	uint8_t maxMovement;
	uint8_t movementIters;
	uint8_t newDirAddIters;
	uint8_t newTarAddIters;
};
#endif