/*
 * ArcadeDrive.h
 *
 *  Created on: Oct 15, 2016
 *      Author: Benjamin
 */

#ifndef ARCADE_DRIVE_H
#define ARCADE_DRIVE_H

#include "WPILib.h"
#include "Commands/Command.h"

class ArcadeDrive: public Command{
public:
	ArcadeDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	float baseSpeed;
	float rightSpeedMod;
	float leftSpeedMod;
	float direction;

};

#endif
