#ifndef RotatePusherToPosition_H
#define RotatePusherToPosition_H

#include "../CommandBase.h"
#include "WPILib.h"

class RotatePusherToPosition: public CommandBase
{

private:


public:
	RotatePusherToPosition();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
