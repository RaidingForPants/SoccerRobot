#ifndef Pusher_H
#define Pusher_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Pusher: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	static std::shared_ptr<CANTalon> motor;

public:
	Pusher();
	void InitDefaultCommand();
};

#endif
