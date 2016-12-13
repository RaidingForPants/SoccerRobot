/*
 * XBoxController.cpp
 *
 *  Created on: Oct 15, 2016
 *      Author: Benjamin
 */

#include <map>
#include "XBoxController.h"

XBoxController::XBoxController(int port) {
	wpilib_joystick = std::unique_ptr<Joystick>(new Joystick(port));

	left_stick_offset = Vector(0, 0);
	right_stick_offset = Vector(0, 0);
}

Vector XBoxController::getStick(int xId, int yId, Vector offset) {
	float xRaw = wpilib_joystick->GetRawAxis(xId);
	float yRaw = wpilib_joystick->GetRawAxis(yId);

	return Vector(xRaw - offset.x, yRaw - offset.y);
}

float XBoxController::getTrigger(int id) {
	float raw = wpilib_joystick->GetRawAxis(id);
	return (raw - 0.5) * 2;// Trigger is an axis that starts(Unpressed) with the value 0.5
}

Vector XBoxController::getLeftStick() {
	return getStick(AXIS_LEFT_STICK_X_ID, AXIS_LEFT_STICK_Y_ID, left_stick_offset);
}

Vector XBoxController::getRightStick() {
	return getStick(AXIS_RIGHT_STICK_X_ID, AXIS_RIGHT_STICK_Y_ID, right_stick_offset);
}

bool XBoxController::getButton(int id) {
	return wpilib_joystick->GetRawButton(id);
}

bool XBoxController::getDPad(int angle) {
	return angle == wpilib_joystick->GetPOV();
}

float XBoxController::getLeftTrigger() {
	return getTrigger(AXIS_LEFT_TRIGGER_ID);
}

float XBoxController::getRightTrigger() {
	return getTrigger(AXIS_RIGHT_TRIGGER_ID);
}

bool XBoxController::getLeftTriggerAsButton() {
	return getLeftTrigger() >= LEFT_TRIGGER_BUTTON_THRESHOLD;
}

bool XBoxController::getRightTriggerAsButton() {
	return getRightTrigger()>= RIGHT_TRIGGER_BUTTON_THRESHOLD;
}

std::shared_ptr<JoystickButton> XBoxController::getJoystickButton(int id) {
	if(joystick_button_map.count(id) == 0) {
		joystick_button_map[id] = std::shared_ptr<JoystickButton>(new JoystickButton(wpilib_joystick.get(), id));
	}

	return joystick_button_map[id];
}

/*std::shared_ptr<XboxControllerTriggerButton> XBoxController::getTriggerJoystickButton(int id, float threshold) {
	if(trigger_joystick_button_map.count(id) == 0) {
		trigger_joystick_button_map[id] = std::shared_ptr<XboxControllerTriggerButton>(
				new XboxControllerTriggerButton(this, id, threshold)
		);
	}

	return trigger_joystick_button_map[id];
}*/

XboxControllerTriggerButton::XboxControllerTriggerButton(XBoxController *controller, int trigger_id, float pressed_threshold):
		controller(controller),
		trigger_id(trigger_id),
		pressed_threshold(pressed_threshold) {

}

bool XboxControllerTriggerButton::get() {
	return controller->getTrigger(trigger_id) >= pressed_threshold;
}

void XBoxController::Calibrate() {
	left_stick_offset = Vector(wpilib_joystick->GetRawAxis(AXIS_LEFT_STICK_X_ID),
								wpilib_joystick->GetRawAxis(AXIS_LEFT_STICK_Y_ID));


	right_stick_offset = Vector(wpilib_joystick->GetRawAxis(AXIS_RIGHT_STICK_X_ID),
								wpilib_joystick->GetRawAxis(AXIS_RIGHT_STICK_Y_ID));
}


