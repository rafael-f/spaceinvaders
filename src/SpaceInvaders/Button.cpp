#include "Button.h"

Button::Button(Vector2f position, float width, float height, Color color, const std::string& text)
	:m_Collider(position, Vector2f(width, height))
{
	m_Button.setPosition(position);
	m_Button.setFillColor(color);
	m_Button.setSize(Vector2f(width, height));
	m_Text = "" + text;

	float textPaddingX = width / 10;
	float textPaddingY = height / 5;

	m_ButtonText.setCharacterSize(/*height * .7f*/1.0f);
	m_ButtonText.setString(text);
	m_Font.loadFromFile("fonts/Roboto-Bold.ttf", height * .7f);
	m_ButtonText.setFont(m_Font);
	m_ButtonText.setPosition(Vector2f((position.x + textPaddingX), (position.y + textPaddingY)));
}

void Button::draw(RenderWindow& window)
{
	window.draw(&m_Button);
	window.draw(&m_ButtonText);
}
