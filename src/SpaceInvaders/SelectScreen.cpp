#include "SelectScreen.h"
#include "SelectUIPanel.h"
#include "SelectInputHandler.h"
#include <Windows.h>

SelectScreen::SelectScreen(ScreenManagerRemoteControl* smrc, Vector2i res, Sprite backgroundSprite)
	:m_ScreenManagerRemoteControl(smrc), m_BackgroundSprite(backgroundSprite)
{
	auto suip = std::make_unique<SelectUIPanel>(res);
	auto sih = std::make_shared<SelectInputHandler>();

	addPanel(std::move(suip), smrc, sih);

	auto textureSize = m_BackgroundSprite.getTexture()->getSize();

	int x = GetSystemMetrics(SM_CXSCREEN);
	int y = GetSystemMetrics(SM_CYSCREEN);
	m_View.setSize(static_cast<float>(x), static_cast<float>(y));
	m_View.setCenter(static_cast<float>(x / 2), static_cast<float>(y / 2));

	m_BackgroundSprite.setScale(float(m_View.getSize().x) / static_cast<float>(textureSize.x), float(m_View.getSize().y) / static_cast<float>(textureSize.y));
}

void SelectScreen::draw(RenderWindow& window)
{
	// Change to this screen's view to draw
	window.setView(m_View);
	window.draw(&m_BackgroundSprite);

	// Draw the UIPanel view(s)
	Screen::draw(window);
}
