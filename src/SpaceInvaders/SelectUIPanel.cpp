#include "Color.h"
#include "SelectUIPanel.h"
#include <iostream>

SelectUIPanel::SelectUIPanel(Vector2i res) :
	// Create a new UIPanel
	// by calling the super-class constructor
	UIPanel(res,
		(res.x / 10) * 2, // Start 2/10 across
		res.y / 3, // 1/3 of the resolution from the top
		static_cast<float>((res.x / 10) * 6), // as wide as 6/10 of the resolution
		static_cast<float>(res.y / 3), // and as tall as 1/3 of the resolution
		50, 255, 255, 255) // a, r, g, b
{
	m_ButtonWidth = static_cast<float>(res.x / 20);
	m_ButtonHeight = static_cast<float>(res.y / 20);
	m_ButtonPadding = static_cast<float>(res.x / 100);
	m_Text.setFillColor(Color(0, 255, 0, 255));
	m_Text.setString("SPACE INVADERS ++");

	//https://www.dafont.com/roboto.font
	m_Font.loadFromFile("fonts/Roboto-Bold.ttf", 10); // todo size
	m_Text.setFont(m_Font);
	m_Text.setPosition(Vector2f(m_ButtonPadding + (res.x / 10) * 2, res.y / 3 + m_ButtonHeight + (m_ButtonPadding * 2)));
	m_Text.setCharacterSize(16);
	initialiseButtons();
}

void SelectUIPanel::initialiseButtons()
{
	// Buttons are positioned relative to the top left
	// corner of the UI panel(m_View in UIPanel)
	addButton(m_ButtonPadding, m_ButtonPadding, static_cast<int>(m_ButtonWidth), static_cast<int>(m_ButtonHeight), Color(0, 255, 0, 255), "Play");

	addButton(m_ButtonWidth + (m_ButtonPadding * 2), m_ButtonPadding, static_cast<int>(m_ButtonWidth), static_cast<int>(m_ButtonHeight), Color(255, 0, 0, 255), "Quit");
}

void SelectUIPanel::draw(RenderWindow& window)
{
	show();
	UIPanel::draw(window);
	window.draw(&m_Text);
}
