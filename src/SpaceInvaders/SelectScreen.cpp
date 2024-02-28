#include "SelectScreen.h"
#include "SelectUIPanel.h"
#include "SelectInputHandler.h"

SelectScreen::SelectScreen(ScreenManagerRemoteControl* smrc, Vector2i res)
	: m_BackgroundTexture("graphics/background.png")
{
	auto suip = std::make_unique<SelectUIPanel>(res);
	auto sih = std::make_shared<SelectInputHandler>();

	addPanel(std::move(suip), smrc, sih);

	m_ScreenManagerRemoteControl = smrc;
	m_BackgroundSprite.setTexture(m_BackgroundTexture);

	auto textureSize = m_BackgroundSprite.getTexture()->getSize();

	m_BackgroundSprite.setScale(float(m_View.getSize().x) / textureSize.x, float(m_View.getSize().y) / textureSize.y);
}

void SelectScreen::draw(RenderWindow& window)
{
	// Change to this screen's view to draw
	window.setView(m_View);
	window.draw(m_BackgroundSprite);

	// Draw the UIPanel view(s)
	Screen::draw(window);
}
