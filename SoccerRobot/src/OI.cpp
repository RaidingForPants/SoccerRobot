#include "OI.h"

#include "RobotMap.h"

#include "Commands/ArcadeDrive.h"

OI::OI() {
	xbox_controller = std::shared_ptr<XBoxController>(new XBoxController(RobotMap::OPERATOR_INPUT_PORT));

	xbox_controller->getJoystickButton(XBoxController::BUTTON_A_ID)->WhenPressed(new SetPusherPosition());

	xbox_controller->getJoystickButton(XBoxController::BUTTON_A_ID);



	//xbox_controller->getButton(XBoxController::BUTTON_B_ID)->WhenPressed(/*extend/retract the blockers*/);
	//xbox_controller->getButton(XBoxController::BUTTON_X_ID)->WhenPressed(/*"Slap" with blockers*/);
	//xbox_controller->getButton(XBoxController::BUTTON_Y_ID)->WhenPressed(/*Output motor position to the SmartDashboard*/);

	//xbox_controller->GetTriggerJoystickButton(XBoxController::AXIS_RIGHT_TRIGGER_ID, XBoxController::RIGHT_TRIGGER_BUTTON_THRESHOLD)->WhenPressed(new RunShooter(-1));
	//xbox_controller->GetTriggerJoystickButton(XBoxController::AXIS_RIGHT_TRIGGER_ID, XBoxController::RIGHT_TRIGGER_BUTTON_THRESHOLD)->WhenReleased(new StopShooter());
	//xbox_controller->GetJoystickButton(XBoxController::BUTTON_LEFT_BUMPER)->WhenPressed(new RunBallRetriever(1));
	//xbox_controller->GetJoystickButton(XBoxController::BUTTON_LEFT_BUMPER)->WhenReleased(new StopBallRetriever());

}
