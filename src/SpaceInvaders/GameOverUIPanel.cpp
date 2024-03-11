#include "Color.h"
#include "GameOverUIPanel.h"
#include "GameScreen.h"

bool GameScreen::m_GameOver;

GameOverUIPanel::GameOverUIPanel(Vector2i res) :
	UIPanel(res,
		(res.x / 10) * 3,
		res.y / 2, // 50% of the resolution from the top
		static_cast<float>((res.x / 10) * 3), // as wide as 1/3 of the resolution
		static_cast<float>(res.y / 6), // and as tall as 1/6 of the resolution
		50, 255, 255, 255) // a, r, g, b
{
	m_ButtonWidth = static_cast<float>(res.x / 20);
	m_ButtonHeight = static_cast<float>(res.y / 20);
	m_ButtonPadding = static_cast<float>(res.x / 100);
	m_Text.setFillColor(Color(0, 255, 0, 255));// Green
	m_Text.setString("GAME OVER!");
	m_Font.loadFromFile("fonts/Roboto-Bold.ttf", m_ButtonPadding * .7f); // todo size
	m_Text.setFont(m_Font);
	m_Text.setPosition(Vector2f(m_ButtonPadding, (m_ButtonPadding * 2) + m_ButtonHeight));
	m_Text.setCharacterSize(60);
	initialiseButtons();
}

void GameOverUIPanel::initialiseButtons()
{
	addButton(m_ButtonPadding, m_ButtonPadding, static_cast<int>(m_ButtonWidth), static_cast<int>(m_ButtonHeight), Color(0, 255, 0, 125), "Play");

	addButton(m_ButtonWidth + (m_ButtonPadding * 2), m_ButtonPadding, static_cast<int>(m_ButtonWidth), static_cast<int>(m_ButtonHeight), Color(255, 0, 0, 125), "Home");
}

void GameOverUIPanel::draw(RenderWindow& window)
{
	if (GameScreen::m_GameOver)
	{
		show();
		UIPanel::draw(window);
		window.draw(&m_Text);
	}
	else
	{
		hide();
	}
}
