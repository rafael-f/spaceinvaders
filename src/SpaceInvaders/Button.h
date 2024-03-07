#pragma once
#include "FloatRect.h"
#include "Font.h"
#include "RectangleShape.h"
#include "Text.h"
#include "Vector2f.h"
#include "RenderWindow.h"
#include <string>

class Button
{
public:
	Button(Vector2f position, float width, float height, Color color, const std::string& text);
	
	std::string m_Text;

	FloatRect m_Collider;

	void draw(RenderWindow& window);

private:
	RectangleShape m_Button;
	Text m_ButtonText;
	Font m_Font;
};
