/*
 * Robot.h
 *
 *  Created on: Oct 15, 2016
 *      Author: Benjamin
 */

#ifndef ROBOT_H
#define ROBOT_H

#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "CommandBase.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/Pusher.h"

class Robot: public IterativeRobot{

public:
	static std::shared_ptr<DriveTrain> drive_train;
	//static std::shared_ptr<Pusher> pusher;
	static std::unique_ptr<OI> oi;

private:
	std::unique_ptr<Command> autonomousCommand;
	SendableChooser *chooser;

	void RobotInit(){}
	void DisabledInit(){}
	void DisabledPeriodic(){}
	void AutonomousInit(){}
	void AutonomousPeriodic(){}
	void TeleopInit(){}
	void TeleopPeriodic(){}
	void TestPeriodic(){}

};

#endif /* SRC_ROBOT_H_ */
