#include "ScreenManager.h"
#include "ShaderManager.h"
#include "BitmapStore.h"

ScreenManager::ScreenManager(Vector2i res)
{
	Sprite gameBackground = Sprite(ShaderManager::GetShader("sprite"), BitmapStore::getBitmap("background"));

	m_Screens["Game"] = std::make_unique<GameScreen>(this, res, gameBackground);
	m_Screens["Select"] = std::make_unique<SelectScreen>(this, res, gameBackground);
}

void ScreenManager::handleInput(RenderWindow& window)
{
	m_Screens[m_CurrentScreen]->handleInput(window);
}

void ScreenManager::update(float fps)
{
	m_Screens[m_CurrentScreen]->update(fps);
}

void ScreenManager::draw(RenderWindow& window)
{
	m_Screens[m_CurrentScreen]->draw(window);
}
