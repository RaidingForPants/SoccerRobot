#include "Pusher.h"
#include "../RobotMap.h"

Pusher::Pusher() :
		Subsystem("Pusher")
{
	motor = std::shared_ptr<CANTalon>(new CANTalon(RobotMap::PUSHER_MOTOR_PORT));
	motor->SetControlMode(CANSpeedController::kSpeed);
}

void Pusher::InitDefaultCommand()
{

}

// Put methods for controlling this subsystem
// here. Call these from Commands.
