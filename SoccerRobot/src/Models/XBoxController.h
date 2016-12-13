/*
 * XBoxController.h
 *
 *  Created on: Oct 15, 2016
 *      Author: Benjamin
 */

#ifndef XBOX_CONTROLLER_H
#define XBOX_CONTROLLER_H

#include "WPILib.h"
#include "Vector.h"

class XboxControllerTriggerButton;

class XBoxController{

public:
	//Axis IDs
	const static int AXIS_LEFT_STICK_X_ID = 0;
	const static int AXIS_LEFT_STICK_Y_ID = 1;
	const static int AXIS_RIGHT_STICK_X_ID = 4;
	const static int AXIS_RIGHT_STICK_Y_ID = 5;
	const static int AXIS_LEFT_TRIGGER_ID = 2;
	const static int AXIS_RIGHT_TRIGGER_ID = 3;

	//Button IDs
	const static int BUTTON_LEFT_STICK_CLICK_ID = 9;
	const static int BUTTON_RIGHT_STICK_CLICK_ID = 10;
	const static int BUTTON_LEFT_BUMPER_ID = 5;
	const static int BUTTON_RIGHT_BUMPER_ID = 6;
	const static int BUTTON_A_ID = 1;
	const static int BUTTON_B_ID = 2;
	const static int BUTTON_X_ID = 3;
	const static int BUTTON_Y_ID = 4;
	const static int BUTTON_BACK_ID = 7;
	const static int BUTTON_START_ID = 8;

	//D-Pad IDs
	const static int DPAD_N_ID = 0;
	const static int DPAD_NE_ID = 45;
	const static int DPAD_E_ID = 90;
	const static int DPAD_SE_ID = 135;
	const static int DPAD_S_ID = 180;
	const static int DPAD_SW_ID = 225;
	const static int DPAD_W_ID = 270;
	const static int DPAD_NW_ID = 315;

	//Other
	constexpr static float LEFT_TRIGGER_BUTTON_THRESHOLD = 0.8;
	constexpr static float RIGHT_TRIGGER_BUTTON_THRESHOLD = 0.8;

	XBoxController(int port);

	static Vector getLeftStick();
	static Vector getRightStick();
	static Vector getStick(int xId, int yId, Vector offset);
	static float getLeftTrigger();
	static float getRightTrigger();
	static float getTrigger(int id);

	static bool getButton(int id);
	static bool getDPad(int angle);
	static bool getLeftTriggerAsButton();
	static bool getRightTriggerAsButton();

	static void Calibrate();

	std::shared_ptr<JoystickButton> getJoystickButton(int id);
	std::shared_ptr<XboxControllerTriggerButton> getTriggerJoystickButton(int id, float threshold);

private:

		std::map<int, std::shared_ptr<JoystickButton>> joystick_button_map;
		std::map<int, std::shared_ptr<XboxControllerTriggerButton>> trigger_joystick_button_map;

		std::unique_ptr<Joystick> wpilib_joystick;

		Vector left_stick_offset;
		Vector right_stick_offset;

};

class XboxControllerTriggerButton: public Button {
private:
	XBoxController *controller;

	int trigger_id;
	float pressed_threshold;

public:
	XboxControllerTriggerButton(XBoxController *controller, int trigger_id, float pressed_threshold);

	bool get();
};

#endif
