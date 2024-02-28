#pragma once

class Keyboard
{
public:
	enum Key
	{
		Escape,
		Left,
		Right,
		Up,
		Down,
		Space
	};

	static bool isKeyPressed(Keyboard::Key key);
};
