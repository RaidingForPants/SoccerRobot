/*
 * ArcadeDrive.cpp
 *
 *  Created on: Oct 15, 2016
 *      Author: Benjamin
 */

#include "ArcadeDrive.h"
#include "../Robot.h"
#include "../Models/Vector.h"
#include "Command.h"
#include <math.h>

ArcadeDrive::ArcadeDrive(): Command(“ArcadeDrive””){
	Requires(Robot::drive_train.get());
}

void ArcadeDrive::Initialize(){
	Robot::drive_train->Reset();
}

void ArcadeDrive::Execute(){
	Vector v = Robot::oi->xbox_controller->getLeftStick;

	baseSpeed=v.getMagnitude();

	if(v.x>0){
		leftSpeedMod = 1;
		rightSpeedMod = 1-v.x/v.getMagnitude();
	}else{
		leftSpeedMod = 1-v.x/v.getMagnitude();
		rightSpeedMod = 1;
	}

	direction = ((v.y>0) ? 1 : -1);

	Robot::drive_train->drive(baseSpeed*leftSpeedMod*direction, baseSpeed*rightSpeedMod*direction);
}

bool ArcadeDrive::IsFinished(){
	return false;
}

void ArcadeDrive::End(){
	Robot::drive_train->Reset();
}

void ArcadeDrive::Interrupted(){
	End();
}



