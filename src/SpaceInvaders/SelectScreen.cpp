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
}

void SelectScreen::draw(RenderWindow& window)
{
	window.draw(&m_BackgroundSprite);

	// Draw the UIPanel view(s)
	Screen::draw(window);
}
