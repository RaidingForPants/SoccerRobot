#ifndef SetPusherPosition_H
#define SetPusherPosition_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetPusherPosition: public CommandBase
{
public:
	SetPusherPosition();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
