#pragma once

// todo
class Joystick
{
public:
	static bool isConnected(int joystick);

	enum Axis
	{
		X,
		Y
	};

	static float getAxisPosition(int joystick, Axis axis);

	static bool isButtonPressed(int joystick, int button);
};
