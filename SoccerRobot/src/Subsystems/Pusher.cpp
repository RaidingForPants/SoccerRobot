#include "Pusher.h"
#include "../RobotMap.h"
#include "CANSpeedController.h"

Pusher::Pusher() :
		Subsystem("Pusher")
{
	motor = std::shared_ptr<CANTalon>(new CANTalon(RobotMap::PUSHER_MOTOR_PORT));
	motor->SetControlMode(CANSpeedController::kPosition);
	motor->SetPosition(0);
}

void Pusher::InitDefaultCommand()
{
	SetDefaultCommand(new RotatePusherToPosition());
}

void Pusher::rotate(){
	motor->Set(goalPosition);
}

void Pusher::Reset(){
	motor->SetPosition(0);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
