#pragma once
#include "FloatRect.h"
#include "Font.h"
#include "RectangleShape.h"
#include "Text.h"
#include "Vector2f.h"
#include "Window.h"
#include <string>

class Button
{
private:
	RectangleShape m_Button;
	Text m_ButtonText;
	Font m_Font;

public:
	Button(Vector2f position, float width, float height, int red, int green, int blue, const std::string& text);
	
	std::string m_Text;

	FloatRect m_Collider;

	void draw(Window& window) const;
};
