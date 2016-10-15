#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
//const int LEFTMOTOR = 1;
//const int RIGHTMOTOR = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;

namespace RobotMap{

const int OPERATOR_INPUT_PORT = 0;

const int RIGHT_DRIVE_MOTOR_PORT = 1;
const int LEFT_DRIVE_MOTOR_PORT = 2;

const int PUSHER_MOTOR_PORT = 3;
//AKA FLIPPER_MOTOR_PORT
const int BLOCKER_MOTOR_PORT = 4;
//AKA FLAPPER_MOTOR_PORT
}

#endif
