/*
 * DriveTrain.cpp
 *
 *  Created on: Oct 15, 2016
 *      Author: Benjamin
 */

#include "DriveTrain.h"

#include "../RobotMap.h"
#include "../Commands/ArcadeDrive.h"

DriveTrain::DriveTrain(): Subsystem("DriveTrain") {

	//ASK NILS WHAT MOTOR ENCODER

	left_primary_motor = std::shared_ptr<CANTalon>(new CANTalon(RobotMap::LEFT_DRIVE_MOTOR_PORT));

	right_primary_motor = std::shared_ptr<CANTalon>(new CANTalon(RobotMap::RIGHT_DRIVE_MOTOR_PORT));

	robot_drive = std::unique_ptr<RobotDrive>(
			new RobotDrive(left_primary_motor, right_primary_motor)
	);

	left_primary_motor->Set(0, 0);
	right_primary_motor->Set(0, 0);

	//SetOutputRange(-1, 1);

	robot_drive->SetSafetyEnabled(true);
	robot_drive->SetExpiration(0.3);

	//Disable();

	Reset();
}

void DriveTrain::InitDefaultCommand() {
	SetDefaultCommand(new ArcadeDrive());
}

void DriveTrain::drive(float left, float right) {

	if(left < -1) {
		left = -1;
	} else if(left > 1) {
		left = 1;
	}

	if(right < -1) {
		right = -1;
	} else if(right > 1) {
		right = 1;
	}

	robot_drive->TankDrive(left, right, false);
}

void DriveTrain::UsePIDOutput(double output) {
	robot_drive->TankDrive(output, output, false);
}

double DriveTrain::ReturnPIDInput() {
	return (left_primary_motor->GetPosition() + right_primary_motor->GetPosition()) / 2;
}

void DriveTrain::returnPosition(int motor){
	SmartDashboard::PutNumber("Motor Position", ((motor == 0) ? left_primary_motor->GetPosition() : right_primary_motor->GetPosition()));
}

void DriveTrain::Reset() {
	drive(0, 0);

	//left_primary_motor->SetPosition(0);
	//right_primary_motor->SetPosition(0);

	//Disable();
	//SetSetpoint(0);
}



